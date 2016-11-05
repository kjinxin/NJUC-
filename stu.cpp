#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;

const int maxn=200;
int n,a[maxn];
bool flag,v[maxn];

void dfs(int x,int z)
{
	if(z==n)
	{
		flag=1;
		return;
	}
	if(x>2*n)
	{
		return;
	}
	if(a[x]!=0)dfs(x+1,z);else
	for(int i=n;i>=1;--i)
	{
		if(x+i+1>2*n)continue;
		if(!v[i])
		{
			if(a[x+i+1]==0)
			{
				a[x]=a[x+i+1]=i;
				v[i]=1;
				dfs(x+1,z+1);
				if(flag)return;
				v[i]=0;
				a[x]=a[x+i+1]=0;
			}
		}
	}
}

int main()
{
//	freopen("1.txt","r",stdin);
	//while(scanf("%d",&n)!=-1)
	{
		scanf("%d",&n);

		if(((n%4)==1)||((n%4)==2))
		{
			printf("No Solution.\n");
		}else

		{
			memset(a,0,sizeof(a));
			memset(v,0,sizeof(v));
			flag=false;
			dfs(1,0);
			if(flag)
			{
				for(int i=1;i<=2*n;++i)
					if(i==(2*n))printf("%d\n",a[i]);
					else printf("%d ",a[i]);
			}else printf("No Solution.\n");
		}
	}
	return 0;
}
