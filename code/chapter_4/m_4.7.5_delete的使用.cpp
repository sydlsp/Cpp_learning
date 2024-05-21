#include <iostream>
using namespace std;

int main()
{
    int *ps=new int;
    int *pq=ps;

    cout<<ps<<endl;
    cout<<pq<<endl;

    delete pq;

    cout<<ps<<endl;
    cout<<pq<<endl;
}