#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

void display(int n[3][2]);
void display(char *);
void display(string);

int main(int argc, char *argv[]){
    int just_array[3];
    int init_array[3] = {1, 2, 3};
    int just_multi_array[3][2];
    int init_multi_array[1][3][2] = {{{11, 12},{21, 22},{31, 32}}};

    vector<int> vector_int = {1,3,34,5,6};

    char char_str[200];

    string str;

    for (int i =0 ; i < 3; i++){
        for (int j =0 ; j < 2; j++){
            printf("init_multi_array[%d][%d][%d] = %d\n" ,0,i,j,init_multi_array[0][i][j]);
            just_multi_array[i][j] = init_multi_array[0][i][j];
        }
    }
    cout << "initilized just array" <<endl;
    display(just_multi_array);
    cout <<"Please supply a string:";
    getline(cin, str);
    cout << "your string : "<<str <<endl;
    display(str);
    cout <<"Please supply a string:";
    cin.get(char_str,100);
    cout << "your string : "<< char_str <<endl;
    display(char_str);
      
}

void display(int n[3][2]){
    cout << "Displaying Values: " << endl;
    for(int i = 0;  i < 3; ++i){
        for(int j = 0; j < 2; ++j){
            cout << n[i][j] << " ";
        }
        cout <<endl;
    }
}

void display(char s[]){
    cout << "your char array: " << s << endl;
}
void display(string s){
    cout << "your string: " << s << endl;
}