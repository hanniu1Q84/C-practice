#include <iostream>
using namespace std;

class Complex {
public:
	Complex(int r, int i):m_r(r), m_i(i) {}
	void print(void) const {
		cout << m_r << "+" << m_i << 'i' << endl;
	}
	/*从左道右有3个const
	 * 1）修饰返回之，让其返回右值
	 * 2）常引用：为了能接收常量型的右值（常量型的右操作数）
	 * 3）常函数：为了能让常对象调用（支持常左操作数）
	 */	
	const Complex operator+(const Complex& c) const{
		return Complex(m_r + c.m_r, m_i + c.m_i);
	}
private:
	int m_r;
	int m_i;
	//frined 将全局函数生命为当前类的友元
	//友元函数可以访问当前类的任何成员
	friend const Complex operator-
		(const Complex& l, Complex& r);
};
const Complex operator-(const Complex& l, Complex& r){
	return Complex(l.m_r - r.m_r, l.m_i - r.m_i);
}

int main(void) {
	Complex c1(1, 2);
	Complex c2(3, 4);
	c1.print();
	c2.print();
	Complex c3 = c1 + c2; //c3 = c1.operator+(c2)
	c3.print();
	Complex c4 = c3 - c1; // Complex c4 = ::operator-(c3,c1)
	c4.print();

	Complex c5 = c1 + c2 + c3 + c4;
	c5.print();

	return 0;
}
