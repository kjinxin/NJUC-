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
//**************************************////////////////////

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
//****************************************************************



Move move[4]={{0,1},{1,0},{0,-1},{-1,0}};   //���嵱ǰλ���ƶ���4������
bool Mazepath(int **maze,int m,int n);
     //Ѱ���Թ�maze�дӣ�0��0������m,n����·��
     //���򷵻�true,���򷵻�false
void PrintPath(stack p);        //����Թ���·��
void Restore(int **maze,int m,int n);        //�ָ��Թ�
int** GetMaze(int &m,int &n);       //��ȡ�Թ����ɴ��ļ��ж�ȡ��Ҳ�����룩
                                 //���ش�ȡ�Թ��Ķ�άָ��

int main()
{
 int m=0,n=0;       //�����Թ��ĳ��Ϳ�
 int **maze;        //�����άָ���ȡ�Թ�
 maze=GetMaze(m,n);  //����GetMaze(int &m,int &n)�������õ��Թ�
 if(Mazepath(maze,m,n)) //����Mazepath(int **maze,int m,int n)������ȡ·��
  cout<<"�Թ�·��̽���ɹ�!/n";
 else cout<<"·��������!/n";
 return 0;
}

int** GetMaze(int &m,int &n)
                //��ȡ�Թ����ɴ��ļ��ж�ȡ��Ҳ�����룩
    //���ش�ȡ�Թ��Ķ�άָ��
{
 int **maze;              //�����άָ���ȡ�Թ�
 int i=0,j=0;
 char Choose;            //����һ����־��ѡ���ȡ�ļ���ֱ�����룬��ȡ�Թ�
 cout<<"��ѡ����ļ��ж�ȡ�ļ�(1)����������(2):";
 cin>>Choose;           //�����־
 if(Choose=='1')         //����־ChooseΪ��1��ʱ����ȡ�ļ�
 {
     cout<<"�ļ�������ֻ��Թ�����:/n";
  char ch;             //����һ���ַ�����ȡ�ļ��е�����
  i=0,j=0;
 //���ȵõ��ļ��������ַ�����Ŀ�����õ��Թ��ĳ��Ϳ�
  ifstream fip("test.txt");
           //����һ���ļ����󣬲����ļ���test.txt��
  while(fip.get(ch))        //�Ӷ�ȡ�ļ������ݣ�һ�����ַ���
  {
   if(ch>='0'&&ch<='9')  //��ȡ�ļ��е������ַ�
   {
    j++;               //������ַ�����ͼ�1
   }
   if(ch=='/n')
   {
    i++;           //����ǻ��У����м�1
    n=j;          //�õ���������
    j=0;
   }
  }
  fip.close();    //��ȡ�ļ�����
  m=i;             //�õ���������
  maze=new int *[m+2];  //���볤�ȵ���������2�Ķ���ָ��
  for(i= 0;i<m+2;i++)    //����ÿ����άָ��Ŀռ�
  {
   maze[i]=new int[n+2];
  }
  i=j=1;
  ifstream fip2("test.txt");//���¶�ȡ�ļ����Եõ�����
  while(fip2.get(ch))
  {
   if(ch>='0'&&ch<='9')
   {
    maze[i][j]=ch-'0';      //�������ַ�ת��Ϊ���֣����浽ָ����
    cout<<maze[i][j]<<"   "; //����Ļ����ʾ�Թ�
    j++;
   }
   if(ch=='/n')         //�������У�ָ��Ҳ��Ӧ����
   {
    cout<<endl;
    i++;
    j=1;
   }
  }
  fip2.close();        //��ȡ����
 }

 else           //Choose=2  ,�����Թ�
 {
  cout<<"�������Թ��ĳ��Ϳ�:";
  int a,b;
  cin>>a>>b;             //�����Թ��ĳ��Ϳ�
  cout<<"�������Թ�����:/n";
  m=a;
  n=b;          //m,n�ֱ�����Թ�������������
  maze=new int *[m+2];  //���볤�ȵ���������2�Ķ���ָ��
  for(i= 0;i<m+2;i++)  //����ÿ����άָ��Ŀռ�
  {
   maze[i]=new int[n+2];
  }
  for(i=1;i<=m;i++)          //�����Թ������ݣ�1�����ͨ��0����ͨ
   for(j=1;j<=n;j++)
    cin>>maze[i][j];
  cout<<"�Ƿ񱣴����Թ���/n";
  char choose;
  cin>>choose;
  if(choose=='Y'||choose=='y')
  {
   char ch;
   ofstream fop("Newtest.txt");
   for(i=1;i<=m;i++)
   {
    for(j=1;j<=n;j++)
    {
     ch='0'+maze[i][j];
     fop<<ch;
    }
    fop<<endl;
    flush(cout);
   }
   fop.close();
  }
 }
//���Թ������ܼ�һ��ǽ�������Թ����ܶ���Ϊ1
 for(i=0;i<m+2;i++)
  maze[i][0]=maze[i][n+1]=1;
 for(i=0;i<n+2;i++)
  maze[0][i]=maze[m+1][i]=1;
 return maze;              //���ش����Թ��Ķ�άָ��maze
}
bool Mazepath(int **maze,int m,int n)
          //Ѱ���Թ�maze�дӣ�0��0������m,n����·��
           //���򷵻�true,���򷵻�false
{
 stack q,p;       //����ջp��q,�ֱ��̽���Թ��Ĺ��̺ʹ洢·��
 DataType Temp1,Temp2;
 int x,y,loop;
 Temp1.x=1;
 Temp1.y=1;
 q.Push(Temp1);           //�����λ����ջ
 p.Push(Temp1);
 maze[1][1]=-1;          //��־���λ���ѵ����
 while(!q.IsEmpty())      //ջq�ǿգ��򷴸�̽��
 {
  Temp2=q.GetPop();      //��ȡջ��Ԫ��
  if(!(p.GetPop().x==q.GetPop().x&&p.GetPop().y==q.GetPop().y))
   p.Push(Temp2);
     //�������λ����ջ�������һ��̽����λ�ô���ջp
  for(loop=0;loop<4;loop++)   //̽����ǰλ�õ�4������λ��
  {
   x=Temp2.x+move[loop].x;     //�������λ��xλ��ֵ
   y=Temp2.y+move[loop].y;      //�������λ��yλ��ֵ
   if(maze[x][y]==0)         //�ж���λ���Ƿ�ɴ�
   {
    Temp1.x=x;
    Temp1.y=y;
    maze[x][y]=-1;          //��־��λ���ѵ����
    q.Push(Temp1);         //��λ����ջ
   }
   if((x==(m))&&(y==(n)))    //�ɹ��������
   {
    Temp1.x=m;
    Temp1.y=n;
    Temp1.pre=0;
    p.Push(Temp1);       //�����һ��λ����ջ
    PrintPath(p);        //���·��
    Restore(maze,m,n);        //�ָ�·��
    return 1;            //��ʾ�ɹ��ҵ�·��
   }
  }
  if(p.GetPop().x==q.GetPop().x&&p.GetPop().y==q.GetPop().y)
        //���û����λ����ջ���򷵻ص���һ��λ��
  {
   p.Pop();
   q.Pop();
  }
 }
 return 0;           //��ʾ����ʧ�ܣ����Թ���·��
}
void PrintPath(stack p)        //���·��
{
 cout<<"�Թ���·��Ϊ/n";
 cout<<"�����ڵ����ݷֱ��ʾΪ(������,������,���ֻ�����,����)/n";
 stack t;            //����һ��ջ��������ڵ����ڴ�ȡ·��
 int a,b;
 DataType data;
 LinkNode *temp;
 temp=new LinkNode;         //����ռ�
 temp->data=p.Pop();        //ȡջp�Ķ���Ԫ�أ�����һ��λ��
 t.Push(temp->data);  //��һ��λ����ջt
 delete temp;         //�ͷſռ�
 while(!p.IsEmpty())    //ջp�ǿգ��򷴸�ת��
 {
  temp=new LinkNode;
  temp->data=p.Pop();         //��ȡ��һ��λ��
  //�õ����߷���
  a=t.GetPop().x-temp->data.x;   //�����귽��
  b=t.GetPop().y-temp->data.y;   //�����귽��
  if(a==1) temp->data.pre=1;     //�������£���1��ʾ
  else if(b==1) temp->data.pre=2; //�������ң���2��ʾ
  else if(a==-1) temp->data.pre=3;  //�������ϣ���3��ʾ
  else if(b==-1) temp->data.pre=4;  //����������4��ʾ
  t.Push(temp->data);            //����λ����ջ
  delete temp;
 }
 //���·�������������꣬�����꣬��һ��λ�÷���
 while(!t.IsEmpty())         //ջ�ǿգ��������
 {
  data=t.Pop();
  cout<<'('<<data.x<<','<<data.y<<','<<data.pre<<",";  //��������꣬������
  switch(data.pre)   //�����Ӧ�ķ���
  {
  case 1:cout<<"��)/n";break;
  case 2:cout<<"��)/n";break;
  case 3:cout<<"��)/n";break;
  case 4:cout<<"��)/n";break;
  case 0:cout<<")/n";break;
  }
 }
}
void Restore(int **maze,int m,int n)       //�ָ��Թ�
{
 int i,j;
 for(i=0;i<m+2;i++)            //����ָ��
  for(j=0;j<n+2;j++)
  {
   if(maze[i][j]==-1)         //�ָ�̽����λ�ã�����-1�ָ�Ϊ0
    maze[i][j]=0;
  }
}
