#include <iostream>
using namespace std;

class A{
public:
	void foo(void) {
		cout << "A::foo(void)" << endl;
	}
};

class B {
public:
	void foo(int i) {
		cout << "B::foo(int)" << endl;
	}
};

class C:public A, public B {
public:
	using A::foo;
	using B::foo;
};

int main(void) {
	C c;
	c./*A::*/foo();
	c./*B::*/foo(100);
}
