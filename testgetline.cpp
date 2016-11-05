#include <iostream>
#include <fstream>
#include <string>

#include <sstream>
#include <vector>
#include <stdio.h>

#include <algorithm>
using namespace std;

  ifstream ifs("1158_2.in");
    ofstream ofs("hehe.out");
struct ListNode
{
	int value;
	ListNode* next;

	ListNode(int val):value(val),next(NULL) {}

	void append(int val)
	{
		//next must be NULL
		next = new ListNode(val);
	}
};

class FancySorter
{
	vector<ListNode*> heap;
	int size, currentValue;

	ListNode* currentTail;

public:
	FancySorter(int value):heap(), size(1),currentValue(value),currentTail(NULL)
	{
		ListNode* pnode = new ListNode(value);
		heap.push_back(pnode);
		currentTail = pnode;
	}

	void insert(int value)
	{
		if(value >= currentValue) {
			currentTail->append(value);
			currentTail = currentTail->next;
		}
		else
		{
			ListNode* pnew = new ListNode(value);
			heap.push_back(pnew);
			currentTail = pnew;
			shiftup();
		}
		currentValue = value;	// bug 1
		size ++;
	}

	void print()
	{
		while(size > 1)
		{
			cout<<heap[0]->value<<' ';

			ListNode* phead = heap[0];
			heap[0] = heap[0]->next;
			delete phead;
			shiftdown();
			size --;
		}
		cout<<heap[0]->value<<endl;
	}

	void shiftup()
	{
		int currentIndex = heap.size()-1;
		while(currentIndex > 0 && heap[currentIndex]->value < heap[parentIndex(currentIndex)]->value)
		{
			iter_swap(heap.begin()+currentIndex, heap.begin()+parentIndex(currentIndex));
			currentIndex = parentIndex(currentIndex);
		}
	}

	void shiftdown()
	{
		if(heap[0] == NULL)
		{
			heap[0] = heap[heap.size()-1];
			heap.erase(heap.begin()+heap.size()-1);
		}

		int current = 0;
		int child = smallerChildIndex(current);

		while(child >= 0) {
			iter_swap(heap.begin()+current, heap.begin()+child);
			current = child;	// bug 2
			child = smallerChildIndex(current);
		}
	}

	int smallerChildIndex(int currentIndex)
	{
		int left = currentIndex*2+1;
		int right = currentIndex*2+2;

		if(left >= heap.size())
			return -1;

		if(right >= heap.size())
			return heap[left]->value < heap[currentIndex]->value ? left : -1;

		int smaller = heap[left]->value < heap[right]->value ? left : right;
		return heap[smaller]->value < heap[currentIndex]->value ? smaller : -1;
	}

	int parentIndex(int p)
	{
		if(p > 0)
			return (p-1) / 2;
		return 0;
	}
};
int main()
{

        string line;
        getline(cin,line);
	istringstream iss(line);
	int value;
	iss >> value;
	FancySorter sorter(value);

	while (iss >> value)
	{
		sorter.insert(value);
	}
	sorter.print();
 //cin.get();
 return 0;
}
