//#include "Englishman.h"
//#include "Chinese.h"
#include "Human.h"

void test_eating(Human *h)
{
    h->eating();
}

int main(int argc, char **argv)
{
    //Englishman e("Bill", 10, "aaaaaaaaaaaaaaaaaaa");
    //Chinese c;
    
    Human& e = CreateEnglishman("Bill", 10, "aaaaaaasdssdasd");
    Human& c = CreateChinese("zhangsan", 11, "beijing");
    

    Human* h[2] = {&e, &c};
    int i;

    for (int i = 0; i < 2; i++) {
        test_eating(h[i]);
    }

    delete &e;
    delete &c;
    
    return 0;
}
