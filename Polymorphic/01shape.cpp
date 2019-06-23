#include <iostream>
using namespace std;

// class shape 包含了纯虚函数，不能实例化为对象
class Shape {
public:
	Shape(int x, int y):m_x(x), m_y(y) {}
	virtual void draw(void) = 0;
	/*virtual void draw(void) {
		cout << "绘制图形" << m_x << ',' << m_y << endl;
	}*/
protected:
	int m_x;
	int m_y;
};

class Rect:public Shape{
public:
	Rect(int x, int y, int w, int h):
		Shape(x,y), m_w(w), m_h(h) {}
	void draw(void) {
		cout << "绘制矩形：" << m_x << ',' << m_y <<
			',' << m_w << ',' << m_h << endl;
	}
private:
	int m_w;
	int m_h;
};

class Circle:public Shape {
public:
	Circle(int x, int y, int r):Shape(x,y), m_r(r) {}
	void draw(void) {
		cout << "绘制圆形：" << m_x << ',' << m_y <<
			',' << m_r << endl;
	}
private:
	int m_r;
};

//子类没有覆盖基类中的纯虚函数，也将变成抽象类
class Triangle:public Shape{
public:
	Triangle(int x, int y):Shape(x, y) {}
	/*void draw(void) {
		cout << "绘制三角形" << endl;
	}*/
};

void render(Shape* shapes[]) {
	for(int i = 0; shapes[i]; i++) {
		shapes[i]->draw();
	}
}	

int main(void) {
//	Shape a;
	//Triangle b(2,3);
	Shape* shapes[1024] = {};
	shapes[0] = new Rect(2, 3, 5, 6);
	shapes[1] = new Rect(4, 5, 10, 11);
	shapes[2] = new Circle(6, 8, 8);
	shapes[3] = new Circle(15, 16, 20);
	shapes[4] = new Rect(10, 12, 20, 30);
	//shapes[5] = new Triangle(2,3);
	//shapes[5] = &b;
	render(shapes);
		
	return 0;
}
