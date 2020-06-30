#include"MyClass.h"
MyClass::MyClass(int a, int b) :x(a), y(b) {};
void MyClass::print() {
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
};  
void MyClass::setX(int a) {
    x = a;
}
void MyClass::setY(int a) {
    y = a;
}