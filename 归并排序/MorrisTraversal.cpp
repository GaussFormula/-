#include "MorrisTraversal.h"
#include<iostream>
#include <time.h>


void MorrisTraversal(BinaryTreeNode* root)//ÖÐÐò±éÀú
{
	if (root == nullptr)
	{
		return;
	}

	BinaryTreeNode*pCur = root;
	BinaryTreeNode*pPre;
	while (pCur!=nullptr)
	{
		if (pCur->LeftChild == nullptr)
		{
			std::cout << pCur->key << " ";
			pCur = pCur->RightChild;
		}
		else
		{
			pPre = pCur->LeftChild;
			
			while (pPre->RightChild!=nullptr&&pPre->RightChild!=pCur)
			{
				pPre = pPre->RightChild;
			}
			if (pPre->RightChild == nullptr)
			{
				pPre->RightChild = pCur;
				pCur = pCur->LeftChild;
				//pPre = pCur->LeftChild;
			}
			else if(pPre->RightChild==pCur)
			{
				//pCur = pCur->RightChild;
				pPre->RightChild = nullptr;
				std::cout << pCur->key << " ";
				pCur = pCur->RightChild;
			}
		}
	}
}

void MorrisTraversalTest(void)
{
	//srand((unsigned int)time(0));
	BinaryTreeNode*root = new BinaryTreeNode;
	root->key = 1;
	root->LeftChild = root->RightChild = nullptr;
	BinaryTreeNode*p = new BinaryTreeNode;
	p->key = 2;
	p->LeftChild = p->RightChild = nullptr;
	root->LeftChild = p;
	p = new BinaryTreeNode;
	p->key = 3;
	p->LeftChild = p->RightChild = nullptr;
	root->RightChild = p;
	MorrisTraversal(root);
}