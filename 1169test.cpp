#include<stdio.h>
#include<cstdlib>
#include<ctime>

int n;
void test(int t1, int t2)
{
    while (!(t1 == n && t2 == n - 1))
    {
    if (t1 - t2 >= 2)
    {
        int a = rand() %2;
        if (a == 0 && t1 < n)
        {
            t1 ++;
            double tt = (rand() % n)* 1.0 / n * (n + 1);
            printf("%lf ", tt);
        }
        else
        {
            t2 ++;
            a = rand() % 4;
            switch (a){
                case 0:
                    printf("+ ");
                    break;
                case 1:
                    printf("- ");
                    break;
                case 2:
                    printf("* ");
                    break;
                case 3:
                    printf("/ ");
                    break;
            }
        }
    }
    else
    {
        t1 ++;
        double tt = (rand() % 100)* 1.0 / n * (n + 1);
        printf("%lf ", tt);
    }
    }
}
int main()
{
     srand( (unsigned)time( NULL ) );
    n = 20;
    int t1 = 0, t2 = 0;
    freopen("1169_4.in", "w", stdout);
    test(t1, t2);
    fclose(stdout);
    return 0;
}
