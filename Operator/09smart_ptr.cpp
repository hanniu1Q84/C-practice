#include <iostream>
#include <memory>
using namespace std;

class A {
public:
	A(const string& str = " "):m_str(str) {
	      	cout << "A::A()" << endl; 
	}
	~A(void) { cout << "~A::A()" << endl; }
	string m_str;
};

/*class PA {
public:
	PA(A* pa = NULL):m_pa(pa) {}
	~PA(void) {
		if(m_pa)
			delete m_pa;
	}
	A* operator->() const{
		return m_pa;
	}
	A& operator*() const {
		return *m_pa;
	}
private:
	A* m_pa;
};*/

int main(void) {
#if 0
	//A* pa = new A("hello");
	//cout << pa->m_str << endl;
	//cout << (*pa).m_str << endl;
	PA pa(new A("hello"));
	// pa.operator->() ->m_str
	cout << pa-> m_str << endl;
	// pa.operator*() .m_str
	cout << (*pa) .m_str << endl;
#else
	//标准库中的智能指针
	auto_ptr<A> pa(new A("hello"));
	cout << pa->m_str << endl;
	cout << (*pa).m_str << endl;
#endif
	return 0;
}
