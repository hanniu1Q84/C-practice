#include <iostream>
using namespace std;

class Square {
public:
	double operator() (double x)const{
		return x * x;
	}		
	int operator() (int a, int b, int c = 9) {
		return a + b - c;
	}
};

int main(void) {
	Square square;
	cout << square(13.3) << endl;
	cout << square(10, 10 , 8) << endl;
	cout << square(10, 10) << endl;
	return 0;
}
