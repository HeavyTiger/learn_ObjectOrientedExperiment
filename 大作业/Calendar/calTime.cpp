#include"calTime.h"

//[����]		calTime
//[����]		�ṩʹ��ʱ�������
//[����]		void
//[����]		void
void calTime() {
	int nSelection;
	int y, m, d, h, min, sec;
	system("cls");
	cout << "**********************ʱ �� �� �� ��**********************" << endl;
	cout << "��������Ҫ������ʱ��(��2020 7 8 23 59 59):";
	cin >> y >> m >> d >> h >> min >> sec;
	cin.clear();		//��ջ�����
	cin.sync();
	DateTime start(y, m, d, h, min, sec);
	start.show();
	cout << "**********************************************************" << endl;
	cout << "��ѡ����(1.����ʱ��  2.����ʱ��  �������ּ�����):";
	cin >> nSelection;
	cin.clear();		//��ջ�����
	cin.sync();
	if (nSelection == 1) {		//����ʱ��
		cout << "��ָ���������ʱ��(��23 59 59,֧������Զ���λ):";
		cin >> h >> min >> sec;
		if (h < 0 || min < 0 || sec < 0) {
			cout << "ʱ��ָ��ʱ���ָ���������" << endl;
			system("pause");
			system("cls");
			return; 
		}
		else {
			DateTime temp(-1, -1, -1, h, min, sec);		//���ڹ���dateʱ����������Ϊ0��
			start = start + temp;
			start.show();
			system("pause");
			system("cls");
			return;
		}
	}
	else if (nSelection == 2) {		//����ʱ��
		cout << "��ָ������ʱ��(��23 59 59,֧������Զ���λ):";
		cin >> h >> min >> sec;
		if (h < 0 || min < 0 || sec < 0) {
			cout << "ʱ��ָ��ʱ���ָ���������" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			DateTime temp(-1, -1, -1, h, min, sec);		//���ڹ���dateʱ����������Ϊ0��
			start = start - temp;
			start.show();
			system("pause");
			system("cls");
			return;
		}
	}
	else return;
	return;
}