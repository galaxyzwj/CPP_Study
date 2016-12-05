#include <stdio.h>
#include <stdlib.h>

struct person
{
	char *name;
	int age;
	char *work;

	void (*printInfo)(struct person *per);
};

void  printInfo(struct person *per)
{
	printf("name = %s, age = %d, work = %s\n", per->name, per->age, per->work);
}

int main(int argc, char **argv)
{
	struct person Person[] = {
			{"zhuweijun", 23, "hehe", printInfo},
			{"wangzhongfeng", 24, "xixi", printInfo},
	};

	Person[0].printInfo(&Person[0]);
	Person[1].printInfo(&Person[1]);

	return 0;
}



