#include <iostream>
#include "11.4_mytime1.h"

// 默认构造函数
Time::Time()
{
    hours=minutes=0;
}

Time::Time(int h,int m)
{
    hours=h;
    minutes=m;
}

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
      sum.hours=this->hours+t.hours+sum.minutes/60;
      sum.minutes=sum.minutes%60;
      return sum;
}

void Time::Show() const
{
     using std::cout;
     cout<<hours<<"hours,"<<minutes<<"minutes"<<std::endl;
}