#include<stdio.h>

double a[1000010];
int main()
{
    int top = 0;
    char b[100], c;
    double data;
    freopen("1169_4.in", "r", stdin);
    while(scanf("%s", b) != EOF)
    {
        char c = b[0];
        switch (c) {
            case '+':
                top --;
                a[top - 1] = a[top - 1] + a[top];
                break;
            case '-':
                top --;
                a[top - 1] = a[top - 1] - a[top];
                break;
            case '*':
                top --;
                a[top - 1] = a[top - 1] * a[top];
                break;
            case '/':
                top --;
                a[top - 1] = a[top - 1] / a[top];
                break;
            default:
                sscanf(b, "%lf", &data);
                a[top] = data;
                top ++;

        }
    }
    fclose(stdin);
    freopen("1169_4.out", "w", stdout);
    printf("%.3lf\n", a[top - 1]);
    fclose(stdout);
    return 0;
}
