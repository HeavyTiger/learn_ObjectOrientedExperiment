/*3．某销售公司有销售经理和销售员工，月工资的计算办法是：
销售经理的底薪为 4000 元，并将销售额的 2 / 1000 作为提成，
销售员工无底薪，只提取销售额的 5 / 1000 作为工资。编写程序：
（1）定义—个基类 Employee，它包含 3 个数据成员 number（职员编号）
、name（姓名）和salary（工资），以及用于输入编号和姓名的构造函数。
（2）由 Employee 类派生 Salesman 类。
Salesman 类包含两个新数据成员 commrate（提成比例）和sales（销售额），
还包含用于输入销售额并计算销售员工工资的成员函数 pay()
和用于输出的成员函数 print()。
（3）由 Salesman 类派生 Salesmanager 类。
Salesmanager 类包含新数据成员 monthlypay（底薪），
以及用于输入销售额并计算销售经理工资的成员函数 pay()，
用于输出的成员函数 print（）。
（4）编写 main 函数中，测试所设计的类结构，并求若干个不同员工的工资。*/

#include<iostream>
using namespace std;
#define MONTHLYPAY 4000
#define SALESMANRATE 0.005
#define SALESMANAGERRATE 0.002

class Employee {
protected:
	char name[10];		//姓名
	short number;		//编号
	double salary;		//工资
public:
	Employee(const char* cName, short num) :number(num){
		strcpy_s(name, cName);
	}
};
class Salesman :public Employee {
protected:
	double commrate;
	double sales;
public:
	Salesman(const char* cName, short num,double rate = SALESMANRATE):Employee(cName,num),commrate(rate){}
	void pay() {
		cout << "请输入销售员工"<<name<<"的销售额：";
		cin >> sales;
		salary = sales * commrate;
	}
	void print() {
		cout << "编号为" << number << "的销售员工" 
			<< name << ",工资为：" << salary << endl;
	}
};
class Salesmanager:public Salesman{
protected:
	double monthlypay;
public:
	Salesmanager(const char* cName,short num,double rate = SALESMANAGERRATE)
		:Salesman(cName, num, rate) {monthlypay = MONTHLYPAY;}
	void pay() {
		cout << "请输入销售经理" << name << "的销售额：";
		cin >> sales;
		salary = sales * commrate + monthlypay;
	}
	void print() {
		cout << "编号为" << number << "的销售经理"
			<< name << ",工资为：" << salary << endl;
	}
};


int main() {
	Salesman dcm("dcm", 100);
	Salesmanager DanGe("fcx", 101);
	dcm.pay();
	dcm.print();
	DanGe.pay();
	DanGe.print();
	return 0;
}