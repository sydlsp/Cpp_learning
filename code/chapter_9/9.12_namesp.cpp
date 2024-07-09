#include <iostream>
#include "9.11_namesp.h" //注意，这里再复习一下，用双引号的时候，是在当前目录下找头文件

namespace pers
{
    using std::cout;
    using std::cin;
    
    // 对头文件中的函数原型做具体实现
    void getPerson(Person & rp)
    {
       cout<<"Enter first name: ";
       cin>>rp.fname;

       cout<<"Enter last name: ";
       cin>>rp.lname;
    }

    void showPerson(const Person & rp)
    {
        cout<<rp.lname<<" "<<rp.fname;
    }
}

namespace debts
{
      void getDebt(Debt & rd)
      {
        getPerson(rd.name);
        std::cout<<"Enter debt: ";
        std::cin>>rd.amount;
      }
      
      void showDebt(const Debt & rd)
      {
        showPerson(rd.name);
        std::cout<<": $"<<rd.amount<<std::endl;
      }

      double sumDebets(const Debt ar[],int n)
      {
        double total=0;
        for (int i=0;i<n;i++)
        {
            total+=ar[i].amount;
        }

        return total;
      }
      
}