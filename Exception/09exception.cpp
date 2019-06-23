#include <iostream>
using namespace std;

class A {
public:
	void func(void) {
		throw -1;
	}
	~A(void) {
		try{
			throw -2;
		}
		catch(int& ex) {
			cout << "异常代码是" << ex << endl;
			
		}
	}
};

int main(void) {
	A a;
	try{
		a.func();
	}
	catch(int& ex){
		cout << "异常码是：" << ex << endl;
		return -1;
	}

	return 0;
}
