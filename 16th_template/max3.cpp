#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;


template<typename T>
const T& myMax(const T& a, const T&b)
{
    //cout<<"myMax(T&, T&)"<<endl;
    cout << __PRETTY_FUNCTION__ <<endl;
    return (a < b)? b : a;
}

int main(int argc, char **argv)
{
    int ia = 1;
    int ib = 2;
 
    myMax(ia, ib);
    
    return 0;
    
}


