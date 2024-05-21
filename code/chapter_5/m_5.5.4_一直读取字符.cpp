#include <iostream>
using namespace std;
int main()
{
    char ch;

    while (cin.get(ch))
    {
        // cin.get(ch)的返回值是cin
        // 当读取失败的时候：包括但不限于读到EOF（还可能是磁盘故障等） cin的值为false
        cout<<ch<<endl;
    }
    
}