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
	//前++
	Integer& operator++() {
		++m_i;
		return *this;
	}
	//前--
	friend Integer& operator--(Integer& i) {
		--i.m_i;
		return i;
	}
	//后++
	const Integer operator++(int) {
		Integer old = *this;
		//复用前++
		++(*this);//++m_i;
		return old;
	}
	//后--
	friend const Integer operator--(Integer& i, int) {
		Integer old = i;
		--i;
		return old;
	}
	
private:
	int m_i;	
};

int main(void) {
	Integer i(100);
	Integer j = ++i;
	i.print();//101
	j.print();//101
	++++i;
	i.print(); // 103
	------i;
	i.print();

	cout << "============" << endl;
	j = i++;
	i.print();
	j.print();
	j = i--;
	i.print();
	j.print();

	return 0;
}
