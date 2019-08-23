#include <iostream>
#include <stdio.h>

using namespace std;

struct Position{    
    int x;
    int y;
    float value;
};

enum day { monday=0, tuesday, wednesday, thusrday, friday, saturday, sunday };

void display(Position);

void set_position(Position &);

int main(int argc, char *argv[]){
    Position pos1;
    Position pos2;
    pos1.x = 10;
    pos1.y = 11;
    pos1.value = 10.2;
    display(pos1);
    set_position(pos2);
    display(pos2);

    day today;
    today = tuesday;
    cout << "tomorrow day:" <<today+1 <<endl;

}

void display(Position pos){
    printf("x : %d, y : %d, z : %.2f\n",pos.x, pos.y, pos.value);
}

void set_position(Position &pos){
    cout << "X: ";
    cin >> (pos).x;
    cout << "Y: ";
    cin >> (pos).y;
    cout << "Value: ";
    cin >> (pos).value;
}