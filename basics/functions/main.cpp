#include <iostream>
#include <stdio.h>

using namespace std;

// global 
int global_var = 0;

// prototype
int add_numbers(int a, int b, int c = 0);
// overload
float add_numbers(float a, float b, float c = 0); //default argument
// increase with static and globals
int increase_number(int val = 1);
// recursive function
int factorial(int);

int main(int argc, char *argv[]){
    int a = 0;
    int b = 0;
    cout << "enter number a:";
    cin >> a;
    cout << "enter number b:";
    cin >> b;  
    printf("%d + %d = %d\n",a,b,add_numbers(a,b)); 

    float A = 0;
    float B = 0;
    cout << "enter number A:";
    cin >> A;
    cout << "enter number B:";
    cin >> B;
    printf("%.2f + %.2f = %.2f\n",A,B,add_numbers(A,B)); 

    printf(" increase a number by %d\n",1);
    increase_number();
    increase_number();
    printf("!%d = %d\n",a,factorial(a));
    return 0;
}

int add_numbers(int a, int b, int c){
    return a+b+c;
}

float add_numbers(float a, float b, float c){
    return a+b+c;
}

int increase_number(int val){
    static int static_var = 0;
    static_var += val;
    global_var += val; 
    cout<< "new global = " << +global_var <<endl;
    cout<< "new static = " << +static_var <<endl;
}

int factorial(int n){
    if (n > 1){
        return n*factorial(n-1);
    }
    else{
        return 1;
    }
}

