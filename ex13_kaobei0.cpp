#include<iostream>
using namespace std;

class numbered
{
    private:
        static int seq;
    public:
        numbered()
        {
            cout<<"调用了默认构造函数"<<endl;
            mysn=seq++;
        }
        //f(numbered s);
        int mysn;
};


int numbered::seq = 0;

void f(numbered s)
{
    cout<<s.mysn<<endl;
}


int main()
{
    numbered a,b=a,c=b;
    f(a);//这里调用了构造函数
    f(b);
    f(c);
    return 0;
}