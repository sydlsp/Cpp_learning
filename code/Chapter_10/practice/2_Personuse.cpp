#include <iostream>
#include "2_Person.h"
using namespace std;
int main()
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy","Sam");
    one.Show();
    one.FormalShow();
    two.Show();
    two.FormalShow();
    three.Show();
    three.FormalShow();
}