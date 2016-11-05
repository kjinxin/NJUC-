#include <iostream>
#include <string>
using namespace std;
long int n,len;
string s,word[500];
long int t[500],path[5000];
string ans[50000];
long int t_ans;
void search(long int k,long int top)
{
  if (k>=len)
  {
    t_ans++;
    ans[t_ans]=word[path[1]];
    for (long int col=2;col<=top;col++)
        ans[t_ans]=ans[t_ans]+' '+word[path[col]];
  }
  else
  {
    for (long int col=1;col<=n;col++)
    if (k+t[col]<=len)
    {
      bool boo=true;
      for (long int row=0;row<=t[col]-1;row++)
          if (s[k+row]!=word[col][row]) boo=false;
      if (boo)
      {
        path[top+1]=col;
        search(k+t[col],top+1);
      }
    }
  }
}
void qsort(long int left,long int right)
{
  string  a=ans[(left+right)/2];
  long int i=left,j=right;
  while (i<=j)
  {
    while (ans[i]<a) i++;
    while (a<ans[j]) j--;
    if (i<=j)
    {
      string temp=ans[i];ans[i]=ans[j];ans[j]=temp;
      i++;j--;
    }
  }
  if (left<j) qsort(left,j);
  if (i<right) qsort(i,right);
}
int main()
{
  int T;
  cin>>T;
  for (long int p=1;p<=T;p++)
  {
     cin>>n;
     for (long int col=1;col<=n;col++)
         cin>>word[col];
     cin>>s;
     len=s.size();
     for (long int col=1;col<=n;col++) t[col]=word[col].size();
     t_ans=0;
     search(0,0);
     qsort(1,t_ans);
     cout<<p<<endl;
     for (long int col=1;col<=t_ans;col++)
          cout<<ans[col]<<endl;
  }
  cin.get();
  //cin.get();
  //cin.ignore();
  cin.ignore();
  return 0;
}
