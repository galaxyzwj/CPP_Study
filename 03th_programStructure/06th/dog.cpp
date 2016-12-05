#include <iostream>
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
	std::cout<<"dog's name is "<<this->name<<" age = "<<this->age<<std::endl;
}

void printVersion(void)
{
	std::cout<<"Dog v1 by zhuweijun"<<std::endl;
}
}
