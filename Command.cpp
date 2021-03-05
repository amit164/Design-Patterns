#include <iostream>
#include <cstring>

using namespace std;

class Receiver{
public:
    virtual void action(const char* command)=0;
};

class Command{
public:
    virtual void execute(Receiver &receiver)=0;
};

class Eat: public Command{
    char* command;
public:
    Eat(const char* s){
        this->command = new char[strlen(s)+1];
        strcpy(this->command, s);
    }

    void execute(Receiver &receiver) override{
        receiver.action(command);
    }
};

class Student: public Receiver{
    char* name;
public:
    Student(const char* s){
        name = new char[strlen(s)+1];
        strcpy(name, s);
    }

    void action(const char* command) override{
        cout<< name<< " is " << command <<endl;
    }
};

class Parent{
    Command* command;
public:
    Parent(){
        this->command = new Eat("eating");
    }

    void makeStudentDoCommand(Student &s){
        this->command->execute(s);
    }
};


int main() {
    Parent p = Parent();
    Student s("Tomer");
    p.makeStudentDoCommand(s);
}
