#include<cstdio>

void sort(int m,int n,int s[],int l[])
{
    int t,x,l1,l2;
    l1=m; l2=n;
    x=s[(l1+l2)/2];
    do
    {
        while (s[l1]<x) l1++;
        while (s[l2]>x) l2--;
        if (l1<=l2)
        {
            t=s[l1]; s[l1]=s[l2]; s[l2]=t;
            t=l[l1]; l[l1]=l[l2]; l[l2]=t;
            l1++;
            l2--;
        }
    }while (l1<=l2);
    if (l1<n) sort(l1,n,s,l);
    if (l2>m) sort(m,l2,s,l);
}
int main()
{
   int m,n,ans,a[100010],s[100010],l[100010];
   while(scanf("%d%d",&n,&m)!=EOF)
   {
       a[0]=0; s[0]=0;
       for (int i=1; i<=n; i++)
       {
           scanf("%d",&a[i]);
           a[i]%=m;
           if (a[i]<0) a[i]+=m;
       }
       s[1]=a[1]; l[1]=1;
       ans=0;
       for (int i=2; i<=n; i++)
       {
           s[i]=s[i-1]+a[i];
           s[i]%=m;
           if (s[i]<0) s[i]+=m;
           l[i]=i;
       }
       sort(1,n,s,l);
       for (int i=1; i<=n; i++)
       {
           int j=i;
           while (j>=0)
           {
               if (s[j]!=s[i])
               break;
               int t=l[j]-l[i];
               if (t<0) t=-t;
               if (t>ans) ans=t;
               j--;
           }
       }
       printf("%d\n",ans);
   }
   return 0;
}
