#pragma once

#include "QuickSort.h"
using namespace std;

int Resort(vector<int>&source, int Left, int Right)
{
	int i;
	vector<int>store;
	for (i = Left; Right-i<4;i+=5)
	{
		QuickSort(source, i, i + 4);
		store.push_back(i+2);
	}
	QuickSort(source, i, Right);
	store.push_back(i + (Right - i + 1) / 2);
	QuickSort(store, 0, store.size() - 1);
	return store[store.size() / 2];
}

int Partition(vector<int>&source, int Left, int Right)
{
	int key = Resort(source, Left, Right);
	for (int i = Left-1,j=Left; j <= Right; j++)
	{
		if (source[j] < source[key])
		{
			i++;
			swap(source[i], source[j]);
			if (i == key)
			{
				key = j;
			}
			if (j == Right)
			{
				swap(source[key], source[i + 1]);
				key = i + 1;
			}
		}
	}
	return key;
}

int Select(vector<int>&source, int Left, int Right, int i)
{
	if (Left == Right)
	{
		return source[Left];
	}
	int q = Partition(source, Left, Right);
	int k = q - Left + 1;
	if (k == i)
	{
		return source[q];
	}
	else if (i < k)
	{
		return Select(source, Left, q - 1, i);
	}
	else
	{
		return Select(source, q + 1, Right, i - k);
	}
}