#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define NUM 105
#define MAX 1000000.0

struct {
	pair <float, float> pos;
	int visit;
} node[NUM];

struct e {
	int src;
	int dest;
	float dis;
} edge[NUM * NUM];

int compare(const void * a, const void * b) {
	return (*(e *)a).dis - (*(e *)b).dis;
}

int getroot(int a) {
	while (node[a].visit >= 0) {
		a = node[a].visit;
	}
	return a;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int num = 0;
	while (cin >> num) {
		int i = 0;
		for (i = 0; i < num; i++) {
			cin >> node[i].pos.first >> node[i].pos.second;
			node[i].visit = -1;
		}
		for (; i < NUM; i++) {
			node[i].pos.first = -1;
			node[i].pos.second = -1;
			node[i].visit = -1;
		}
		if (num <= 1) {
			cout << 0.00 << endl;
			continue;
		}
		int edgenum = 0;
		for (int m = 0; m < num - 1; m++) {
			for (int n = m + 1; n < num; n++) {
				if (m != n) {
					edge[edgenum].src = m;
					edge[edgenum].dest = n;
					edge[edgenum].dis = sqrt(
						pow(node[m].pos.first - node[n].pos.first, 2) +
						pow(node[m].pos.second - node[n].pos.second, 2));
					edgenum++;
				}
			}
		}
		qsort(edge, edgenum, sizeof(e), compare);
		for (int i = 0; i < edgenum; i ++) {
            printf("%lf\n",edge[i].dis);
		}
		float sum = 0;
		for (int k = 0; k < edgenum; k++) {
			int pa = getroot(edge[k].src), pb = getroot(edge[k].dest);
			if (pa != pb) {
				sum += edge[k].dis;
				node[pb].visit = pa;
			}
		}
		printf("%.2lf\n", sum);
	}
	return 0;
}
