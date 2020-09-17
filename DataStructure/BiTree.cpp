#include "stdafx.h"
#include"BiTree.h"
#include<queue>
#include<iostream>
using namespace std;

Status CreateBiTree(BiTree &T)
{
	ElenType ch;

	cin >> ch;
	if (ch == '0')
		T = 0;
	else
	{
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

Status Visit(ElenType e)
{
	cout << e << " ";
	return OK;
}

Status PreOrderTraverse(BiTree T, Status(*Visit)(ElenType e))
{
	if (T == 0)
		return ERROR;
	Visit(T->data);
	PreOrderTraverse(T->lchild, Visit);
	PreOrderTraverse(T->rchild, Visit);

	return OK;
}

Status InOrderTraverse(BiTree T, Status(*Visit)(ElenType e))
{
	if (T == 0)
		return ERROR;
	InOrderTraverse(T->lchild, Visit);
	Visit(T->data);
	InOrderTraverse(T->rchild, Visit);

	return OK;
}

Status PostOrderTraverse(BiTree T, Status(*Visit)(ElenType e))
{
	if (T == 0)
		return ERROR;
	PostOrderTraverse(T->lchild, Visit);
	PostOrderTraverse(T->rchild, Visit);
	Visit(T->data);

	return OK;
}

Status LevelOrderTraverse(BiTree T, Status(*Visit)(ElenType e))
{
	queue<BiTree> Q;
	if (T)
		Q.push(T);
	BiTree p = 0;
	while (Q.empty() == false)
	{
		p = Q.front();
		Q.pop();
		Visit(p->data);
		if (p->lchild)
			Q.push(p->lchild);
		if (p->rchild)
			Q.push(p->rchild);
	}
	delete p;
	return OK;
}

int BiTreeDepth(BiTree T)
{
	if (T == 0)
		return 0;
	if (BiTreeDepth(T->lchild) >= BiTreeDepth(T->rchild))  //�ж�����������ȵĴ�С��
		return BiTreeDepth(T->lchild) + 1;
	return BiTreeDepth(T->rchild) + 1;
}

int LeafCount(BiTree T)
{
	if (T == 0)
		return 0;
	else if (LeafCount(T->lchild) == 0 && LeafCount(T->rchild) == 0)  //��������������������Ϊ��ʱ��ֻ��һ���ڵ㡣
		return 1;
	else
		return LeafCount(T->lchild) + LeafCount(T->rchild);
}

ElenType SearchParent(BiTree T, BiTNode *e)
{
	if (T)
	{
		if (T->data == e->data)
			return 0;
		//�жϽڵ�eΪT->lchild;
		else if (T->lchild->data == e->data)
		{
			return T->data;
		}

		else
		{         //�жϽڵ�eΪT->rchild;
			if (T->rchild->data == e->data)
			{
				return T->data;
			}
			else
			{
				return SearchParent(T->lchild, e);
				return SearchParent(T->rchild, e);
			}
		}
	}
	else
		return 0;
}

ElenType RightSibling(BiTree T, BiTNode * e)
{
	if (T->lchild)   //���Ӵ��ڲ��п��ܴ������ֵܣ�
	{
		if (T->lchild->data == e->data)
		{
			if (T->rchild)
				return T->rchild->data;
			else
				return 0;
		}
		else
			return RightSibling(T->lchild, e);

	}
	else
		return 0;
}

ElenType LeftSibling(BiTree T, BiTNode * e)
{
	if (T->rchild)     //�Һ��Ӵ��ڲ��п��ܴ������ֵܣ�
	{
		if (T->rchild->data == e->data)
		{
			if (T->lchild)
				return T->lchild->data;
			else
				return 0;
		}
		else
			return LeftSibling(T->rchild, e);

	}
	else
		return 0;
}

