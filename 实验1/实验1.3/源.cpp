#include<iostream>
using namespace std;
class IntArray {
public:
	~IntArray();		//析构函数

	IntArray(int sz = 0, int* Array = nullptr);

	int* getArray() {
		return ia;
	}
	int getSize() {
		return size;
	}

	void printAll();

private:
	int* ia;
	int size;
};
IntArray::~IntArray() {
	if (ia != nullptr) {
		delete ia;
	}
	else {
		cout << "数组为空！" << endl;
	}
}

IntArray::IntArray(int sz,int* Array) {
	if (Array == nullptr) {
		size = sz;
		ia = new int[size];
		for (int i = 0; i < size; i++) {
			ia[i] = 0;
		}
	}

	else {
		size = sz;
		ia = new int[size];
		for (int i = 0; i < size; i++) {
			ia[i] = Array[i];
		}
	}
}



void IntArray::printAll() {
	for (int i = 0; i < size; i++)
		cout << ia[i] << "  ";
	cout << endl;
}

int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	IntArray arr1(10), arr2(5,a), arr3(arr2.getSize(),arr2.getArray());
	arr1.printAll();
	arr2.printAll();
	arr3.printAll();
	return 0;
}
