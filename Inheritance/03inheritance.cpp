#include <iostream>
using namespace std;

class A {
public:
	int m_pub;
protected:
	int m_pro;
private:
	int m_pri;
};

class B:public A {};
class C:protected A {};
class D:private A {};

class X:public B{
public:
	void func(void) {
		m_pub = 10;
		m_pro = 10;
		//m_pri = 10;
	}
};
class Y:public C{
public:
	void func(void) {
		m_pub = 10;
		m_pro = 10;
		//m_pri = 10;
	}
};
class Z:public D{
public:
	void func(void) {
		//m_pub = 10;
		//m_pro = 10;
		//m_pri = 10;
	}
};

int main(void){
	B b;
	b.m_pub = 10;
	//b.m_pro = 10;
	//b.m_pri = 10;
	C c;
	//c.m_pub = 10;
	//c.m_pro = 10;
	//c.m_pri = 10;
	D d;
	//d.m_pub = 10;
	//d.m_pro = 10;
	//d.m_pri = 10;

	return 0;
}
