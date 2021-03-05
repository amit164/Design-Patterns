#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

class Observer {
public:
    virtual void update(const char *s) = 0;
    //virtual bool operator ==(Observer* observer)=0;
};

class Observable {
protected:
    vector<Observer *> observers;

public:
    Observable() {
        observers = vector<Observer *>();
    }

    void attach(Observer *observer) {
        this->observers.push_back(observer);
    }

/*    void detach(Observer* observer){
        auto iter = this->observers.begin();
        auto end = this->observers.end();
        while(iter != end){
            if(*iter == observer) {
                this->observers.erase(iter);
                break;
            }
            iter++;
        }
    }*/

    virtual void notify(const char *s) = 0;
};

class Moodle : public Observable {
    map<const char *, int> courses;
public:
    Moodle() : Observable() {
        this->courses = map<const char *, int>();
    }

    map<const char *, int> getState() {
        this->courses;
    }

    void setState(const char *c, int num) {
        if(this->courses.find(c) == this->courses.end())
            this->courses.insert({c, num});
        else {
            this->courses.at(c) = num;
        }
        notify(c);
    }

    void notify(const char *string1) override {
        for (auto &ob: this->observers) {
            ob->update(string1);
        }
    }
};

class Student : public Observer {
    map<const char *, int> courses;
    Moodle *moodle;
public:
    Student(Moodle *moodle1) {
        this->courses = map<const char *, int>();
        this->moodle = moodle1;
    }

    void update(const char *s) override {
        if (strcmp(s, "algo") == 0) {
            this->courses = map<const char *, int>(this->moodle->getState());
            if(this->courses.at(s) > 80)
                cout<< "nice"<< endl;
        }
    }

    bool operator==(Observable *observable) {
        Moodle *m = dynamic_cast<Moodle *>(observable);
        if (m) {
            if (this->courses.size() != m->getState().size())
                return false;
            map<const char *, int> courses2 = m->getState();
            auto iter2 = courses2.begin();
            for (auto &course: this->courses) {
                if (strcmp((*iter2).first, course.first) || (*iter2).second != course.second)
                    return false;
                iter2++;
            }
        }
    }
};


int main() {
    Moodle *moodle = new Moodle();
    Student *s = new Student(moodle);
    moodle->attach(s);
    moodle->setState("math", 100);
    moodle->setState("algo", 70);
    moodle->setState("algo", 81);
}
