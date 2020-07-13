#include"date.h"

int CommonYear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };		
//平年每月天数,如果是闰年则：CommonYear[1] = 29

//[函数]		isLeapYear
//[功能]		判断是否是闰年
//[参数]		int year：年份
//[返回]		true:是闰年false:否
bool isLeapYear(int year) {
	bool OK = 1;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) OK = 1;
	else OK = 0;
	return OK;
}

//[函数]		date::date（构造函数）
//[功能]		构造函数，能判断输入的信息是否非法。
//[参数]		y：年份		m：月份		d：日期
//[返回]		void
date::date(int y, int m, int d) :year(y), month(m), day(d) {
	if (isLeapYear(y)) CommonYear[1] = 29;		//判断当前年是否是闰年
	else CommonYear[1] = 28;
	if (y == -1 && m == -1 && d == -1) {
		year = 0; month = 0; day = 0;		//便于calTime中的构造函数使用
	}
	else if (m < 1 || m > 12 || d < 1 || d > CommonYear[m - 1]) {
		cout << "日期非法！已设置为0001年1月1日！" << endl;
		year = 1; month = 1; day = 1;		//设置为指定日期
	}
}

//[函数]		date::date（复制构造函数）
//[功能]		复制构造函数
//[参数]		date& dat
//[返回]		void
date::date(date& dat) {
	this->year = dat.year;
	this->month = dat.month;
	this->day = dat.day;
}

//[函数]		date::setYear
//[功能]		设置年份
//[参数]		int y ：年份；
//[返回]		void
void date::setYear(int y) {
	if (y < 1) {
		cout << "年份设置非法！请重新设置！" << endl;
		return;
	}
	else {
		year = y;
	}
}

//[函数]		date::setMonth
//[功能]		设置月份
//[参数]		int m ：月份；
//[返回]		void
void date::setMonth(int m) {
	if (m < 1 || m > 12) {
		cout << "月份设置非法！请重新设置！" << endl;
		return;
	}
	else {
		month = m;
	}
}

//[函数]		date::setDay
//[功能]		设置日期
//[参数]		int d ：日期；
//[返回]		void
void date::setDay(int d) {
	if (d < 1 || d > CommonYear[month - 1]) {
		cout << "日期设置非法！请重新设置！" << endl;
		return;
	}
	else {
		day = d;
	}
}

//[函数]		date::showDate（复制构造函数）
//[功能]		打印输出年月日
//[参数]		void
//[返回]		void
void date::showDate() {
	cout << "今日日期为：" << year << "年" << month << "月" << day << "日" << endl;
}
 
//[函数]		date::重载运算符-
//[功能]		重载运算符-，用以实现计算两个date对象之间所差天数
//[参数]		date& b：进行减法运算的对象
//[返回]		int：返回所减天数
int date::operator - (date& b) {		//支持自动比较两个日期大小返回差值
	int count = 0;
	date high;		//high为两日期中较大的
	date temp;		//temp为两日期中较小的
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
                                                                                                                                                                                                                                                                                                   
//[函数]		date::normal
//[功能]		进位函数用以对进位进行改变
//[参数]		int oper	：oper为1则是加法，oper为0则是减法
//[返回]		void
date date::normal(int oper, int days) {
	date temp(*this);
	if (oper == 1) {
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
	}
	 if (oper == 0) {
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
	}
	*this = temp;
	return temp;
}

//[函数]		date::重载运算符+
//[功能]		重载运算符+，用以实现对对象date加上任意天数。
//[参数]		int days：总共所加天数
//[返回]		date型的对象，用以返回数据
date date::operator + (int days) {
	this->normal(1, days);
	return *this;
}

//[函数]		date::重载运算符-
//[功能]		重载运算符-，用以实现对对象date减去任意天数。
//[参数]		int days：总共所减天数
//[返回]		date型的对象，用以返回数据
date date::operator - (int days) {
	this->normal(0, days);
	return *this;
}

//[函数]		date::重载运算符 前置自减--
//[功能]		重载运算符--，用以实现对对象date自减1天
//[参数]		调用重载运算符-进行减1天。
//[返回]		date型的对象，用以返回数据
date date::operator -- (){
	*this = *this - 1;
	return *this;
}

//[函数]		date::重载运算符 后置自减--
//[功能]		重载运算符--，用以实现对对象date自减1天，但返回未自减的值
//[参数]		调用重载运算符-进行减1天。
//[返回]		date型的对象temp，用以返回未自减时的数据
date date::operator -- (int) {
	date temp(*this);
	*this = *this - 1;
	return temp;
}

//[函数]		date::重载运算符 前置自加++
//[功能]		重载运算符++，用以实现对对象date自加1天
//[参数]		调用重载运算符+进行加1天。
//[返回]		date型的对象，用以返回数据
date date::operator ++ () {
	*this = *this + 1;
	return *this;
}

//[函数]		date::重载运算符 后置自加++
//[功能]		重载运算符++，用以实现对对象date自加1天，但返回未自加的值
//[参数]		调用重载运算符+进行加1天。
//[返回]		date型的对象temp，用以返回未自加时的数据
date date::operator ++ (int) {
	date temp(*this);
	*this = *this + 1;
	return temp;
}