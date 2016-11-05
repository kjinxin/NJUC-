#include<stdio.h>
#include<fstream>
#include<time.h>
#include<stdlib.h>
int main()
{
    srand( (unsigned)time( NULL ) );
    freopen("heap5.in", "w", stdout);
    int l1 = 0, l2 = 0;
    int t;
    for(int i = 0; i < 500000; i ++)
    {
        t = rand() % 2;
        if (l1 <= l2 || t == 0)
        {
            printf("0 %d\n", rand());
            l1 ++;
        }
        else
        {
            printf("1\n");
            l2 ++;
        }
    }
    fclose(stdout);
}
