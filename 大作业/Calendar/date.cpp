#include"date.h"

int CommonYear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };		
//ƽ��ÿ������,�����������CommonYear[1] = 29

//[����]		isLeapYear
//[����]		�ж��Ƿ�������
//[����]		int year�����
//[����]		true:������false:��
bool isLeapYear(int year) {
	bool OK = 1;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) OK = 1;
	else OK = 0;
	return OK;
}

//[����]		date::date�����캯����
//[����]		���캯�������ж��������Ϣ�Ƿ�Ƿ���
//[����]		y�����		m���·�		d������
//[����]		void
date::date(int y, int m, int d) :year(y), month(m), day(d) {
	if (isLeapYear(y)) CommonYear[1] = 29;		//�жϵ�ǰ���Ƿ�������
	else CommonYear[1] = 28;
	if (y == -1 && m == -1 && d == -1) {
		year = 0; month = 0; day = 0;		//����calTime�еĹ��캯��ʹ��
	}
	else if (m < 1 || m > 12 || d < 1 || d > CommonYear[m - 1]) {
		cout << "���ڷǷ���������Ϊ0001��1��1�գ�" << endl;
		year = 1; month = 1; day = 1;		//����Ϊָ������
	}
}

//[����]		date::date�����ƹ��캯����
//[����]		���ƹ��캯��
//[����]		date& dat
//[����]		void
date::date(date& dat) {
	this->year = dat.year;
	this->month = dat.month;
	this->day = dat.day;
}

//[����]		date::setYear
//[����]		�������
//[����]		int y ����ݣ�
//[����]		void
void date::setYear(int y) {
	if (y < 1) {
		cout << "������÷Ƿ������������ã�" << endl;
		return;
	}
	else {
		year = y;
	}
}

//[����]		date::setMonth
//[����]		�����·�
//[����]		int m ���·ݣ�
//[����]		void
void date::setMonth(int m) {
	if (m < 1 || m > 12) {
		cout << "�·����÷Ƿ������������ã�" << endl;
		return;
	}
	else {
		month = m;
	}
}

//[����]		date::setDay
//[����]		��������
//[����]		int d �����ڣ�
//[����]		void
void date::setDay(int d) {
	if (d < 1 || d > CommonYear[month - 1]) {
		cout << "�������÷Ƿ������������ã�" << endl;
		return;
	}
	else {
		day = d;
	}
}

//[����]		date::showDate�����ƹ��캯����
//[����]		��ӡ���������
//[����]		void
//[����]		void
void date::showDate() {
	cout << "��������Ϊ��" << year << "��" << month << "��" << day << "��" << endl;
}
 
//[����]		date::���������-
//[����]		���������-������ʵ�ּ�������date����֮����������
//[����]		date& b�����м�������Ķ���
//[����]		int��������������
int date::operator - (date& b) {		//֧���Զ��Ƚ��������ڴ�С���ز�ֵ
	int count = 0;
	date high;		//highΪ�������нϴ��
	date temp;		//tempΪ�������н�С��
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
                                                                                                                                                                                                                                                                                                   
//[����]		date::normal
//[����]		��λ�������ԶԽ�λ���иı�
//[����]		int oper	��operΪ1���Ǽӷ���operΪ0���Ǽ���
//[����]		void
date date::normal(int oper, int days) {
	date temp(*this);
	if (oper == 1) {
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
	}
	 if (oper == 0) {
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
	}
	*this = temp;
	return temp;
}

//[����]		date::���������+
//[����]		���������+������ʵ�ֶԶ���date��������������
//[����]		int days���ܹ���������
//[����]		date�͵Ķ������Է�������
date date::operator + (int days) {
	this->normal(1, days);
	return *this;
}

//[����]		date::���������-
//[����]		���������-������ʵ�ֶԶ���date��ȥ����������
//[����]		int days���ܹ���������
//[����]		date�͵Ķ������Է�������
date date::operator - (int days) {
	this->normal(0, days);
	return *this;
}

//[����]		date::��������� ǰ���Լ�--
//[����]		���������--������ʵ�ֶԶ���date�Լ�1��
//[����]		�������������-���м�1�졣
//[����]		date�͵Ķ������Է�������
date date::operator -- (){
	*this = *this - 1;
	return *this;
}

//[����]		date::��������� �����Լ�--
//[����]		���������--������ʵ�ֶԶ���date�Լ�1�죬������δ�Լ���ֵ
//[����]		�������������-���м�1�졣
//[����]		date�͵Ķ���temp�����Է���δ�Լ�ʱ������
date date::operator -- (int) {
	date temp(*this);
	*this = *this - 1;
	return temp;
}

//[����]		date::��������� ǰ���Լ�++
//[����]		���������++������ʵ�ֶԶ���date�Լ�1��
//[����]		�������������+���м�1�졣
//[����]		date�͵Ķ������Է�������
date date::operator ++ () {
	*this = *this + 1;
	return *this;
}

//[����]		date::��������� �����Լ�++
//[����]		���������++������ʵ�ֶԶ���date�Լ�1�죬������δ�Լӵ�ֵ
//[����]		�������������+���м�1�졣
//[����]		date�͵Ķ���temp�����Է���δ�Լ�ʱ������
date date::operator ++ (int) {
	date temp(*this);
	*this = *this + 1;
	return temp;
}