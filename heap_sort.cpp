#include<iostream>

using namespace std;

void down_tree(int* p, int current, int n)
{
	while (current < n / 2)
	{
		int small = current;
		if (2 * current + 1 < n && p[small] > p[2 * current + 1]) small = 2 * current + 1;
		if (2 * (current + 1) < n && p[small] > p[2 * (current + 1)]) small = 2 * (current + 1);
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
		if (p[current] < p[fa])
		{
			int temp = p[current]; p[current] = p[fa]; p[fa] = temp;
			current = fa;
		}
		else break;
    }
}
void build_heap(int* p, int n)
{
	for (int i = n / 2 - 1; i >= 0; i --)
    down_tree(p, i, n);
}

void heap_sort(int* p, int n)
{
	for (int i = 0; i < n - 1; i ++)
	{
	    //cout<< p[0] << endl;
		int temp = p[0]; p[0] = p[n - i - 1]; p[n - i - 1] = temp;
		down_tree(p, 0, n - i - 1);
	}
}
int main()
{
	int n;
	cin >> n;
	int * p = new int[n]();
	for (int i = 0; i < n; i ++) cin >> p[i];
	build_heap(p, n);
	heap_sort(p, n);
	for (int i = 0; i < n; i ++) cout << p[i] << endl;
	delete []p;
}
