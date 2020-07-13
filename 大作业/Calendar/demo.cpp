#include"calculagraph.h"
#include"calTime.h"
#include"calendar.h"
int main() {
	int nSelection = 0;
	while (1) {
		cout << "***********主菜单***********" << endl;
		cout << "1.使用计时器(倒计时或累计时)" << endl;
		cout << "2.使用派生类DateTime时间功能" << endl;
		cout << "3.使用派生类cDate日历功能" << endl;
		cout << "0.使用其他数字键退出程序" << endl;
		cout << "****************************" << endl;
		cout << "请选择使用的功能:";
		cin >> nSelection;
		cin.clear();
		cin.sync();
		switch (nSelection) {
			case 1:calculagraph(); break;
			case 2:calTime(); break;
			case 3:calendar(); break;
			default: return 0;
		}
	}
}