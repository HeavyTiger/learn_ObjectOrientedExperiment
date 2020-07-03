#include<iostream>
using namespace std;
template<class T1,class T2>
class Test
{
public:
    void SetData1(T1 val);
    void SetData2(T2 val);
    T1 GetData1();
    T2 GetData2();
private:
    T1 data1;
    T2 data2;
};
template<class T1,class T2>
void Test<T1,T2>::SetData1(T1 val) { data1 = val; }
template<class T1,class T2>
void Test<T1, T2>::SetData2(T2 val) { data2 = val; }
template<class T1, class T2>
T1 Test<T1, T2>::GetData1() { return data1; }
template<class T1, class T2>
T2 Test<T1, T2>::GetData2() { return data2; }

int main() {
    Test<int,double> t;
    t.SetData1(13);
    t.SetData2(17.5);
    cout << "data1Îª£º" << t.GetData1() << endl;
    cout << "data2Îª£º" << t.GetData2() << endl;
    return 0;
}