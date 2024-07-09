#include <iostream>
#include "1_BankAccount.h"

BankAccount::BankAccount()
{
    name="Anonymity";
    id=0;
    total_money=0;
}

BankAccount::BankAccount(std::string name_in,int id_in,double money_in)
{
    name=name_in;
    id=id_in;
    total_money=money_in;
}

void BankAccount::account_in(double add_money_in)
{
    total_money+=add_money_in;
}

void BankAccount::account_out(double money_out)
{
    if (money_out>total_money)
    {
        std::cout<<"error:can not fetch so much money"<<std::endl;
        return;
    }
    
    total_money-=money_out;
}

void BankAccount::show_info() const
{
    using std::cout;
    cout<<"name:"<<name<<"  id:"<<id<<"  total_money:"<<total_money<<std::endl;
}
