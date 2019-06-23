#include <iostream>
using namespace std;

class Integer {
public:
	Integer(int i = 0):m_i(i) {}
	void print(void) const {
		cout << m_i << endl;
	}
	const Integer operator-(void) const{
		return Integer(-m_i);
	}
	//自定义～为乘
	friend const Integer operator~(const Integer& i) {
		return Integer(i.m_i * i .m_i);
	}
private:
	int m_i;	
};

int main(void) {
	Integer i(100);
	Integer j = -i;
	j.print();
	j = ~i;
	j.print();

	return 0;
}
