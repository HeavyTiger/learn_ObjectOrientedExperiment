#include<iostream>
using namespace std;

int CommonYear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };		//平年每月天数,闰年CommonYear[1] = 29

//[函数名]		isLeapYear
//[功能]		判断是否是闰年
//[参数]		int year：年份
//[返回值]		true:是闰年false:否
bool isLeapYear(int year) {
	bool OK = 1;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) OK = 1;
	else OK = 0;
	return OK;
}

class Date {
public:
	Date(int y = 0, int m = 1, int d = 1) :year(y), month(m), day(d) {
		if (isLeapYear(y)) CommonYear[1] = 29;		//判断当前年是否是闰年
		else CommonYear[1] = 28;
		if (m < 1 || m > 12 || d < 1 || d > CommonYear[m - 1]) {
			cout << "日期非法！" << endl;
			abort();
		}
	}
	Date(Date& dat) {
		this->year = dat.year;
		this->month = dat.month;
		this->day = dat.day;
	}
	void showDate() {
		cout << "日期为:" << year << "年" << month << "月" << day << "日" << endl;
	}
	Date operator + (int days);
	Date operator - (int days);
	int operator - (Date& b);
private:
	int  year,month,day;
};

int Date::operator - (Date& b) {		//支持自动比较两个日期大小返回差值
	int count = 0;
	Date high;		//high为两日期中较大的
	Date temp;		//temp为两日期中较小的
	bool OK = 1;		//1为b在*this的日期之前。如this（2001，8，30），b（2000，1，1）。0相反
	int y, m, d;
	//判断二者先后
	y = this->year - b.year;		//若b在this之前，此值为正
	m = this->month - b.month;
	d = this->day - b.day;
	if (y < 0) OK = 0;
	if (y == 0 && m < 0) OK = 0;
	if (y == 0 && m == 0 && d < 0)OK = 0;
	if (y == 0 && m == 0 && d == 0) {
		return 0;
	}
	if (OK == 1) { temp = b; high = *this; }
	else { temp = *this; high = b; }
	//进行计数；
	if (isLeapYear(temp.year)) CommonYear[1] = 29;		//判断当前年是否是闰年
	else CommonYear[1] = 28;
	while (temp.year != high.year || temp.month != high.month || temp.day != high.day) {
		if (temp.day < CommonYear[temp.month - 1]) {		//天数小于当前月份天数，可以自加
			temp.day++;		//日期自加1
			count++;		//相差天数自加1
		}
		else if (temp.day == CommonYear[temp.month - 1] && temp.month != 12) {		//非12月的月底
			temp.month++;
			temp.day = 1;
			count++;
		}
		else if (temp.day == CommonYear[temp.month - 1] && temp.month == 12) {		//12月月底
			temp.year++;
			temp.month = 1;
			temp.day = 1;
			count++;
			if (isLeapYear(temp.year)) CommonYear[1] = 29;		//判断今年（下一年）是否是闰年
			else CommonYear[1] = 28;
		}
	}
	return count;
}

Date Date::operator + (int days) {
	Date temp(*this);
	if (isLeapYear(temp.year)) CommonYear[1] = 29;		//判断当前年是否是闰年
	else CommonYear[1] = 28;
	while (days > 0) {
		if (temp.day < CommonYear[temp.month - 1]) {		//天数小于当前月份天数，可以自加
			temp.day++;		//日期自加1
			days--;		//需要天数自减1
		}
		else if (temp.day == CommonYear[temp.month - 1] && temp.month != 12) {		//非12月的月底
			temp.month++;
			temp.day = 1;
			days--;
		}
		else if (temp.day == CommonYear[temp.month - 1] && temp.month == 12) {		//12月月底
			temp.year++;
			temp.month = 1;
			temp.day = 1;
			days--;
			if (isLeapYear(temp.year)) CommonYear[1] = 29;		//判断今年（下一年）是否是闰年
			else CommonYear[1] = 28;
		}
	} 
	return temp;
}

Date Date::operator - (int days) {
	Date temp(*this);
	if (isLeapYear(temp.year)) CommonYear[1] = 29;		//判断当前年是否是闰年
	else CommonYear[1] = 28;
	while (days > 0) {
		if (temp.day > 1) {		//天数大于1天，可以自减
			temp.day--;		//日期自减1
			days--;		//需要天数自减1
		}
		else if (temp.day == 1 && temp.month != 1) {		//非一月初
			temp.month--;		//月份自减1
			temp.day = CommonYear[temp.month - 1];		//日期变为当前（前一个月）月的总天数
			days--;
		}
		else if (temp.day == 1 && temp.month == 1) {		//一月初
			temp.year--;
			temp.month = 12;
			temp.day = 31;
			days--;
			if (isLeapYear(temp.year)) CommonYear[1] = 29;		//判断今年（下一年）是否是闰年
			else CommonYear[1] = 28;
		}
	}
	return temp;
}

int main() {
	int y1, m1, d1, y2, m2, d2;
	cout << "请输入date1的参数(年 月 日):";
	cin >> y1 >> m1 >> d1;
	cout << "请输入date2的参数(年 月 日):";
	cin >> y2 >> m2 >> d2;
	Date dat1(y1, m1, d1),dat2(y2,m2,d2);
	Date dat3;
	int nSelect,days;
	cout << "请选择功能:" << endl << "1.返回Date1加天数days后得到的日期" << endl <<
		"2.返回Date1减去天数days后得到的日期" << endl << "3.返回两日期相差的天数" << endl << "其他数字键退出" << endl;
	cin >> nSelect;
	switch (nSelect) {
		case 1: {
			cout << "请输入天数days:";
			cin >> days;
			dat3 = dat1 + days;
			dat3.showDate();
			break;
		}
		case 2: {
			cout << "请输入天数days:";
			cin >> days;
			dat3 = dat1 - days;
			dat3.showDate();
			break;
		}
		case 3: {
			int count;
			count = dat1 - dat2;
			cout << "相差" << count << "天";
			break;
		}
	}
	return 0;
}