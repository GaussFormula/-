#pragma once
#include "QuickSort.h"
int partition(std::vector<int>&source, int key)
{
	//key是要主元的下标
	int a = source[key];
	int j = -1;
	for (int i = 0; i < source.size(); i++)
	{
		if (source[i] < a)
		{
			j++;
			std::swap(source[i], source[j]);
		}
	}
	std::swap(source[key], source[j+1]);
	return j + 1;
}

int LinearTimeSelect(std::vector<int>&source, int k,int Left,int Right)
{
	if (Left >= Right)
	{
		return source[Left];
	}
	int i;
	for (i = 0; i+4 <=Right; i+=5)
	{
		QuickSort(source, i, i + 4);
	}
	QuickSort(source, Right - (Right % 5), Right);
	std::vector<int> middle;
	for (i = 2; i + 5 <= Right; i+=5)
	{
		middle.push_back(source[i]);
	}
	if (source.size() % 5 < 3)
	{
		middle.push_back(source[(Right % 5) / 2 + Right - (Right % 5)]);
	}
	QuickSort(middle, 0, middle.size() - 1);
	int MiddleOfMiddle;
	if (middle.size() % 2 == 0)
	{
		MiddleOfMiddle = middle[middle.size() / 2 - 1];
	}
	else
	{
		MiddleOfMiddle = middle[middle.size() / 2];
	}
	int positionOfMiddleOfMiddle;
	for (i = 0; source[i] != MiddleOfMiddle; i++)
	{
		;
	}
	positionOfMiddleOfMiddle = i;
	positionOfMiddleOfMiddle=partition(source, positionOfMiddleOfMiddle);
	if (k < positionOfMiddleOfMiddle + 1)
	{
		return LinearTimeSelect(source, k, 0, positionOfMiddleOfMiddle - 1);
	}
	else if(k>positionOfMiddleOfMiddle+1)
	{
		return LinearTimeSelect(source, k, positionOfMiddleOfMiddle + 1, Right);
	}
	else
	{
		return source[positionOfMiddleOfMiddle];
	}
}