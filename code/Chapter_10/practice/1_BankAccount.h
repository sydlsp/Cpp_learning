// 习题10.1  定义一个类来表示银行账户
#include <string>
class BankAccount
{
    private:
       std::string name;
       int id;
       double total_money;
    
    public:
      //默认构造函数
      BankAccount();
      //构造函数
      BankAccount(std::string name_in,int id_in,double money_in);
      void account_in(double add_money_in);
      void account_out(double money_out);
      void show_info() const; // 展示的时候要保证类中的数据成员不变


};