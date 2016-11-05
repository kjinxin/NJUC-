#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define maxnum 3002
#define maxint 250000
int dist[maxnum];
int prev[maxnum];
int map[maxnum][maxnum];
int temp[maxnum][2];

void calcudij(int n, int v, int *dist, int *prev, int map[maxnum][maxnum])
{
	bool s[maxnum];
	for (int i = 1; i <= n; ++i)
	{
		dist[i] = map[v][i];
		s[i] = 0;
		if (dist[i] == maxint)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	dist[v] = 0;
	s[v] = 1;

	for (int i = 2; i <= n; ++i)
	{
		int tmp = maxint;
		int u = v;
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && dist[j]<tmp)
			{
			u = j;
			tmp = dist[j];
			}
		s[u] = 1;

		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && map[u][j]<maxint)
			{
			int newdist = dist[u] + map[u][j];
			if (newdist < dist[j])
			{
				dist[j] = newdist;
				prev[j] = u;
			}
			}
	}
}



int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			map[i][j] = maxint;

	for (int i = 1; i <= n; ++i)
		dist[i] = maxint;

	for (int i = 1; i <= n; i++){
		cin >> temp[i][0];
		cin >> temp[i][1];
	}

	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			map[i][j] = min(abs(temp[i][0] - temp[j][0]), abs(temp[i][1] - temp[j][1]));
			map[j][i] = map[i][j];
		}
	}

	calcudij(n, 1, dist, prev, c);
    cout<<dist[n]<<endl;
	return 0;
}
