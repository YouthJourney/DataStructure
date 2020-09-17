#pragma once
#include"def.h"

//单链表的基本操作；
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode*next;
}LNode, *LinkList;

Status CreateList_L(LinkList &L, int n);
void PrintList(LinkList L);
Status ListInsert_L(LinkList&L, int i, ElemType e);
Status ListDelete_L(LinkList&L, int i);
Status ListSearch_L(LinkList &L, int i, ElemType e);