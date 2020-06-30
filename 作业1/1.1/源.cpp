/*1. 在某次歌手大赛中，有 JudgeNum 个评委给选手打分，参加比赛
的选手有 PlayerNum 名，现为比赛记分编写一个 CompetitionResult 类，
类的定义如下：

class CompetitionResult {

   short num;         // 选手号码

   char name[10];     // 选手姓名

   float score[JudgeNum];  // 记录各评委给选手的打分 

   float average;      // 选手最后得分，去掉一个最高分和
   一个最低分后的平均分

public:

   CompetitionResult( );                // 无参数构造函数

   CompetitionResult(short n, char * ps);   // 一般构造函数

   float MaxScore( );                   // 求评委打的最高分

   float MinScore( );                   // 求评委打的最低分

   void SetAvg();                     // 求选手的最后得分

   float GetAvg()                     // 读选手的最后得分

   short GetNo( )                     // 读选手的编号

   void  setNo (int i)                  // 设置选手的编号

   char * GetName( )                  // 读选手的姓名

   float GetScore(int j)                 // 读第j个评委的打分

   void SetScore(int k, float av)          // 记录第j个评委的打分

   friend void Sort(CompetitionResult *pr, int n);  
   // 按最后得分由高到低排序

};

（1）写出所有成员函数的实现代码；

（2）编写 main( ) 函数对该类进行测试。在函数体中，定义一个 
CompetitionResult 类的对象数组r[PlayerNum]，
它的每个元素记录着每个运动员的所有信息，各评委的打分通过键盘输入，
在屏幕上应有提示信息进行交互式操作，比赛结果按选手得分从高到低排序输出。
*/

#include<iostream>
#define JudgeNum 5
#define PlayerNum 5
using namespace std;

class CompetitionResult {
    short num;         // 选手号码
    char name[10];     // 选手姓名
    float score[JudgeNum];  // 记录各评委给选手的打分 
    float average;      // 选手最后得分，去掉一个最高分和一个最低分后的平均分

public:
    CompetitionResult();                // 无参数构造函数
    CompetitionResult(short n,const char* ps);   // 一般构造函数
    float MaxScore();                   // 求评委打的最高分
    float MinScore();                   // 求评委打的最低分
    void SetAvg();                     // 求选手的最后得分
    float GetAvg();                 // 读选手的最后得分
    short GetNo();             // 读选手的编号
    void  setNo(int i);         // 设置选手的编号
    char* GetName();           // 读选手的姓名
    float GetScore(int j);             // 读第j个评委的打分
    void SetScore(int k, float av);       // 记录第k+1个评委的打分
    friend void Sort(CompetitionResult* pr, int n);// 按最后得分由高到低排序
};
CompetitionResult::CompetitionResult() {}       // 无参数构造函数
CompetitionResult::CompetitionResult(short n,const char* ps){    // 一般构造函数
    num = n;
    strcpy_s(name, ps);
}
float CompetitionResult::MaxScore() {   // 求评委打的最高分
    float Max = 0.0;
    for (int i = 0; i < JudgeNum; i++) {
        if (score[i] >= Max) Max = score[i];
    }
    return Max;
}
float CompetitionResult::MinScore() {   // 求评委打的最低分
    float Min = this -> MaxScore();
    for (int i = 0; i < JudgeNum; i++) {
        if (score[i] <= Min) Min = score[i];
    }
    return Min;
}
void CompetitionResult::SetAvg() {      // 求选手的最后得分
    float sum = 0.0;
    for (int i = 0; i < JudgeNum; i++) {
        sum += score[i];
    }
   average =  (sum - this->MaxScore() - this->MinScore()) / (float)(JudgeNum - 2);
}
float  CompetitionResult::GetAvg() {        // 读选手的最后得分
    return average;
}
short CompetitionResult::GetNo() {         // 读选手的编号
    return num;
}
void  CompetitionResult::setNo(int i) {     // 设置选手的编号
    num = (short)i;
}
char* CompetitionResult::GetName() {       // 读选手的姓名
    return name;
}
float CompetitionResult::GetScore(int j) {      // 读第j个评委的打分
    return score[j-1];      //第j个评委打分为score[j-1]
}
void CompetitionResult::SetScore(int k, float av) {     // 记录第k+1个评委的打分
    score[k] = av;
}
void Sort(CompetitionResult* pr, int n) {       // 按最后得分由高到低排序
    CompetitionResult temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pr[j].average >= pr[j + 1].average) {
                temp = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = temp;
            }
        }
        cout << "第" << i + 1 << "名是" << pr[n - 1 - i].GetName() << ",编号为" << 
            pr[n - 1 - i].GetNo() << "，最终得分是" << pr[n - 1 - i].average << endl;
    }
    cout << "第" << n << "名是" << pr[0].GetName() << ",编号为" <<
        pr[0].GetNo() << "，最终得分是" << pr[0].average << endl;
}

int main() {
    CompetitionResult r[PlayerNum] = {
        CompetitionResult(1,"wang"),
        CompetitionResult(2,"li"),
        CompetitionResult(3,"ming"),
        CompetitionResult(4,"zhang"),
        CompetitionResult(5,"qiang"),
    };
    float ftemp;
    for (int i = 0; i < PlayerNum; i++) {   //读数据
        cout << "请依次输入"<<JudgeNum<<"个评委给"<< r[i].GetName() << "的评分：";
        for (int j = 0; j < JudgeNum; j++) {
            cin >> ftemp;
            r[i].SetScore(j, ftemp);
        }
        r[i].SetAvg();
    }
    Sort(r, PlayerNum);
    return 0;
}