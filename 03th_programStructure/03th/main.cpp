#include <stdio.h>
#include "person.h"
#include "dog.h"

int main(int argc, char **argv)
{
	P::Person per;
	per.setName("zhangsan");
	per.setAge(55);
	per.setWork("shabi");
	per.printInfo();

	D::Dog dog;
	dog.setName("wangcai");
	dog.setAge(5);
	dog.printInfo();
	
	D::printVersion();
	P::printVersion();

	
	return 0;

}



