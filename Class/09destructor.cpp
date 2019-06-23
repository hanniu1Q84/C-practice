#include <iostream>
using namespace std;

class A {
public:
	A(void) {
		cout << "A::A(void)" << endl;
	}
	~A(void) {
		cout << "A::~A(void)" << endl;
	}
};

class B {
public:
	B(void) {
		cout << "B::B(void)" << endl;
	}
	~B(void) {
		cout << "B::~B(void)" << endl;
	}
	A m_a;
};

int main(void) {
	B b;
	
	return 0;
}
