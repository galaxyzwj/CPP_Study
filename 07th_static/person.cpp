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
	char *work;

public:
	Person()
	{
		cout << "Person()" << endl;
		this->work = NULL;
		this->name = NULL;
        cnt++;
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
        cnt++;
	}

	Person(char *name, int age, char *work = "none") 
	{
		cout << "Person(name,age,work)"<<"name="<<name<<", age="<<age<<", work"<<work << endl;
		this->age = age;
		
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);

		this->work = new char[strlen(work) + 1];
		strcpy(this->work, work);
        cnt++;
	}

	Person(Person &per) 
	{
		cout << "Person(Person &per)" << endl;
		this->age = per.age;
		
		this->name = new char[strlen(per.name) + 1];
		strcpy(this->name, per.name);

		this->work = new char[strlen(per.work) + 1];
		strcpy(this->work, per.work);
        cnt++;
	}

	void printInfo(void)
	{
		cout <<"name = " << name << ", age = " << age << ", work = " << work << endl;	
	}

    static int getCount(void)
    {
        return cnt;
    }

};

class Student
{
private:
    Person father;
    Person mother;
    int student_id;

public:
    Student()
    {
        cout<< "Student()" << endl;
    }

    Student(int id, char *father, char *mother, int fat_age = 40, int mot_age = 39):father(father, fat_age),mother(mother, mot_age)
    {
        cout<<"id="<<id<<" ,father="<<father<<" ,mother="<<mother<<" ,fat_age="<<fat_age<<" ,mot_age="<<mot_age<<endl;    
    }

    ~Student()
    {}

};


int Person::cnt = 0;

int main(int argc, char **argv)
{
    Person per1;
    Person per2;
    Person per3;
    Person per4;

    Person *per5 = new Person[10];

    cout<<"person number: "<<Person::getCount()<<endl;;
    

	return 0;
}
	
