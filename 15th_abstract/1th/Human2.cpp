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
    virtual void eating(void) = 0;
    virtual void wearing(void) = 0;
    virtual void driving(void) = 0;
    virtual ~Human() { cout << "~Human()"  << endl;}
    virtual Human* test(void) { cout << "Human's test" << endl; return this; }
    
};

class Englishman : public Human {
public:
    Englishman() { cout << "Englishman()"  << endl;}    
    void eating(void) { cout << "use knife to eat" << endl; }
    void wearing(void) { cout << "wear english style" << endl; }
    void driving(void) { cout << "drive english car" << endl; }
    ~Englishman() { cout << "~Englishman()"  << endl;}
    virtual Englishman* test(void) { cout << "Englishman's test" << endl; return this; }
};

class Chinese : public Human {
public:
    Chinese() { cout << "Chinese()"  << endl;}        
    void eating(void) { cout << "use chopsticks to eat" << endl; }
    void wearing(void) { cout << "wear chinese style" << endl; }
    //void driving(void) { cout << "drive chinese car" << endl; }
    ~Chinese() { cout << "~Chinese()"  << endl;}
    virtual Chinese* test(void) { cout << "Chinese's test" << endl; return this; }
};

class Anhuiman : public Chinese {
public:
    void driving(void) { cout << "drive Anhui car" << endl; }    
};

int  main(int argc, char **argv)
{
    //Human h;
    Englishman e;
    //Chinese c;
    Anhuiman a;
    
    return 0;
}
