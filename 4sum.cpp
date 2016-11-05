#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <fstream>
#define init(N,s) {for(int i=1;i<=N;i++) fin>> *(s+i);}
using namespace std;

ifstream fin("1165_2.in");
ofstream fout("1165_2.out");

int a,b,c,d;
int sa[1050],sb[1050],sc[1050],sd[1050];
struct data{
	int val;
	pair<int,int> source;
}s1[1000010],s2[1000010];
int n1,n2;

bool cmp(const data &a,const data &b){
	return a.val<b.val;
}
void merge(data *s,int *a,int *b,int na,int nb,int &tot){
	tot=0;
	for(int i=1;i<=na;i++)
		for(int j=1;j<=nb;j++)
			s[++tot]=(data){a[i]+b[j],make_pair(i,j)};
}
int main(){
	//scanf("%d%d%d%d",&a,&b,&c,&d);
	fin>> a>>b>>c>>d;
	init(a,sa);
	init(b,sb);
	init(c,sc);
	init(d,sd);
	merge(s1,sa,sb,a,b,n1);
	merge(s2,sc,sd,c,d,n2);
	sort(s1+1,s1+n1+1,cmp);
	sort(s2+1,s2+n2+1,cmp);
	int i=1,j=n2;
	while(i<=n1&&j){
		if(s1[i].val<-s2[j].val) i++;
		else if(s1[i].val>-s2[j].val) j--;
		else{
			fout<<sa[s1[i].source.first]<<" "<< sb[s1[i].source.second]<<" "<<sc[s2[j].source.first]<<" " <<sd[s2[j].source.second]<<endl;
			return 0;
		}
	}
	return 0;
}
