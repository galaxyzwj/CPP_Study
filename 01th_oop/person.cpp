#include <stdio.h>
#include <stdlib.h>

class person
{
public :
	char *name;
	int age;
	char *work;

	void printInfo(void)
	{
		printf("name = %s, age = %d, work = %s\n", name, age, work);	
	}
};

int main(int argc, char **argv)
{
	struct person Person[] = {
			{"zhuweijun", 23, "hehe"},
			{"wangzhongfeng", 24, "xixi"},
	};

	Person[0].printInfo();
	Person[1].printInfo();

	return 0;
}



