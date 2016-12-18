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

class Anhuiman : public Chinese {
public:
    void eating(void) { cout << "use chopsticks to eat, but i come from anhui" << endl; }
};

void test_eating(Human& h)
{
#if 1
    //Englishman& pe = dynamic_cast<Englishman&>(h);
    Chinese&    pc = dynamic_cast<Chinese&>(h);
    Anhuiman&   pa = dynamic_cast<Anhuiman&>(h);
#else
    Englishman& pe = reinterpret_cast<Englishman&>(h);
    Chinese& pe = reinterpret_cast<Chinese&>(h);
    Anhuiman& pe = reinterpret_cast<Anhuiman&>(h);
#endif
    h.eating();

    
}

int  main(int argc, char **argv)
{
    //Human h;
    //Englishman e;
    //Chinese c;
    Anhuiman a;

    //test_eating(h);
    //test_eating(e);
    //test_eating(c);
    test_eating(a);
    
    return 0;
}
