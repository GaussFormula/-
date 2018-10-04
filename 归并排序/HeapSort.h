#include <vector>
using namespace std;

inline int LeftChild(int i)
{
	return i << 1;
}

inline int RightChild(int i)
{
	return (i << 1) + 1;
}


inline int Parent(int i)
{
	return i >> 1;
}

//template<typename T>
void Max_Heapify(vector<int>*p,int i)
{
	int left = LeftChild(i + 1);
	int right = RightChild(i + 1);
	int largest = -1;
	if (left <= p->size() && (*p)[left - 1] > (*p)[i])
	{
		largest = left - 1;
	}
	else
	{
		largest = i;
	}
	if (right <= p->size() && (*p)[right - 1] > (*p)[largest])
	{
		largest = right - 1;
	}
	if (largest != i)
	{
		int store = (*p)[largest];
		(*p)[largest] = (*p)[i];
		(*p)[i] = store;
		//swap((p + largest), (p + i));
		Max_Heapify(p, largest);
	}
}

//template<typename T>
void BuildMaxHeap(vector<int>* p)
{
	for (int i = (p->size()) / 2 - 1; i >= 0; i--)
	{
		Max_Heapify(p, i);
	}
}

//template<typename T>
void HeapSort(vector<int>* p,vector<int>* q)
{
	BuildMaxHeap(p);
	for (int i = p->size() - 1; i >= 0; i--)
	{
		int store = (*p)[0];
		(*p)[0] = (*p)[i];
		(*p)[i] = store;
		//swap(p, p + i);
		q->push_back((*p)[p->size()-1]);
		p->pop_back();
		Max_Heapify(p, 0);
	}
}
