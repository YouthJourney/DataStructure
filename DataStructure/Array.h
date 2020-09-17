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
	int i, j;     //该非零元的行下标和列下表，从1开始；
	ElemType e;    //第i行第j列的元素值；
}Triple;

typedef struct {
	Triple data[MAXSIZE + 1];       //非零三元组表；data[0]没有用；
	int row_n, col_n, non_zero;  //矩阵的行数，列数和非零元的个数；
	int rops[MAXRC + 1];         //
}TSMatrix;

//Status InitArray(Array &A, int dim, int bounds[]);
//Status Locate(Array A, va_list ap, int &off);
//Status Value(ElemType &e, Array A, ...);

Status CreateSMatrix(TSMatrix &M);   //创建稀疏矩阵；
Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix &Q);  //求矩阵的乘法；
Status PrintSMatrix(TSMatrix M);      //输出稀疏矩阵；