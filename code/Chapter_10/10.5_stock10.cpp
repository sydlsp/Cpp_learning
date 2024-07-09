#include <iostream>
#include "10.4_stock10.h"
using namespace std;
Stock::Stock() // 默认构造函数
{
    cout<<"Default constructor called\n";
    shares=0;
    share_val=0.0;
    total_val=0.0;
}

Stock::Stock(const string & co,long n,double pr) 
// 由于在类声明的时候已经说过默认参数的值了，这里就不能再指定了，否则会报重定义错误
{
    cout<<"Constructor using "<<co<<" called\n";
    company=co;
    if (n<0)
    {
        cout<<"Number of shares can't be negative; "
            <<company<<" shares set to 0.\n";
        shares=0;
    }

    else
        shares=n;
    
    share_val=pr;
    set_tot();
}

Stock::~Stock()
{
    std::cout<<"Bye, "<<company<<"!\n";
}

// 实现类中的其他方法
void Stock::buy(long num,double price)
{
    if (num<0)
    {
        std::cout<<"Number of shares purchased can't be negative. "
                 <<"Transaction is aborted.\n";
    }

    else
    {
        shares+=num;
        share_val=price;
        set_tot();
    }
}

void Stock::sell(long num,double price)
{
    using std::cout;
    if (num<0)
    {
        cout<<"Number of shares sold can't be negative. "
            <<"Transaction is aborted.\n";
    }

    else if (num>shares)
    {
        cout<<"You can't sell more than you have! "
            <<"Transaction is aborted.\n";
    }

    else
    {
        shares-=num;
        share_val=price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val=price;
    set_tot();
}

void Stock::show()
{
    using std::cout;
    using std::ios_base;
    // 设置格式为#.###
    ios_base::fmtflags orig=cout.setf(ios_base::fixed,ios_base::floatfield);
    std::streamsize prec=cout.precision(3);

    cout<<"Company: "<<company
        <<" Shares: "<<shares<<'\n'
        <<" Share Price: $"<<share_val;
    // 设置格式为#.##
    cout.precision(2);
    cout<<" Total Worth: $"<<total_val<<'\n';

    // 恢复原始格式
    cout.setf(orig,ios_base::floatfield);
    cout.precision(prec);
}