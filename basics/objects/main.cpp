#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

enum gender {male, female};

class User{
private: 
    int uid;
    int age;
    gender sex;
public:
    User(): uid(0), age(0), sex(male){}
    User(int a, gender s): uid(0), age(a), sex(s){ }
    int getUid(){
        return uid;
    }
    int getAge(){
        return age;
    }
    gender getSex(){
        return sex;
    }
    void setAge(int age){
        this->age=age;
    }
    void setSex(gender sex){
        this->sex=sex;
    }
    void printUser(){
        cout << +uid << " : " << +age << " : " << sex << endl;
    }

    int compareUsers (User user1){
        if (this->age == user1.getAge()){
            if(this->sex == user1.getSex()){
                printf("users match\n");
                return 0;
            }            
        }
        printf("users does not match\n");
        return 1;
    }
    //operator overloading
    void operator ++(){
        age = age + 1;
    }
};


int main(int argc, char *argv[]){
    User myuser1(2,female);
    User myuser2 = myuser1;

    myuser1.printUser();
    myuser2.printUser();

    // copy to new user
    User myuser3(myuser1);
    myuser3.printUser();
    myuser1.compareUsers(myuser3);
    ++myuser1;
    myuser1.printUser();
    myuser1.compareUsers(myuser3);
    return 0;      
}



