#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
	ofstream ofs("over.txt");
	char wbuf[] = "jiangguangliang94@sina.com";
	ofs.write(wbuf, sizeof(wbuf));
	ofs.close();
	ifstream ifs("over.txt");
	char rbuf[100] = {0};
	ifs.read(rbuf, sizeof(rbuf));
	cout << rbuf << endl;
	ifs.close();

	return 0;
}
