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

    sp(const sp &other)
    {
        cout<<"sp(const Person *other)"<<endl;
        p = other.p;
    }        

    sp(Person *other)
    {
        cout<<"sp(Person *other)"<<endl;
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

void test_func(sp &other)
{
    //Person *p = new Person();
    //p->printInfo();   /* ��Ҫ�ֹ� delete p; */
    //Person per;       /* �ֲ����� */
    //per.printInfo();
    sp s = other;
    s->printInfo();
}

int main(int argc, char **argv)
{
    int i = 0;

    /* �൱��:
     * 1. Person *p = new Person();  
     * 2. sp tmp(p); ==> ���� sp(Person *other)
     * 3.
     * 3.1 sp other(tmp); ==> ���� sp(sp &other2)
     *      ��������: sp &other2 = tmp; //�����﷨
     *                const sp &other2 = tmp; // ok    
     * ����:
     * 3.2 sp other(tmp ==> Person*); ==> ���� sp(Person *other)
     */
    
    sp other = new Person();
    
    for (i = 0; i < 2; i++) {
        test_func(other);
    }
    
	return 0;
}
	
