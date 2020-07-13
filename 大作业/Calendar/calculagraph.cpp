//��ʱ��������ʵ�ָ߿�����ʱ���ͱ���ʱ���ۻ���
#include"calculagraph.h"

//[����]		calculagraph
//[����]		�ṩѡ��ʹ�õ���ʱ��countDownTimer�����ۼ���cumulativeTimer
//[����]		void
//[����]		void
void calculagraph(){
	int nSelection;
	cout << "��ѡ��ʹ��(1.�߿�����ʱ��  2.����ʱ���ۻ���  �������ּ�����):";
	cin >> nSelection;
	cin.clear();		//��ջ�����
	cin.sync();
	system("cls");

	if (nSelection == 1) {		//����ʱ��
		countDownTimer();
	}
	else if (nSelection == 2) {		//����ʱ���ۼ���
		cumulativeTimer();
	}
	else return;
	return;
}

//[����]		countDownTimer
//[����]		ʹ�ø߿�����ʱ��,��ָ��ʱ������ۼ�����
//[����]		void
//[����]		void
void countDownTimer() {
	int y, m, d, days, nSelection = 0, nDay = 0;
	cout << "�����������ʱ��(��2019 6 7):";
	cin >> y >> m >> d;
	cin.clear();
	cin.sync();
	date end(y, m, d);
	cout << "�����뵹��ʱ������(��97):";
	cin >> days;
	if (days < 0) {
		cout << "����ʱ�����Ƿ���" << endl;
		system("pause");
		system("cls");
		return;
	}
	cin.clear();
	cin.sync();
	system("cls");
	date temp;
	temp = end - days;		//���ڳ�ʼ����
	while (days >= 0) {
		cout << "----------�߿�����ʱ----------" << endl;
		temp.showDate();		//�����������
		cout << "����߿���ʣ:" << days << "��" << endl;
		if (days != 0) {
			cout << "------------------------------" << endl;
			cout << "��ѡ��(1.ʣ��ʱ�����1��  2.ʣ��ʱ�����ָ������  �������ּ��˳�):";
			cin >> nSelection;
			cin.clear();
			cin.sync();
			if (nSelection == 1) {
				temp++;
				days--;
			}
			else if (nSelection == 2) {
				cout << "������ָ�����ٵ�����:";
				cin >> nDay;
				if (nDay > days) {		//�ж�ָ�����������Ƿ����ʣ������
					cout << "ָ�����ٵ���������ʣ������!����"<< endl;
					system("pause");
					system("cls");
					continue;
				}
				if (nDay < 0) {		////�ж�ָ�����������Ƿ�Ϊ����
					cout << "ָ�����ٵ�����Ϊ����!����" << endl;
					system("pause");
					system("cls");
					continue;
				}
				cin.clear();
				cin.sync();
				temp = temp + nDay;
				days -= nDay;
			}
			else {
				system("cls");
				return;
			}
			system("cls");
		}
		else {
			cout << "ף�߿�˳�������������" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//[����]		cumulativeTimer
//[����]		ʹ���ۼ���,��ָ����ʼʱ������ۼӣ������ܱ���ʱ��;
//[����]		void
//[����]		void
void cumulativeTimer() {
	int y, m, d, count = 1, nSelection = 0, nDay = 0;
	cout << "�����뿪ʼ�ۼ�ʱ�������(��2019 1 1):";
	cin >> y >> m >> d;
	cin.clear();
	cin.sync();
	date start(y, m, d);
	system("cls");
	date temp(start);
	while (1) {
		cout << "----------����ʱ���ۼ���----------" << endl;
		temp.showDate();		//�����������
		cout << "�Ѿ�����:" << count << "��" << endl;
		cout << "-----------------------------" << endl;
		cout << "��ѡ��(1.����ʱ������1��  2.����ʱ������ָ������  �������ּ��˳�):";
		cin >> nSelection;
		cin.clear();
		cin.sync();
		if (nSelection == 1) {
			temp++;
			count++;
		}
		else if (nSelection == 2) {
			cout << "������ָ�����ӵ�����:";
			cin >> nDay;
			if (nDay < 0) {		//�ж�ָ�����������Ƿ�Ϊ����
				cout << "ָ�����ٵ�����Ϊ����!����" << endl;
				system("pause");
				system("cls");
				continue;
			}
			cin.clear();
			cin.sync();
			temp = temp + nDay;
			count += nDay;
		}
		else {
			system("cls");
			return;
		}
		system("cls");
	}
}