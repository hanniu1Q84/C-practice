#include <iostream>
using namespace std;

//普通员工
class Employee {
public:
	Employee(const string& name, int id, int grade):
		m_name(name), m_id(id), m_grade(grade) {}
	//打印员工信息
	void printInfo(void) {
		printBasic(); //公有信息
		printExtra(); //特有信息
	}
	//计算员工工资
	void paySalary(void) {
		cout << "输入出勤天数：";
		int attend;
		cin >> attend;
		m_attend = attend / 22.0;
		
		setMessage();

		cout << "工资为：" << 
			calBasic()/* * m_attend*/ + calMerit() << endl;
	}
protected:
	double m_attend; //出勤率
private:
	//计算基本工资
	double calBasic(void) {
		m_basic = s_grades[m_grade - 1];
		
		return m_basic * m_attend;
	}
	//其他输入项
	virtual void setMessage(void) {}
	//计算绩效工资
	virtual double calMerit(void) {
		return m_basic / 2;
	}
	//打印员工的基本信息
	void printBasic(void) {
		cout << "姓名：" << m_name << ", 职级：" << 
			m_grade << ", 工号：" << m_id << endl;
	}
	virtual void printExtra(void) {
		cout << "职位：普通员工" << endl;
	}
	string m_name; //姓名
	int m_id;	//工号
	int m_grade;	//职级
	double m_basic;	//基本工资
	static double s_grades[6];//职级薪资
};
double Employee::s_grades[] = {
	3000, 3500, 5000, 8000, 10000};

//技术员
class Technician:virtual public Employee {
public:
	Technician(const string& name, int id, int grade,
			double allow):Employee(name, id, grade),
			m_allow(allow), factor(0) {}
protected:
	void printExtra(void) {
		cout << "职位：技术人员" << endl;
		cout << "研发津贴：" << m_allow << endl;
	}
	double calMerit(void) {
		//小时数*出勤率*进度因数*研发津贴
		return 8*23*m_attend*factor*m_allow;
	}
	void setMessage(void) {
		cout << "输入进度因数：";
		cin >> factor;
	}
private:
	double m_allow; //研发津贴
	double factor; //进度因数
};
//经理
class Manager:virtual public Employee {
public:
	Manager(const string& name, int id, int grade,
			double bouns):
		Employee(name, id, grade), 
			m_bouns(bouns), factor(0) {}
		
protected:
	void printExtra(void) {
		cout << "职位：经理" << endl;
		cout << "绩效奖金：" << m_bouns << endl;
	}
	void setMessage(void) {
		cout << "输入绩效因数：";
		cin >> factor;
	}
	double calMerit(void) {
		//绩效奖金*绩效因数*出勤率
		return m_bouns*factor*m_attend;
	}
private:
	double m_bouns; //绩效奖金
	double factor;
};

//技术主管
class TechMngr:public Technician, public Manager {
public:
	TechMngr(const string& name, int id, int grade,
			double allow, double bouns):
		Technician(name, id, grade, allow),
		Manager(name, id, grade, bouns),
		Employee(name, id, grade) {}
private:
	void printExtra(void) {
		Technician::printExtra();
		Manager::printExtra();
	}
	void setMessage(void){
		Technician::setMessage();
		Manager::setMessage();
	}
	double calMerit(void) {
		return (Technician::calMerit() +
				Manager::calMerit()) / 2;
	}
};

int main(void) {
	Employee emp("张三", 10086, 2);
	emp.printInfo();
	emp.paySalary();
	cout << "========================" << endl;
	Technician tech("孔明", 10088, 4, 50);
	tech.printInfo();
	tech.paySalary();
	cout << "========================" << endl;
	Manager mngr("刘备", 10012, 5, 5000);
	mngr.printInfo();
	mngr.paySalary();
	cout << "========================" << endl;
	TechMngr tm("关羽", 10000, 5, 50, 5000);
	tm.printInfo();
	tm.paySalary();

	return 0;
}
