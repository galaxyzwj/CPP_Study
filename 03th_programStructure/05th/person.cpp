#include <stdio.h>

#include "person.h"

namespace P {

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
	printf("name = %s, age = %d, work = %s\n", this->name, this->age, this->work);
}



void printVersion(void)
{
	printf("Persion v1 by zhuweijun\n");
}
}
