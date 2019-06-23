#include <iostream>
#include <cstdio>
using namespace std;

class FileError {
public:
	FileError(const string& file, int line):
		m_file(file), m_line(line) {
		cout << "出错位置：" << m_file
			<< ":" << m_line << endl;
		}
	string m_file;
	int m_line;
};

class A {
public:
	A(void) { cout << "A::A()" << endl;}
	~A(void) {cout << "A::~A()" << endl;}
};

int func3(void) {
	A a;
	FILE* fp = fopen("none.txt","r");
	if(fp == NULL) {
		//cout << "file open failed!" << endl;
		throw FileError(__FILE__, __LINE__);
		throw -1;//抛出异常，条转到右花括号
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
	try{
		func1();
		cout << "func1没有发生异常" << endl;
		// ...
	} catch(int& ex){
		cout << "file open failed" << endl;
		return -1;
	}
	catch(FileError& ex){
		cout << "FileError" << endl;
		return -1;
	}

	return 0;
}
