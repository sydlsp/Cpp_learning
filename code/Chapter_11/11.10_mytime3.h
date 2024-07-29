#ifndef MYTIME3_H_
#define MYTIME3_H_

#include <iostream>
class Time
{
    private:
       int hours;
       int minutes;
    
    public:
      Time();
      Time(int h,int m=0);
      void AddMin(int m);
      void AddHr(int h);
      void Reset(int h=0,int m=0);

      // 这下面三个用const的原因是不想修改本来实例的数值
      Time operator+(const Time &t) const;
      Time operator-(const Time &t) const;

      // 在C++中，编译器在处理类声明的时候会首先了解所有成员函数的存在
      // 因此前面的函数可以调用后面声明的函数，只要函数在类的声明部分被声明过
      // 就可以在类的任何成员或友元函数中调用它们
      //Time operator*(double n) const; 
      
      // 用上面重载的*运算符
      friend Time operator*(double m,const Time &t)
      {
          return t*m;
      }  // 内联函数

      Time operator*(double n) const;

      friend std::ostream & operator<<(std::ostream &os,const Time &t);
};

#endif