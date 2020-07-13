#pragma once
#include"date.h"
class DateTime :public date {
public:
	DateTime(int y = 1, int m = 1, int d = 1, int h = 0, int min = 0, int sec = 0);
	DateTime(DateTime& dat);
	DateTime operator +(DateTime& dat);
	DateTime operator -(DateTime& dat);
	DateTime normalForm(int n);		//将this转换成标准形式
	void show();
private:
	int hour, minute, second;
};