#include <iostream>
using namespace std;

class A {
public:
	void func1(void) const {
		cout << "长函数" << endl;
	}
	void func2(void) {
		cout << "非常函数" << endl;
	}
};

int main(void) {
	A b;
	b.func1();
	b.func2();
	
	const A b2 = b;
	b2.func1();
//	b2.func2();

	const A* p = &b;
	p->func1(); //ok
//	p->func2(); // error!

	const A& r = b; //常引用
	r.func1();// ok
//	r.func2();// error

	return 0;
}
