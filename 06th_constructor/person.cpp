#include <stdio.h>
#include <stdlib.h>

class Person
{

private:
	char *name;
	int age;
	char *work;

public:
	void setName(char *n)
	{
		name = n;
	}

	void printInfo(void)
	{
		printf("name = %s, age = %d, work = %s\n", name, age, work);	
	}
};

int main(int argc, char **argv)
{
	Person per;

	//per.name = "zhangsan";
	per.setName("zhangsan");


	per.printInfo();
	
	return 0;

}



