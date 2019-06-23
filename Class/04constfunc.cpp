#include <iostream>
using namespace std;

class A {
public:
	A(int data = 0):m_data(data),m_counter(0) {}
	// 如果成员函数中不需要修改类中的成员变量，那么就应该声明
	// 为长函数，避免意外修改其成员变量
	void print(void) const {
		cout << m_data/*++*/ << endl;
	}
	void show(void) const {
		cout << m_counter++ << endl;
	}
private:
	// mutable 修饰的成员变量会在使用是去处常属性，该成员变量在
	// 常函数中修改
	int m_data;
	mutable int m_counter;
};

int main(void) {
	A a(100);
	a.print();
	a.show();
	a.show();

	return 0;
}
