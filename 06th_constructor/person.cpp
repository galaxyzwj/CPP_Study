#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Person
{

private:
	char *name;
	int age;
	char *work;

public:
	Person()
	{
		cout << "Person()" << endl;
	}

	Person(char *name)
	{
		cout << "Person(char *name)" << endl;
	}
	Person(char *name, int age, char *work = "none") 
	{
		cout << "Person(char *name, int age)" << endl;
		this->name = name;
		this->age = age;
		this->work = work;
	}
	void setName(char *name)
	{
		this->name = name;
	}

	void printInfo(void)
	{
		cout <<"name = " << name << ", age = " << age << ", work = " << work << endl;	
	}
};

int main(int argc, char **argv)
{
	Person per("zhangsan", 16);
	Person per2;

	Person per3; /* int fun() */
	
	per.printInfo();
	
	return 0;

}



