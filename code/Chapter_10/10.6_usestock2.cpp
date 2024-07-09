#include <iostream>
#include "10.4_stock10.h"

int main()
{
    using std::cout;
    cout<<"使用构造函数创建新的实例"<<endl;
    Stock stock1("NanoSmart",12,20.0); // 隐式调用构造函数
    stock1.show();

    Stock stock2=Stock("Boffo Objects",2,2.0); // 显式调用构造函数
    stock2.show();

    //把stock1赋值给stock2
    stock2=stock1;
    cout<<"展示stock1和stock2"<<endl;
    stock1.show();
    stock2.show();

    // 使用构造函数来重新给stock1实例化
    stock1=Stock("Nifty Foods",10,50.0);
    cout<<"新的stock1"<<endl;
    stock1.show();
    return 0;
}