#pragma once
#include "QuickSort.h"


#include <time.h>
using namespace std;

int Randomized_Partition(vector<int>&p, int Left, int Right)
{
	if (Left == Right)
	{
		return Left;
	}
	srand((unsigned int)time(0));
	int key = (rand() % (Right - Left + 1)) + Left;
	for (int i = Left - 1, j = Left; j <= Right; j++)
	{
		if (p[j] < p[key])
		{
			i++;
			swap(p[i], p[j]);
			if (i == key)
			{
				key = j;
			}
		}
		if (j == Right)
		{
			swap(p[key], p[i + 1]);
			key = i + 1;
		}
	}
	return key;
}

int Randomized_Select(vector<int>&p, int Left, int Right, int i)
{
	if (Left == Right)
	{
		return p[Left];
	}
	int q = Randomized_Partition(p, Left, Right);
	int k = q - Left + 1;
	if (k==i)
	{
		return p[q];
	}
	else if(i<k)
	{
		return Randomized_Select(p, Left, q - 1, i);
	}
	else
	{
		return Randomized_Select(p, q + 1, Right, i - k);
	}

}