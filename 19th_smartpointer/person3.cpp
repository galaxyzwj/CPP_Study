#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person()" << endl;
    }
	
	~Person()
	{
		cout << "~Person()" << endl;
	}

	void printInfo(void)
	{
		cout << "just test function" << endl;	
	}
};

class sp {
private:
    Person *p;

public:
    sp() : p(NULL) {}
        

    sp(Person *other)
    {
        cout<<"sp(const Person *other)"<<endl;
        p = other;
    }

    ~sp()
    {
        cout<<"~sp()"<<endl;
        if (p) { delete p; }
    }

    Person *operator->()
    {
        return p;
    }
};

void test_func(void)
{
    //Person *p = new Person();
    //p->printInfo();   /* 需要手工 delete p; */
    //Person per;       /* 局部变量 */
    //per.printInfo();
    sp s = new Person();
    s->printInfo();
}

int main(int argc, char **argv)
{
    int i = 0;
    for (i = 0; i < 2; i++) {
        test_func();
    }
    
	return 0;
}
	
