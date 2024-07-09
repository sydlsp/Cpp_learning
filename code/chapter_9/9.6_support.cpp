#include <iostream>

extern double warming; // 在另一个文件中使用warming
// double warming = 100; // 这样是不被允许的
void update(double dt);
void local();

using std::cout;

void update(double dt)
{
	//extern double warming; // 可选，写不写效果一样

	warming += dt;
	
	cout << "Updating global warming to" << warming;
	cout << " degrees." << std::endl;
}

void local()
{
	double warming = 0.8;
	cout << "local warming= " << warming << " degrees." << std::endl;

	cout << "But global warming= " << ::warming << " degrees" << std::endl;
}
