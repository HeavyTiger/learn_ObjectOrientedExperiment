#pragma once
#include<iostream>
using namespace std;
class MyClass {
public:
	MyClass(int a = 0, int b = 0);
	void print();
	void setX(int a);
	void setY(int a);
private:
	int x,y;
};