#include<iostream>
#include<iomanip>
using namespace std;

class telephone {
public:
	friend ostream &operator << (ostream &output, telephone &tel);
	friend istream &operator >> (istream &input, telephone &tel);
private:
	char front[4];
	char number[9];
};

ostream& operator << (ostream& output, telephone& tel) {
	output << "(" << tel.front<<")"<<tel.number;
	return output;
}
istream& operator >> (istream& input, telephone& tel) {
	input.ignore();
	input >> setw(4) >> tel.front;
	input.ignore(1);
	input >> setw(9) >> tel.number;
	return input;
}

int main() {
	telephone tel;
	cout << "������绰���룺";
	cin >> tel;
	cout <<"�̶��绰����Ϊ��"<< tel;
	return 0;
}