#include <iostream>
using namespace std;

class Base {
public:
	Base(void):m_i(0) {
		cout << "Base::Base(void)" << endl;
	}
	Base(int i):m_i(i) {
		cout << "Base::Base(int)" << endl;
	}
	~Base(void) {
		cout << "Base::~Base()" << endl;
	}
	int m_i;
};

class Member {
public:
	Member(void):m_i(0) {
		cout << "Member::Member()" << endl;
	}
	Member(int i):m_i(i) {
		cout << "Member::Member(int)" << endl;
	}
	~Member(void){
		cout << "Member::~Member()" << endl;
	}
	int m_i;
};

class Derived:public Base {
public:
	Derived(void) {
		cout << "Derived::Derived()" << endl;
	}
	// Base(i) ==>说明基类子对象初始化方式
	// m_member(j) ==>说明成员函数的初始化方式
	Derived(int i, int j):Base(i),m_member(j) {
		cout << "Derived::Derived(int)" << endl;
	}
	~Derived(void) {
		cout << "Derived::~Derived()" << endl;
	}
	Member m_member;
};

int main(void) {
	//Derived d;
	//cout << d.m_i << endl;
	//Derived d2(10);
	//Derived d3(100, 200);
	//cout << d3.m_i << ' ' << d3.m_member.m_i << endl;
	Base* pb = new Derived;
	delete pb; //只调用基类的析构函数，有内存泄漏风险

	return 0;
}
