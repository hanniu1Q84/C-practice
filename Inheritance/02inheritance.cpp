#include <iostream>
using namespace std;

class A {
public:
	void func(void) {
		cout << "A::func(void)" << endl;
	}
};

class B:public A {
public:
	void func(int i) {
		cout << "B::func(int)" << endl;
	}
	void foo(void) {
		A::func(); //用名字空间重载的方式较优
		func(100);
	}
	//将基类中的func函数声明到子类中，可以将子类中同名
	//不同参函数构造重载关系
	//using A::func;
};

int main(void) {
	B b;
	b.foo();
	
	return 0;
}
