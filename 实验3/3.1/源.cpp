#include<iostream>
#include<cmath>
#define PI 3.1415926
using namespace std;

class Geometric_shape {
protected:
	double Perimeter = 0.0, Area = 0.0,Volumn = 0.0;
public:
	virtual double perimeter() { return Perimeter; }
	virtual double area() { return Area; }
	virtual double volumn() { return Volumn; }
	virtual void show() {};
};

class Rectangle :public Geometric_shape {
protected:
	double length, width;
public:
	Rectangle(double l = 0.0,double w = 0.0)
		:length(l),width(w){}
	virtual void show() {
		cout << "���εĳ�Ϊ��" << length << ",��Ϊ��" << width;
	}
	virtual double perimeter() {
		Perimeter = 2 * (length + width);
		return Perimeter; 
	}
	virtual double area() { 
		Area = length * width;
		return Area; 
	}
	virtual double volumn() { 
		Volumn = 0.0;
		return Volumn; 
	}
};

class Box :public Rectangle {
protected:
	double height;
public:
	Box(double l = 0.0, double w = 0.0,double h = 0.0)
		:Rectangle(l,w),height(h) {}
	void show() {
		cout << "������ĳ�Ϊ��" << length << ",��Ϊ��" << width << ",��Ϊ��" << height;
	}
	double perimeter() {
		Perimeter = 2 * (length + width);
		return Perimeter;
	}
	double area() {
		Area = length * width;
		return Area;
	}
	double volumn() {
		Volumn = this->area() * height;
		return Volumn;
	}
};

class Circle :public Geometric_shape {
protected:
	double radius;
public:
	Circle(double r = 0.0):radius(r) {}
	virtual void show() {
		cout << "Բ�εİ뾶Ϊ��" << radius;
	}
	virtual double perimeter() {
		Perimeter = 2 * PI * radius;
		return Perimeter;
	}
	virtual double area() {
		Area = PI * radius * radius;
		return Area;
	}
	virtual double volumn() {
		Volumn = 0.0;
		return Volumn;
	}
};

class Cylinder :public Circle {
protected:
	double height;
public:
	Cylinder(double r = 0.0,  double h = 0.0)
		:Circle(r), height(h) {}
	void show() {
		cout << "Բ���ĵײ�Բ�뾶Ϊ��" << radius << ",��Ϊ��" << height;
	}
	double perimeter() {
		Perimeter = 2 * PI * radius;
		return Perimeter;
	}
	double area() {
		Area = PI * radius * radius;
		return Area;
	}
	double volumn() {
		Volumn = this->area() * height;
		return Volumn;
	}
};

class Cone :public Circle {
protected:
	double height;
public:
	Cone(double r = 0.0, double h = 0.0)
		:Circle(r), height(h) {}
	void show() {
		cout << "Բ׶�ĵײ�Բ�뾶Ϊ��" << radius << ",��Ϊ��" << height;
	}
	double perimeter() {
		Perimeter = 2 * PI * radius;
		return Perimeter;
	}
	double area() {
		Area = PI * radius * radius;
		return Area;
	}
	double volumn() {
		Volumn = (1.0 / 3) * this->area() * height;
		return Volumn;
	}
};

class Triangle :public Geometric_shape {
protected:
	double line1,line2,line3;
	double p;
public:
	Triangle(double l1 = 0.0, double l2 = 0.0, double l3 = 0.0)
		: line1(l1), line2(l2), line3(l3) {
		p = (l1 + l2 + l3 ) / 2.0;
	}
	virtual void show() {
		cout << "�����εı߳��ֱ�Ϊ��" << line1 << "," << line2 << "," << line3;
	}
	virtual double perimeter() {
		Perimeter = 2 * p;
		return Perimeter;
	}
	virtual double area() {
		Area = sqrt(p * (p - line1) * (p - line2) * (p - line3));
		return Area;
	}
	virtual double volumn() {
		Volumn = 0.0;
		return Volumn;
	}
};



class T_prism :public Triangle {
protected:
	double height;
public:
	T_prism(double l1 = 0.0, double l2 = 0.0, double l3 = 0.0, double h = 0.0)
		:Triangle(l1, l2, l3), height(h) {}
	void show() {
		cout << "�������ĵױ߳��ֱ�Ϊ��" << line1 << "," << line2 << "," << line3 << ",��Ϊ��" << height;
	}
	double perimeter() {
		Perimeter = Triangle::perimeter();
		return Perimeter;
	}
	double area() {
		Area = Triangle::area();
		return Area;
	}
	double volumn() {
		Volumn = this->area() * height;
		return Volumn;
	}
};

class T_pyramid :public Triangle {
protected:
	double height;
public:
	T_pyramid(double l1 = 0.0, double l2 = 0.0, double l3 = 0.0, double h = 0.0)
		:Triangle(l1, l2, l3), height(h) {}
	void show() {
		cout << "����׶�ĵױ߳��ֱ�Ϊ��" << line1 << "," << line2 << "," << line3 << ",��Ϊ��" << height;
	}
	double perimeter() {
		Perimeter = Triangle::perimeter();
		return Perimeter;
	}
	double area() {
		Area = Triangle::area();
		return Area;
	}
	double volumn() {
		Volumn = (1.0 / 3) * this->area() * height;
		return Volumn;
	}
};

int main()
{
	Geometric_shape* gs[] = { new Circle(10),
		new  Rectangle(6,8),new Triangle(3,4,5),
		new Box(6,8,3),new Cylinder(10,3),
		new  Cone(10,3),new T_pyramid(3,4,5,3),
		new T_prism(3,4,5,3) };
	for (int i = 0; i < 8; i++) {
		gs[i]->show();
		cout << endl;
	}
	cout << "ƽ��ͼ�Σ�" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "ͼ���ܳ���" << gs[i]->perimeter() << '\t'; 
		cout << "ͼ�������" << gs[i]->area() << '\t'; 
		cout << "ͼ�������" << gs[i]->volumn() << endl;
	}
	cout << "����ͼ�Σ�"<<endl; 
	for (int i = 3; i < 8; i++) {
		cout << "ͼ�ε��ܳ���" << gs[i]->perimeter() << '\t';
		cout << "ͼ�ε������" << gs[i]->area() << '\t'; 
		cout << "ͼ�����  ��" << gs[i]->volumn() << endl;
	}
	return 0;
}