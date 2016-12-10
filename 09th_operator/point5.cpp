#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point() {
        cout << "Point()" << endl;
    }
    Point(int x, int y):x(x),y(y) {
        cout << "Point(int x, int y)" << endl;
    }
    Point(const Point& p) {
        cout << "Point(const Point& p)" << endl;
        x = p.x;
        y = p.y;
    }
    ~Point() {
        cout << "~Point()" << endl;
    }

    
    int getX(void) { return x; }
    int getY(void) { return y; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }    

    void printInfo()
    {
        cout<<"("<<x<<", "<<y<<")"<<endl;
    }

    friend Point add(Point &p1, Point &p2);
    friend Point operator+(Point &p1, Point &p2);
    friend Point& operator++(Point &p1);
    friend Point operator++(Point &p1, int a);
};

Point add(Point &p1, Point &p2)
{
    Point n;
    n.x = p1.x + p2.x;
    n.y = p1.y + p2.y;
    return n;
}

Point operator+(Point &p1, Point &p2)
{
    cout << "Point operator+(Point &p1, Point &p2)" << endl;
    Point n;
    n.x = p1.x + p2.x;
    n.y = p1.y + p2.y;
    return n;
}

/* Point p(1, 2); ++p */
Point& operator++(Point &p1)
{
    cout << "++p" << endl;
    p1.x += 1;
    p1.y += 1;
    cout << ">>.<<" << endl;
    return p1;
}

/* Point p(1, 2); p++ */
Point operator++(Point &p1, int a)
{
    cout << "p++" << endl;
    Point n;
    n = p1;
    p1.x += 1;
    p1.y += 1;
    return n;    
}

int main(int argc, char **argv)
{
    Point p1(1, 2);
    Point m, n;

    cout << "begin" << endl;
    //m = ++p1;
    ++p1;
    m = p1; 

    cout << "****************" << endl;

    n = p1++;
    cout << "end" << endl;
        
    return 0;
}





