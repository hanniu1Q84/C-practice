#include <iostream>
#include <sstream>
using namespace std;

int main(void){
	int i = 100;
	double d = 1.23;
	char c = 'A';
	char s[20] = "bye C++";

	//sprintf()
	/*
	 *char buf[100];
	  sprintf(buf,"%d %g %c % s", i, d, c, s);
	  printf("%s", buf);
	 */
	ostringstream oss;
	oss << i << ' ' << d << ' ' << c << ' ' 
		<< s << endl;
	cout << oss.str() << endl;
	cout << "==========================" << endl;
	istringstream iss;
	iss.str("123 3.14 B helloword");
	iss >> i >> d >> c >> s;
	cout << i << ' ' << d << ' ' << s << endl;
	
	return 0;
}
