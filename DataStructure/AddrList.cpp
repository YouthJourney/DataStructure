#include"stdafx.h"
#include"AddrList.h"
#include<iostream>
using namespace std;

Status CreateAddrList_L(AddrLinkList &L, int n)
{
	AddrLinkList p, q;
	L = new ALNode;
	L->next = NULL;
	q = L;

	cout << "��������ϵ��\n ";
	cout << "����\t����\n";

	for (int i = 0; i < n; i++)
	{
		p = new ALNode;
		cin >> p->data.name>>p->data.numble;
		p->next = NULL;    //p�ǵ�����һ�����ռ䣬q�������ӳ�����
		q->next = p;
		q = p;
	}
	return OK;
}

void PrintAddrList(AddrLinkList L)
{
	if (L == 0)
		cout << "ͨѶ¼Ϊ��";
	AddrLinkList p = L->next;
	cout << "����\t����\n";
	while (p)
	{
		cout << p->data.name << "\t " << p->data.numble << endl;
		p = p->next;
	}
}

Status AddrListInsert_L(AddrLinkList & L, int i, LinkMan e)
{
	AddrLinkList p = L;
	for (int j = 0; j < i - 1; j++)
	{
		if (p)
			p = p->next;
	}
	if (p)
	{
		AddrLinkList q = new ALNode;
		q->data = e;
		q->next = p->next;
		p->next = q;
		return OK;
	}
	return ERROR;
}

Status AddrListDelete_L(AddrLinkList & L, int i)
{
	AddrLinkList p = L;
	int j = 0;
	while (p->next&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1)
		return ERROR;
	AddrLinkList q = p->next;
	p->next = q->next;
	free(q);
	return OK;
}

LinkMan AddrListSearch_L(AddrLinkList & L, int i, LinkMan &e)
{
	AddrLinkList p = L->next;
	int j = 1;
	while (p&&j<i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		exit(OVERFLOW);
	e = p->data;
	return e;
}
