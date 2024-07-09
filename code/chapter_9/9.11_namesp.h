//头文件
#include <string>

// 创建pers和debt的命名空间

namespace pers
{
    struct Person
    {
        std::string fname;
        std::string lname;
    };

    void getPerson (Person &);
    void showPerson(const Person &);
    
}

namespace debts
{
    // 这里涉及到名称空间的嵌套
    using namespace pers;
    struct Debt
    {
        // 这里可以直接使用pers名称空间的Person结构体
        Person name;
        double amount;
    };

    void getDebt(Debt &);
    void showDebt(const Debt &);
    double sumDebets(const Debt ar[],int n);
}