#include <iostream>
using namespace std;

class Integer{
public:
	Integer(int data = 0):m_data(new int(data)) {}
	int get(void) const {
		return *m_data;
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

	return 0;
}
