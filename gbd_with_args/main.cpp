
#include <iostream>
#include <vector>


using namespace std;


int main(int argc, char *argv[]) {
    int count=0;
    int myarray[5];
    vector<int> my_vec;
    for (int i =0; i<5;i++){
        myarray[i] = i;
        my_vec.push_back(i);
    }
    if(argc<2){
        printf("please enter integer values for count\n");
        cin >> count;
    }
    else if ( !isdigit(argv[1][0]) ){
        printf("please enter integer values for count\n");
        cin >> count;
    }
    else{
        count = static_cast<int>(argv[1][0]);        
    }
    printf("\n\n");
    printf("Accessing element %d from 5 item array\n",count);
    printf("\n\n");
    printf("Undefined behaviour in next line. May be it might fail without a error. Accessing out of bound memory \n");
    printf("myarray[%d] = %d\n",count,myarray[count]);
    printf("\n\n");
    printf("Undefined behaviour in next line. May be it might fail without a error. Accessing out of bound memory \n");;
    printf("my_vec[%d] = %d\n",count,my_vec[count]);
    printf("\n\n");

    int number_of_logics = 2;
    if (count%number_of_logics == 0){
        printf("This should produce segmentation fault. Accessing incorrect memory\n");
        printf("\n\n");
        int* my_pointer = (int*)malloc(1); //allocating memory
        my_pointer = 0x0; // change address
        *my_pointer = 0x10; //accessing freeing memory 
    }
    else if (count%number_of_logics == 1){
        printf("This should produce segmentation fault. Modifying read only memory\n");
        printf("\n\n");
        char *rd_string;
        rd_string = (char*)"string";
        *(rd_string+1) = 'a';
    }
    return 0;
}