#include"calTime.h"

//[函数]		calTime
//[功能]		提供使用时间计算器
//[参数]		void
//[返回]		void
void calTime() {
	int nSelection;
	int y, m, d, h, min, sec;
	system("cls");
	cout << "**********************时 间 计 算 器**********************" << endl;
	cout << "请输入需要操作的时间(如2020 7 8 23 59 59):";
	cin >> y >> m >> d >> h >> min >> sec;
	cin.clear();		//清空缓冲区
	cin.sync();
	DateTime start(y, m, d, h, min, sec);
	start.show();
	cout << "**********************************************************" << endl;
	cout << "请选择功能(1.增加时间  2.减少时间  其他数字键返回):";
	cin >> nSelection;
	cin.clear();		//清空缓冲区
	cin.sync();
	if (nSelection == 1) {		//增加时间
		cout << "请指定增或减的时间(如23 59 59,支持溢出自动进位):";
		cin >> h >> min >> sec;
		if (h < 0 || min < 0 || sec < 0) {
			cout << "时间指定时出现负数！错误！" << endl;
			system("pause");
			system("cls");
			return; 
		}
		else {
			DateTime temp(-1, -1, -1, h, min, sec);		//便于构造date时将参数设置为0；
			start = start + temp;
			start.show();
			system("pause");
			system("cls");
			return;
		}
	}
	else if (nSelection == 2) {		//减少时间
		cout << "请指定减少时间(如23 59 59,支持溢出自动进位):";
		cin >> h >> min >> sec;
		if (h < 0 || min < 0 || sec < 0) {
			cout << "时间指定时出现负数！错误！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			DateTime temp(-1, -1, -1, h, min, sec);		//便于构造date时将参数设置为0；
			start = start - temp;
			start.show();
			system("pause");
			system("cls");
			return;
		}
	}
	else return;
	return;
}