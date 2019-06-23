#include <iostream>
using namespace std;

class Phone {
public:
	Phone(const string& number):m_number(number) {}
	void call(const string& number) {
		cout << m_number << "打给" << number << endl;
	}
private:
	string m_number;
};

class Player{
public:
	Player(const string media):m_media(media) {}
	void play(const string& music) {
		cout << m_media << "播放器播放" << music << endl;
	}	
private:
	string m_media;
};

class Computer {
public:
	Computer(const string& os):m_os(os) {}
	void run(const string& app) {
		cout << "在" << m_os << "系统上运行" << app << endl;
	}
private:
	string m_os;
};

class SmartPhone:public Phone,public Player,
	public Computer{
public:
	SmartPhone(const string& number,
			const string& media, const string& os):
			Phone(number), Player(media), Computer(os) {}
};

int main(void){
	SmartPhone sp("18721327729", "MP4", "Andriod");
	sp.call("0101-6000000");
	sp.play("最选名族风.mp3");
	sp.run("Angry Birds");
	// 编译器会自动计算指针的偏移量
	SmartPhone* p1 = &sp;
	Phone* p2 = p1;// p1 + 0
	Player* p3 = p1;//p1 + sizeof(Phone)
        Computer* p4 = p1;//p1+sizeof(Phone)+sizof(player)
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;
	cout << "p3 = " << p3 << endl;
	cout << "p4 = " << p4 << endl;
		
	return 0;
}
