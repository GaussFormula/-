#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
void merge_sort(int*source, int p, int r)
{
	int q = (p + r) / 2;
	if (p<r)
	{
		merge_sort(source, p, q);
		merge_sort(source, q + 1, r);
		merge(source, p, q, r);
	}

}
void merge(int* source, int p, int q, int r)
{
	int LeftLength = q - p + 1;
	int RightLength = r - q;
	int* LeftArray = new int[LeftLength];
	int* RightArray = new int[RightLength];
	for (int i = 0; i < LeftLength; i++)
	{
		LeftArray[i] = source[p + i];
	}
	//LeftArray[LeftLength] = INT32_MAX;
	for (int i = 0; i < RightLength; i++)
	{
		RightArray[i] = source[q + 1 + i];
	}
	//RightArray[RightLength] = INT32_MAX;
	for (int i = 0, j = 0, k = p; k <= r; )
	{
		if (LeftArray[i] <= RightArray[j])
		{
			source[k] = LeftArray[i];
			i++;
			k++;
		}
		else
		{
			source[k] = RightArray[j];
			j++;
			k++;
		}
		if (i == LeftLength)
			//说明左数组已排序完成，但右数组有剩余，即剩余右数组比左侧
			//数组最大的要大，所以应把右数组整个复制进去
		{
			while (j<RightLength)
			{
				source[k] = RightArray[j];
				j++;
				k++;
			}
			delete[] LeftArray;
			delete[] RightArray;
			break;
		}
		if (j == RightLength)
		{
			while (i<LeftLength)
			{
				source[k] = LeftArray[i];
				i++;
				k++;
			}
			delete[] LeftArray;
			delete[] RightArray;
			break;
		}
	}