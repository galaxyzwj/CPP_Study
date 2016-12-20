#include "Englishman.h"
#include "Chinese.h"

int main(int argc, char **argv)
{
    Englishman e;
    Chinese c;

    e.setName("Bill");
    c.setName("Zhangsan");

    cout<< "Englishman's Name: "<<e.getName() << endl;
    cout<< "Chinese's Name: "<<c.getName() << endl;

    return 0;
}
