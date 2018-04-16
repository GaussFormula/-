#include <iostream>
#include "QuickSort.h"
using namespace std;
int main()
{
	int*source =new int[5]  { 0,4,3,2,1 };
	QuickSort(source, 5, 0, 4);
	for (int i = 0; i < 5; i++)
	{
		cout << source[i]<<" ";
	}
	getchar();
	return 0;
}