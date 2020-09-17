#pragma once
#include"def.h"

//typedef char VertexType;

typedef int QElemType; // �������� 

					   //  �������У������е���ʽ�洢�ṹ 
typedef struct QNode
{
	QElemType data;		//������
	struct QNode *next;	//ָ����
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front,	//��ͷָ�룬ָ����ָ���ͷԪ��
		rear;		//��βָ�룬ָ���βԪ��
}LinkQueue;


int InitQueue(LinkQueue *Q);
int EnQueue(LinkQueue *Q, QElemType e);
int DeQueue(LinkQueue *Q, QElemType *e);
int QueueEmpty(LinkQueue Q);