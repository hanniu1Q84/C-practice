//简单工厂方法
#include <iostream>
using namespace std;

class PdfParser {
public:
	void prase(const char* pdffile) {
	//解析出一个矩形
	this->onRect();
	//解析出一个圆形
	onCircle();
	//解析出一行文本
	onText();
	//解析出一张图片
	onImage();
	}
private:
	virtual void onRect(void) = 0;
	virtual void onCircle(void) = 0;
	virtual void onText(void) = 0;
	virtual void onImage(void) = 0;
};

class PdfRender:public PdfParser {
private:
	void onRect(void) {
		cout << "解析矩形" << endl;
	}
	void onCircle(void) {
		cout << "解析圆形" << endl;
	}
	void onText(void) {
		cout << "解析文本" << endl;
	}
	void onImage(void) {
		cout << "解析图像" << endl;
	}

};

int main(void) {
	PdfRender render;
	render.prase("something.pdf"); //render.pdfPrase::prase()
				//prase中的相关函数由this调用，
				//this为pdfPrase* &render,为pdfRender 的向上造型
				//因此构成多态；

	return 0;
}
