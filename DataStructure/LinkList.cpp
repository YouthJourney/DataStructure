#include"stdafx.h"
#include"LinkList.h"
#include<string>
#include<iostream>
using namespace std;

Status CreateList_L(LinkList &L, int n)
{
	LinkList p,q;
	L = new LNode;
	L->next = NULL;
	q = L;

	cout << "请输入数据: ";
	
	for (int i = 0; i < n; i++)
	{
		p = new LNode;
		cin >> p->data;
		p->next = NULL;
		q->next = p;
		q=p;
	}
	return OK;
}

void PrintList(LinkList L)
{
	LinkList p = L->next;
	cout << "数据为：";
	while (p)
	{
		cout << p->data<<" ";
		p = p->next;
	}
}

Status ListInsert_L(LinkList&L, int i, ElemType e)
{
	LinkList p = L;
	for (int j = 0; j < i - 1; j++)
	{
		if (p)
			p = p->next;
	}
	if (p)
	{
		LinkList q = new LNode;
		q->data = e;
		q->next = p->next;
		p->next = q;
		return OK;
	}
	return ERROR;
}

Status ListDelete_L(LinkList&L, int i)
{
	LinkList p = L;
	int j = 0;
	while (p->next&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1)
		return ERROR;
	LinkList q = p->next;
	p->next = q->next;
	free(q);
	return OK;
}

ElemType ListSearch_L(LinkList & L,int i, ElemType e)
{
	LinkList p = L->next;
	int j = 1;
	while (p&&j<i)
	{
		p = p->next;
		j++;
	}
	if (!p || j>i)
		return ERROR;
	e = p->data;
	return e;
}

