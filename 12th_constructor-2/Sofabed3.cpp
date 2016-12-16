#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Furniture {
private:
     int weight;
public:
    void watchTV(void) { cout<<"watch tv"<<endl; }
    void setWeight(int weight) { this->weight = weight; }
    int getWeight(void) const { return weight; }
    Furniture() { cout<<"Furniture()"<<endl; }        
};

class Vertification3C {
public:
    Vertification3C() { cout<<"Vertification3C()"<<endl; }
};


class Sofa : virtual public Furniture, virtual public Vertification3C {
private:
    int a;
public:
    void watchTV(void) { cout<<"watch tv"<<endl; }
    Sofa() { cout<<"Sofa()"<<endl; }    
};

class Bed : virtual public Furniture, virtual public Vertification3C {
private:
    int b;
public:
    void sleep(void) { cout<<"sleep"<<endl; }  
    Bed() { cout<<"Bed()"<<endl; }
};


class Sofabed : public Sofa, public Bed {
private:
    int c;
public:
    Sofabed() { cout<<"Sofabed()"<<endl; }
    Sofabed(char *abc) { cout<<"Sofabed(char *abc)"<<endl; }
};

class LeftRightCom {
public:
    LeftRightCom() { cout<<"LeftRightCom()"<<endl; }
    LeftRightCom(char *abc) { cout<<"LeftRightCom(char *abc)"<<endl; }
};
class Date {
public:
    Date() { cout<<"Date()"<<endl; }
    Date(char *abc) { cout<<"Date(char *abc)"<<endl; }
};
class Type {
public:
    Type() { cout<<"Type()"<<endl; }
    Type(char *abc) { cout<<"Type(char *abc)"<<endl; }  
};

class LeftRightSofabed : public Sofabed, virtual public LeftRightCom {
private:
    Date date;
    Type type;
public:
    LeftRightSofabed() { cout<<"LeftRightSofabed()"<<endl; }
    LeftRightSofabed(char *str1, char *str2, char *str3) : Sofabed(str1), LeftRightCom(str2), date(str3) { cout<<"LeftRightSofabed()"<<endl; }
};
    
int  main(int argc, char **argv)
{
    LeftRightSofabed s("abc", "1234", "galaxy");
    
    return 0;
}



