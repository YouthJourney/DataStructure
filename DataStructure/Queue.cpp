#include"stdafx.h"
#include"Queue.h"
#include<iostream>
using namespace std;

//	����һ���ն���Q��
int InitQueue(LinkQueue *Q)
{
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));	//��̬����һ���ռ�
	if (!(*Q).front)
		exit(0);
	(*Q).front->next = NULL;	//��ͷָ��ָ��գ�������������������һ���ն���
	return 1;
}

// 	����Ԫ��eΪQ���µĶ�βԪ�ء�
int EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)	// �洢����ʧ�� 
		exit(0);
	// ����һ����ΪeΪ������Ķ���Ԫ��
	p ->data = e;
	p ->next = NULL;
	//�����¶���Ԫ�ؽ��ڶ�β�ĺ���
	(*Q).rear ->next = p;
	(*Q).rear = p;
	return 1;
}

// 	�����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������1,���򷵻�0��
int DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if ((*Q).front == (*Q).rear)
		return 0;
	p = (*Q).front ->next;	//��ͷԪ��
	*e = p->data;
	(*Q).front ->next = p ->next;
	if ((*Q).rear == p)
		(*Q).rear = (*Q).front;
	free(p);
	return 1;
}

//	��QΪ�ն���,�򷵻�1,���򷵻�0��
int QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return 1;
	else
		return 0;
}
