#pragma once
#include <iostream>
using namespace std;
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void QuickSort(int* source, int length,int Left,int Right)
{
	if (Left >= Right)
	{
		return;
	}
	int key = source[Right];
	int i, j;
	for (i = Left-1,j=Left; j < Right; j++)
	{
		if (source[j] < key)
		{
			i++;
		}
		else
		{
			swap(source + i + 1, source + j);
		}
	}
	swap(source + i + 1, source+Right);
	QuickSort(source, length, Left, i);
	QuickSort(source, length, i+2, Right);
}