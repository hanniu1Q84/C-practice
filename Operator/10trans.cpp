#include <iostream>
using namespace std;

class Integer {
public:
	explicit Integer(int data = 0):m_data(data) {
		cout << "通过构造函数实现类型转换" << endl;
	}

	/*explicit*/ operator int(void) const{
		cout << "通过类型转换操作符重载函数实现转换" << endl;
		return m_data;
	}
private:
	int m_data;
};

int main(void) {
	Integer i1(100);
	cout << i1 << endl;

	int i2 = i1;
	cout << i2 << endl;

	return 0;
}
