/*1. ��ĳ�θ��ִ����У��� JudgeNum ����ί��ѡ�ִ�֣��μӱ���
��ѡ���� PlayerNum ������Ϊ�����Ƿֱ�дһ�� CompetitionResult �࣬
��Ķ������£�

class CompetitionResult {

   short num;         // ѡ�ֺ���

   char name[10];     // ѡ������

   float score[JudgeNum];  // ��¼����ί��ѡ�ֵĴ�� 

   float average;      // ѡ�����÷֣�ȥ��һ����߷ֺ�
   һ����ͷֺ��ƽ����

public:

   CompetitionResult( );                // �޲������캯��

   CompetitionResult(short n, char * ps);   // һ�㹹�캯��

   float MaxScore( );                   // ����ί�����߷�

   float MinScore( );                   // ����ί�����ͷ�

   void SetAvg();                     // ��ѡ�ֵ����÷�

   float GetAvg()                     // ��ѡ�ֵ����÷�

   short GetNo( )                     // ��ѡ�ֵı��

   void  setNo (int i)                  // ����ѡ�ֵı��

   char * GetName( )                  // ��ѡ�ֵ�����

   float GetScore(int j)                 // ����j����ί�Ĵ��

   void SetScore(int k, float av)          // ��¼��j����ί�Ĵ��

   friend void Sort(CompetitionResult *pr, int n);  
   // �����÷��ɸߵ�������

};

��1��д�����г�Ա������ʵ�ִ��룻

��2����д main( ) �����Ը�����в��ԡ��ں������У�����һ�� 
CompetitionResult ��Ķ�������r[PlayerNum]��
����ÿ��Ԫ�ؼ�¼��ÿ���˶�Ա��������Ϣ������ί�Ĵ��ͨ���������룬
����Ļ��Ӧ����ʾ��Ϣ���н���ʽ���������������ѡ�ֵ÷ִӸߵ������������
*/

#include<iostream>
#define JudgeNum 5
#define PlayerNum 5
using namespace std;

class CompetitionResult {
    short num;         // ѡ�ֺ���
    char name[10];     // ѡ������
    float score[JudgeNum];  // ��¼����ί��ѡ�ֵĴ�� 
    float average;      // ѡ�����÷֣�ȥ��һ����߷ֺ�һ����ͷֺ��ƽ����

public:
    CompetitionResult();                // �޲������캯��
    CompetitionResult(short n,const char* ps);   // һ�㹹�캯��
    float MaxScore();                   // ����ί�����߷�
    float MinScore();                   // ����ί�����ͷ�
    void SetAvg();                     // ��ѡ�ֵ����÷�
    float GetAvg();                 // ��ѡ�ֵ����÷�
    short GetNo();             // ��ѡ�ֵı��
    void  setNo(int i);         // ����ѡ�ֵı��
    char* GetName();           // ��ѡ�ֵ�����
    float GetScore(int j);             // ����j����ί�Ĵ��
    void SetScore(int k, float av);       // ��¼��k+1����ί�Ĵ��
    friend void Sort(CompetitionResult* pr, int n);// �����÷��ɸߵ�������
};
CompetitionResult::CompetitionResult() {}       // �޲������캯��
CompetitionResult::CompetitionResult(short n,const char* ps){    // һ�㹹�캯��
    num = n;
    strcpy_s(name, ps);
}
float CompetitionResult::MaxScore() {   // ����ί�����߷�
    float Max = 0.0;
    for (int i = 0; i < JudgeNum; i++) {
        if (score[i] >= Max) Max = score[i];
    }
    return Max;
}
float CompetitionResult::MinScore() {   // ����ί�����ͷ�
    float Min = this -> MaxScore();
    for (int i = 0; i < JudgeNum; i++) {
        if (score[i] <= Min) Min = score[i];
    }
    return Min;
}
void CompetitionResult::SetAvg() {      // ��ѡ�ֵ����÷�
    float sum = 0.0;
    for (int i = 0; i < JudgeNum; i++) {
        sum += score[i];
    }
   average =  (sum - this->MaxScore() - this->MinScore()) / (float)(JudgeNum - 2);
}
float  CompetitionResult::GetAvg() {        // ��ѡ�ֵ����÷�
    return average;
}
short CompetitionResult::GetNo() {         // ��ѡ�ֵı��
    return num;
}
void  CompetitionResult::setNo(int i) {     // ����ѡ�ֵı��
    num = (short)i;
}
char* CompetitionResult::GetName() {       // ��ѡ�ֵ�����
    return name;
}
float CompetitionResult::GetScore(int j) {      // ����j����ί�Ĵ��
    return score[j-1];      //��j����ί���Ϊscore[j-1]
}
void CompetitionResult::SetScore(int k, float av) {     // ��¼��k+1����ί�Ĵ��
    score[k] = av;
}
void Sort(CompetitionResult* pr, int n) {       // �����÷��ɸߵ�������
    CompetitionResult temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pr[j].average >= pr[j + 1].average) {
                temp = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = temp;
            }
        }
        cout << "��" << i + 1 << "����" << pr[n - 1 - i].GetName() << ",���Ϊ" << 
            pr[n - 1 - i].GetNo() << "�����յ÷���" << pr[n - 1 - i].average << endl;
    }
    cout << "��" << n << "����" << pr[0].GetName() << ",���Ϊ" <<
        pr[0].GetNo() << "�����յ÷���" << pr[0].average << endl;
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
    for (int i = 0; i < PlayerNum; i++) {   //������
        cout << "����������"<<JudgeNum<<"����ί��"<< r[i].GetName() << "�����֣�";
        for (int j = 0; j < JudgeNum; j++) {
            cin >> ftemp;
            r[i].SetScore(j, ftemp);
        }
        r[i].SetAvg();
    }
    Sort(r, PlayerNum);
    return 0;
}