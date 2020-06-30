#include<iostream>
#include<cmath>
using namespace std;

class myPoint {
public:
    myPoint(double x0, double y0) :x(x0), y(y0) {}   
    myPoint(myPoint& np) :x(np.x), y(np.y) {}   
    double GetX() { return x; }
    double GetY() { return y; }
    void SetX(double x0) { x = x0; }
    void SetY(double y0) { y = y0; }
    void SetPoint(double x0, double y0) { x = x0; y = y0; }   
    void SetPoint(myPoint& np) { x = np.x; y = np.y; }   
    double  GetLength(myPoint p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
void Printit() {
    cout << " (" << x << "," << y << ") "; 
}
private:
    double x, y;
};

class Triangle {
public:
    Triangle(double x1, double y1, double x2, double y2,
        double x3, double y3) :p1(x1, y1), p2(x2, y2), p3(x3, y3) {};
    double getPerimeter() {
        perimeter = p1.GetLength(p2) + p2.GetLength(p3) + p3.GetLength(p1);
        return perimeter;
    }
    double getSize() {
        double p = perimeter / 2.0;
        size = sqrt(p * (p - p1.GetLength(p2)) * (p - p2.GetLength(p3)) * (p - p3.GetLength(p1)));
        return size;
    }


private:
    myPoint p1, p2, p3;
    double size, perimeter;
};


int main() {
    double x1, y1, x2, y2, x3, y3;
    cout << "请依次输入三点的坐标参数（x，y）：" << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Triangle t1(x1, y1, x2, y2, x3, y3);
    cout << "周长为：" << t1.getPerimeter() << endl;
    cout << "面积为：" << t1.getSize() << endl;
    return 0;
}