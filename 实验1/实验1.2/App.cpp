#include"rectangle.h"
int main() {
	rectangle r1(20, 50), r2(3.6, 4.5);
	r1.getSize();
	r1.getPerimeter();
	r2.getSize();
	r2.getPerimeter();
	r1.print();
	r2.print();
	return 0;
}