#pragma once
#include <vector>
using namespace std;

void CountingSort(vector<int>& v1,vector<int>& v2,int k)
{
	vector<int> c;//辅助数组
	for (int i = 0; i <= k; i++)//c有k+1个元素
	{
		c.push_back(0);//初始化
	}
	for (int i = 0; i < v1.size(); i++)
	{
		v2.push_back(0);//v2初始化
	}
	for (int i = 0; i < v1.size(); i++)
	{
		c[v1[i]]++;//c数组中的每个元素，存储的是V1中每个元素出现的次数
	}
	for (int i = 1; i <= k; i++)
	{
		c[i] = c[i - 1]+c[i];//此时c[i]记录的是小于等于i的元素个数
	}
	for (int i = v1.size() - 1; i >= 0; i--)//核心部分
	{
		v2[c[v1[i]]-1] = v1[i];//从v1尾部取出一个数，查询数组c，得知这个数在排序后的位置，放入v2中
		c[v1[i]]--;//放入之后就将记录减1，
	}
}