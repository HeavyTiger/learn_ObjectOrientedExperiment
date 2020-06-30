/*3��ĳ���۹�˾�����۾��������Ա�����¹��ʵļ���취�ǣ�
���۾���ĵ�нΪ 4000 Ԫ���������۶�� 2 / 1000 ��Ϊ��ɣ�
����Ա���޵�н��ֻ��ȡ���۶�� 5 / 1000 ��Ϊ���ʡ���д����
��1�����塪������ Employee�������� 3 �����ݳ�Ա number��ְԱ��ţ�
��name����������salary�����ʣ����Լ����������ź������Ĺ��캯����
��2���� Employee ������ Salesman �ࡣ
Salesman ��������������ݳ�Ա commrate����ɱ�������sales�����۶��
�����������������۶��������Ա�����ʵĳ�Ա���� pay()
����������ĳ�Ա���� print()��
��3���� Salesman ������ Salesmanager �ࡣ
Salesmanager ����������ݳ�Ա monthlypay����н����
�Լ������������۶�������۾����ʵĳ�Ա���� pay()��
��������ĳ�Ա���� print������
��4����д main �����У���������Ƶ���ṹ���������ɸ���ͬԱ���Ĺ��ʡ�*/

#include<iostream>
using namespace std;
#define MONTHLYPAY 4000
#define SALESMANRATE 0.005
#define SALESMANAGERRATE 0.002

class Employee {
protected:
	char name[10];		//����
	short number;		//���
	double salary;		//����
public:
	Employee(const char* cName, short num) :number(num){
		strcpy_s(name, cName);
	}
};
class Salesman :public Employee {
protected:
	double commrate;
	double sales;
public:
	Salesman(const char* cName, short num,double rate = SALESMANRATE):Employee(cName,num),commrate(rate){}
	void pay() {
		cout << "����������Ա��"<<name<<"�����۶";
		cin >> sales;
		salary = sales * commrate;
	}
	void print() {
		cout << "���Ϊ" << number << "������Ա��" 
			<< name << ",����Ϊ��" << salary << endl;
	}
};
class Salesmanager:public Salesman{
protected:
	double monthlypay;
public:
	Salesmanager(const char* cName,short num,double rate = SALESMANAGERRATE)
		:Salesman(cName, num, rate) {monthlypay = MONTHLYPAY;}
	void pay() {
		cout << "���������۾���" << name << "�����۶";
		cin >> sales;
		salary = sales * commrate + monthlypay;
	}
	void print() {
		cout << "���Ϊ" << number << "�����۾���"
			<< name << ",����Ϊ��" << salary << endl;
	}
};


int main() {
	Salesman dcm("dcm", 100);
	Salesmanager DanGe("fcx", 101);
	dcm.pay();
	dcm.print();
	DanGe.pay();
	DanGe.print();
	return 0;
}