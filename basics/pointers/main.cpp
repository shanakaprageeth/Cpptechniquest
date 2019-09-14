#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

// function with references
void swap(int& a, int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// function with rerefence pointers
void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char *argv[]){
    int value = 0;
    int array[10];
    fill (array, array + 10, 0 ); 
    int *pointer;
    // assign pointer to value referece
    pointer = &value;
     //dereference pointer to value
    (*pointer) = (*pointer) + 1;

    cout << "value : " << +value << endl;
    cout << "address : " << +pointer << endl;

    //array pointers
    pointer = &array[1]; // second element of array
    // increase third element of array
    *(pointer + 1) = *(pointer + 1) + 1;
    cout << " , 0:" <<+array[0]<<" , 2:" << +array[2] <<endl;
    swap(array[2], array[0]);
    cout << " , 0:" <<+array[0]<<" , 2:" << +array[2] <<endl;
    swap((pointer + 1), (pointer - 1));
    cout << " , 0:" <<+array[0]<<" , 2:" << +array[2] <<endl;

    //memory allocation and release
    int *ptr = new int[10];
    delete [] ptr; // [] to delete the full array

    return 0;      
}



