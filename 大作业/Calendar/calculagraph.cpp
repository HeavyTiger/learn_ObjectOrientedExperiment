//计时器，用以实现高考倒计时器和备考时间累积器
#include"calculagraph.h"

//[函数]		calculagraph
//[功能]		提供选择使用倒计时器countDownTimer，或累加器cumulativeTimer
//[参数]		void
//[返回]		void
void calculagraph(){
	int nSelection;
	cout << "请选择使用(1.高考倒计时器  2.备考时间累积器  其他数字键返回):";
	cin >> nSelection;
	cin.clear();		//清空缓冲区
	cin.sync();
	system("cls");

	if (nSelection == 1) {		//倒计时器
		countDownTimer();
	}
	else if (nSelection == 2) {		//备考时间累计器
		cumulativeTimer();
	}
	else return;
	return;
}

//[函数]		countDownTimer
//[功能]		使用高考倒计时器,对指定时间进行累减操作
//[参数]		void
//[返回]		void
void countDownTimer() {
	int y, m, d, days, nSelection = 0, nDay = 0;
	cout << "请输入结束的时间(如2019 6 7):";
	cin >> y >> m >> d;
	cin.clear();
	cin.sync();
	date end(y, m, d);
	cout << "请输入倒计时的天数(如97):";
	cin >> days;
	if (days < 0) {
		cout << "倒计时天数非法！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cin.clear();
	cin.sync();
	system("cls");
	date temp;
	temp = end - days;		//置于初始天数
	while (days >= 0) {
		cout << "----------高考倒计时----------" << endl;
		temp.showDate();		//输出今日日期
		cout << "距离高考还剩:" << days << "天" << endl;
		if (days != 0) {
			cout << "------------------------------" << endl;
			cout << "请选择(1.剩余时间减少1天  2.剩余时间减少指定天数  其他数字键退出):";
			cin >> nSelection;
			cin.clear();
			cin.sync();
			if (nSelection == 1) {
				temp++;
				days--;
			}
			else if (nSelection == 2) {
				cout << "请输入指定减少的天数:";
				cin >> nDay;
				if (nDay > days) {		//判断指定减少天数是否大于剩余天数
					cout << "指定减少的天数大于剩余天数!错误！"<< endl;
					system("pause");
					system("cls");
					continue;
				}
				if (nDay < 0) {		////判断指定减少天数是否为负数
					cout << "指定减少的天数为负数!错误！" << endl;
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
			cout << "祝高考顺利，金榜题名！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//[函数]		cumulativeTimer
//[功能]		使用累加器,对指定初始时间进行累加，计算总备考时间;
//[参数]		void
//[返回]		void
void cumulativeTimer() {
	int y, m, d, count = 1, nSelection = 0, nDay = 0;
	cout << "请输入开始累计时间的日期(如2019 1 1):";
	cin >> y >> m >> d;
	cin.clear();
	cin.sync();
	date start(y, m, d);
	system("cls");
	date temp(start);
	while (1) {
		cout << "----------备考时间累加器----------" << endl;
		temp.showDate();		//输出今日日期
		cout << "已经备考:" << count << "天" << endl;
		cout << "-----------------------------" << endl;
		cout << "请选择(1.备考时间增加1天  2.备考时间增加指定天数  其他数字键退出):";
		cin >> nSelection;
		cin.clear();
		cin.sync();
		if (nSelection == 1) {
			temp++;
			count++;
		}
		else if (nSelection == 2) {
			cout << "请输入指定增加的天数:";
			cin >> nDay;
			if (nDay < 0) {		//判断指定减少天数是否为负数
				cout << "指定减少的天数为负数!错误！" << endl;
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