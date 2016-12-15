#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Sofa {
private:
     int weight;
public:
    void watchTV(void) { cout<<"watch tv"<<endl; }
    void setWeight(int weight) { this->weight = weight; }
    void getWeight(void) const { return weight; }
};
class Bed {
private:
    int weight;
public:
    void sleep(void) { cout<<"sleep"<<endl; }
    void setWeight(int weight) { this->weight = weight; }
    void getWeight(void) const { return weight; }
    
};
class Sofabed : public Sofa, public Bed {
    
};
int  main(int argc, char **argv)
{
    Sofabed s;
    s.watchTV();
    s.sleep();

    //s.setWeight(100); /* error,有二义性 */
    s.Sofa::setWeight(100);
    
    return 0;
}



