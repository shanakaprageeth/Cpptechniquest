#ifndef SHMSUPPORT_H
#define SHMSUPPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include  <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MMAP_FILE_ALLOC_FAIL 2
#define MMAP_MAP_FAIL 1
#define MMAP_INIT_PASS 0

void *set_up_mmap_new(const char * file_name, int file_size, int options, int mode,int * file);
void *set_up_mmap_slave_new(const char * file_name, int options, int mode,int * file_fp);
void *set_up_mmap(const char * file_name, int file_size, int options, int mode);
void *set_up_mmap_slave(const char * file_name, int options, int mode);
void *shm_setup(key_t key, int *shmid, int shm_size, int mode);
void *shm_setup_name(const char* file_name, int *shmid, int shm_size, int mode); // IPC_CREAT |0666 for server 0666 for client
int delete_shm(void * addr);
int shm_user_control(int shmid, int uid, int giu, int mode);
#endif
