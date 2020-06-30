#pragma once
#include<iostream>
using namespace std;
class rectangle {
public:
	rectangle(float a = 0, float b = 0):length(a),width(b){}
	void setLength(float a) {
		length = a;
	}
	void setWidth(float a) {
		width = a;
	}
	void getSize() {
		size = length * width;
		
	}
	void getPerimeter() {
		perimeter = 2 * (length + width);
	}
	void print() {
		cout << "�ܳ�Ϊ��" << perimeter << endl;
		cout << "���Ϊ��" << size << endl << endl;
	}
private:
	float length, width;
	float size,perimeter;
};