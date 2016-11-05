#include <cstdio>
#include <cstdlib>

void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int choose_pivot(int i,int j )
{
    return((i+j) /2);
}

void quicksort(int list[],int m,int n)
{
    int key,i,j,k;
    if( m < n)
    {
        k = choose_pivot(m,n);
        swap(&list[m],&list[k]);
        key = list[m];
        i = m+1;
        j = n;
        while(i <= j)
        {
        while((i <= n) && (list[i] <= key))
                i++;
        while((j >= m) && (list[j] > key))
                j--;
        if( i < j)
                swap(&list[i],&list[j]);
        }
    // ��������Ԫ�ص�λ��
        swap(&list[m],&list[j]);
    // �ݹ�ضԽ�С���������н�������
        quicksort(list,m,j-1);
        quicksort(list,j+1,n);
    }
}

void printlist(int list[],int n)
{
    int i;
    printf("%d",list[0]);
    for(i=1;i<n;i++)
        printf(" %d",list[i]);
    printf("\n");
}

int main()
{
    int MAX_ELEMENTS ;
    int list[200];
    scanf("%d",&MAX_ELEMENTS);
    int i = 0;

    // ����������е������
    for(i = 0; i < MAX_ELEMENTS; i++ )
        scanf("%d",&list[i]);
    quicksort(list,0,MAX_ELEMENTS-1);
    printlist(list,MAX_ELEMENTS);
}
