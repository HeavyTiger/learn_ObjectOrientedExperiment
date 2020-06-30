#include<iostream>
using namespace std;

class Complex {
private:
	double real, unreal;
public:
	Complex(double rl = 0.0 , double url = 0.0)
		:real(rl),unreal(url){}
	
	void show() {
		if (unreal > 0) {
			cout << "复数为 " << real << "+" << unreal << "i" << endl;
		}
		else if (unreal == 0) {
			cout << "复数为 " << real << endl;
		}
		else {
			cout << "复数为 " << real << unreal << "i" << endl;
		}
		
	}

	Complex operator + (Complex c1) {
		c1.real += this->real;
		c1.unreal += this->unreal;
		return c1;
	}
	Complex operator + (double d1) {
		this->real += d1;
		return *this;
	}
	Complex operator - (Complex c1) {
		this->real -= c1.real;
		this->unreal -= c1.unreal;
		return *this;
	 }
	Complex operator - (double d1) {
		this->real -= d1;
		return *this;
	 }
};


int main() {
	Complex c1(6, 7), c2(7, 8);
	Complex temp;
	temp = c1 + c2;
	temp.show();
	temp = c1 - c2;
	temp.show();
	return 0;
}