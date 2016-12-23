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
    cout << __PRETTY_FUNCTION__ <<endl;
    return (a < b)? b : a;
}

template<typename T>
const T* myMax2(const T* a, const T* b)
{
    //cout<<"myMax(T&, T&)"<<endl;
    cout << __PRETTY_FUNCTION__ <<endl;
    return (a < b)? b : a;
}


int main(int argc, char **argv)
{
    char a[] = "ab";
    char b[] = "cd";
    myMax(a, b); // T = char[3]
    myMax2(a, b);

    char a2[] = "abc";
    char b2[] = "cd";
    //myMax(a2, b2); //myMax(char[4], char[3]),无法推导出T: myMax(char& [4], char& [3])
    myMax2(a2, b2);  //myMax2(char[4], char[3]),推导出T: myMax2(const char*, const char*)  
    
    return 0;
    
}


