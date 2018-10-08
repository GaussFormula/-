#pragma once
#include <iostream>
#include <vector>
using namespace std;
void QuickSort(vector<int>& source, int length,int Left,int Right)
{
	if (Left >= Right)//当左下标等于右下标时，说明数组此时只有一个元素，排序结束
	{
		return;
	}
	int key = source[Right];//取尾值做主元
	int i, j;//临时变量i及其左边存放比主元小的值，右边存放比主元大的值
	for (i = Left-1,j=Left; j < Right; j++)
	{
		if (source[j] < key)//若小于主元
		{
			i++;//小于主元的区间扩张
			swap(source[i], source[j]);//并将新出现的比主元小的数置入进来
		}
		
	}
	swap(source[i + 1], source[Right]);//将主元放在两个区间中间
	QuickSort(source, length, Left, i);//递归求解左区间
	QuickSort(source, length, i+2, Right);//递归求解右区间
}