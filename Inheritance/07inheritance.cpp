#include <iostream>
using namespace std;

class Base {
public:
	Base(void):m_i(0) {
		cout << "Base::Base(void)" << endl;
	}
	Base(int i):m_i(i) {}
	Base(const Base& that):m_i(that.m_i) {
		cout << "Base::Base(const Base&)" << endl;
	}
	Base& operator= (const Base& that) {
		cout << "Base::operator= " << endl;
		if(&that != this) {
			m_i = that.m_i;
		}
		return *this;
	}
	int m_i;
};

class Derived:public Base{
public:
	Derived(void):m_i(0) {}
	Derived(int i, int i2):Base(i),m_i(i2) {}
	Derived(const Derived& that):
		m_i(that.m_i), Base(that) {
		cout << "Derived(const Derived&)" << endl;
	}
	Derived& operator= (const Derived& that) {
		cout << "Derived::operator=" << endl;
		if(&that != this) {
			//直接调用基类的拷贝赋值函数，
			//赋值基类子对象
			Base::operator=(that);
			m_i = that.m_i;
		}
		return *this;
	}
	int m_i;
};

int main(void) {
	Derived d1(100, 200);
	Derived d2(d1);
	cout << d1.Base::m_i << ',' << d1.m_i << endl;
	cout << d2.Base::m_i << ',' << d2.m_i << endl;

	Derived d3;
	d3 = d2; //拷贝赋值
	cout << d3.Base::m_i << ',' << d3.m_i << endl;

	return 0;
}

