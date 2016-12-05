#include <stdio.h>

namespace P {
class Person
{

private:
	char *name;
	int age;
	char *work;

public:
	void setName(char *n);
	int setAge(int age);
	void setWork(char *m);
	void printInfo(void);

	
};

void printVersion(void);
}
