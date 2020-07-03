#include<iostream>
#define PI 3.1415926
using namespace std;
class body {
public:
	body(double dat):data(dat){}
	virtual double getSize() = 0;
	virtual double getVolumn() = 0;
protected:
	double data;		//��Ϊ��İ뾶��������ı߳���Բ�������Բ�İ뾶
};
class sphere :public body {
public:
	sphere(double r) :body(r) {};
	double getSize() {
		return 4 * PI * data * data;
	}
	double getVolumn() {
		return 3.0 / 4 * PI * data * data * data;
	}
};
class cube :public body {
public:
	cube(double length) :body(length) {};
	double getSize() {
		return 6 * data * data;
	}
	double getVolumn() {
		return data * data * data;
	}
};
class cylinder :public body {
public:
	cylinder(double r,double h) :body(r),height(h) {};
	double getSize() {
		return 2 * PI * data * data + 2 * PI * data * height;
	}
	double getVolumn() {
		return data * data * PI * height;
	}
private:
	double height;
};

int main() {
	sphere s1(7.5);
	cube c1(6.3);
	cylinder cy1(5.5, 10);
	cout << "��ı����Ϊ��" << s1.getSize() << endl;
	cout << "������Ϊ��" << s1.getVolumn() << endl;
	cout << "������ı����Ϊ��" << c1.getSize() << endl;
	cout << "����������Ϊ��" << c1.getVolumn() << endl;
	cout << "Բ����ı����Ϊ��" << cy1.getSize() << endl;
	cout << "Բ��������Ϊ��" << cy1.getVolumn() << endl;
	return 0;
}