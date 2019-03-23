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
void Max_Heapify(vector<int>&p,int i)
{
	int left = LeftChild(i + 1);
	int right = RightChild(i + 1);
	int largest = -1;
	if (left <= p.size() && p[left - 1] > p[i])//当下标不越界且左孩子大于父节点
	{
		largest = left - 1;//说明最大值出现在左孩子
	}
	else//否则 将最大值的下标设为i
	{
		largest = i;
	}
	if (right <= p.size() && p[right - 1] > p[largest])//再次判断上一轮所得的最大值与右孩子的大小关系
	{
		largest = right - 1;//若右孩子大于最大值，则更新最大值
	}
	if (largest != i)//最大值下标为i（即父节点）说明最大值是父节点
	{//反之则需要修改父节点、左右孩子之间的位置关系
		std::swap(p[largest],p[i]);
		Max_Heapify(p, largest);
	}
}

//template<typename T>
void BuildMaxHeap(vector<int>& p)
{
	for (int i = (p.size()) / 2 - 1; i >= 0; i--)
	{
		Max_Heapify(p, i);
	}
}

//template<typename T>
void HeapSort(vector<int>& p,vector<int>& q)
{
	BuildMaxHeap(p);
	for (int i = p.size() - 1; i >= 0; i--)
	{
		/*int store = p[0];
		p[0] = p[i];
		p[i] = store;*/
		swap(p[0], p[i]);
		q.push_back(p[p.size()-1]);
		p.pop_back();
		Max_Heapify(p, 0);
	}
}
