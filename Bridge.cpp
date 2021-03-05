#include <iostream>
#include <string>
#include <iostream>

using namespace std;

//Interface
class House{
public:
    virtual void print()=0;
};

class AbstractHouse{
protected:
    House* house;
public:
    virtual string type()=0;
};

class BigHouse: public AbstractHouse{

    string type() override;

public:
    BigHouse(House &h){
        this->house = &h;
    }
    string type() {
        std:: cout<< "Abstrcat = Big House"<<endl;
        this->house->print();
    }
};

class StrawHouse: public House{
    char* name;
public:
    StrawHouse(){
        this->name = "Straw House";
    }
    void print() {
        cout<<this->name<< endl;
    }
};

class TreeHouseImp: public House{
    char* name;
public:
    explicit TreeHouseImp(){
        name = "Tree House";
    }

    void print() {
        std::cout << this->name << endl;
    }
};

int main() {
    House *h1 = new TreeHouseImp();
    House *h2 = new StrawHouse();
    AbstractHouse *abstractHouse1 = new BigHouse(*h1);
    //abstractHouse1->type();
    AbstractHouse *abstractHouse2 = new BigHouse(*h2);
    abstractHouse2->type();
}
