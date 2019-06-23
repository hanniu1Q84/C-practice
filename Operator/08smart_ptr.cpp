#include <iostream>
using namespace std;

class A {
public:
	A(void) { cout << "A::A()" << endl; }
	~A(void) { cout << "~A::A()" << endl; }
};

class PA {
public:
	PA(A* pa = NULL):m_pa(pa) {}
	~PA(void) {
		if(m_pa)
			delete m_pa;
	}
private:
	A* m_pa;
};

int main(void) {
	PA pa(new A);
	try{
		// ...
		char* pstr = new char[0xffffffff];

	} catch(...) {
		cout << "程序发生异常" << endl;
		return -1;
	}

	return 0;
}
