#include"DateTime.h"

//[����]		DateTime::normalForm
//[����]		��thisת��Ϊ24Сʱ���µı�׼��ʱ��
//[����]		int n:ȡ�����Ƿ���Ҫ��λ���£���λΪ1.����λΪ0��
//[����]		DateTime
DateTime DateTime::normalForm(int n) {
	int temp_day = 0 ,temp_hour = 0, temp_min = 0;
	if (this->second >= 0) {
		temp_min = this->second / 60;		//������Ҫ��λ��minute�ϵ�����
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
		if (n == 0) {	//������Ҫ��λ����ֱ�Ӽ�
			return *this;
		}
		else if (n == 1) {
			temp_day = this->hour / 24;
			this->hour %= 24;
			this->date::operator+(temp_day);		////ע�⣡�������������������������ǵò��������ܷ�ɹ�����////������ɹ���������
		}
	}
	else {
		int count = 1;		//count����ͳ����Ҫ�����첹λ��hour��
		while ((count * 24 + this->hour) < 0) {
			count++;
		}
		this->hour += (count * 24);		
		this->date::operator-(count);		//��ȥcount��
	}
	return *this;
}

//[����]		DateTime::DateTime�����캯����
//[����]		�������������ʱ����ı�׼ʱ�����������
//[����]		int y = 1, int m = 1, int d = 1, int h = 0, int min = 0, int sec = 0
//[����]		void
DateTime::DateTime(int y, int m, int d, int h, int min, int sec):date(y,m,d),hour(h),minute(min),second(sec) {
	if (y != -1 && m != -1 && d != -1) {
		this->normalForm(1);		//��Ҫ��λ
	}
}

//[����]		DateTime::DateTime�����ƹ��캯����
//[����]		�������������ʱ����ı�׼ʱ�����������
//[����]		DateTime& dat
//[����]		void
DateTime::DateTime(DateTime& dat){
	this->year = dat.year;
	this->month = dat.month;
	this->day = dat.day;
	this->hour = dat.hour;
	this->minute = dat.minute;
	this->second = dat.second;
}

//[����]		DateTime::show
//[����]		�������ʱ����Ϣ
//[����]		void
//[����]		void
void DateTime::show() {
	cout << "��������Ϊ��" << year << "��" << month << "��" << day << 
		"��" << hour << "ʱ" << minute << "��" << second << "��" << endl;
}

//[����]		DateTime::���������+
//[����]		���������+������ʵ�ּ�������DateTime��������֮��
//[����]		DateTime& dat:���мӷ�����Ķ���
//[����]		DateTime: ���ؼӷ��Ľ��
DateTime DateTime::operator +(DateTime& dat) {
	dat.normalForm(0);		//��ֹ�����������������λ
	this->hour += dat.hour;
	this->minute += dat.minute;
	this->second += dat.second;
	this->normalForm(1);		//��this��׼������λ
	return *this;
}

//[����]		DateTime::���������-
//[����]		���������-������ʵ�ּ�������DateTime��������֮��
//[����]		DateTime& dat:���м�������Ķ���
//[����]		DateTime: ���ؼӷ��Ľ��
DateTime DateTime::operator -(DateTime& dat) {
	dat.normalForm(0);		//��ֹ�����������������λ
	this->hour -= dat.hour;
	this->minute -= dat.minute;
	this->second -= dat.second;
	this->normalForm(1);		//��this��׼������λ
	return *this;
}