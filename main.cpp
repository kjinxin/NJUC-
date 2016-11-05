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
//**************************************////////////////////

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
//****************************************************************



Move move[4]={{0,1},{1,0},{0,-1},{-1,0}};   //定义当前位置移动的4个方向
bool Mazepath(int **maze,int m,int n);
     //寻找迷宫maze中从（0，0）到（m,n）的路径
     //到则返回true,否则返回false
void PrintPath(stack p);        //输出迷宫的路径
void Restore(int **maze,int m,int n);        //恢复迷宫
int** GetMaze(int &m,int &n);       //获取迷宫（可从文件中读取，也可输入）
                                 //返回存取迷宫的二维指针

int main()
{
 int m=0,n=0;       //定义迷宫的长和宽
 int **maze;        //定义二维指针存取迷宫
 maze=GetMaze(m,n);  //调用GetMaze(int &m,int &n)函数，得到迷宫
 if(Mazepath(maze,m,n)) //调用Mazepath(int **maze,int m,int n)函数获取路径
  cout<<"迷宫路径探索成功!/n";
 else cout<<"路径不存在!/n";
 return 0;
}

int** GetMaze(int &m,int &n)
                //获取迷宫（可从文件中读取，也可输入）
    //返回存取迷宫的二维指针
{
 int **maze;              //定义二维指针存取迷宫
 int i=0,j=0;
 char Choose;            //定义一个标志，选择读取文件或直接输入，获取迷宫
 cout<<"请选择从文件中读取文件(1)或重新输入(2):";
 cin>>Choose;           //输入标志
 if(Choose=='1')         //当标志Choose为‘1’时，读取文件
 {
     cout<<"文件里的数字化迷宫如下:/n";
  char ch;             //定义一个字符，读取文件中的内容
  i=0,j=0;
 //首先得到文件中数字字符的数目，并得到迷宫的长和宽
  ifstream fip("test.txt");
           //定义一个文件对象，并打开文件“test.txt”
  while(fip.get(ch))        //从读取文件中内容（一个个字符）
  {
   if(ch>='0'&&ch<='9')  //获取文件中的数字字符
   {
    j++;               //如果是字符，宽就加1
   }
   if(ch=='/n')
   {
    i++;           //如果是换行，就行加1
    n=j;          //得到宽，即列数
    j=0;
   }
  }
  fip.close();    //读取文件结束
  m=i;             //得到长即行数
  maze=new int *[m+2];  //申请长度等于行数加2的二级指针
  for(i= 0;i<m+2;i++)    //申请每个二维指针的空间
  {
   maze[i]=new int[n+2];
  }
  i=j=1;
  ifstream fip2("test.txt");//重新读取文件，以得到内容
  while(fip2.get(ch))
  {
   if(ch>='0'&&ch<='9')
   {
    maze[i][j]=ch-'0';      //把数字字符转化为数字，并存到指针里
    cout<<maze[i][j]<<"   "; //在屏幕中显示迷宫
    j++;
   }
   if(ch=='/n')         //遇到换行，指针也相应换行
   {
    cout<<endl;
    i++;
    j=1;
   }
  }
  fip2.close();        //读取结束
 }

 else           //Choose=2  ,输入迷宫
 {
  cout<<"请输入迷宫的长和宽:";
  int a,b;
  cin>>a>>b;             //输入迷宫的长和宽
  cout<<"请输入迷宫内容:/n";
  m=a;
  n=b;          //m,n分别代表迷宫的行数和列数
  maze=new int *[m+2];  //申请长度等于行数加2的二级指针
  for(i= 0;i<m+2;i++)  //申请每个二维指针的空间
  {
   maze[i]=new int[n+2];
  }
  for(i=1;i<=m;i++)          //输入迷宫的内容，1代表可通，0代表不通
   for(j=1;j<=n;j++)
    cin>>maze[i][j];
  cout<<"是否保存新迷宫？/n";
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
//给迷宫的四周加一堵墙，即把迷宫四周定义为1
 for(i=0;i<m+2;i++)
  maze[i][0]=maze[i][n+1]=1;
 for(i=0;i<n+2;i++)
  maze[0][i]=maze[m+1][i]=1;
 return maze;              //返回存贮迷宫的二维指针maze
}
bool Mazepath(int **maze,int m,int n)
          //寻找迷宫maze中从（0，0）到（m,n）的路径
           //到则返回true,否则返回false
{
 stack q,p;       //定义栈p、q,分别存探索迷宫的过程和存储路径
 DataType Temp1,Temp2;
 int x,y,loop;
 Temp1.x=1;
 Temp1.y=1;
 q.Push(Temp1);           //将入口位置入栈
 p.Push(Temp1);
 maze[1][1]=-1;          //标志入口位置已到达过
 while(!q.IsEmpty())      //栈q非空，则反复探索
 {
  Temp2=q.GetPop();      //获取栈顶元素
  if(!(p.GetPop().x==q.GetPop().x&&p.GetPop().y==q.GetPop().y))
   p.Push(Temp2);
     //如果有新位置入栈，则把上一个探索的位置存入栈p
  for(loop=0;loop<4;loop++)   //探索当前位置的4个相邻位置
  {
   x=Temp2.x+move[loop].x;     //计算出新位置x位置值
   y=Temp2.y+move[loop].y;      //计算出新位置y位置值
   if(maze[x][y]==0)         //判断新位置是否可达
   {
    Temp1.x=x;
    Temp1.y=y;
    maze[x][y]=-1;          //标志新位置已到达过
    q.Push(Temp1);         //新位置入栈
   }
   if((x==(m))&&(y==(n)))    //成功到达出口
   {
    Temp1.x=m;
    Temp1.y=n;
    Temp1.pre=0;
    p.Push(Temp1);       //把最后一个位置入栈
    PrintPath(p);        //输出路径
    Restore(maze,m,n);        //恢复路径
    return 1;            //表示成功找到路径
   }
  }
  if(p.GetPop().x==q.GetPop().x&&p.GetPop().y==q.GetPop().y)
        //如果没有新位置入栈，则返回到上一个位置
  {
   p.Pop();
   q.Pop();
  }
 }
 return 0;           //表示查找失败，即迷宫无路经
}
void PrintPath(stack p)        //输出路径
{
 cout<<"迷宫的路径为/n";
 cout<<"括号内的内容分别表示为(行坐标,列坐标,数字化方向,方向)/n";
 stack t;            //定义一个栈，按从入口到出口存取路径
 int a,b;
 DataType data;
 LinkNode *temp;
 temp=new LinkNode;         //申请空间
 temp->data=p.Pop();        //取栈p的顶点元素，即第一个位置
 t.Push(temp->data);  //第一个位置入栈t
 delete temp;         //释放空间
 while(!p.IsEmpty())    //栈p非空，则反复转移
 {
  temp=new LinkNode;
  temp->data=p.Pop();         //获取下一个位置
  //得到行走方向
  a=t.GetPop().x-temp->data.x;   //行坐标方向
  b=t.GetPop().y-temp->data.y;   //列坐标方向
  if(a==1) temp->data.pre=1;     //方向向下，用1表示
  else if(b==1) temp->data.pre=2; //方向向右，用2表示
  else if(a==-1) temp->data.pre=3;  //方向向上，用3表示
  else if(b==-1) temp->data.pre=4;  //方向向左，用4表示
  t.Push(temp->data);            //把新位置入栈
  delete temp;
 }
 //输出路径，包括行坐标，列坐标，下一个位置方向
 while(!t.IsEmpty())         //栈非空，继续输出
 {
  data=t.Pop();
  cout<<'('<<data.x<<','<<data.y<<','<<data.pre<<",";  //输出行坐标，列坐标
  switch(data.pre)   //输出相应的方向
  {
  case 1:cout<<"↓)/n";break;
  case 2:cout<<"→)/n";break;
  case 3:cout<<"↑)/n";break;
  case 4:cout<<"←)/n";break;
  case 0:cout<<")/n";break;
  }
 }
}
void Restore(int **maze,int m,int n)       //恢复迷宫
{
 int i,j;
 for(i=0;i<m+2;i++)            //遍历指针
  for(j=0;j<n+2;j++)
  {
   if(maze[i][j]==-1)         //恢复探索过位置，即把-1恢复为0
    maze[i][j]=0;
  }
}
