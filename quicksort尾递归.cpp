#include <cstring>
#include <ctime>
#include <cstdio>
#include <cstdlib>
int Partition(int *a,int p,int r)
{
    int tmp=0,i=0,j=0;
    i=p-1;
    for(j=p;j<r;j++)
    if(a[j]<=a[r])
    {
        i++; tmp=a[i]; a[i]=a[j]; a[j]=tmp;
    }
    tmp=a[i+1]; a[i+1]=a[r]; a[r]=tmp;
    return i+1;
}

int RandomPartition(int *a,int p,int r)
{
    int min=0,mid=0,max=0,i=0,j=0,k=0,tmp=0;
    srand((unsigned)time(NULL));
    i=rand()%(r-p+1)+p;
    j=rand()%(r-p+1)+p;
    k=rand()%(r-p+1)+p;

    min=a[i];
    mid=a[j];
    max=a[k];

    min=(min<mid)?min:mid;
    mid=(mid<max)?mid:max;
    mid=(mid>min)?mid:min;
    if(a[i]==mid)
    {
        tmp=a[i]; a[i]=a[r]; a[r]=tmp;
    }
    else if(a[j]==mid)
    {
        tmp=a[j]; a[j]=a[r]; a[r]=tmp;
    }
    else if(a[k]==mid)
    {
        tmp=a[k]; a[k]=a[r]; a[r]=tmp;
    }
    return Partition(a,p,r);
}

void QuickSort(int *a,int p,int r)
{
    int q=0;
    while(p<r)
    {
        q=RandomPartition(a,p,r);
        QuickSort(a,p,q-1);
        p=q+1;
    }
}

int main()
{
    int i=0;
    int j=0;
    int a[200];
    int BUFFER_SIZE;
    scanf("%d",&BUFFER_SIZE);
    for(j=0;j<BUFFER_SIZE;j++)
        scanf("%d",&a[j]);
    QuickSort(a,0,BUFFER_SIZE-1);
    printf("%d",a[0]);
    for(i=1;i<BUFFER_SIZE;i++)
        printf(" %d",a[i]);
    printf("\n");
    return 0;
}
