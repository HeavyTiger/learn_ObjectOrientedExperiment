#include"calendar.h"
//[函数]		calendar
//[功能]		提供日历相关操作
//[参数]		void
//[返回]		void
void calendar() {
	int y, m;
	system("cls");
	cout << "**********************日历**********************" << endl;
	cout << "请选择需要输出日历的年份及月份(如2019 6):";
	cin >> y >> m;
	cin.clear();
	cin.sync();
	CDate temp(y, m);
	temp.display();
	cout << "************************************************" << endl;
	system("pause");
	system("cls");
}