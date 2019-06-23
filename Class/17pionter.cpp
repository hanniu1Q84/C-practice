#include <iostream>
using namespace std;

class Student {
public:
	Student(const string& name, int age = 20):
		m_name(name), m_age(age) {}
	void who(void) {
		cout << m_name << ' ' << m_age << endl;
	}
private:
	string m_name;
	int m_age;
};

int main(void) {
	void (Student::*pwho)(void) = &Student::who;
	Student s1("张飞");
	Student s2("赵云");
	(s1.*pwho)();
	Student* ps2 = &s2;
	(ps2->*pwho)();

	return 0;
}
