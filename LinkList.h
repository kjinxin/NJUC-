#include<iostream>
#include<fstream>
using namespace std;
struct DataType       //定义描述迷宫中当前位置的结构类型
{
 int x;          //x代表当前位置的行坐标
 int y;          //y代表当前位置的列坐标
 int pre;        //pre表示移动到下一步的方向
};
struct Move         //定义下一个位置的方向
{
 int x;
 int y;
};
struct LinkNode      //链表结点
{
 DataType data;
 LinkNode *next;
};
//下面定义栈
class stack
{
private:
 LinkNode *top;           //指向第一个结点的栈顶指针
public:
 stack();              //构造函数，置空栈
 ~stack();             //析构函数
 void Push(DataType data);           //把元素data压入栈中
 DataType Pop();                  //使栈顶元素出栈
 DataType GetPop();               //取出栈顶元素
 void Clear();                   //把栈清空
 bool IsEmpty();        //判断栈是否为空，如果为空则返回1，否则返回0
};
