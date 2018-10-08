#pragma once
#include <iostream>
#include <vector>
using namespace std;
void QuickSort(vector<int>& source, int length,int Left,int Right)
{
	if (Left >= Right)//�����±�������±�ʱ��˵�������ʱֻ��һ��Ԫ�أ��������
	{
		return;
	}
	int key = source[Right];//ȡβֵ����Ԫ
	int i, j;//��ʱ����i������ߴ�ű���ԪС��ֵ���ұߴ�ű���Ԫ���ֵ
	for (i = Left-1,j=Left; j < Right; j++)
	{
		if (source[j] < key)//��С����Ԫ
		{
			i++;//С����Ԫ����������
			swap(source[i], source[j]);//�����³��ֵı���ԪС�����������
		}
		
	}
	swap(source[i + 1], source[Right]);//����Ԫ�������������м�
	QuickSort(source, length, Left, i);//�ݹ����������
	QuickSort(source, length, i+2, Right);//�ݹ����������
}