#include "stdafx.h"
#include"Array.h"
#include<iostream>
#include<stdarg.h>
using namespace std;

//Status InitArray(Array &A, int dim, int bounds[])
//{
//	if (dim<1 || dim>MAX_ARRAY_DIM)
//		return ERROR;
//	A.dim = dim;
//	A.bounds = bounds;
//	if (A.bounds == NULL)
//		return EOVERFLOW;
//	int elemtotal = 1;
//
//	va_list ap;
//	va_start(ap, dim);       //从dim后面开始找，与参数列表的顺序有关。
//	for (int i = 0; i < dim; i++)
//	{
//		A.bounds[i] = va_arg(ap, int);
//		if (A.bounds[i] < 0)
//			return ERROR;
//		elemtotal *= A.bounds[i];
//	}
//	va_end(ap);
//
//	A.base = new ElemType[elemtotal];
//	if (!A.base)
//		return ERROR;
//	A.constants = new int[dim];
//	if (!A.constants)
//		return ERROR;
//	A.constants[dim - 1] = 1;
//	for (int i = dim - 2; i >= 0; i--)
//		A.constants[i] = A.bounds[i + 1] * A.constants[i + 1];
//
//	return OK;
//}
//Status Locate(Array A, va_list ap, int &off)
//{
//	off = 0;
//	for (int i = 0; i < A.dim; i++)
//	{
//		int ind = va_arg(ap, int);
//		if (ind < 0 || ind >= A.bounds[i])
//			return OVERFLOW;
//		off += A.constants[i] * ind;
//	}
//	return OK;
//}
//
//
//Status Value(ElemType &e, Array A, ...)
//{
//	va_list ap;
//	va_start(ap, A);         //从A后面开始找，与参数列表的顺序有关。
//	int off;
//	if (Locate(A, ap, off) == ERROR)
//		return ERROR;
//	e = *(A.base + off);
//	va_end(ap);
//	return OK;
//}


Status CreateSMatrix(TSMatrix & M)
{
	int temp;
	cout << "Input the row and the col of the Matrix: ";
	cin >> M.row_n >> M.col_n;
	M.non_zero = 0;

	cout << endl << "按行序输入矩阵： " << endl;
	for (int i = 1; i <= M.row_n; i++)
	{
		M.rops[i] = M.non_zero + 1;
		for (int j = 1; j <= M.col_n; j++)
		{
			cin >> temp;
			if (temp) {      //存储非0元
				M.data[M.non_zero + 1].i = i;
				M.data[M.non_zero + 1].j = j;
				M.data[M.non_zero + 1].e = temp;     //非零元的值；
				M.non_zero++;
			}
		}
	}
	return OK;
}

Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix & Q)
{
	if (M.col_n != N.row_n)  //如果两个矩阵的行数或者列数不相同,就无法实现乘法；  
		return ERROR;

	Q.row_n = M.row_n;
	Q.col_n = N.col_n;
	Q.non_zero = 0;          //Q初始化；

	if (M.non_zero*N.non_zero != 0)  //Q是非0矩阵；
	{
		for (int arow = 1; arow <= M.row_n; arow++)   //处理M的每一行
		{
			/*int *ctemp;
			ctemp = new int[Q.row_n*Q.col_n];*/
			int ctemp[MAXRC] = { 0 };            //经过后面代码分析，ctemp是记录Q的每一行
												 //最终ctemp[1]，ctemp[2]，ctemp[3]...记录的是第Q的第arow行第1，2，3...列的元素
												 //MAXRC是随便写的，只要不小于N.col_n
			Q.rops[arow] = Q.non_zero + 1;
			int tp;                             //记录下一行第一个非零元在M中的位置，
			if (arow < M.row_n)
				tp = M.rops[arow + 1];
			else
				tp = M.non_zero + 1;              //当arow=tu时，tu+1可以表示第arow+1行第一个非零元的位置
			for (int p = M.rops[arow]; p < tp; p++) //对M当前行的每一个非零元
			{
				int brow = M.data[p].j;  //找到对应元在N中的行号,如：M的第1行第3列元素只可能和N中的第3行的某元素相乘
				int t;
				if (brow < N.row_n)
					t = N.rops[brow + 1];
				else
					t = N.non_zero + 1;
				for (int q = N.rops[brow]; q < t; q++) //对N的当前行的每一个非零元
				{
					int ccol = N.data[q].j;
					ctemp[ccol] += M.data[p].e*N.data[q].e; //p（不是q）所在的循环完后，ctemp[i]表示的是Q第arow行第i列的元素
															//更准确的说应该是M第arow行与N的第j列的元素乘积之和
				}
			}
			for (int ccol = 1; ccol <= Q.col_n; ccol++)
			{
				if (ctemp[ccol])             //M第arow行与N的第ccol列的元素成绩之和不为0，存入Q
				{
					if (++Q.non_zero > MAXSIZE)  //也就是来一个存一个，且存在最后，让Q的非零元的个数与它所存储的位置相应；
						return ERROR;
					Q.data[Q.non_zero].i = arow;
					Q.data[Q.non_zero].j = ccol;
					Q.data[Q.non_zero].e = ctemp[ccol];
				}
			}
		} //for arow;
	} //if;

	return OK;
}

Status PrintSMatrix(TSMatrix M)
{
	if (M.non_zero == 0)
	{
		cout << "空矩阵";
		return ERROR;
	}

	cout << "row\t" << "col\t" << "e\t" << endl;
	for (int i = 1; i < M.non_zero + 1; i++)
		cout << M.data[i].i << "\t" << M.data[i].j << "\t" << M.data[i].e << endl;

	return OK;
}