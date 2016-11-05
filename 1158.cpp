#include<stdio.h>

struct node{
    int data;
    int pos;
};

int data[5000005];
node heap[1010];
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
    scanf("%d", &data[num]);
    heap[top].data = data[num]; heap[top].pos = num;
    num ++; top ++;
    while (scanf("%d", &data[num]) != EOF)
    {
        if (data[num] < data[num - 1])
        {
            heap[top].data = data[num];
            heap[top].pos = num;
            top ++;
        }
        num ++;
        if (data[num - 1] == -1) break;
    }
    buildheap(heap, top);
    for (int i = 0; i < num - 1; i ++)
    {
        printf("%d ", heap[0].data);
        if (heap[0].pos + 1< num && data[heap[0].pos] <= data[heap[0].pos + 1])
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
    printf("%d\n", heap[0].data);
    return 0;
}
