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

public:

    int address;
    
	Person()
	{
		cout << "Person()" << endl;
		this->name = NULL;
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
	}

	Person(char *name, int age) 
	{
		cout << "Person(name,age)"<<"name="<<name<<", age="<<age<< endl;
		this->age = age;
		
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
        
	}

	Person(Person &per) 
	{
		cout << "Person(Person &per)" << endl;
		this->age = per.age;
		
		this->name = new char[strlen(per.name) + 1];
		strcpy(this->name, per.name);

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

};

class Student : public Person
{
private:
    int grade;

public:
    void setGrade(int grade) {this->grade = grade;}
    void getGrade(void) {return grade;}
	void printInfo(void)
	{
		cout<< "Student ";
        Person::printInfo();
	}
};

void test_func(Person &p)
{
    p.printInfo();
}


int main(int argc, char **argv)
{
    Person p("lisi", 16);
    
    Student s;
    s.setName("zhangsan");
    s.setAge(16);
    s.printInfo();

    test_func(p);
    test_func(s);

	return 0;
}
	
