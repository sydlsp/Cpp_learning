#include <iostream>
#include "1_BankAccount.h"
int main()
{
    using namespace std;
    BankAccount ac1;
    BankAccount ac2("Mike",100,123456);
    ac1.show_info();
    ac2.show_info();
    ac1.account_in(1000);
    ac1.account_out(2000);
    ac2.account_out(100000);
    ac1.show_info();
    ac2.show_info();
}