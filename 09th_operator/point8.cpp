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
    friend ostream& operator<<(ostream &o, Point p);

    /* p.operator+(); p++ */
    Point operator+(Point &p)
    {
        cout << "Point operator+(Point &p)" << endl;
        Point n;
        n.x = this->x + p.x;
        n.y = this->y + p.y;
        return n;
    }

    /* Point p(1, 2); ++p */
    Point& operator++(void)
    {
        cout << "Point& operator++(void)" << endl;
        this->x += 1;
        this->y += 1;
        return *this;
    }

    /* Point p(1, 2); p++ */
    Point operator++(int a)
    {
        cout << "Point operator++(int a)" << endl;
        Point n;
        n = *this;
        this->x += 1;
        this->y += 1;
        return n;    
    }
};

Point add(Point &p1, Point &p2)
{
    Point n;
    n.x = p1.x + p2.x;
    n.y = p1.y + p2.y;
    return n;
}

/* p.operator<< [error method] */
ostream& operator<<(ostream &o, Point p)
{
    cout << "("<<p.x<<", "<< p.y << ")";
    return o;
}

int main(int argc, char **argv)
{
    Point p1(1, 2);
    Point p2(2, 3);
    Point m, n;

    m = p1 + p2; /* equal=> m = p1.operator+(p2) */
    cout << "add p1,p2 = " << m << endl;

    cout << "begin" << endl;

    m = ++p1; /* m = p1.operator++() */
    cout << "m = "<< m << " p1 = "<< p1 << endl;
    
    cout << "****************" << endl;

    n = p1++; /* n = p1.operator++(0) */
    cout << "n = "<< n << " p1 = "<< p1 << endl;

    cout << "end" << endl;

    cout << m << " " << n << endl;

        
    return 0;
}





