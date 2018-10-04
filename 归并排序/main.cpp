#include <iostream>
#include <vector>
#include <time.h>


#include "QuickSort.h"
#include "HeapSort.h"

#define random(x) (rand()%x)
using namespace std;
int main()
{
	srand((int)time(0));
	vector<int> v,v1;
	for (int i = 1; i <= 5; i++)
	{
		v.push_back(random(100));
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it<<" ";
	}
	cout << endl;
	HeapSort(&v, &v1);
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	getchar();
	return 0;
}