#include<iostream>
#include<malloc.h>
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define STACK_INIT 100
typedef int status;		//status表示函数运行状态
using namespace std;

template <class T>
class Stack {
public:
	Stack();		//构造栈；
	status Push(T& n);		//入栈
	status Pop(T& n);		//n 表示出栈元素
	status GetTop(T& n);		//n 表示返回元素
	status Empty();		//判断栈是否为空
	int Size();		//返回栈元素个数
	status ClearStack();		//将栈清空
	~Stack();		//析构函数
private:
	T* base;
	int stacksize;		//当前已经开辟空间大小
	int top;		//当前的位置
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
	//测试int
	Stack<int> sqStack_int;
	if (sqStack_int.Empty()) { cout << "顺序栈为空" << endl; }		//此时应该为空
	int itemp;
	cout << "插入值为：";
	for (int i = 0; i < 70; i++) {
		sqStack_int.Push(i);
		sqStack_int.GetTop(itemp);
		cout << itemp << "  ";
	}
	cout << endl <<"pop得到的值为：";
	for (int i = 0; i < 50; i++) {
		sqStack_int.Pop(itemp);
		cout << itemp << "  ";
	}
	cout << endl ;
	if (!sqStack_int.Empty()) { cout << "顺序栈非空" << endl; }		//此时应该为非空
	cout << "顺序栈的长度为：" << sqStack_int.Size() << endl;		//判断长度应该为20
	
	sqStack_int.ClearStack();		//清空
	if (sqStack_int.Empty()) { cout << "清空后顺序栈为空" << endl; }		//此时应该为空
	cout << endl << endl;
	
	//测试char
	Stack<char> sqStack_char;
	if (sqStack_char.Empty()) { cout << "顺序栈为空" << endl; }		//此时应该为空
	char ctemp;
	cout << "插入字符为：";
	for (int i = 40; i < 110; i++) {
		ctemp = i;
		sqStack_char.Push(ctemp);
		sqStack_char.GetTop(ctemp);
		cout << ctemp << "  ";
	}
	cout << endl << "pop得到的字符为：";
	for (int i = 0; i < 50; i++) {
		sqStack_char.Pop(ctemp);
		cout << ctemp << "  ";
	}
	cout << endl;
	if (!sqStack_char.Empty()) { cout << "顺序栈非空" << endl; }		//此时应该为非空
	cout << "顺序栈的长度为：" << sqStack_char.Size() << endl;		//判断长度应该为20
	sqStack_char.ClearStack();		//清空
	if (sqStack_char.Empty()) { cout << "清空后顺序栈为空" << endl; }		//此时应该为空

	return 0;
}