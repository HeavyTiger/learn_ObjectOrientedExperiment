#include"CDate.h"
#include"date.h"
int commonYear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//平年每月天数,如果是闰年则：CommonYear[1] = 29

//[函数]		CDate:CDate(构造函数)
//[功能]		构造函数，并判断第一天是星期几
//[参数]		int y,int m		倘若m为0代表firstDay为1年的开始
//[返回]		void
CDate::CDate(int y, int m):date(y,m,1){
	date temp(1, 1, 1);		//这天为星期一，具体可推算，我们要相信科学！！！
	this->firstDay = (*this - temp) % 7 + 1;
}
//[函数]		CDate:display
//[功能]		打印该月的日历
//[参数]		void
//[返回]		void
void CDate::display() {
	int count = 0;
	if (isLeapYear(this->year)) commonYear[1] = 29;		//判断当前年是否是闰年
	else commonYear[1] = 28;
	count = commonYear[this->month - 1];
	cout << this->year << "年" << this->month << "月日历" << endl;
	cout << std::left << setw(5) << "周一" << setw(5) << "周二" << setw(5) << "周三" << setw(5) << "周四"
		<< setw(5) << "周五" << setw(5) << "周六" << setw(5) << "周日" << endl;
	int i, j;
	for (i = 1; i < this->firstDay; i++) {
		cout << setw(5) <<" ";
	}
	for (j = 1; j <= count; j++) {
		cout << std::left <<  setw(5) << j;
		if ((this->firstDay + j - 1) % 7 == 0) {
			cout << endl;
		}
	}
	cout << endl;
}