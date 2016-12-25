#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Person
{
private:
    int count;
    
public:
	Person()
	{
		cout << "Person()" << endl;
    }
	
	~Person()
	{
		cout << "~Person()" << endl;
	}

    void incStrong() {
        count++;
    }

    void decStrong() {
        count--;
    }

    int getStrongCount() {
        return count;
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
        p->incStrong();
    }        

    sp(Person *other)
    {
        cout<<"sp(Person *other)"<<endl;
        p = other;
        p->incStrong();
    }

    ~sp()
    {
        cout<<"~sp()"<<endl;
        if (p) { 
            p->decStrong();
            if (p->getStrongCount() == 0) {
                delete p; 
                p = NULL;
            }
        }
    }

    Person *operator->()
    {
        return p;
    }

    Person& operator*()
    {
        return *p;
    }
};

void test_func(sp &other)
{
    //Person *p = new Person();
    //p->printInfo();   /* ��Ҫ�ֹ� delete p; */
    //Person per;       /* �ֲ����� */
    //per.printInfo();

    sp s = other;
    cout<<"In test_func: "<<s->getStrongCount()<<endl;


    s->printInfo();
}

int main(int argc, char **argv)
{
    int i = 0;

    /* ����"Person *", �� "sp"������"Person *"
     * Person *per;
     * ��2�в���:per->XXX, (*per).XXX
     * spҲӦ������2�в���:
     *                  sp->xxx, (*sp).xxx
     */
    sp other = new Person();

    cout<<"Before call test_func: "<<other->getStrongCount()<<endl;
    (*other).printInfo(); /* 82line override */
    
    for (i = 0; i < 2; i++) {
        test_func(other);
        cout<<"After call test_func: "<<other->getStrongCount()<<endl;        
    }
    
	return 0;
}
	
