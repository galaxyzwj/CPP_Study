#include <stdio.h>
#include "person.h"
#include "dog.h"

/* global namespace */

/* �� P::Person���� global namespace���Ժ����ʹ�� Person����ʾP::Person */
using P::Person;
/* �� D::Dog���� global namespace���Ժ����ʹ�� Dog����ʾD::Dog */
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



