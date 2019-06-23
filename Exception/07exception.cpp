#include <iostream>
#include <cstdio>
using namespace std;

class A{
public:
	A(void) {cout << "A::A()" << endl;}
	~A(void) { cout << "A::~A()" << endl;}
};

class B {
public:
	B(void):m_a(new A){
		FILE* fp = fopen("none.txt","r");
		if(fp == NULL) {
			delete m_a;
			throw -1;
		}
		fclose(fp);
	}
	~B(void) {
		delete m_a;
	}
private:
	A* m_a;
};

int main(void) {
	try{
		B b;
	}
	catch(int& ex) {
		cout << "捕获到异常：" << ex << endl;
		return -1;
	}
	return 0;
}
