#include <iostream>
using namespace std;

class Counter{
public:
	Counter(int data = 0):m_data(data) {}
	Counter& add(void) {
		++m_data;
		return *this;
	}
	int m_data;
};

int main(void) {
	Counter cn; // this = &cn;
	cn.add().add().add();

	cout << cn.m_data << endl;

	return 0;
}
