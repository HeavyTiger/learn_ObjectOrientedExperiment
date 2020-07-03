#include <iostream>
using namespace std;
class Complex
{
public:
    Complex(double re = 0, double im = 0):real(re), imag(im) {};
    //重载<<运算符实现输出复数
    friend ostream& operator <<(ostream& output, Complex& c);
    //重载>>运算符实现输入复数
    friend istream& operator >>(istream& input, Complex& c);

private:
    double real;//实部
    double imag;//虚部
};

istream& operator >>(istream& input, Complex& c)
{
    int a, b;
    char sign, i;
    do{
        cout << "请输入一个复数,以a+bi的形式输入:";
        input >> a >> sign >> b >> i;

    } while (!((sign ==  '+'|| sign == '-') && 'i' == i));
    c.real = a;
    c.imag = ('+' == sign) ? b : -b;
    return input;
}

ostream& operator <<(ostream& output, Complex& c)
{
    double num = c.imag;
    if (num > 0){
        output << c.real << "+" << c.imag << "i" << endl;
    }
    else{
        output << c.real << c.imag << "i" << endl;
    }
    return output;
}

int main(){
    Complex c1,c2;
    cin >> c1;
    cin >> c2;
    cout << c1;
    cout << c2;
    return 0;
}
