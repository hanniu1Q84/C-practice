#include <iostream>
#include <cstdio>
using namespace std;

class A {
public:
	A(void) { cout << "A::A()" << endl;}
	~A(void) {cout << "A::~A()" << endl;}
};

int func3(void) {
	A a;
	FILE* fp = fopen("none.txt","r");
	if(fp == NULL) {
		cout << "file open failed!" << endl;
		return -1;
	}
	//...
	fclose(fp);
	return 0;
}

int func2(void) {
	A a;
	if(func3() == -1) {
		return -1;
	}

	// ...
	return 0;
}
int func1(void) {
	A a;
	if(func2() == -1) {
		return -1;
	}

	// ...
	return 0;
}

int main(void) {
	if(func1() == -1) {
		return -1;
	}

	return 0;
}
