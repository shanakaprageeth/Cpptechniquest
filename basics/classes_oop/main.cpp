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

class Student: public User{
    private:
        int studentId;
    public:
        Student(int a, gender s){
            studentId = 0;
            setAge(a);
            setSex(s);
        }
        int getStudentId(){
            return this->studentId;
        }
        // allow access to private objects for non-member classes
        friend int increaseStudentId(Student);
};

int increaseStudentId(Student s){
    s.studentId = s.studentId+ 1;
}

class friendClass;
class normalClass{
private:
    int a;
public:
    friend class friendClass;
};

class friendClass{
public:
    int getA(normalClass x){return x.a;}
};


int main(int argc, char *argv[]){
    User myuser1(2,female);
    User myuser2 = myuser1;

    Student student(12,male);
    cout << student.getAge() <<endl;

    student.printUser();

    
    return 0;      
}



