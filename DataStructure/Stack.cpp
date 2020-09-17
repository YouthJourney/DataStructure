
#include"stdafx.h"
#include"Stack.h"
#include<iostream>
using namespace std;

Status Push(Stack &S, ElemType e)
{
	SLNode *p = new SLNode;
	if (!p)
		return ERROR;
	p->data = e;
	p->next = S->next;
	S->next = p;
	return OK;
}

Status Pop(Stack &S, ElemType &e)
{
	if (S->next == 0)
		return ERROR;
	SLNode *p = S->next;
	e = p->data;
	S->next = p->next;
	delete p;
	
	return OK;
	
}

Status GetTop(Stack S, ElemType &e)
{
	if (S->next == 0)
		return ERROR;
	e = S->next->data;
	return OK;
}

Status InitStack(Stack &S)
{
	S = new SLNode;
	S->next = 0;
	return OK;
}

Status StackEmpty(Stack S)
{
	if (S->next == 0)
		return TRUE;
	return FALSE;
}