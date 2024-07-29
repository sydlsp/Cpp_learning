#include <iostream>
#include "11.16_stonewt.h"
using std::cout;
void display(const Stonewt & st, int n);

int main()
{
    Stonewt incognito=275; //使用构造函数来将275隐式转换为对象
    Stonewt wolfe(285.7);
    Stonewt taft(21,8);

    cout<<"The Celebrity weiged";
    incognito.show_stn();

    cout<<"The detective weiged";
    wolfe.show_stn();

    cout<<"The president weighed";
    taft.show_lbs();

    incognito=276.8;  // 又一次使用隐式转换
    taft=325;
    
    cout<<"After dinner, the Celebrity weighed";
    incognito.show_stn();

    cout<<"After dinner, the Presedent weighed";
    taft.show_lbs();

    display(taft,2);
    cout<<"The wrestler weighed even more"<<std::endl;
    display(422,2);
    cout<<"No stone left unearned"<<std::endl;
    cout<<"ok";
    return 0;

}

void display(const Stonewt & st,int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<"Wow!";
        st.show_stn();
    }
}