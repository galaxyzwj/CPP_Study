#include <iostream>

#include "person.h"

namespace P {

using namespace std;

void Person::setName(char * name)
{
	this->name = name; 
}

int Person::setAge(int age)
{
	if (age > 150 || age < 0)
	{
		this->age = 0;
		return -1;
	}

	this->age = age;
	return 0;
}
void Person::setWork(char *work)
{
	this->work = work;
}
void Person::printInfo(void)
{
	cout<<"name = "<<this->name<<" age = "<<this->age<<" work = "<<this->work<<endl;
}



void printVersion(void)
{
	cout<<"Persion v1 by zhuweijun"<<endl;
}
}
