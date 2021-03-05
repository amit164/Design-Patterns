#include <iostream>
#include <vector>

using namespace std;

class Sorter{
public:
    virtual void sort()=0;
};

class CommonSorter: public Sorter{
protected:
    vector<int> numbers;
};

class BubbleSorter: public CommonSorter{
public:
    void sort() override{
        for(auto& iter: this->numbers)
            cout<<iter<< endl;
    }
};


class Task{
public:
    virtual void doTask()=0;
};

class BubbleSorterTask: public Task, BubbleSorter{
public:
    void doTask() override{
        sort();
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
