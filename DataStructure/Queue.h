#pragma once
#include"def.h"

//typedef char VertexType;

typedef int QElemType; // 队列类型 

					   //  单链队列－－队列的链式存储结构 
typedef struct QNode
{
	QElemType data;		//数据域
	struct QNode *next;	//指针域
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front,	//队头指针，指针域指向队头元素
		rear;		//队尾指针，指向队尾元素
}LinkQueue;


int InitQueue(LinkQueue *Q);
int EnQueue(LinkQueue *Q, QElemType e);
int DeQueue(LinkQueue *Q, QElemType *e);
int QueueEmpty(LinkQueue Q);