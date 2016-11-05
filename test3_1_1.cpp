#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int heap[1000000], n;
void down_tree(int* p, int current, int n)
{
	while (current < n / 2)
	{
		int small = current;
		if (2 * current + 1 < n && p[small] < p[2 * current + 1]) small = 2 * current + 1;
		if (2 * (current + 1) < n && p[small] < p[2 * (current + 1)]) small = 2 * (current + 1);
		if (small == current) break;
		int temp = p[current]; p[current] = p[small]; p[small] = temp;
		current = small;
    }
}

void up_tree(int *p, int current, int n)
{
	while(current > 0)
	{
		int fa = (current - 1) / 2;
		if (p[current] > p[fa])
		{
			int temp = p[current]; p[current] = p[fa]; p[fa] = temp;
			current = fa;
		}
		else break;
    }
}
int main()
{
    int a, b;
    n = 0;
    freopen("heap5.in", "r", stdin);
    freopen("heap5.out", "w", stdout);
    while(scanf("%d", &a) != EOF)
    {
        if (a == 0)
        {
            scanf("%d", &b);
            heap[n] = b; n ++;
            up_tree(heap, n - 1, n);
        }
        else
        {
            printf("%d\n", heap[0]);
            heap[0] = heap[n - 1];
            n --;
            down_tree(heap, 0, n);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
