#include<stdio.h>

double a[1000010];
int main()
{
    int top = 0;
    char b[100], c;
    double data;
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
    printf("%.3lf\n", a[top - 1]);
    return 0;
}
