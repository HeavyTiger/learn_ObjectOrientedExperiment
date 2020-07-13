#include"CDate.h"
#include"date.h"
int commonYear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//ƽ��ÿ������,�����������CommonYear[1] = 29

//[����]		CDate:CDate(���캯��)
//[����]		���캯�������жϵ�һ�������ڼ�
//[����]		int y,int m		����mΪ0����firstDayΪ1��Ŀ�ʼ
//[����]		void
CDate::CDate(int y, int m):date(y,m,1){
	date temp(1, 1, 1);		//����Ϊ����һ����������㣬����Ҫ���ſ�ѧ������
	this->firstDay = (*this - temp) % 7 + 1;
}
//[����]		CDate:display
//[����]		��ӡ���µ�����
//[����]		void
//[����]		void
void CDate::display() {
	int count = 0;
	if (isLeapYear(this->year)) commonYear[1] = 29;		//�жϵ�ǰ���Ƿ�������
	else commonYear[1] = 28;
	count = commonYear[this->month - 1];
	cout << this->year << "��" << this->month << "������" << endl;
	cout << std::left << setw(5) << "��һ" << setw(5) << "�ܶ�" << setw(5) << "����" << setw(5) << "����"
		<< setw(5) << "����" << setw(5) << "����" << setw(5) << "����" << endl;
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