#include"calculagraph.h"
#include"calTime.h"
#include"calendar.h"
int main() {
	int nSelection = 0;
	while (1) {
		cout << "***********���˵�***********" << endl;
		cout << "1.ʹ�ü�ʱ��(����ʱ���ۼ�ʱ)" << endl;
		cout << "2.ʹ��������DateTimeʱ�书��" << endl;
		cout << "3.ʹ��������cDate��������" << endl;
		cout << "0.ʹ���������ּ��˳�����" << endl;
		cout << "****************************" << endl;
		cout << "��ѡ��ʹ�õĹ���:";
		cin >> nSelection;
		cin.clear();
		cin.sync();
		switch (nSelection) {
			case 1:calculagraph(); break;
			case 2:calTime(); break;
			case 3:calendar(); break;
			default: return 0;
		}
	}
}