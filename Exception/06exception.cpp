#include <iostream>
#include <cstdio>
using namespace std;

class FileError:public exception {
public:
	const char* what(void) const throw() {
		return "std::File Error";
	}
};

void func(void) {
	if (!fopen("none.txt", "r")){
		throw FileError();
	}
}
int main(void) {
	try{
		func();
		char* p = new char[0xffffffffff];
	}
	catch(exception& ex){
		cout << ex.what() << endl;
		return -1;
	}
	return 0;
}

