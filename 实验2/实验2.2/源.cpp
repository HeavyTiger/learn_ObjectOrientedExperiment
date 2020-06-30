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
		cout << "左上顶点为：";
		Point::Show();
		cout << "长为：" << length << "宽为：" << width << endl;
	}
	//[函数名]	ifInsideRectangle
	//[功能]		判断点在矩形内，边缘还是外部。
	//[参数]		Point &pt：点pt
	//[返回值]	void  若OK为0在内部，1在边缘，2在外部；
	void ifInsideRectangle(Point& pt) {
		int OK = 1;
		if (pt.getx() < getx() || pt.getx() > getx() + length 
			|| pt.gety() > gety() || pt.gety() < gety() - width) {
			OK = 2;		//此时点在矩形外部：
		}
		if (pt.getx() > getx() && pt.getx() < getx() + length
			&& pt.gety() < gety() && pt.gety() > gety() - width) {
			OK = 0;		//此时点在矩形内部；
		}
		if (OK == 0) {
			cout << "点在矩形内部" << endl;
		}
		else if (OK == 1) {
			cout << "点在矩形边缘" << endl;
		}
		else {
			cout << "点在矩形外部" << endl;
		}
	}
private:
	double length, width;
};

class Circle :private Point {
public:
	Circle(double x = 0.0,double y = 0.0,double r = 0.0):Point(x,y),radius(r){}
	void show() {
		cout << "圆心为：";
		Point::Show();
		cout << "半径为：" << radius << endl;
	}
	//[函数名]	ifInsideCircle
	//[功能]		判断点在圆内，边缘还是外部。
	//[参数]		Point &pt：点pt
	//[返回值]	void  若OK为0在内部，1在边缘，2在外部；
	void ifInsideCircle(Point& pt) {
		int OK = 2;
		if (this->range(pt) == radius) {
			OK = 1;
		}
		if (this->range(pt) < radius) {
			OK = 0;
		}
		if (OK == 0) {
			cout << "点在圆内部" << endl;
		}
		else if (OK == 1) {
			cout << "点在圆边缘" << endl;
		}
		else {
			cout << "点在圆外部" << endl;
		}
	}
private:
	double radius;	//半径
};


int main() {
	Point pt1(3, 1);
	Point pt2(1, -1);
	Point pt3(2, 0);
	Rectangle r1(0, 0, 4, 3);
	r1.show();
	r1.ifInsideRectangle(pt1);		//在外
	r1.ifInsideRectangle(pt2);		//在内
	r1.ifInsideRectangle(pt3);		//在上
	Circle c1(0, 0, 2);
	c1.show();
	c1.ifInsideCircle(pt1);		//在外
	c1.ifInsideCircle(pt2);		//在内
	c1.ifInsideCircle(pt3);		//在上
	return 0;
}