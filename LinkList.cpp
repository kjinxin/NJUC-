#include"LinkList.h"
stack::stack()          //���캯�����ÿ�ջ
{
 top=NULL;
}
stack::~stack()         //��������
{
/* LinkNode *p=top;
 while(top!=NULL)
 {
  p=top;
  top=top->next;
 // delete p;
 }*/

}
void stack::Push(DataType x)          //��Ԫ��dataѹ��ջ��
{
 LinkNode *TempNode;
 TempNode=new LinkNode;
 TempNode->data=x;
 TempNode->next=top;
 top=TempNode;
}
DataType stack::Pop()                 //ʹջ��Ԫ�س�ջ
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
DataType stack::GetPop()               //ȡ��ջ��Ԫ��
{
 return top->data;
}
void stack::Clear()                    //��ջ���
{
 top=NULL;
}
bool stack::IsEmpty()        //�ж�ջ�Ƿ�Ϊ�գ����Ϊ���򷵻�1�����򷵻�0
{
 if(top==NULL) return true;
 else return false;
}
