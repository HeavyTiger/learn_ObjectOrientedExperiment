/*
2．声明一个图形基类 Shape，在它的基础上派生出矩形类 Rectangle
和圆形类 Circle，它们都有计算面积和周长、输出图形信息等成员函数，
再在 Rectangle 类的基础上派生出正方形类 Square。
编写程序完成各类的定义和实现，以及类的使用。
*/
#include<iostream>
using namespace std;

class Shape {
private:
	double x, y;		//左上角顶点
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
		cout<<"面积为"<< length * width << endl;
	}
	double getLength() { return length; }
	void showPosition() {
		cout << "左上角顶点为(" << getX() << "," << getY() <<
			"),长为" << length << ",宽为" << width << endl;
	}
};

class Circle :protected Shape {
private:
	double radius;
public:
	Circle(double rx, double ry, double r) :Shape(rx, ry), radius(r) {}
	void showSize() {
		cout << "面积为" << 3.141592*radius*radius<< endl;
	}
	void showPosition() {
		cout << "圆心为(" << getX() << "," << getY() <<
			"),半径为" << radius << endl;
	}
};

class Square :public Rectangle {
public:
	Square(double rx, double ry, double l) :Rectangle(rx, ry,l,l),Shape(rx, ry) {}
	void showSize() {
		Rectangle::showSize();
	}
	void showPosition() {
		cout << "左上角顶点为(" << getX() << "," << getY() <<
			"),长为" << getLength() << ",宽为" << getLength() << endl;
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