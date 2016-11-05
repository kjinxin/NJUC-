#include<cstdio>
#include<cstring>
int main()
{
    int n,length,M[310][310];
    bool hash[310][310];
    scanf("%d",&n);
    char st[400];
    for (int p=0; p<n; p++)
    {
        scanf("%s",st);
        length=strlen(st);
        memset(M,0,sizeof(M));
        memset(hash,0,sizeof(hash));
        for(int len=1; len<=length; len++)
        {
           for(int i=0; i<length-len+1; i++)
           {

                int j=i+len-1;
                if(len==1)
                    hash[i][j]=true;
                else if(len==2)
                    hash[i][j]=(st[i]==st[j]);
                else
                    hash[i][j]=(st[i]==st[j]) && hash[i+1][j-1];
                if(hash[i][j])
                    M[i][j] = 0;
                else
                {
                    int min = 99999;
                    for(int k=i; k<j; k++)
                        min=(min>M[i][k]+M[k+1][j]+1)?(M[i][k]+M[k+1][j]+1):min;
                    M[i][j] = min;
                }
           }
        }
        printf("%d\n",M[0][length-1]+1);
    }
    return 0;
}
