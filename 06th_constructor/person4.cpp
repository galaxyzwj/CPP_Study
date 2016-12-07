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
		//cout << "Person()" << endl;
		this->work = NULL;
		this->name = NULL;
	}
	/*
	~Person()
	{
		if (this->work) {
			delete this->work;
		}
		if (this->name) {
			delete this->name;
		}
	}*/ // 去掉后存在内存泄漏

	Person(char *name)
	{
		//cout << "Person(char *name)" << endl;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->work = NULL;
	}

	Person(char *name, int age, char *work = "none") 
	{
		//cout << "Person(char *name, int age, char *work)" << endl;
		this->age = age;
		
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);

		this->work = new char[strlen(work) + 1];
		strcpy(this->work, work);
	}

	void setName(char *name)
	{
		this->name = name;
	}

	void printInfo(void)
	{
		//cout <<"name = " << name << ", age = " << age << ", work = " << work << endl;	
	}
};

void test_func()
{
	Person per("zhangsan", 16);
	Person per2; /* 调用无参构造函数*/

	Person per3(); /* int fun() */

	Person *per4 = new Person; /* 无参构造函数 */
	Person *per5 = new Person(); /* 无参构造函数 */

	Person *per6 = new Person[2];
	Person *per7 = new Person("lisi", 18, "student");
	Person *per8 = new Person("wangwu", 18);
	Person *per9 = new Person("mazi");

	per.printInfo();
	per7->printInfo();
	per8->printInfo();
	per9->printInfo();

	delete per4;
	delete per5;
	delete []per6;
	delete per7;
	delete per8;
	delete per9;

	//没有delete掉分配的work、name的内存，只是单纯的释放了对象的内存空间
	//return 0;

}

int main(int argc, char **argv)
{
	for (int i = 0; i < 100000; i++) {
		test_func(); //注释掉析构函数存在内存泄漏，free -m 查询内存大小。
	}
	cout << "run test_fun end" << endl;
	sleep(10);
	return 0;
}
	
