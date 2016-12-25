#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

int a = 1;
double b =1.2;
float c = 1.3;

class MyException {
public:
    void what(void) { cout << "This is MyException" << endl;}
};



void C(int i)
{

    if (i == 0) {
        cout << "In C, it is OK" << endl;
    } else if (i == 1) {
        throw a;
    } else if (i == 2) {
        throw b;
    } else if (i == 3) {
        throw c;
    } else if (i == 4) {
        throw MyException();
    } else {
        throw 'a';
    }
}

void B(int i)
{
    cout<< "Before call C..."<<endl;
    C(i);
    cout<< "After call C..."<<endl;
}

void A(int i)
{
    try {
        B(i);
    } catch (int j) {
        cout<< "catch int exception int:"<< j <<endl; 
    } catch (double k) {
        cout<< "catch double exception double:"<< k <<endl; 
    } catch (MyException &e) {
        e.what();
    } catch (...) {
        cout<< "catch other exception float:"<< c <<endl; 
    } 

}


int main(int argc, char **argv)
{
    int i;
    if (argc != 2) {
        cout << "Usage: " << endl;
        cout << argv[0] << "<0|1|2|>" << endl;
        return -1;
    }
    i = strtoul(argv[1], NULL, 0);
    A(i);
    
    return 0;
}

