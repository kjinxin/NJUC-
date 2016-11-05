#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
ifstream fin("1129_test2.in");
int count(vector<int>&, int p, int r);
int merge(vector<int>&, int p, int q, int r);

int main()
{
	int n, i, b, inv;
	while (fin >> n)
	{
		vector<int>a(n);
		for (i = 0; i < n; i++)
		{
			fin >> b;
			a[i] = b;
		}
		inv = count(a, 0, n - 1);
		cout << inv << endl;
	}
	return 0;
}

int count(vector<int>&a, int p, int r)
{
	int inv = 0;
	if (p < r)
	{
		int q;
		q = floor((p + r) / 2);
		inv = inv + count(a, p, q);
		inv = inv + count(a, q + 1, r);
		inv = inv + merge(a, p, q, r);
	}
	return inv;
}

int merge(vector<int>&a, int p, int q, int r)
{
	int n1, n2, i, j, k, inv;
	n1 = q - p + 1;
	n2 = r - q;
	vector<int>L(n1);
	vector<int>R(n2);
	for (i = 0; i < n1; i++)
		L[i] = a[p + i];
	for (j = 0; j < n2; j++)
		R[j] = a[q + j + 1];
	i = 0;
	j = 0;
	inv = 0;
	k = p;
	while ((i < n1) && (j < n2))
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
			inv = inv + n1 - i;
		}
		k++;
	}
	while (i < n1)
	{
		a[k] = L[i];
		k++;
		i++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		k++;
		j++;
	}
	return inv;
}
