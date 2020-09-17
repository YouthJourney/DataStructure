#include"stdafx.h"
#include"Queue.h"
#include<iostream>
using namespace std;

//	构造一个空队列Q。
int InitQueue(LinkQueue *Q)
{
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));	//动态分配一个空间
	if (!(*Q).front)
		exit(0);
	(*Q).front->next = NULL;	//队头指针指向空，无数据域，这样构成了一个空队列
	return 1;
}

// 	插入元素e为Q的新的队尾元素。
int EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)	// 存储分配失败 
		exit(0);
	// 生成一个以为e为数据域的队列元素
	p ->data = e;
	p ->next = NULL;
	//将该新队列元素接在队尾的后面
	(*Q).rear ->next = p;
	(*Q).rear = p;
	return 1;
}

// 	若队列不空,删除Q的队头元素,用e返回其值,并返回1,否则返回0。
int DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if ((*Q).front == (*Q).rear)
		return 0;
	p = (*Q).front ->next;	//队头元素
	*e = p->data;
	(*Q).front ->next = p ->next;
	if ((*Q).rear == p)
		(*Q).rear = (*Q).front;
	free(p);
	return 1;
}

//	若Q为空队列,则返回1,否则返回0。
int QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return 1;
	else
		return 0;
}
