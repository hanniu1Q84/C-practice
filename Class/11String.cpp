#include <iostream>
#include <cstring>
using namespace std;

class String {
public:
	//无参构造函数
	String(void):m_str(NULL) {}
	//有参构造函数
	String(const char* str = "") {
		m_str = new char[strlen(str) + 1];
		strcpy(m_str, str);
	}
	//析构函数
	~String(void) {
		delete [] m_str;
		m_str = NULL;
	}
	//深拷贝构造函数
	String(const String& that) {
		m_str = new char[strlen(that.m_str) + 1];
		strcpy(m_str, that.m_str);
	}
	String& operator=(const String& that) {
		//1)防止自赋值
		if(this != &that) {
			/*正确版
			 * //2)删除旧内存
			delete[] m_str;
			//3)建立新内存，4）赋值
			m_str = new char[strlen(that.m_str) + 1];
			strcpy(m_str, that.m_str);*/
			/*better版
			 * char* str = new char[strlen(that.m_str) + 1];
			delete [] m_str;
			m_str = strcpy(str, that.m_str);*/
			//复用神拷贝拷贝构造和析构
			String temp(that);
			swap(m_str, temp.m_str);
		}
		//5)返回自引用
		return *this;
	}
	//查询接口
	const char* c_str(void) {
		return m_str;
	}
	/*const string str(void) {
		string str = m_str;
		return str;
	}*/

private:
	char* m_str;
};

int main(void) {
	String s1("hello");
	cout << s1.c_str() << endl;
	String s2(s1);
	cout << s2.c_str() << endl;
	String s3("hello C++!");
	s2 = s3;
	cout << s2.c_str() << endl;

	return 0;
}
