#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>
class Stock
{
    private:
        std::string company; // 公司名称
        long shares; // 持有的股票数量
        double share_val; // 每股的价格
        double total_val; // 总价值
        void set_tot() {total_val=shares*share_val;} // 成员函数可以就地定义
    
    public:
       void acquire(const std::string &co,long n,double pr);
       void buy(long num,double price); // 也可以用原型表示
       void sell(long num,double price);
       void update(double price);
       void show();
};

#endif