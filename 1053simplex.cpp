#include<cstdio>
#include<cstdlib>
#include<cstring>

const int maxm=1000000000;
struct node
{
	int a,b,c,v;
};

void pivot(double a[][210],double b[],double c[],int n,int m,double &v,int l,int e)
{
	b[l]=b[l]/a[l][e];
	for (int j=1; j<=n; j++)
	{
		if (j==e) continue;
		a[l][j]=a[l][j]/a[l][e];
	}
	a[l][e]=1/a[l][e];
	for (int i=1; i<=m; i++)
	{
		if (i==l) continue;
		b[i]=b[i]-a[i][e]*b[l];
		for (int j=1; j<=n; j++)
		{
			if (j==e) continue;
			a[i][j]-=a[i][e]*a[l][j];
		}
		a[i][e]=-a[i][e]*a[l][e];
	}
	v+=c[e]*b[l];
	for (int j=1; j<=n; j++)
	if (j==e) continue;
	else
	c[j]-=c[e]*a[l][j];
	c[e]=-c[e]*a[l][e];
	return;
}
void simplex(double a[][210],double b[],double c[],int n,int m)
{
	bool o=true;
	int e;
	double v=0;
	while (o)
	{
		o=false;
		for (int i=1; i<=n; i++)
		if (c[i]>0)
		{
 			o=true; e=i; break;
		}
		if (!o) break;
		int k=maxm,l;
		for (int i=1; i<=m; i++)
		{
			if ((a[i][e]>0)&&(b[i]/a[i][e]<k))
			{
				k=b[i]/a[i][e];
				l=i;
			}
		}
		if (k==maxm)
		{
			printf("unbounded"); break;
		}
		else
		pivot(a,b,c,n,m,v,l,e);
	}
	printf("%.f\n",v);
}
int main()
{
	int n,s,h;
	node data[210];
	double c[210],a[210][210],b[210];
	scanf("%d%d%d",&n,&s,&h);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d%d%d",&data[i].a,&data[i].b,&data[i].c,&data[i].v);
	}
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	memset(b,0,sizeof(b));
	for (int i=1; i<=n; i++)
	{
		c[i]=data[i].v;
		b[i]=data[i].c;
		a[i][i]=1;
		a[n+1][i]=data[i].a;
		a[n+2][i]=data[i].b;
	}
	b[n+1]=s; b[n+2]=h;
	simplex(a,b,c,n,n+2);
}
