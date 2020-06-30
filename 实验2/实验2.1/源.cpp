#include <iostream> 
using namespace std; 

class Base 
{
public:
    Base(int p1, int p2): data1(p1), data2(p2) {}
      int Inc1() { return ++data1; }
      int Inc2() { return ++data2; }
      void Display()
      {
          cout << "data1 = " << data1 << " data2 = " << data2 << endl;
      }
protected:
    int data1, data2;
};


class D1 :virtual public Base {
public:
    D1(int p1, int p2, int p3) : Base(p1, p2) { data3 = p3; }   
    int Inc1() { return Base::Inc1(); }
    int Inc3() { return ++data3; }
    void Display()
    {
        cout << "data1 = " << data1 << " data2 = " << data2 
            << " data3 = " << data3 << endl;
        cout << "Base::Display() ----";
        Base::Display();
    }
protected:
    int data3;
};



class D2 :virtual public Base {
public:
    D2(int p1, int p2, int p4) : Base(p1, p2) { data4 = p4; }    
    int Inc1()
    {
        Base::Inc1();   Base::Inc2();
        return Base::Inc1();
    }
        int Inc4() { return ++data4; }    
        void Display()
        {
            cout << "data1 = " << data1 << " data2 = " << data2
                << " data4 = " << data4 << endl;
            cout << "Base::Display() ----";
            Base::Display();
        }
protected:
    int data4;
};



class D12 : public D1, public D2 {
public:
    D12(int p11, int p12, int p13, int p21, int p22, int p23, int p):D1(p11, p12, p13), D2(p21, p22, p23) ,Base(p11,p12){ data5 = p; }
    int Inc1() {
        D1::Inc1();
        D2::Inc1();
        return D1::Inc1();
    }
    int Inc5() { return ++data5; }
    void Display()
    {
        cout << "data1 = " << data1 << " data2 = " << data2 << endl; 
        cout << "data3 = " << data3 << " data4 = " << data4 << " data5 = " << data5 << endl;
        cout << "D1::Display( )----";
        D1::Display();
        cout << "D2::Display( )----";
        D2::Display();
    }
private:
    int data5;
};



int main() {
    D12 d(1, 2, 3, 4, 5, 6, 7);
    d.Display();
    cout << endl;
    d.Inc1();
    d.Inc2();
    d.Inc3();
    d.Inc4();
    d.Inc5();
    d.D12::Inc1();
    d.Display();
    return 0;
}