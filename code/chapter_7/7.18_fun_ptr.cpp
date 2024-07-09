#include <iostream>

double betsy(int);
double pam(int);

// 定义一个接受函数指针的函数
void estimate(int lines,double (*pf)(int));

int main()
{
    using namespace std;

    int code;

    cout<<"How many lines of code do you need?"<<endl;

    cin>>code;

    cout<<"Here is Betsy's estimate:"<<endl;
    estimate(code,betsy);

    cout<<"Here is Pam's estimate:"<<endl;
    estimate(code,pam);

}

double betsy(int lns)
{
    return 0.05*lns;
}

double pam(int lns)
{
     return 0.03*lns+0.004*lns*lns;
}

void estimate(int lines,double (*pf)(int))
{
    using namespace std;
    cout<<lines<<"lines will take"<<endl;
    // cout<<pf(lines)<<"hour(s) will take"<<endl;
    cout<<(*pf)(lines)<<"hour(s) will take"<<endl;
}