#include"calendar.h"
//[����]		calendar
//[����]		�ṩ������ز���
//[����]		void
//[����]		void
void calendar() {
	int y, m;
	system("cls");
	cout << "**********************����**********************" << endl;
	cout << "��ѡ����Ҫ�����������ݼ��·�(��2019 6):";
	cin >> y >> m;
	cin.clear();
	cin.sync();
	CDate temp(y, m);
	temp.display();
	cout << "************************************************" << endl;
	system("pause");
	system("cls");
}