#include <cstdio>
void swap1(int &a,int &b)
{
    int t;
    t=a; a=b; b=t;
}
void maxheap(int a[],int j)
{
    int i;
    while (j>1)
    {
        i=j/2;
        if (a[i]<a[j])
        swap1(a[i],a[j]);
        else break;
        j=i;
    }
    return;
}
void heapify(int a[],int top)
{
    int largest,t=1;
    while (t<top)
    {
        if ((2*t<=top)&&(a[2*t]>a[t])) largest=2*t;
        else largest=t;
        if ((2*t+1<=top)&&(a[2*t+1]>a[largest])) largest=2*t+1;
        if (largest==t) break;
        else
        {
            swap1(a[t],a[largest]);
            t=largest;
        }
    }
    return;
}
int main()
{
    int a[200],num;
    scanf("%d",&num);
    int top=num;
    for(int i=1; i<=num; i++)
    {
        scanf("%d",&a[i]);
        maxheap(a,i);
    }
    for (int i=1; i<num; i++)
    {
        swap1(a[1],a[num-i+1]);
        top--;
        heapify(a,top);
    }
    for (int i=1; i<num; i++)
        printf("%d ",a[i]);
    printf("%d\n",a[num]);
    return 0;
}
