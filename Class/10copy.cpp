#include <iostream>
using namespace std;

class Integer{
public:
	Integer(int data = 0):m_data(new int(data)) {}
	int get(void) const {
		return *m_data;
	}
	//缺省拷贝构造函数，浅拷贝
	//Integer(const Integer& that):m_data(that.m_data) {}
	//自定义的拷贝构造函数，深拷贝
	Integer(const Integer& that) {
		m_data = new int(*that.m_data);
	}
	/* 编译器会为类提供缺省的拷贝赋值函数，满足对象之间赋值操作*/
	/*Integer& operator=(const Integer& that) {
		cout << "缺省的拷贝赋值函数" << endl;
		m_data = that.m_data;
		return *this;
	}*/
	/*自定义神拷贝赋值函数*/
	Integer& operator=(const Integer& that){
		//1)防止自赋值
		if(this != &that) {
			//2)释放旧内存
			delete m_data;
			// 3)分配新内存 4)拷贝新数据
			m_data = new int(*that.m_data);
		}
		// 5)返回自引用
		return *this;
	}
	~Integer(void) {
		cout << "析构函数" << endl;
		delete m_data;
	}
private:
	int* m_data;
};

int main(void) {
	Integer i(100);
	cout << i.get() << endl;
	Integer i2(i); //拷贝构造
	cout << i2.get() << endl;
	Integer i3;
	i3 = i2; // copy 赋值
	//i3.operator= (i2); 函数返回结果就是赋值表达式结果
	cout << i3.get() << endl;

	return 0;
}
