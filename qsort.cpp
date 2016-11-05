#include<iostream>

using namespace std;

int partition(int *p, int l, int r)
{
	int l1 = l, r1 =l, pivot = p[r];
            for (; r1 <r; r1 ++)
	{
		if (p[r1] < pivot)
		{
			int temp = p[r1];
			p[r1] = p[l1]; p[l1] = temp;
			l1 ++;
		}
	}
	int temp = p[r];
	p[r] = p[l1]; p[l1] = temp;
	return l1;
}
void qsort(int * p, int l , int r)
{
	int pivot = partition(p, l, r);
if (l < pivot) qsort(p, l, pivot - 1);
if (pivot < r) qsort(p, pivot + 1, r);
}
int main()
{
	int n;
	cin >> n;
	int *p = new int[n]();
	for (int i = 0; i < n; i ++) cin >> p[i];
	cout <<n<<endl;
	qsort(p, 0, n - 1);
	cout<< p[1]<<endl;
	for (int i = 0; i < n; i ++) cout << p[i] <<endl;
	return 0;
}
