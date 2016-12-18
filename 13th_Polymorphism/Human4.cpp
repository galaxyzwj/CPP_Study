#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Human {
private:
    int a;
public:
    Human() { cout << "Human()"  << endl;}
    virtual void eating(void) { cout << "use hand to eat" << endl; }
    virtual ~Human() { cout << "~Human()"  << endl;}
};

class Englishman : public Human {
public:
    Englishman() { cout << "Englishman()"  << endl;}    
    void eating(void) { cout << "use knife to eat" << endl; }
    ~Englishman() { cout << "~Englishman()"  << endl;}
};

class Chinese : public Human {
public:
    Chinese() { cout << "Chinese()"  << endl;}        
    void eating(void) { cout << "use chopsticks to eat" << endl; }
    ~Chinese() { cout << "~Chinese()"  << endl;}
};

void test_eating(Human& h)
{
    h.eating();
}


int  main(int argc, char **argv)
{
    Human* h = new Human();
    Englishman* e = new Englishman();
    Chinese* c = new Chinese();

    Human *p[3] = {h, e, c};
    int i;

    for (i = 0; i < 3; i++) {
        p[i]->eating();
        delete p[i];
    }


    return 0;
}
