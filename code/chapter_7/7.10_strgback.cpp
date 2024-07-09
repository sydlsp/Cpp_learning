#include <iostream>
using namespace std;
char * buildstr(char c,int n);

int main()
{
    int times;
    char ch;

    cout<<"Enter a character:";
    cin>>ch;
    cout<<"Enter an integer";
    cin>>times;

    char *ps=buildstr(ch,times);
    cout<<ps<<endl;
    delete []ps;
}

char * buildstr(char c,int n)
{
    char *pstr=new char[n+1];
    pstr[n]='\0';
    while(n-->0)
    {
        pstr[n]=c;
    }

    return pstr;
}
