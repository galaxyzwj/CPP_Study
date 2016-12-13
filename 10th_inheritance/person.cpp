#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Person
{

private:
    static int cnt;
	char *name;
	int age;

public:
	Person()
	{
		cout << "Person()" << endl;
		this->name = NULL;
        cnt++;
    }
    
	~Person()
	{
		cout << "~Person()" << endl;
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
        cnt++;
	}

	Person(char *name, int age) 
	{
		cout << "Person(name,age)"<<"name="<<name<<", age="<<age<< endl;
		this->age = age;
		
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
        
        cnt++;
	}

	Person(Person &per) 
	{
		cout << "Person(Person &per)" << endl;
		this->age = per.age;
		
		this->name = new char[strlen(per.name) + 1];
		strcpy(this->name, per.name);

        cnt++;
	}

	void printInfo(void)
	{
		cout <<"name = " << name << ", age = " << age << endl;	
	}
    void setName(char* name)
    {
        if (this->name)
        {
            delete this->name;
        }
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void setAge(int age)
    {
        this->age = age;
    }

    static int getCount(void)
    {
        return cnt;
    }

};

class Student : public Person
{

};


int Person::cnt = 0;

int main(int argc, char **argv)
{
    Student s;
    s.setName("zhangsan");
    s.setAge(16);
    s.printInfo();


	return 0;
}
	
