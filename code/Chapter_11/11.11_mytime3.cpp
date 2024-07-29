#include "11.10_mytime3.h"

// 这里不用#include<iostream>的原因是在头文件中已经包含了，用了也没什么
#include <iostream>
Time::Time()
{
    hours=minutes=0;
}

Time::Time(int h,int m)
{
    hours=h;
    minutes=m;
}

// 现在再来理解种格式的含义Time::只是为了限定是哪一个类中的AddMin的实现
void Time::AddMin(int m)
{
    minutes+=m;
    hours+=minutes/60;
    minutes=minutes%60;
}

void Time::AddHr(int h)
{
      hours+=h;
}

void Time::Reset(int h,int m)
{
    hours=h;
    minutes=m;
}

Time Time::operator+(const Time &t) const
{
     Time sum;
     sum.minutes=minutes+t.minutes;
     sum.hours=hours+t.hours+sum.minutes/60;
     sum.minutes%=60;
     // 这里注意返回的其实是数据成员，函数成员是共用的
     return sum;
}

Time Time::operator-(const Time &t) const
{
   Time diff;
   int tot1,tot2;
   tot1=t.minutes+60*t.hours;
   tot2=minutes+60*hours;
   diff.minutes=(tot2-tot1)%60;
   diff.hours=(tot2-tot1)/60;
   return diff;
}

Time Time::operator*(double mult) const
{
    Time result;
    long totalminutes=hours*mult*60+minutes*mult;
    result.hours=totalminutes/60;
    result.minutes=totalminutes%60;
    return result;
}

std::ostream & operator<<(std::ostream & os,const Time &t)
{
   os<<t.hours<<" hours,"<<t.minutes<<" minutes";
   return os;
}

