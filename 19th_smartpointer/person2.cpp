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

void test_func(void)
{
    //Person *p = new Person();
    //p->printInfo();
    Person per;
    per.printInfo();
}

int main(int argc, char **argv)
{
    int i = 0;
    for (i = 0; i < 2; i++) {
        test_func();
    }
    
	return 0;
}
	
