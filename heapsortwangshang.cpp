#include<cstdio>

void heapAjust(int array[],int root,int n)
{
    int i = root;
    int j = root*2;
    int tmp;
    while(j <= n)
    {
        if(j < n && array[j+1] < array[j])
            j = j+1;
        if(array[i] > array[j])
        {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            int i = j;
            int j = i*2;
        }
        else
        {
            j = n+1;
        }
    }
}
void heapSort(int array[],int n)
{
    int i;
    int tmp;
    for(i = n/2; i >=0; i--)
    {
            heapAjust(array,i,n);
    }
    for(i = n; i > 0; i--)
    {
        tmp = array[i];
        array[i] = array[0];
        array[0] = tmp;
        heapAjust(array,0,i-1);
    }
}
int main()
{
    int i;
    int array[100];
    int n;
    scanf("%d",&n);
    heapSort(array,n);
    printf("%d",array[0]);
    for(i = 1; i < n; i++)
    {
        printf("%d",array[i]);
    }
    printf("\n");
    return 0;
}
