// 在下面的实现中，利用了C++名称空间的开放性，将方法定义添加到VECTOR名称空间中
#include <cmath>
#include "11.13_vector.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
    // 计算180/pi的值
    const double Rad_to_deg=45.0/atan(1.0);

    // private函数
    void Vector::set_mag()
    {
        mag=sqrt(x*x+y*y);
    }

    void Vector::set_ang()
    {
        if(x==0.0 && y==0.0)
           ang=0.0;
        else
           ang=atan2(y,x);
    }

    void Vector::set_x()
    {
        x=mag*cos(ang);
    }

    void Vector::set_y()
    {
        y=mag*sin(ang);
    }

    // public函数
    Vector::Vector()
    {
        x=y=mag=ang=0.0;
    }
    
    Vector::Vector(double n1,double n2,Mode form)
    {
        mode=form;
        if (form==RECT)
        {
            x=n1;
            y=n2;
            set_mag();
            set_ang();
        }

        else if (form==POL)
        { 
            // 输入的两个值一个是长度另一个是角度
            mag=n1;
            // 这里把角度转化为弧度
            ang=n2/Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout<<"Incorrect 3rd argument to Vector()--";
            cout<<"Vector set to 0"<<std::endl;
            x=y=mag=ang=0;
            mode=RECT;
        }

    }
    
    void Vector::reset(double n1,double n2,Mode form)
    {
        mode=form;
        if (form==RECT)
        {
            x=n1;
            y=n2;
            set_mag();
            set_ang();
        }

        else if (form==POL)
        { 
            // 输入的两个值一个是长度另一个是角度
            mag=n1;
            // 这里把角度转化为弧度
            ang=n2/Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout<<"Incorrect 3rd argument to Vector()--";
            cout<<"Vector set to 0"<<std::endl;
            x=y=mag=ang=0;
            mode=RECT;
        }
    }
    
    // 析构函数实现
    Vector::~Vector()
    {

    }

    void Vector::polar_mode()
    {
        mode=POL;
    }

    void Vector::rect_mode()
    {
        mode=RECT;
    }

    // 运算符重载的定义
    Vector Vector::operator+(const Vector &b) const
    {
        // 这里其实是调用了构造函数
        return Vector(x+b.x,y+b.y);
    }

    Vector Vector::operator-(const Vector &b) const
    {
        return Vector(x-b.x,y-b.y);
    }
    
    std::ostream& operator<<(std::ostream &os,const Vector &v)
    {
        // 这里要注意，虽然友元函数可以访问类的所有成员，
        // 但友元函数不在类的作用域内，所以，下面要用Vector::REC
        if (v.mode==Vector::Vector::RECT)
           os<<"(x,y)=("<<v.x<<","<<v.y<<")";
        
        else if (v.mode==Vector::POL)
        {
            os<<"(m,a)=("<<v.mag<<","<<v.ang*Rad_to_deg<<")";
        }
        else
           os<<"Vector object mode is invalid";

           return os;

    }
    
    Vector Vector::operator*(double n) const
    {
        // 这里还是调用构造函数
        return Vector(n*x,n*y);
    }
 
    // 友元函数不是类中的函数，所以不需要限定符
    Vector operator*(double n,const Vector &b)
    {
         return b*n;
    }

    // 对已重载的运算符进行重载
    // 在C++中减法运算符有两种含义。使用两个操作数的话是进行减法操作，使用一个操作数的话是取负运算
    Vector Vector::operator-() const
    {
        return Vector(-x,-y);
    }
}
