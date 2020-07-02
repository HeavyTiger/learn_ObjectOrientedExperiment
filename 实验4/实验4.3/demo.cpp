#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class Student {
public:
	void getData() {
		cin >> number >> name >> score;
	}
	void show() {
		cout << setiosflags(ios::left) << setw(10) << number << setw(10) << name << setw(10) << score << endl;
	}
	char* getName() {
		return name;
	}
private:
	int number;
	char name[10];
	int score;
};

//[������]		saveToFile
//[����]		���ļ���Ϣ����������ı�
//[����]		void
//[����ֵ]		void
void saveToFile() {
	ofstream outfile;
	outfile.open("student.data", ios::out | ios::app | ios::binary);
	if (!outfile) {
		cout << "�ı���ʧ�ܣ�" << endl;
		abort();
	}
	Student temp;
	int count;		//��¼��Ҫ��ȡ��ѧ������
	cout << "��������" << endl << "ѧ��������";
	cin >> count;
	for (int i = 0; i < count; i++) {
		cout << "��" << i + 1 << "��ѧ��";
		temp.getData();
		outfile.write((char*)&temp, sizeof(temp));
	}
	outfile.close();
}
//[������]		readFile
//[����]		��ȡ�ļ��е���Ϣ�������������ָʾ����
//[����]		void
//[����ֵ]		void
void readFile() {
	ifstream infile;
	infile.open("student.data", ios::in | ios::binary);
	if (!infile) {
		cout << "�ı���ʧ�ܣ�" << endl;
		abort();
	}
	Student temp;
	cout << "�������" << endl << "ѧ��      " << "����      " << "�ɼ�" << endl;
	infile.read((char*)&temp, sizeof(temp));
	while (infile) {
		temp.show();
		infile.read((char*)&temp, sizeof(temp));
	}
	infile.close();
}
//[������]		compare
//[����]		ƥ��ѧ����Ϣ
//[����]		void
//[����ֵ]		void
void compare() {
	char name[10];
	cout << "������������֧��ģ����ѯ����";
	cin >> name;
	
	ifstream infile;
	infile.open("student.data", ios::in | ios::binary);
	if (!infile) {
		cout << "�ı���ʧ�ܣ�" << endl;
		abort();
	}
	Student temp;
	int count = 0;
	cout << "��ѯ���Ľ����" << endl;
	infile.read((char*)&temp, sizeof(temp));
	while (infile) {
		if (strstr(temp.getName(), name) != NULL) {
			temp.show();
			count++;
		}
		infile.read((char*)&temp, sizeof(temp));
	}
	cout << "��" << count << "������" << endl;
	infile.close();
}

int main() {
	int nSelect;
	do {
		cout << "ѡ�񣺣�1.�������� 2.������� 3.���������� �����˳�����";
		cin >> nSelect;
		switch (nSelect) {
		case 1:saveToFile(); break;
		case 2:readFile(); break;
		case 3:compare(); break;
		}
	} while (nSelect == 1 || nSelect == 2 || nSelect == 3);
	return 0;
}