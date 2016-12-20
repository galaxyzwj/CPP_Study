#include "Englishman.h"


Englishman::Englishman(char * name, int age, char * address)
{
    setName(name);
    this->age = age;
    memset(this->address, 0, 1000);
    strcpy(this->address, address);
}

Englishman::Englishman()
{

}

void Englishman::eating(void) 
{ 
    cout << "use knife to eat" << endl; 
}

void Englishman::wearing(void)
{ 
    cout << "wear english style" << endl;
}

void Englishman::driving(void)
{ 
    cout << "drive english car" << endl;
}

Englishman::~Englishman() 
{
    cout << "~Englishman()"  << endl;
}

