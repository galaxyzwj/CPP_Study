#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;


template<typename T>
T& myMax(T& a, T&b)
{
    //cout<<"myMax(T&, T&)"<<endl;
    cout << __PRETTY_FUNCTION__ <<endl;
    return (a < b)? b : a;
}

void add(int a, int b)
{
    cout<<"add(int a, int b)"<<endl;
}

int main(int argc, char **argv)
{
    const int ia = 1;
    const int ib = 2;
    
    myMax(ia, ib);

    int a = 1;
    double b = 2.1;

    add(a, b);

    myMax(a, b);
    
    return 0;
    
}


