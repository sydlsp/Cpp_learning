
#include <iostream>

using namespace std;

double warming = 0.3; // 外部变量

// 函数原型
void update(double dt);
void local();

int main()
{
	cout << "Golbal warming is" << warming << " degrees." << endl;

	update(0.1);

	cout << "Golbal warming is" << warming << " degrees." << endl;

	local();

	cout << "Golbal warming is" << warming << " degrees" << endl;

}


