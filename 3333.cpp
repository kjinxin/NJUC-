#include <cstdio>
#include <cstring>

int f[2005][2005],g[2005][2005];
char s[2005];
char temp[2005];
int next[2005];

inline void findnext(char *p)
{
	next[0]=-1;
	int j=0;
	int k=-1;
	while ( j < strlen(p)-1)
	{
		if (k==-1 || p[j]==p[k])
		{
			j++;
			k++;
			next[j]=k;
		}
		else
			k=next[k];
	}
}


int main(){
    int T;
    scanf("%d\n",&T);
    int Q,left,right;
    while (T --){
        scanf("%s",s);
        int len = strlen(s);
        for (int i = 0; i < len; i ++) f[i][i] = 1;
        for (int j = 1; j < len; j ++){
            for (int i = j; i >=0; i --)
                temp[j-i] = s[i];
            temp[j+1] = '#';
            temp[j+2] = '\0';
            findnext(temp);
            int max = next[1];
            for (int  i = 1; i <= j; i ++){
                if (next[i+1] > max) max = next[i+1];
                f[j-i][j] = f[j-i][j-1]+1+i-max;
            }
        }
        scanf("%d",&Q);
        for (int i = 0; i < Q; i ++){
            scanf("%d%d",&left,&right);
            printf("%d\n",f[left-1][right-1]);
        }
    }
    return 0;
}

