#include <stdio.h>
#include "person.h"
#include "dog.h"

/* global namespace */

/* 把 P::Person放入 global namespace，以后可以使用 Person来表示P::Person */
using P::Person;
/* 把 D::Dog放入 global namespace，以后可以使用 Dog来表示D::Dog */
using D::Dog;

int main(int argc, char **argv)
{
	/* local namespace */

	Person per; // P::Person per;
	per.setName("zhangsan");
	per.setAge(55);
	per.setWork("shabi");
	per.printInfo();
 
	Dog dog; // D::Dog dog
	dog.setName("wangcai");
	dog.setAge(5);
	dog.printInfo();
	
	D::printVersion();
	P::printVersion();

	
	return 0;

}



