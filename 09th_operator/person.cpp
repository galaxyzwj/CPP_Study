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

	Person(const Person &per) 
	{
		cout << "Person(Person &per)" << endl;
		this->age = per.age;
		
		this->name = new char[strlen(per.name) + 1];
		strcpy(this->name, per.name);

		this->work = new char[strlen(per.work) + 1];
		strcpy(this->work, per.work);
        cnt++;
	}

	void printInfo(void) const
	{
		cout <<"name = " << name << ", age = " << age << ", work = " << work << endl;	
	}

    Person& operator=(const Person& p) // 返回引用效率高
    {
        if (this == &p)
            return *this;
        this->age = p.age;
		if (this->work) {
            delete this->work;
		}
		if (this->name) {
			delete this->name;
		}         
		this->name = new char[strlen(p.name) + 1];
		strcpy(this->name, p.name);

		this->work = new char[strlen(p.work) + 1];
		strcpy(this->work, p.work);
        
    }


    static int getCount(void);
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

int Person::getCount(void)
{
    return cnt;
}

int main(int argc, char **argv)
{
    const Person p1("zhangsan", 18);
    cout<<"Person p2 = p1"<<endl;

    Person p2 = p1; // 拷贝构造函数

    Person p3;
    cout<<"p3 = p1"<< endl;
    
    p3 = p1;        // 运算符重载操作
    cout<< "end" << endl;
    p1.printInfo();
    p2.printInfo();
    p3.printInfo();
    
	return 0;
}
	
