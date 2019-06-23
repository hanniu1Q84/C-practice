#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <ctime>
using namespace std;

class Clock {
public:
	Clock(time_t t) {
		tm* local = localtime(&t);
		m_hour = local->tm_hour;
		m_min = local->tm_hour;
		m_sec = local->tm_sec;
	}
	Clock(void):m_hour(0), m_min(0), m_sec(0) {}
	void run(void) {
		while(1){
			show();
			tick();
		}
	}
private:
	void show(void){
		printf("\r%02d:%02d:%02d",
			m_hour, m_min, m_sec);
	//刷新标准输出缓冲区
	fflush(stdout);
	}
	void tick(void) {
		sleep(1);
		if(++m_sec == 60) {
			m_sec = 0;
			if(++m_min == 60) {
				m_min = 0;
				if(++m_hour == 24)
					m_hour = 0;
			}
		}
	}

private:
	int m_hour;
	int m_min;
	int m_sec;
};


int main(void) {
/*	Clock clock(time(0));
	clock.run();
*/	
	Clock c;
	c.run();

	return 0;
}
