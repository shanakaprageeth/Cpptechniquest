#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <list>
#include <iostream>  
#include <stdlib.h>
#include <ctime>
#include <sys/mman.h>
#include "shared_memory_support.hpp"

#define BUF_SZ 100

typedef struct controller_t {
  int flag;
}controller_t;

const char *worker_buf_mmap_file_name = "/home/shanaka/repos/worker_buf";
int worker_buf_mmap_shmid;
int worker_mmap_buf_sz = BUF_SZ*sizeof(int);
char* shm_buf ;
pthread_mutex_t *change_flag;
pthread_mutex_t *thead_state;

int quitPthread(pthread_mutex_t *mtx)
{
  switch(pthread_mutex_trylock(mtx)) { // try to lock the mutex
    case 0: /* if we got the lock, unlock and return 1 (true) */
      pthread_mutex_unlock(mtx);
      return 1;
    case EBUSY: /* return 0 (false) if the mutex was locked */
      return 0;
  }
  return 1;
}

void *my_thread(void *info){
    controller_t *my_info = (controller_t *)info;
    while(!quitPthread(thead_state)){        
        printf("data : %d\n",my_info->flag);
        if (my_info->flag >= 100){
            if(pthread_mutex_trylock(change_flag) == 0){ // try to lock
                printf("data reset: %d\n",my_info->flag);
                my_info->flag = 0x0;
                pthread_mutex_unlock(change_flag);                  
            }
            /* this is a wait and lock
            pthread_mutex_lock(change_flag)
            my_info->flag = 0x0;
            pthread_mutex_unlock(change_flag);
            printf("data reset: %d\n",my_info->flag);
            */
        }
    }
    pthread_exit(NULL); 
}

int main(){

    change_flag = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    thead_state = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    controller_t my_controller;
    my_controller.flag =0x0;
    pthread_t *p_thread_ptr;
    pthread_t client_pthread;
    pthread_mutex_init(change_flag,NULL);
    pthread_mutex_init(thead_state,NULL);
    pthread_mutex_lock(thead_state);
    pthread_create( p_thread_ptr, NULL, my_thread, &my_controller );

    shm_buf = (char *)shm_setup_name(worker_buf_mmap_file_name, &worker_buf_mmap_shmid, worker_mmap_buf_sz, IPC_CREAT|0666);
    int count = 0;
    while(1){
        usleep(0.00001);
        count++;
        if(count > 1000)
            break;
        pthread_mutex_lock(change_flag);
        my_controller.flag = my_controller.flag + 0x1;
        pthread_mutex_unlock(change_flag);
    }
    pthread_mutex_unlock(thead_state);     
    pthread_cancel(*p_thread_ptr);
    pthread_join(*p_thread_ptr,NULL);
}

  