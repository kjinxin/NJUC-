#include <stdio.h>
#include <math.h>
#include <string.h>

struct{ double x,y; } coor[2000];
double f[1000][1001][2],dis[2000][2000];

double sqr(double x)
{
	return x*x;
}

double min(double a,double b)
{
	return a>b?b:a;
}

int main(void)
{
	int n,i,j,s,l;
	double ans=1000000000.0;

	scanf("%d",&n);
	memset(f,0x7f,sizeof(f));
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf",&coor[i].x,&coor[i].y);
		coor[i+n].x=coor[i].x;
		coor[i+n].y=coor[i].y;
		f[i][1][1]=0;
		f[i][1][0]=0;
	}

	for(i=0;i<n*2;i++)
		for(j=0;j<n*2;j++)
			dis[i][j]=sqrt(sqr(coor[i].x-coor[j].x) + sqr(coor[i].y-coor[j].y));

	for(l=2;l<=n;l++)
		for(s=0;s<n;s++)
		{
			f[s][l][0]=min( dis[s][s+1] + f[s+1][l-1][0],
					dis[s][s+l-1] + f[s+1][l-1][1] );
			f[s][l][1]=min( dis[s+l-1][s+l-2] + f[s][l-1][1],
					dis[s+l-1][s] + f[s][l-1][0] );
		}

	ans=f[0][n][0];

	printf("%.3lf\n",ans);
	return 0;
}
