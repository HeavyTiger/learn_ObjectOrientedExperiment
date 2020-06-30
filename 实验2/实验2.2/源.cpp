#include<iostream>
#include<cmath>
using namespace std;

class Point {
public:
	Point() { x = 0; y = 0; }
	Point(double xv, double yv) { x = xv; y = yv; }
	Point(Point& pt) { x = pt.x;  y = pt.y; }
	double range(Point& pt) {
		return sqrt((this->x - pt.x) * (this->x - pt.x) + (this->y - pt.y) * (this->y - pt.y));
	}
	double getx() { return x; }
	double gety() { return y; }
	double Area() { return 0; }
	void Show() { cout << "x=" << x << ' ' << "y=" << y << endl; }
private:
	double x, y;
};

class Rectangle:private Point {
public:
	Rectangle(double x = 0.0,double y = 0.0,double l = 0.0,double w = 0.0)
		:Point(x,y),length(l),width(w){}
	void show() {
		cout << "���϶���Ϊ��";
		Point::Show();
		cout << "��Ϊ��" << length << "��Ϊ��" << width << endl;
	}
	//[������]	ifInsideRectangle
	//[����]		�жϵ��ھ����ڣ���Ե�����ⲿ��
	//[����]		Point &pt����pt
	//[����ֵ]	void  ��OKΪ0���ڲ���1�ڱ�Ե��2���ⲿ��
	void ifInsideRectangle(Point& pt) {
		int OK = 1;
		if (pt.getx() < getx() || pt.getx() > getx() + length 
			|| pt.gety() > gety() || pt.gety() < gety() - width) {
			OK = 2;		//��ʱ���ھ����ⲿ��
		}
		if (pt.getx() > getx() && pt.getx() < getx() + length
			&& pt.gety() < gety() && pt.gety() > gety() - width) {
			OK = 0;		//��ʱ���ھ����ڲ���
		}
		if (OK == 0) {
			cout << "���ھ����ڲ�" << endl;
		}
		else if (OK == 1) {
			cout << "���ھ��α�Ե" << endl;
		}
		else {
			cout << "���ھ����ⲿ" << endl;
		}
	}
private:
	double length, width;
};

class Circle :private Point {
public:
	Circle(double x = 0.0,double y = 0.0,double r = 0.0):Point(x,y),radius(r){}
	void show() {
		cout << "Բ��Ϊ��";
		Point::Show();
		cout << "�뾶Ϊ��" << radius << endl;
	}
	//[������]	ifInsideCircle
	//[����]		�жϵ���Բ�ڣ���Ե�����ⲿ��
	//[����]		Point &pt����pt
	//[����ֵ]	void  ��OKΪ0���ڲ���1�ڱ�Ե��2���ⲿ��
	void ifInsideCircle(Point& pt) {
		int OK = 2;
		if (this->range(pt) == radius) {
			OK = 1;
		}
		if (this->range(pt) < radius) {
			OK = 0;
		}
		if (OK == 0) {
			cout << "����Բ�ڲ�" << endl;
		}
		else if (OK == 1) {
			cout << "����Բ��Ե" << endl;
		}
		else {
			cout << "����Բ�ⲿ" << endl;
		}
	}
private:
	double radius;	//�뾶
};


int main() {
	Point pt1(3, 1);
	Point pt2(1, -1);
	Point pt3(2, 0);
	Rectangle r1(0, 0, 4, 3);
	r1.show();
	r1.ifInsideRectangle(pt1);		//����
	r1.ifInsideRectangle(pt2);		//����
	r1.ifInsideRectangle(pt3);		//����
	Circle c1(0, 0, 2);
	c1.show();
	c1.ifInsideCircle(pt1);		//����
	c1.ifInsideCircle(pt2);		//����
	c1.ifInsideCircle(pt3);		//����
	return 0;
}