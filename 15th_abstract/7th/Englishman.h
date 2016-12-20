#ifndef __ENGLISHMAN_H_
#define __ENGLISHMAN_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

#include "Human.h"

using namespace std;

class Englishman : public Human {
private:
    char address[1000];
    int age;
public:
    Englishman();
    Englishman(char *name, int age, char *address);
    void eating(void);
    void wearing(void);
    void driving(void);
    ~Englishman();
    
};

#endif
