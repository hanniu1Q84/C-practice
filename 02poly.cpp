#include <iostream>
using namespace std;

class A {};
class B:public A {};

class Base{
public:
	virtual void foo(void) {
		cout << "Base::foo()" << endl;
	}
	virtual void bar(void) {
		cout << "Base::bar()" << endl;
	}
	virtual A* hum(int i) {
		cout << "Base::hum" << endl;
	}
};

class Derived:public Base {
public:
	int hum(void) {
		cout << "Derived::hum(void)" << endl;
	}
	//返回类型是类类型指针或引用，并且具有继承关系
	//可以形成协变覆盖
	B* hum(int i) {
		cout << "Derived::hum(int)" << endl;
	}
	virtual void foo(void) {
		cout << "Derived::foo" << endl;
	}
	void bar(int i) {
		cout << "Derived::bar(int)" << endl;
	}	
	void bar(void) const {
		cout << "derived::bar(void)" << endl;
	}
};

int main(void) {
	Base* pb = new Derived;
	pb->foo();
	pb->bar();
	pb->hum(100);

	Derived* p = static_cast<Derived*>(pb);
	p->hum();

	return 0;
}
