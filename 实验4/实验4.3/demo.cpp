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

//[函数名]		saveToFile
//[功能]		将文件信息传入二进制文本
//[参数]		void
//[返回值]		void
void saveToFile() {
	ofstream outfile;
	outfile.open("student.data", ios::out | ios::app | ios::binary);
	if (!outfile) {
		cout << "文本打开失败！" << endl;
		abort();
	}
	Student temp;
	int count;		//记录需要读取的学生人数
	cout << "输入数据" << endl << "学生人数：";
	cin >> count;
	for (int i = 0; i < count; i++) {
		cout << "第" << i + 1 << "个学生";
		temp.getData();
		outfile.write((char*)&temp, sizeof(temp));
	}
	outfile.close();
}
//[函数名]		readFile
//[功能]		读取文件中的信息，并输出在命令指示符中
//[参数]		void
//[返回值]		void
void readFile() {
	ifstream infile;
	infile.open("student.data", ios::in | ios::binary);
	if (!infile) {
		cout << "文本打开失败！" << endl;
		abort();
	}
	Student temp;
	cout << "输出数据" << endl << "学号      " << "姓名      " << "成绩" << endl;
	infile.read((char*)&temp, sizeof(temp));
	while (infile) {
		temp.show();
		infile.read((char*)&temp, sizeof(temp));
	}
	infile.close();
}
//[函数名]		compare
//[功能]		匹配学生信息
//[参数]		void
//[返回值]		void
void compare() {
	char name[10];
	cout << "请输入姓名（支持模糊查询）：";
	cin >> name;
	
	ifstream infile;
	infile.open("student.data", ios::in | ios::binary);
	if (!infile) {
		cout << "文本打开失败！" << endl;
		abort();
	}
	Student temp;
	int count = 0;
	cout << "查询到的结果：" << endl;
	infile.read((char*)&temp, sizeof(temp));
	while (infile) {
		if (strstr(temp.getName(), name) != NULL) {
			temp.show();
			count++;
		}
		infile.read((char*)&temp, sizeof(temp));
	}
	cout << "共" << count << "个数据" << endl;
	infile.close();
}

int main() {
	int nSelect;
	do {
		cout << "选择：（1.输入数据 2.输出数据 3.按姓名查找 其他退出）：";
		cin >> nSelect;
		switch (nSelect) {
		case 1:saveToFile(); break;
		case 2:readFile(); break;
		case 3:compare(); break;
		}
	} while (nSelect == 1 || nSelect == 2 || nSelect == 3);
	return 0;
}