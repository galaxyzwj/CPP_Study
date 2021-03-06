#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;


template<typename T>
const T& myMax(const T& a, const T& b)
{
    //cout<<"myMax(T&, T&)"<<endl;
    cout << "1: "<<__PRETTY_FUNCTION__ <<endl;
    return (a < b)? b : a;
}

template<typename T>
const T& myMax(T& a, T& b)
{
    //cout<<"myMax(T&, T&)"<<endl;
    cout << "2: "<<__PRETTY_FUNCTION__ <<endl;
    return (a < b)? b : a;
}

const int& myMax(int& a, int& b)
{
    //cout<<"myMax(T&, T&)"<<endl;
    cout << "3: "<<__PRETTY_FUNCTION__ <<endl;
    return (a < b)? b : a;
}

template<typename T>
const T myMax(const T* a, const T* b)
{
    //cout<<"myMax(T&, T&)"<<endl;
    cout << "4: "<<__PRETTY_FUNCTION__ <<endl;
    return (*a < *b)? *b : *a;
}

int main(int argc, char **argv)
{
    int ia = 1;
    int ib = 2;
        
    cout << myMax(ia, ib) << endl;
    
    int *p1 = &ia;
    int *p2 = &ib;

    cout << myMax(p1, p2) << endl;
    
    return 0;
    
}


