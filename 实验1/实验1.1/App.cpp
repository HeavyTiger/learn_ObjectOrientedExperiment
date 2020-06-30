#include"MyClass.h"
int main() {
	MyClass obj1, obj2(5, 8);
	obj1.setX(1);
	obj1.setY(3);
	obj1.print();
	obj2.print();
	return 0;
}