#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("1158_2.in");
ofstream fout("1158_2.out");

struct node{
    int data;
    int pos;
};

int data[5000005];
node heap[1010000];
int num = 0, top = 0;
int ans[5000005];


void downheap(node heap[], int current, int top)
{
	while (current < top / 2)
	{
		int small = current;
		if (2 * current + 1 < top && heap[small].data > heap[2 * current + 1].data) small = 2 * current + 1;
		if (2 * (current + 1) < top && heap[small].data > heap[2 * (current + 1)].data) small = 2 * (current + 1);
		if (small == current) break;
		node temp = heap[current]; heap[current] = heap[small]; heap[small] = temp;
		current = small;
    }
}

void buildheap(node heap[], int top)
{
	for (int i = top / 2 - 1; i >= 0; i --)
    downheap(heap, i, top);
}

int main()
{
    fin >> data[num];
    heap[top].data = data[num]; heap[top].pos = num;
    num ++; top ++;
    while (fin >> data[num])
    {
        if (data[num] < data[num - 1])
        {
            heap[top].data = data[num];
            heap[top].pos = num;
            top ++;
        }
        num ++;
    }
    buildheap(heap, top);
    for (int i = 0; i < num - 1; i ++)
    {
        fout << heap[0].data <<' ';
        if (heap[0].pos + 1 < num && data[heap[0].pos] <= data[heap[0].pos + 1])
        {
            heap[0].data = data[heap[0].pos + 1];
            heap[0].pos ++;
        }
        else
        {
            heap[0] = heap[-- top];
        }
        downheap(heap, 0, top);
    }
    fout << heap[0].data << endl;
    return 0;
}
