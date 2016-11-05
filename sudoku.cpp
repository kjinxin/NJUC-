/*从数独看搜索思维

下面是数独问题的题目

Description

Sudoku is a very simple task. A square table with 9 rows and 9 columns is divided to 9 smaller squares 3x3 as shown on the Figure. In some of the cells are written decimal digits from 1 to 9. The other cells are empty. The goal is to fill the empty cells with decimal digits from 1 to 9, one digit per cell, in such way that in each row, in each column and in each marked 3x3 subsquare, all the digits from 1 to 9 to appear. Write a program to solve a given Sudoku-task.

很容易看出，通过搜索我们可以很轻松的解决数独问题。

因为我想通过数独问题浅谈一下搜索的思维，所以我想从最简单的搜索数独解法开始，看看我们是如何想到搜索解法又是如何优化的。

（一）我们先看一下什么是一个合法的数独：

1.在数独的81个小格子里都要填进1——9中的任意一个数字。

2.每一行都要包含1——9中的任意一个数字。

3.每一列都要包含1——9中的任意一个数字。

4.每一个小九宫格中都要包含1——9中的任意一个数字。

（二）在既定的数独中已经填入了一些数字。所以我们需要做的，便是在不违反以上规则的情况下，填入其他的相应数字。这样，我们将九宫格的每一个小格编号为1——81，我们可以定义一个函数fillin（top），表示向第top个小格中填入1——9中的任意一个数字。

Fillin（top）

{

If （top>81） return;//表示正确的填完数独；

For （i= 1，i<=9; i++）

If 在第top小格中填入数字i，且满足数独的定义//标注一

Then

Fillin（top+1）；

}

倘若fillin 能顺利的完成我们想要它做的事情，那么数独问题就解决了。现在我们唯一需要知道的是“标注一”如何实现？

最简单的方法也是最浪费效率的方法便是去将整个数独群举一遍，看当前的数独是否满足以下条件：

所填数字所在的

1. 那一列是否有重复的数字？

2. 那一行是否有重复的数字？

3. 那一个小九宫格中是否有重复的数字？

这样，数独问题便得到了解决，那么这个搜索的效率怎么样呢？

我们计算一下最坏的情况：我们需要搜索9的81次方的节点数，每一个节点耗费的代价为27。

因此，只要题目数据出的稍微烂一点，我们的这个算法就基本上解决不了问题。

所以，这就需要优化，首先，我们可以考虑，每次判断节点真的需要27的查找吗？

答案是：不需要！

通过计算，我们不难发现，每一行，每一列，每一个九宫格似乎都满足一定的特性：

因此我们定义三个数组：heng【10】【10】 Lie【10】【10】ge【10】【10】

分别表示，某一行有没有该元素，某一列有没有该元素，某一个小九宫格有没有该元素。而fillin（top），恰恰是在试着在某个小格子里填入1——9中的数字。这样，有了这三个数组，我们在判断top格子里能否填入某个数字时，只需要O（1）的judge。

以下是我优化过后的代码：*/
/*
#include<iostream>
#include<fstream>
using namespace std;
*/
/*
heng【10】【10】表示在那一行有没有该元素；
lie【10】【10】表示在那一列有没有该元素；
ge【10】【10】表示在那一个小格子里有没有该元素；
上述三个数组主要是用来判断有没有放过和放重了没有；
*/
/*
int a[10][10],heng[10][10],lie[10][10],ge[10][10];
int num;
bool o=false;
//ifstream fin("1.in.txt");
//ofstream fout("1.out");
void fillin(int p)
{
    //fout<<p<<endl;
    if (o) return;
    if (p>81) {o=true; return;}
    int i=(p-1)/9+1,j=p-(i-1)*9;        //求出p所在格子的行与列
    if (a[i][j]!=0)//说明这个元素原来读入是就已经有了；
    {
        fillin(p+1);
        return;
    }
    for (int t=1; t<10; t++)
    {
        if ((heng[i][t]==0)&&(lie[j][t]==0)&&(ge[(j-1)/3+1+((i-1)/3)*3][t]==0))  //判断能否在（i，j）这个格子里填入t
        {
            heng[i][t]=1;
            lie[j][t]=1;
            ge[(j-1)/3+1+((i-1)/3)*3][t]=1;
            a[i][j]=t;      //标记该行列格已被占领
            fillin(p+1);  //搜索下一个小格子
            if (o) return;
            a[i][j]=0;
            heng[i][t]=0;
            lie[j][t]=0;
            ge[(j-1)/3+1+((i-1)/3)*3][t]=0;  //回溯
        }
    }
}
int main()
{
    cin>>num;
    for (int t=1; t<=num; t++)
    {
        o=false;
        for (int i=1; i<10; i++)
        for (int j=1; j<10; j++)
        {
            heng[i][j]=0; lie[i][j]=0; ge[i][j]=0;
        }
        char c;
        for (int i=1; i<10; i++)
        for (int j=1; j<10; j++)
        {

            cin>>c;
            a[i][j]=c-'0';
            heng[i][a[i][j]]=1;
            lie[j][a[i][j]]=1;
            ge[(j-1)/3+1+((i-1)/3)*3][a[i][j]]=1;
        }
        fillin(1);// 从一一直填入到81；
        for (int i=1; i<10; i++)
        {
            for (int j=1; j<10; j++)
            cout<<a[i][j];
            cout<<endl;
        }
    }
    return 0;
}
*/
/*
以上是遇到数独问题自然而然就能想到的解法，那么有没有效率更高的算法呢？

于是我就翻阅了一些书籍，我才发现原来数独问题仅仅是精确覆盖问题（搜索的一大类型）的一个小问题罢了！

下面是精确覆盖模型的标准算法：//标注二

Solving an exact cover problem. The following nondeterministic algorithm, which I will call algorithm X for lack of a better name, finds all solutions to the exact cover problem defined by any given matrix A of 0s and 1s. Algorithm X is simply a statement of the obvious trial-and-error approach. (Indeed, I can’t think of any other reasonable way to do the job, in general.)

If A is empty, the problem is solved; terminate successfully.

Otherwise choose a column, c (deterministically).

Choose a row, r, such that A[r, c] = 1 (nondeterministically).

Include r in the partial solution.

For each j such that A[r, j] = 1,

delete column j from matrix A;

for each i such that A[i, j] = 1,

delete row i from matrix A.

Repeat this algorithm recursively on the reduced matrix A.

The nondeterministic choice of r means that the algorithm essentially clones itself into independent subalgorithms; each subalgorithm inherits the current matrix A, but reduces it with respect to a different row r. If column c is entirely zero, there are no subalgorithms and the process terminates unsuccessfully.

以上是精确覆盖的算法框架，然而具体实现却需要用到dancing links：

Dancing lingks 的本质是基于以下四个等式

{

L【R【x】】 ← L【x】 ， R【L【x】】 ← R【x】 将x节点删除；

L【R【x】】 ← x ，R【L【x】】 ← x   将x节点还原；

}

同样是减少了judge的时间

引入dancing links 后，我们的精确覆盖模型便可以改成这样：

The dance steps. One good way to implement algorithm X is to represent each 1 in the matrix A as a data object x with five fields L[x],R[x], U[x],D[x],C[x]. Rows of the matrix are doubly linked as circular lists via the L and R fields (“left” and “right”); columns are

doubly linked as circular lists via the U and D fields (“up” and “down”). Each column list also includes a special data object called its list header. The list headers are part of a larger object called a column object. Each column object y contains the fields L[y],R[y], U[y],D[y], and C[y] of a data object and two additional fields, S[y] (“size”) and N[y] (“name”); the size is the number of 1s in the column, and the name is a symbolic identifier for printing the answers. The C field of each object points

to the column object at the head of the relevant column.

The L and R fields of the list headers link together all columns that still need to be covered. This circular list also includes a special column object called the root, h, which serves as a master header for all the active headers. The fields U[h],D[h],C[h], S[h], and N[h] are not used.

For example, the 0-1 matrix of (3) would be represented by the objects shown in Figure 2, if we name the columns A, B, C, D, E, F, and G. (This diagram “wraps around” toroidally at the top, bottom, left, and right. The C links are not shown because they would clutter up the picture; each C field points to the topmost element in its column.)

Our nondeterministic algorithm to find all exact covers can now be cast in the following explicit, deterministic form as a recursive

核心部分

procedure search(k), which is invoked initially with k = 0:

If R[h] = h, print the current solution (see below) and return.

Otherwise choose a column object c (see below).

Cover column c (see below).

For each r ← D[c], DD[c], . . . , while r 6= c,

set Ok ← r;

for each j ← R[r], RR[r], . . . , while j 6= r,

cover column j (see below);

search(k + 1);

set r ← Ok and c ← C[r];

for each j ← L[r], LL[r], . . . , while j 6= r,

uncover column j (see below).

Uncover column c (see below) and return.

The operation of printing the current solution is easy: We successively print the rows

containing O0, O1, . . . , Ok−1, where the row containing data object O is printed by

printing NC[O], NC[R[O]], NC[R[R[O]]], etc.

为了方便理解精确覆盖模型以及dancing links的实现，我把节点（l，r，u，d，c）五个域之间的关系图附在下面：

那么数独问题又是如何向精确覆盖转化的呢？

仔细研究一下，我们不难发现，数独完全满足精确覆盖的条件。既然数独满足了精确覆盖的条件，那么我们所要做的，就是将数独转化为那个矩阵。我们令矩阵的行表示填入的方式，列表示填入的条件。那么，不难发现，数独问题的填入方式（也就是列数）共有：81*9=729种情况，因为每个小格子里都能填入1——9这九个数字。

那么条件呢？我们知道，在某个小格里填入一个数字后，他将会有如下影响：

1.81个小格有一个被它占领（1*81）；

2.有一列的某一个元素被它占领{9（某一行）*9（某一个元素）}；

3.有一行的某一个元素被它占领（同上9*9）;

4.有一个小九宫格的某一个元素被它占领{同上9（小宫格数）*9}

因此，总条件数（也就是总列数）是：81*4=324；

因此精确覆盖的矩阵大小为：729*324；

不难发现，在这个矩阵中，每一行都有四个条件被满足。

因为题目中的数独中已经填入了一些数字，所以，我们要在初始化的时候将已有的行与列删掉。

二.Dancing links solving sudoku.*/
#include<iostream>
#include<fstream>
using namespace std;
const int maxr=729,maxc=324;//表明该矩阵为729*324.
int r[maxc+maxr*5+10],l[maxc+maxr*5+10],u[maxc+maxr*5+10],d[maxc+maxr*5+10],head[10][10][10],
    row[maxc+maxr*5+10],map[10][10],ans[100],c[maxc+maxr*5+10],s[maxc+10],top=0;

