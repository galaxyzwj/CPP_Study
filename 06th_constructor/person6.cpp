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
		cout << "Person(char *name, int age, char *work)" << endl;
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
		cout <<"name = " << name << ", age = " << age << ", work = " << work << endl;	
	}
};

void test_func()
{
	Person per("zhangsan", 16); // 出栈后自动被释放

	Person *per7 = new Person("lisi", 18, "student");

	//delete per7; /* 注释掉后new出来的空间虽然被释放，但析构函数中不会执行，无法释放*/

}

int main(int argc, char **argv)
{
	Person per("wanger", 13); // 程序结束后释放
	test_func();
	cout << "run test_fun end" << endl;
	sleep(10);
	return 0;
}
	
