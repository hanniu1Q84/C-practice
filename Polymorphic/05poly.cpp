#include <iostream>
using namespace std;

class Base {
public:
	Base(void) {
		m_data = new int;
		cout << "Base::Base()" << endl;
	}
	virtual ~Base(void) {
		cout << "Base::~Base()" << endl;
		delete m_data;
		m_data = NULL;
	}
	int *m_data;
};

class Derived:public Base {
public:
	Derived(void) {
		cout << "Derived::Derived()" << endl;
		m_data = new int;
	}
	~Derived(void) {
		cout << "Derived::~Derived()" << endl;
		delete m_data;
		m_data = NULL;
	}
	int * m_data;
};

int main(void) {
	Base* pb = new Derived;
	// ...
	delete pb;

	return 0;
}
