#include <stdio.h>
#include "dog.h"

namespace D {
void Dog::setName(char * name)
{
	this->name = name;
}

int Dog::setAge(int age)
{
	if (age < 0 || age > 20)
	{
		this->age = 0;
		return -1;
	}

	this->age = age;
	return 0;
}

void Dog::printInfo(void)
{
	printf("dog's name is %s, %d\n", this->name, this->age);
}

void printVersion(void)
{
	printf("Dog v1 by zhuweijun\n");
}
}
