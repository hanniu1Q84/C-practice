#include <iostream>
using namespace std;

class Complex {
public:
	Complex(int r, int i):m_r(r), m_i(i) {}
	void print(void) const {
		cout << m_r << "+" << m_i << 'i' << endl;
	}
	// c1 += c2
	Complex& operator+=(const Complex& c) {
		m_r += c.m_r;
		m_i += c.m_i;

		return *this;
	}
	// 友元函数定义可以放在类的内部，不属于类，
	// 也没有this指针
	friend Complex& operator-=(
			Complex& l, const Complex& r){
		l.m_r -= r.m_r;
		l.m_i -= r.m_i;

		return l;
	}
private:
	int m_r;
	int m_i;
	//frined 将全局函数生命为当前类的友元
	//友元函数可以访问当前类的任何成员
};

int main(void) {
	Complex c1(1, 2);
	Complex c2(3, 4);
	Complex c3(5, 6);
	
	c1 += c2;//c1.operator+= (c2)
	c1.print();
	(c1 +=c2) = c3;
	c1.print();

	c3 -= c2; //operator-=(c3,c2)
	c3.print();

	return 0;
}
