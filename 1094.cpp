#include<cstdio>

int main()
{
    int T;
    scanf("%d",&T);
    int a[202],b[202],n,pp,suma[202],sumb[202],sum1,sum2,ansa,ansb,num1,num2;
    for (int p=0; p<T; p++)
    {
        scanf("%d",&n);
        sum1=0; sum2=0;
        for (int i=1; i<=n; i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            sum1+=a[i]; sum2+=b[i];
        }
        ansa=10000000; ansb=10000000; suma[0]=0; sumb[0]=0;
        for (int i=1; i<=n; i++)
        {
            for (int j=i+1; j<=n; j++)
            {
                if (a[j]<a[i])
                {
                    pp=a[i]; a[i]=a[j]; a[j]=pp;
                }
                if (b[j]<b[i])
                {
                    pp=b[i]; b[i]=b[j]; b[j]=pp;
                }
            }
            suma[i]=suma[i-1]+a[i];
            sumb[i]=sumb[i-1]+b[i];
            if (sum1+(2*i-n)*a[i]-2*suma[i]<ansa)
            {
                ansa=sum1+(2*i-n)*a[i]-2*suma[i];
                num1=i;
            }
            if (sum2+(2*i-n)*b[i]-2*sumb[i]<ansb)
            {
                ansb=sum2+(2*i-n)*b[i]-2*sumb[i];
                num2=i;
            }
        }
        if (p!=T-1) printf("%d %d\n",a[num1],b[num2]);
        else printf("%d %d",a[num1],b[num2]);
    }
    return 0;
}
