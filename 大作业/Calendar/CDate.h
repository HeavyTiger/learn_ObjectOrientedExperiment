#pragma once
#include"date.h"
class CDate :public date {
public:
	CDate(int y = 1, int m = 1);
	void display();
private:
	int firstDay;		//����µĵ�һ��
};