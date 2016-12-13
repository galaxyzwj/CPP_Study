#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Father {
private:
    int money;
protected:
    int room_key;
    
public:
    void it_skill(void)
    {
        cout << "father's is skill" << endl;
    }

    int getMoney(void)
    {
        return money;
    }

    void setMoney(int money)
    {
        this->money = money;
    }
};

class Son : public Father {
private:
    int toy;
public:
    void play_game(void)
    {
        int m;
        cout << "son play game" << endl;
        // money -= 1;
        m = getMoney();
        m--;
        setMoney(m);

        // Son 为 继承类能够访问父类被保护的成员
        room_key = 1;
        
    }
};

int main(int argc, char **argv)
{
    Son s;
    s.setMoney(10);
    cout<< s.getMoney() <<endl;
    s.it_skill();
    s.play_game();

    //s.room_key = 1; // main这个被保护的成员
    return 0;
}

