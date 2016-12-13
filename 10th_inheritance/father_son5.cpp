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

        // Son Ϊ �̳����ܹ����ʸ��౻�����ĳ�Ա
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

        // Son Ϊ �̳����ܹ����ʸ��౻�����ĳ�Ա
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

        // Son Ϊ �̳����ܹ����ʸ��౻�����ĳ�Ա
        //room_key = 1;
        
    }
};

class Grandson_pub : public Son_pub {
public:
    void test(void)
    {
        room_key = 1; /* room_key is protected */
        address = 2; /* address is public */
    }
};

class Grandson_pro : public Son_pro {
public:
    void test(void)
    {
        room_key = 1; /* room_key is protected */
        address = 2; /* address is protected */
    }
};

class Grandson_pri : public Son_pri {
public:
    void test(void)
    {
        //room_key = 1;
        //address = 2;
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
/*    s_pro.it_skill(); // s_pro��it_skill�ӿ�Ϊ protected�� main�����޷����õ�
    s_pri.it_skill();   // ͬ��
 */
    Grandson_pub gs_pub; 
    Grandson_pro gs_pro;
    
    gs_pub.address = 2;
    //gs_pro.address = 2;

   return 0;
}

