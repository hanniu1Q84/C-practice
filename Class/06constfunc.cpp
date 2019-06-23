#include <iostream>
using namespace std;

class A {
public:
	void func(void) const {
		cout << "func 长函数版本" << endl;
	} //隐藏const A*(this)
	void func(void) {
		cout << "func 非常函数版本" << endl;
	} //隐藏A*（this)
};

int main(void) {
	A a;
	const A& ra = a;
	a.func();
	ra.func();
	
	return 0;
}
