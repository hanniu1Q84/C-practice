#include <iostream>
using namespace std;

class A {
public:
	~A(void) { cout << "A::~A(void)" << endl;} 
};

int main(void) {
	do {
		A a1;
		A* pa2 = new A;
		cout << "test1" << endl;
		delete pa2;
		cout << "test3" << endl;
	}while(0); //}---->A::~A();
	cout << "test2" << endl;

	return 0;
}
