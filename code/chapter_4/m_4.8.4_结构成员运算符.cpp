#include <iostream>
using namespace std;

struct things
{
    /* data */
    int good;
    float price;
};

int main()
{
    //创建有名字的结构
    things a={100,125.0};

    //用new创建动态结构
    things *b=new things;
    b->good=50;
    b->price=200.0;

    cout<<a.good;
    cout<<b->price;
}
