#include <iostream>
#include <fstream>

int main()
{
    using namespace std;

    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile; //实例化一个用于输出的类outFile
    outFile.open("carinfo.txt"); //将输出类和文件绑定起来

    cout<<"Enter the make and model of automobile:";
    cin.getline(automobile,50);

    cout<<"Enter the model year:";
    cin>>year;

    cout<<"Enter the original asking price:";
    cin>>a_price;

    d_price=0.913*a_price;

    // 输出到控制台上

    cout<<fixed;
    cout.precision(2); // 两者连用控制小数位数
    cout.setf(ios_base::showpoint);
    cout<<"Make and model:"<<automobile<<endl;
    cout<<"Year:"<<year<<endl;
    cout<<"Was asking $"<<a_price<<endl;
    cout<<"Now asking $"<<d_price<<endl;

    // 输出到文件中
    outFile<<fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile<<"Make and model:"<<automobile<<endl;
    outFile<<"Year:"<<year<<endl;
    outFile<<"Was asking $"<<a_price<<endl;
    outFile<<"Now asking $"<<d_price<<endl;

    outFile.close();
    return 0;

}