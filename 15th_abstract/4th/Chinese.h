#ifndef __CHINESE_H_
#define __CHINESE_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

#include "Human.h"

using namespace std;

class Chinese : public Human {
//private:
//    char *name;
public:
//    void setName(char *name);
//    char* getName(void);
    void eating(void);
    void wearing(void);
    void driving(void);
    ~Chinese();
};

#endif