ifstream fin("1.in");
ofstream fout("1.out");
void node(int c1,int cnt)//找到对应关系
{
     u[d[c1]]=cnt;
     d[cnt]=d[c1];
     u[cnt]=c1;
     d[c1]=cnt;
     s[c1]++;
     c[cnt]=c1;
}
void init()   //初始化
{
     for (int i=0; i<=maxc+maxr*5; i++)
     {
         r[i]=0; l[i]=0; u[i]=0; d[i]=0; c[i]=0; row[i]=0;
     }
     char c1;
     for (int i=1; i<=9; i++)
     for (int j=1; j<=9; j++)
     {
         fin>>c1;
         map[i][j]=c1-'0';
     }
     for (int i=0; i<=maxc; i++)
     {
         s[i]=0; l[i]=i-1; r[i]=i+1; u[i]=d[i]=i; c[i]=0;
     }
     l[0]=maxc; r[maxc]=0;
     int cnt=maxc;
     for (int i=1; i<=9; i++)
     for (int j=1; j<=9; j++)
     for (int k=1; k<=9; k++)
     {
         for (int u=1; u<=4; u++)
         {
             l[cnt+u]=cnt+u-1;
             r[cnt+u]=cnt+u+1;
             row[cnt+u]=81*(k-1)+(i-1)*9+j;
         }
         l[cnt+1]=cnt+4; r[cnt+4]=cnt+1;
         head[i][j][k]=cnt+1;
         node((i-1)*9+j,cnt+1);
         node(81+(k-1)*27+i,cnt+2);
         node(81+(k-1)*27+9+j,cnt+3);
         node(81+(k-1)*27+18+(j-1)/3+1+((i-1)/3)*3,cnt+4);
         cnt+=4;
     }    //建立原始矩阵（只是一种对应关系）
}
void remove(int c1)//将c1列去掉。并且将相应行也去掉。
{
     l[r[c1]]=l[c1]; r[l[c1]]=r[c1];
     for (int i=d[c1]; i!=c1; i=d[i])
     for (int j=r[i]; j!=i; j=r[j])
     {
         u[d[j]]=u[j];
         d[u[j]]=d[j];
         s[c[j]]--;
     }
}

