#include<iostream>
using namespace std;

int CommonYear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };		//ƽ��ÿ������,����CommonYear[1] = 29

//[������]		isLeapYear
//[����]		�ж��Ƿ�������
//[����]		int year�����
//[����ֵ]		true:������false:��
bool isLeapYear(int year) {
	bool OK = 1;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) OK = 1;
	else OK = 0;
	return OK;
}

class Date {
public:
	Date(int y = 0, int m = 1, int d = 1) :year(y), month(m), day(d) {
		if (isLeapYear(y)) CommonYear[1] = 29;		//�жϵ�ǰ���Ƿ�������
		else CommonYear[1] = 28;
		if (m < 1 || m > 12 || d < 1 || d > CommonYear[m - 1]) {
			cout << "���ڷǷ���" << endl;
			abort();
		}
	}
	Date(Date& dat) {
		this->year = dat.year;
		this->month = dat.month;
		this->day = dat.day;
	}
	void showDate() {
		cout << "����Ϊ:" << year << "��" << month << "��" << day << "��" << endl;
	}
	Date operator + (int days);
	Date operator - (int days);
	int operator - (Date& b);
private:
	int  year,month,day;
};

int Date::operator - (Date& b) {		//֧���Զ��Ƚ��������ڴ�С���ز�ֵ
	int count = 0;
	Date high;		//highΪ�������нϴ��
	Date temp;		//tempΪ�������н�С��
	bool OK = 1;		//1Ϊb��*this������֮ǰ����this��2001��8��30����b��2000��1��1����0�෴
	int y, m, d;
	//�ж϶����Ⱥ�
	y = this->year - b.year;		//��b��this֮ǰ����ֵΪ��
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
	//���м�����
	if (isLeapYear(temp.year)) CommonYear[1] = 29;		//�жϵ�ǰ���Ƿ�������
	else CommonYear[1] = 28;
	while (temp.year != high.year || temp.month != high.month || temp.day != high.day) {
		if (temp.day < CommonYear[temp.month - 1]) {		//����С�ڵ�ǰ�·������������Լ�
			temp.day++;		//�����Լ�1
			count++;		//��������Լ�1
		}
		else if (temp.day == CommonYear[temp.month - 1] && temp.month != 12) {		//��12�µ��µ�
			temp.month++;
			temp.day = 1;
			count++;
		}
		else if (temp.day == CommonYear[temp.month - 1] && temp.month == 12) {		//12���µ�
			temp.year++;
			temp.month = 1;
			temp.day = 1;
			count++;
			if (isLeapYear(temp.year)) CommonYear[1] = 29;		//�жϽ��꣨��һ�꣩�Ƿ�������
			else CommonYear[1] = 28;
		}
	}
	return count;
}

Date Date::operator + (int days) {
	Date temp(*this);
	if (isLeapYear(temp.year)) CommonYear[1] = 29;		//�жϵ�ǰ���Ƿ�������
	else CommonYear[1] = 28;
	while (days > 0) {
		if (temp.day < CommonYear[temp.month - 1]) {		//����С�ڵ�ǰ�·������������Լ�
			temp.day++;		//�����Լ�1
			days--;		//��Ҫ�����Լ�1
		}
		else if (temp.day == CommonYear[temp.month - 1] && temp.month != 12) {		//��12�µ��µ�
			temp.month++;
			temp.day = 1;
			days--;
		}
		else if (temp.day == CommonYear[temp.month - 1] && temp.month == 12) {		//12���µ�
			temp.year++;
			temp.month = 1;
			temp.day = 1;
			days--;
			if (isLeapYear(temp.year)) CommonYear[1] = 29;		//�жϽ��꣨��һ�꣩�Ƿ�������
			else CommonYear[1] = 28;
		}
	} 
	return temp;
}

Date Date::operator - (int days) {
	Date temp(*this);
	if (isLeapYear(temp.year)) CommonYear[1] = 29;		//�жϵ�ǰ���Ƿ�������
	else CommonYear[1] = 28;
	while (days > 0) {
		if (temp.day > 1) {		//��������1�죬�����Լ�
			temp.day--;		//�����Լ�1
			days--;		//��Ҫ�����Լ�1
		}
		else if (temp.day == 1 && temp.month != 1) {		//��һ�³�
			temp.month--;		//�·��Լ�1
			temp.day = CommonYear[temp.month - 1];		//���ڱ�Ϊ��ǰ��ǰһ���£��µ�������
			days--;
		}
		else if (temp.day == 1 && temp.month == 1) {		//һ�³�
			temp.year--;
			temp.month = 12;
			temp.day = 31;
			days--;
			if (isLeapYear(temp.year)) CommonYear[1] = 29;		//�жϽ��꣨��һ�꣩�Ƿ�������
			else CommonYear[1] = 28;
		}
	}
	return temp;
}

int main() {
	int y1, m1, d1, y2, m2, d2;
	cout << "������date1�Ĳ���(�� �� ��):";
	cin >> y1 >> m1 >> d1;
	cout << "������date2�Ĳ���(�� �� ��):";
	cin >> y2 >> m2 >> d2;
	Date dat1(y1, m1, d1),dat2(y2,m2,d2);
	Date dat3;
	int nSelect,days;
	cout << "��ѡ����:" << endl << "1.����Date1������days��õ�������" << endl <<
		"2.����Date1��ȥ����days��õ�������" << endl << "3.������������������" << endl << "�������ּ��˳�" << endl;
	cin >> nSelect;
	switch (nSelect) {
		case 1: {
			cout << "����������days:";
			cin >> days;
			dat3 = dat1 + days;
			dat3.showDate();
			break;
		}
		case 2: {
			cout << "����������days:";
			cin >> days;
			dat3 = dat1 - days;
			dat3.showDate();
			break;
		}
		case 3: {
			int count;
			count = dat1 - dat2;
			cout << "���" << count << "��";
			break;
		}
	}
	return 0;
}