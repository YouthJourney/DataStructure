#pragma once
#include"def.h"
#include "stdafx.h"

//#define MAX_ARRAY_DIM 8
//
typedef int ElemType;
//
//typedef struct {
//	ElemType *base;
//	int dim;
//	int *bounds;
//	int *constants;
//}Array;

#define MAXSIZE 12500
#define MAXRC  6250
//#define MAX_BOUNDS  10

typedef struct {
	int i, j;     //�÷���Ԫ�����±�����±���1��ʼ��
	ElemType e;    //��i�е�j�е�Ԫ��ֵ��
}Triple;

typedef struct {
	Triple data[MAXSIZE + 1];       //������Ԫ���data[0]û���ã�
	int row_n, col_n, non_zero;  //����������������ͷ���Ԫ�ĸ�����
	int rops[MAXRC + 1];         //
}TSMatrix;

//Status InitArray(Array &A, int dim, int bounds[]);
//Status Locate(Array A, va_list ap, int &off);
//Status Value(ElemType &e, Array A, ...);

Status CreateSMatrix(TSMatrix &M);   //����ϡ�����
Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix &Q);  //�����ĳ˷���
Status PrintSMatrix(TSMatrix M);      //���ϡ�����