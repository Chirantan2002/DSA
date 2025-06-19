#include<iostream>

using namespace std;

class Student{
public:
    string name;
    int roll;
    float marks;
    Student(string name, int roll, float marks){
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

int main(){
    Student *s = new Student("Chirantan", 45, 67.9);
    s->name = "Raghav";
    cout << s->name << endl;
}