void resume(int c1)//将c1列恢复，并将相应行恢复。记得顺序！！！！之前是d-r，现在是u-l。
{
     for (int i=u[c1]; i!=c1; i=u[i])
     for (int j=l[i]; j!=i; j=l[j])
     {
         u[d[j]]=j;
         d[u[j]]=j;
         s[c[j]]++;
     }
     l[r[c1]]=c1;
     r[l[c1]]=c1;
}
bool dfs(int k)
{
     //if (k>81) return true;
     if (r[0]==0) return true;
     int c1,minnum=10000000;
     for (int i=r[0]; i!=0; i=r[i])
     {
         if (!s[i]) return false;
         if (s[i]<minnum)
         {
            minnum=s[i]; c1=i;
         }
     }
     remove(c1);
     for (int i=d[c1]; i!=c1; i=d[i])
     {
         ans[k]=row[i];
         for (int j=r[i]; j!=i; j=r[j])
             remove(c[j]);
         if (dfs(k+1)) return true;
         for (int j=l[i]; j!=i; j=l[j])
             resume(c[j]);
     }
     resume(c1);
     return false;
}
void print()    //输出一个满足的解
{
    int x,y,num;
    for (int i=1; i<=81; i++)
    {
        num=(ans[i]-1)/81+1;
        x=(ans[i]-(num-1)*81-1)/9+1;
        y=ans[i]-(num-1)*81-(x-1)*9;
        map[x][y]=num;
    }
    for (int i=1; i<=9; i++)
    {
        for (int j=1; j<=9; j++)
        fout<<map[i][j];
        fout<<endl;
    }
}
int main()
{
    init();//初始化；
    for (int i=1; i<=9; i++)
    for (int j=1; j<=9; j++)
    if (map[i][j])   //将已经存在的元素在矩阵中去掉，就是删除并记录相应的行与列
    {
                     top++;
                     ans[top]=row[head[i][j][map[i][j]]];
                     remove(c[head[i][j][map[i][j]]]);
                     for(int u=r[head[i][j][map[i][j]]]; u!=head[i][j][map[i][j]]; u=r[u])
                     remove(c[u]);
    }
    dfs(top+1);//我们一共要填入81个数，但因为已经给了top个数，所以只需要搜索剩下的即可
    print();
    return 0;
}
