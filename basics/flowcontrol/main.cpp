#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]){
    int num = 0;
    cout << "enter a number:";
    cin >> num;    
    if(num > 3){
       // Control of the program move to jump:
        goto goto_label_1;
    }
    else{
        goto goto_label_2;
    }

goto_label_1:    
    cout << "\njump using go to label 1" << endl;
    return 0;
goto_label_2:    
    cout << "\njump using go to label 2" << endl;
    return 0;
}