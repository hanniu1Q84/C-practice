#include <cmath>
#include <iostream>
using namespace std;

int main(void) {
	cout << sqrt(200) << endl; //精度默认保留六位有效数字
	cout.precision(10); //设置保留10位有效数字
	cout << sqrt(200) << endl;

	cout.setf(ios::scientific); //科学计数法
	cout << sqrt(200) << endl;

	cout << "[";
	cout.width(10); //设置与宽10个字符
	cout.setf(ios::internal);
	cout.setf(ios::showpos);
	cout << 1234;
	cout << "]" << endl;
	return 0;
}
