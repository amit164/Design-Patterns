#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Employee {
public:
    virtual void work() = 0;

    virtual void addEmployee(Employee *employee) = 0;

    virtual void removeEmployee(Employee *employee) = 0;

    virtual Employee *getChild(int index) = 0;

    virtual string getID() = 0;

    virtual map<string, Employee *>& getEmployees() = 0;

    virtual bool isMyManager(Employee *employee) = 0;
};

class Manager : public Employee {
    map<string, Employee *> employees;
    string id;
    //vector<Employee*> employees;

public:
    Manager(string id) {
        //this->employees = vector<Employee*>;
        this->employees = map<string, Employee *>();
        this->id = id;
    }

    void work() override {
        cout << "manager working" << endl;
    }

    void addEmployee(Employee *employee) override {
        //this->employees->push_back(employee);
        if (!isMyManager(employee)) {
            this->employees.insert(pair<string, Employee *>(employee->getID(), employee));
        }
    }

    void addEmployee(Worker *employee) override {
    }

        void removeEmployee(Employee *employee) override {
        //auto iter = this->employees.find(employee->getID());
        this->employees.erase(employee->getID());
        /*vector<Employee*>:: iterator iter = this->employees.begin();
        vector<Employee*>:: iterator end = this->employees.end();
        while(iter != end){
            if(*iter == employee){
                this->employees.erase(iter);
                break;
            }
        }*/
    }

    Employee *getChild(int index) override {
        int count = 0;
        for (auto &iter: this->employees) {
            if (count == index)
                return iter.second;
        }
        return nullptr;
    }

    bool isMyManager(Employee *employee) override {
/*        auto* m = dynamic_cast<Manager*>(employee);
        if(!m)
            return false;*/
        if(employee->getEmployees().empty()){
            return false;
        }
        if (employee->getEmployees().find(this->id) != employee->getEmployees().end())
            return true;
        for (int i = 0; i < this->employees.size(); i++) {
            if (this->isMyManager(employee->getChild(i)))
                return true;
        }
        return false;
    }

    map<string, Employee *>& getEmployees() override {
        return this->employees;
    }

    string getID() override {
        return this->id;
    }

};

class Worker : public Employee {
    map<string, Employee *> employees;
    string id;
public:
    Worker(string id) {
        this->employees = map<string, Employee *>();
        this->id = id;
    }

    void work() override {
        cout << "worker working" << endl;
    }

    void addEmployee(Employee *employee) override {
    }

    void removeEmployee(Employee *employee) override {
    }

    Employee *getChild(int index) override {

    }

    bool isMyManager(Employee *employee) override {
        return false;
    }

    string getID() override {
        return this->id;
    }

    map<string, Employee *>& getEmployees() override {
        return this->employees;
    }
};

int main() {
    Employee *e1 = new Manager("12345");
    Employee *e2 = new Manager("24680");
    e1->addEmployee(e2);
    e2->addEmployee(new Worker("13579"));
    e2->addEmployee(e1);
    for (auto &iter: e2->getEmployees()) {
        cout << iter.first << endl;
    }
}
