#include <iostream>
#include <cstdio>
using namespace std;

class Student {
public:
	Student(const string& name):m_name(name) {}
	int m_a;
	double m_d;
	string m_name;
};

int main(void) {
	//定义成员函数
	string Student::*pname = &Student::m_name;
	Student s1("张飞");
	Student s2("赵云");
	cout << s1.*pname << endl;
	cout << s2.*pname << endl;

	Student* ps = &s1;
	cout << ps->*pname << endl;
	
	//成员变量指针本质就是类中特定成员变量在对象中的相对地址
	printf("pname: %p \n", pname);
	printf("&s1 : %p \n", &s1);
	printf("&s1.m_name: %p \n", &s1.m_name);

	return 0;
}
