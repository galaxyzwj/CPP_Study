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
    int address;
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

class Son_pub : public Father {
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
        //room_key = 1;
        
    }
};
class Son_pro : protected Father {
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
        //room_key = 1;
        
    }
};
class Son_pri : private Father {
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
        //room_key = 1;
        
    }
};

int main(int argc, char **argv)
{
    Son_pub s_pub;
    Son_pro s_pro;
    Son_pri s_pri;
    
    s_pub.play_game();
    s_pro.play_game();
    s_pri.play_game();

    s_pub.it_skill();
/*    s_pro.it_skill(); // s_pro的it_skill接口为 protected， main函数无法调用到
    s_pri.it_skill();   // 同上
 */
    
   return 0;
}

