#include <iostream>
using namespace std;

class A {
public:
	int m_data;
	static int s_data; //声明
};

//静态成员变量需要在类的外部单独定义和初始化
int A::s_data = 100;

int main(void) {
	A a;
	cout << sizeof(a) << endl; //4， 静态成员变量不属于对象
					//在内存的全局区
					//限制在类中的全局变量
	//通过类名直接访问
	cout << A::s_data << endl;
	//通过对象访问
	cout << a.s_data << endl;

	return 0;
}
