#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MX 300000
int num[MX];
int sort[MX] , dw[MX];
int M , D , N;

void task1(){
    M = 0;
    sort[0] = num[0];
    for(int i=1 ; i<N ; i++)
    {
        int low=0,high=M;
        while(low <= high)
        {
            int mid = (low + high)>>1;
            if( sort[mid] >= num[i])
                low = mid + 1;
            else
                high = mid - 1;
        }
        sort[low] = num[i];

        if( low > M)
        {
            M++;
        }
    }
    printf("%d\n" , M+1);
}

void task2(){
    M = 0;
    dw[0] = num[0];
    for(int i=1 ; i<N ; i++)
    {
        int low=0,high=M;
        while(low <= high)
        {
            int mid = (low + high)>>1;
            if( dw[mid] < num[i])
                low = mid + 1;
            else
                high = mid - 1;
        }
        dw[low] = num[i];

        if( low > M)
        {
            M++;
        }
    }
    printf("%d\n" , M+1);
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i ++)
        scanf("%d", &num[i]);
    task1();
    task2();
    return 0;
}
