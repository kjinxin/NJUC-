#include <cstdio>
#include <cstdlib>
#include <cstring>

void print_arry(int *arr,int n)
{
    int i;
    printf("%d",arr[0]);
    for(i = 0; i<n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}
void count_sort(int *arr, int *sorted_arr, int n)
{
    int count_arr[200];
    int i;
    memset(count_arr,0,sizeof(count_arr));
    for(i = 0;i<n;i++)
        count_arr[arr[i]]++;
    for(i = 1; i<100; i++)
        count_arr[i] += count_arr[i-1];
    for(i = n; i>0; i--)
    {
        sorted_arr[count_arr[arr[i-1]]-1] = arr[i-1];
        count_arr[arr[i-1]]--;
    }
}
int main() {
    int n,i;
    scanf ("%d", &n);

    int arr[200];
    int sorted_arr[200];
    for (i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    count_sort(arr, sorted_arr, n);
    print_arry(sorted_arr, n);
    return 0;
}
