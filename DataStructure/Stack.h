#pragma once
#include"def.h"
//ջ�Ļ���������Ӧ��
typedef int ElemType;

typedef struct SLNode {
	ElemType data;
	struct SLNode *next;
}*Stack;

Status Push(Stack &S, ElemType e);
Status Pop(Stack &S, ElemType &e);
Status GetTop(Stack S, ElemType &e);
Status InitStack(Stack &S);
Status StackEmpty(Stack S);