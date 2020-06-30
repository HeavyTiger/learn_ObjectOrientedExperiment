/*
2������һ��ͼ�λ��� Shape�������Ļ����������������� Rectangle
��Բ���� Circle�����Ƕ��м���������ܳ������ͼ����Ϣ�ȳ�Ա������
���� Rectangle ��Ļ������������������� Square��
��д������ɸ���Ķ����ʵ�֣��Լ����ʹ�á�
*/
#include<iostream>
using namespace std;

class Shape {
private:
	double x, y;		//���ϽǶ���
public:
	Shape() {};
	Shape(double rx = 0.0, double ry = 0.0) :x(rx),y(ry){}
	Shape(const Shape& tp) { this->x = tp.x; this->y = tp.y;}
	void setX(double rx) { x = rx; }
	void setY(double ry) { y = ry; }
	double getX() { return x; }
	double getY() { return y; }
};

class Rectangle :virtual protected Shape {
private:
	double length, width;
public:
	Rectangle(double rx, double ry, double l, double w):Shape(rx,ry),length(l),width(w){}
	void showSize() {
		cout<<"���Ϊ"<< length * width << endl;
	}
	double getLength() { return length; }
	void showPosition() {
		cout << "���ϽǶ���Ϊ(" << getX() << "," << getY() <<
			"),��Ϊ" << length << ",��Ϊ" << width << endl;
	}
};

class Circle :protected Shape {
private:
	double radius;
public:
	Circle(double rx, double ry, double r) :Shape(rx, ry), radius(r) {}
	void showSize() {
		cout << "���Ϊ" << 3.141592*radius*radius<< endl;
	}
	void showPosition() {
		cout << "Բ��Ϊ(" << getX() << "," << getY() <<
			"),�뾶Ϊ" << radius << endl;
	}
};

class Square :public Rectangle {
public:
	Square(double rx, double ry, double l) :Rectangle(rx, ry,l,l),Shape(rx, ry) {}
	void showSize() {
		Rectangle::showSize();
	}
	void showPosition() {
		cout << "���ϽǶ���Ϊ(" << getX() << "," << getY() <<
			"),��Ϊ" << getLength() << ",��Ϊ" << getLength() << endl;
	}
};

int main() {
	Rectangle r1(1, 3, 5.2, 7.9);
	Circle c1(1, 6, 9.2);
	Square s1(3, 7, 2.3);
	r1.showSize();
	r1.showPosition();
	c1.showSize();
	c1.showPosition();
	s1.showSize();
	s1.showPosition();
	return 0;
}