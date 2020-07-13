#include"DateTime.h"

//[函数]		DateTime::normalForm
//[功能]		将this转换为24小时制下的标准的时间
//[参数]		int n:取决于是否需要进位到月，进位为1.不进位为0；
//[返回]		DateTime
DateTime DateTime::normalForm(int n) {
	int temp_day = 0 ,temp_hour = 0, temp_min = 0;
	if (this->second >= 0) {
		temp_min = this->second / 60;		//保存需要进位到minute上的秒数
		this->second %= 60;
		this->minute += temp_min;
	}
	else {
		this->second += 60;
		this->minute -= 1;
	}
	if (this->minute >= 0) {
		temp_hour = this->minute / 60;
		this->minute %= 60;
		this->hour += temp_hour;
	}
	else {
		this->minute += 60;
		this->hour -= 1;
	}
	if (this->hour >= 0) {
		if (n == 0) {	//若不需要进位，则直接加
			return *this;
		}
		else if (n == 1) {
			temp_day = this->hour / 24;
			this->hour %= 24;
			this->date::operator+(temp_day);		////注意！！！！！！！！！！！！！记得测试这里能否成功运行////结果：成功，嘻嘻！
		}
	}
	else {
		int count = 1;		//count用来统计需要减几天补位到hour上
		while ((count * 24 + this->hour) < 0) {
			count++;
		}
		this->hour += (count * 24);		
		this->date::operator-(count);		//减去count天
	}
	return *this;
}

//[函数]		DateTime::DateTime（构造函数）
//[功能]		构造包含年月日时分秒的标准时间派生类对象
//[参数]		int y = 1, int m = 1, int d = 1, int h = 0, int min = 0, int sec = 0
//[返回]		void
DateTime::DateTime(int y, int m, int d, int h, int min, int sec):date(y,m,d),hour(h),minute(min),second(sec) {
	if (y != -1 && m != -1 && d != -1) {
		this->normalForm(1);		//需要进位
	}
}

//[函数]		DateTime::DateTime（复制构造函数）
//[功能]		构造包含年月日时分秒的标准时间派生类对象
//[参数]		DateTime& dat
//[返回]		void
DateTime::DateTime(DateTime& dat){
	this->year = dat.year;
	this->month = dat.month;
	this->day = dat.day;
	this->hour = dat.hour;
	this->minute = dat.minute;
	this->second = dat.second;
}

//[函数]		DateTime::show
//[功能]		输出日期时间信息
//[参数]		void
//[返回]		void
void DateTime::show() {
	cout << "今日日期为：" << year << "年" << month << "月" << day << 
		"日" << hour << "时" << minute << "分" << second << "秒" << endl;
}

//[函数]		DateTime::重载运算符+
//[功能]		重载运算符+，用以实现计算两个DateTime对象数据之和
//[参数]		DateTime& dat:进行加法运算的对象
//[返回]		DateTime: 返回加法的结果
DateTime DateTime::operator +(DateTime& dat) {
	dat.normalForm(0);		//防止输入数据溢出，不进位
	this->hour += dat.hour;
	this->minute += dat.minute;
	this->second += dat.second;
	this->normalForm(1);		//将this标准化，进位
	return *this;
}

//[函数]		DateTime::重载运算符-
//[功能]		重载运算符-，用以实现计算两个DateTime对象数据之差
//[参数]		DateTime& dat:进行减法运算的对象
//[返回]		DateTime: 返回加法的结果
DateTime DateTime::operator -(DateTime& dat) {
	dat.normalForm(0);		//防止输入数据溢出，不进位
	this->hour -= dat.hour;
	this->minute -= dat.minute;
	this->second -= dat.second;
	this->normalForm(1);		//将this标准化，进位
	return *this;
}