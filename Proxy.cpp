#include <iostream>

using namespace std;

class Bank{
public:
    virtual void request()=0;
};

class IsraelBank: public Bank{
public:
    void request() override{
        cout<<"request"<<endl;
    }
};

class Proxy: public Bank{
    IsraelBank is;
public:
    Proxy(IsraelBank &israelBank){
        is = israelBank;
    }

    void request() override{
        this->is.request();
    }
};


int main() {
    IsraelBank israelBank = IsraelBank();
    Bank* b = new Proxy(israelBank);
    b->request();
}
