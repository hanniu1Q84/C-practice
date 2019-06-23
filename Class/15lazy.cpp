#include <iostream>
using namespace std;

class A {
public:
	// 3)提供该对象的访问方法
	static A& getInstance(void) {
		if(!s_instance)
			s_instance = new A(1234);
		++s_counter;
		return *s_instance;
	}
	void release(void) {
		if(s_counter && --s_counter == 0) {
			delete this; // 自销毁
			s_instance = NULL;
			cout << "析构函数" << endl;
		}
	}
	void print(void) {
		cout << m_data << endl;
	}
private:
	//1)私有化所有的构造函数
	A(int data = 0):m_data(data) {}
	A(const A&);
	int m_data;

	// 2)定义唯一对象
	static A* s_instance;
	static int s_counter;
};

A* A::s_instance = NULL;
int A::s_counter = 0;

int main(void) {
	A& a1 = A::getInstance();
	A& a2 = A::getInstance();
	cout << &a1 << ' ' << &a2 << endl;
	a1.print();
	a1.release();
	
	a2.print();
	a2.release();
	a2.release();

	return 0;
}
