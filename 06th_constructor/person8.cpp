#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

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
		this->work = NULL;
		this->name = NULL;
	}
	
	~Person()
	{
		cout << "~Person()" << endl;
		if (this->work) {
			cout << "work = " << this->work << endl;
			delete this->work;
		}
		if (this->name) {
			cout << "name = " << this->name << endl;
			delete this->name;
		}
	}

	Person(char *name)
	{
		cout << "Person(char *name)" << endl;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->work = NULL;
	}

	Person(char *name, int age, char *work = "none") 
	{
		cout << "Person(name,age,work)"<<"name="<<name<<", age="<<age<<", work"<<work << endl;
		this->age = age;
		
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);

		this->work = new char[strlen(work) + 1];
		strcpy(this->work, work);
	}

	Person(Person &per) 
	{
		cout << "Person(Person &per)" << endl;
		this->age = per.age;
		
		this->name = new char[strlen(per.name) + 1];
		strcpy(this->name, per.name);

		this->work = new char[strlen(per.work) + 1];
		strcpy(this->work, per.work);
	}

	void printInfo(void)
	{
		cout <<"name = " << name << ", age = " << age << ", work = " << work << endl;	
	}
};

Person per_g("per_g", 10); // 全局最开始

void func()
{
    Person per_func("per_func", 11);
    static Person per_func_s("per_func_s", 11);
}


int main(int argc, char **argv)
{
    Person per_main("per_main", 11);
    static Person per_main_s("per_main_s", 11);

    for(int i = 0; i < 2; i++) {
        func();
        Person per_for("per_for", i);
    }
    
	return 0;
}
	
