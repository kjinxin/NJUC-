#include<iostream>
#include<fstream>
using namespace std;
struct DataType       //���������Թ��е�ǰλ�õĽṹ����
{
 int x;          //x����ǰλ�õ�������
 int y;          //y����ǰλ�õ�������
 int pre;        //pre��ʾ�ƶ�����һ���ķ���
};
struct Move         //������һ��λ�õķ���
{
 int x;
 int y;
};
struct LinkNode      //������
{
 DataType data;
 LinkNode *next;
};
//���涨��ջ
class stack
{
private:
 LinkNode *top;           //ָ���һ������ջ��ָ��
public:
 stack();              //���캯�����ÿ�ջ
 ~stack();             //��������
 void Push(DataType data);           //��Ԫ��dataѹ��ջ��
 DataType Pop();                  //ʹջ��Ԫ�س�ջ
 DataType GetPop();               //ȡ��ջ��Ԫ��
 void Clear();                   //��ջ���
 bool IsEmpty();        //�ж�ջ�Ƿ�Ϊ�գ����Ϊ���򷵻�1�����򷵻�0
};
