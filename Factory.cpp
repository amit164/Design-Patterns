#include <iostream>
#include <map>
#include <functional>

using namespace std;

class Product{
protected:
    char c;
public:
    void print(){
        cout<<c<<endl;
    }
};

class A: public Product{
public:
    A(){
        this->c = 'a';
    }
};

class B: public Product{
public:
    B(){
        this->c = 'b';
    }
};


class Factory{
    map<const char*, function<Product*()>> _map;

public:
    Factory(){
        _map.insert({"a", [](){return new A();}});
        _map.insert({"b", [](){return new B();}});
    }

    Product* create(const char* c){
        if(_map.find(c) == _map.end())
            return nullptr;
        return _map.at(c)();
    }
};



int main() {
    Factory f= Factory();
    f.create("a")->print();
}
