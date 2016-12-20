#ifndef __HUMAN_H_
#define __HUMAN_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Human{
private:
    char *name;

public:
    void setName(char *name);
    char *getName(void);
      
};

#endif

