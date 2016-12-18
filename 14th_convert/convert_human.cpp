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
    virtual Human* test(void) { cout << "Human's test" << endl; return this; }
    
};

class Englishman : public Human {
public:
    Englishman() { cout << "Englishman()"  << endl;}    
    void eating(void) { cout << "use knife to eat" << endl; }
    ~Englishman() { cout << "~Englishman()"  << endl;}
    virtual Englishman* test(void) { cout << "Englishman's test" << endl; return this; }
};

class Chinese : public Human {
public:
    Chinese() { cout << "Chinese()"  << endl;}        
    void eating(void) { cout << "use chopsticks to eat" << endl; }
    ~Chinese() { cout << "~Chinese()"  << endl;}
    virtual Chinese* test(void) { cout << "Chinese's test" << endl; return this; }
};

void test_eating(Human& h)
{
    Englishman *pe;
    Chinese    *pc;

    h.eating();

    if (pe =  dynamic_cast<Englishman *>(&h)) {
        cout << "This is a Englishman" << endl;
    }

    if (pc =  dynamic_cast<Chinese *>(&h)) {
        cout << "This is a Anhuiman" << endl;
    }
}

int  main(int argc, char **argv)
{
    Human h;
    Englishman e;
    Chinese c;

    test_eating(h);
    test_eating(e);
    test_eating(c);
    
    return 0;
}
