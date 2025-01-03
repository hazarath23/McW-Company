#include<iostream>
using namespace std;
//Templates
template <class T>//Template declaration for the above class
class hello
{
    public:
    T ax;
    hello(T r)
    {
        ax=r;
    }
    T get()
    {
        return ax;
    }
};
int main()
{
    hello<int> *tc;
    tc = new hello(10);
    cout<<tc->get()<<"\n";
    return 0;
}