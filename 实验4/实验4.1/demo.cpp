#include<iostream>
#include<malloc.h>
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define STACK_INIT 100
typedef int status;		//status��ʾ��������״̬
using namespace std;

template <class T>
class Stack {
public:
	Stack();		//����ջ��
	status Push(T& n);		//��ջ
	status Pop(T& n);		//n ��ʾ��ջԪ��
	status GetTop(T& n);		//n ��ʾ����Ԫ��
	status Empty();		//�ж�ջ�Ƿ�Ϊ��
	int Size();		//����ջԪ�ظ���
	status ClearStack();		//��ջ���
	~Stack();		//��������
private:
	T* base;
	int stacksize;		//��ǰ�Ѿ����ٿռ��С
	int top;		//��ǰ��λ��
};
template<class T>
Stack<T>::Stack():stacksize(STACK_INIT),top(-1){
	base = new T[STACK_INIT];
}
template<class T>
status Stack<T>::Push(T& n) {
	base[++top] = n;
	return TRUE;
}
template<class T>
status Stack<T>::Pop(T &n) {
	n = base[top--];
	return TRUE;
}
template<class T>
status Stack<T>::GetTop(T& n) {
	n = base[top];
	return TRUE;
}
template<class T>
status Stack<T>::Empty() {
	if (top == -1)return TRUE;
	else return FALSE;
}
template<class T>
int Stack<T>::Size() {
	return top + 1;
}
template<class T>
status Stack<T>::ClearStack() {
	top = -1;
	return TRUE;
}
template<class T>
Stack<T>::~Stack() {
	delete base;
}


int main() {		
	//����int
	Stack<int> sqStack_int;
	if (sqStack_int.Empty()) { cout << "˳��ջΪ��" << endl; }		//��ʱӦ��Ϊ��
	int itemp;
	cout << "����ֵΪ��";
	for (int i = 0; i < 70; i++) {
		sqStack_int.Push(i);
		sqStack_int.GetTop(itemp);
		cout << itemp << "  ";
	}
	cout << endl <<"pop�õ���ֵΪ��";
	for (int i = 0; i < 50; i++) {
		sqStack_int.Pop(itemp);
		cout << itemp << "  ";
	}
	cout << endl ;
	if (!sqStack_int.Empty()) { cout << "˳��ջ�ǿ�" << endl; }		//��ʱӦ��Ϊ�ǿ�
	cout << "˳��ջ�ĳ���Ϊ��" << sqStack_int.Size() << endl;		//�жϳ���Ӧ��Ϊ20
	
	sqStack_int.ClearStack();		//���
	if (sqStack_int.Empty()) { cout << "��պ�˳��ջΪ��" << endl; }		//��ʱӦ��Ϊ��
	cout << endl << endl;
	
	//����char
	Stack<char> sqStack_char;
	if (sqStack_char.Empty()) { cout << "˳��ջΪ��" << endl; }		//��ʱӦ��Ϊ��
	char ctemp;
	cout << "�����ַ�Ϊ��";
	for (int i = 40; i < 110; i++) {
		ctemp = i;
		sqStack_char.Push(ctemp);
		sqStack_char.GetTop(ctemp);
		cout << ctemp << "  ";
	}
	cout << endl << "pop�õ����ַ�Ϊ��";
	for (int i = 0; i < 50; i++) {
		sqStack_char.Pop(ctemp);
		cout << ctemp << "  ";
	}
	cout << endl;
	if (!sqStack_char.Empty()) { cout << "˳��ջ�ǿ�" << endl; }		//��ʱӦ��Ϊ�ǿ�
	cout << "˳��ջ�ĳ���Ϊ��" << sqStack_char.Size() << endl;		//�жϳ���Ӧ��Ϊ20
	sqStack_char.ClearStack();		//���
	if (sqStack_char.Empty()) { cout << "��պ�˳��ջΪ��" << endl; }		//��ʱӦ��Ϊ��

	return 0;
}