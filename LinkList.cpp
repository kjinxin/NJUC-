#include"LinkList.h"
stack::stack()          //构造函数，置空栈
{
 top=NULL;
}
stack::~stack()         //析构函数
{
/* LinkNode *p=top;
 while(top!=NULL)
 {
  p=top;
  top=top->next;
 // delete p;
 }*/

}
void stack::Push(DataType x)          //把元素data压入栈中
{
 LinkNode *TempNode;
 TempNode=new LinkNode;
 TempNode->data=x;
 TempNode->next=top;
 top=TempNode;
}
DataType stack::Pop()                 //使栈顶元素出栈
{
 DataType Temp;
 LinkNode *TempNode;
 //if(top==NULL) return NULL;
// else
// {
  TempNode=top;
  top=top->next;
  Temp=TempNode->data;
  delete TempNode;
  return Temp;
// }
}
DataType stack::GetPop()               //取出栈顶元素
{
 return top->data;
}
void stack::Clear()                    //把栈清空
{
 top=NULL;
}
bool stack::IsEmpty()        //判断栈是否为空，如果为空则返回1，否则返回0
{
 if(top==NULL) return true;
 else return false;
}
