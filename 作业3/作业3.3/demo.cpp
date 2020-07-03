#include<iostream>
using namespace std;
template<class T>
void show(T a[], int size) {
	cout << "前" << size << "项已经排序完成，结果为：" << endl;
	for (int i = 0; i < size; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;
}
template<class T>
void sort(T a[], int size) {
	T temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	show(a, size);
}

int main() {
	int arr1[] = { 7,2,4,5,7,9,10,14,6,3,1 };
	double arr2[] = { 1.7,6.5,3.4,2.5,6.3,2.6,7.3,5.4,3.2,2.7,6.0 };
	sort(arr1, 7);
	sort(arr2, 9);
	return 0;
}