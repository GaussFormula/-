#pragma once
#include <vector>
using namespace std;

void CountingSort(vector<int>& v1,vector<int>& v2,int k)
{
	vector<int> c;//��������
	for (int i = 0; i <= k; i++)//c��k+1��Ԫ��
	{
		c.push_back(0);//��ʼ��
	}
	for (int i = 0; i < v1.size(); i++)
	{
		v2.push_back(0);//v2��ʼ��
	}
	for (int i = 0; i < v1.size(); i++)
	{
		c[v1[i]]++;//c�����е�ÿ��Ԫ�أ��洢����V1��ÿ��Ԫ�س��ֵĴ���
	}
	for (int i = 1; i <= k; i++)
	{
		c[i] = c[i - 1]+c[i];//��ʱc[i]��¼����С�ڵ���i��Ԫ�ظ���
	}
	for (int i = v1.size() - 1; i >= 0; i--)//���Ĳ���
	{
		v2[c[v1[i]]-1] = v1[i];//��v1β��ȡ��һ��������ѯ����c����֪�������������λ�ã�����v2��
		c[v1[i]]--;//����֮��ͽ���¼��1��
	}
}