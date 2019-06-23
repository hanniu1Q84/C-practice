#include <iostream>
using namespace std;

class A {virtual void foo() {}};
class B:public A {void foo() {} };
class C:public A {void foo() {} };
class D{};

int main(void) {
	B b;
	A* pa = &b;
	B* pb = dynamic_cast<B*>(pa);
	cout << "pa = " << pa << endl;
	cout << "pb = " << pb << endl;
	C* pc = dynamic_cast<C*>(pa);
	cout << "pc = " << pc << endl;

	D* pd = dynamic_cast<D*>(pa);
	cout << "pd = " << pd << endl;

	A& ra = b;
	C& rc = dynamic_cast<C&>(ra);
	//throwing an instance of 'std::bad_cast'

	return 0;
}
