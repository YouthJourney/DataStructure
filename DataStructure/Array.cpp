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
//	va_start(ap, dim);       //��dim���濪ʼ�ң�������б��˳���йء�
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
//	va_start(ap, A);         //��A���濪ʼ�ң�������б��˳���йء�
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

	cout << endl << "������������� " << endl;
	for (int i = 1; i <= M.row_n; i++)
	{
		M.rops[i] = M.non_zero + 1;
		for (int j = 1; j <= M.col_n; j++)
		{
			cin >> temp;
			if (temp) {      //�洢��0Ԫ
				M.data[M.non_zero + 1].i = i;
				M.data[M.non_zero + 1].j = j;
				M.data[M.non_zero + 1].e = temp;     //����Ԫ��ֵ��
				M.non_zero++;
			}
		}
	}
	return OK;
}

Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix & Q)
{
	if (M.col_n != N.row_n)  //����������������������������ͬ,���޷�ʵ�ֳ˷���  
		return ERROR;

	Q.row_n = M.row_n;
	Q.col_n = N.col_n;
	Q.non_zero = 0;          //Q��ʼ����

	if (M.non_zero*N.non_zero != 0)  //Q�Ƿ�0����
	{
		for (int arow = 1; arow <= M.row_n; arow++)   //����M��ÿһ��
		{
			/*int *ctemp;
			ctemp = new int[Q.row_n*Q.col_n];*/
			int ctemp[MAXRC] = { 0 };            //����������������ctemp�Ǽ�¼Q��ÿһ��
												 //����ctemp[1]��ctemp[2]��ctemp[3]...��¼���ǵ�Q�ĵ�arow�е�1��2��3...�е�Ԫ��
												 //MAXRC�����д�ģ�ֻҪ��С��N.col_n
			Q.rops[arow] = Q.non_zero + 1;
			int tp;                             //��¼��һ�е�һ������Ԫ��M�е�λ�ã�
			if (arow < M.row_n)
				tp = M.rops[arow + 1];
			else
				tp = M.non_zero + 1;              //��arow=tuʱ��tu+1���Ա�ʾ��arow+1�е�һ������Ԫ��λ��
			for (int p = M.rops[arow]; p < tp; p++) //��M��ǰ�е�ÿһ������Ԫ
			{
				int brow = M.data[p].j;  //�ҵ���ӦԪ��N�е��к�,�磺M�ĵ�1�е�3��Ԫ��ֻ���ܺ�N�еĵ�3�е�ĳԪ�����
				int t;
				if (brow < N.row_n)
					t = N.rops[brow + 1];
				else
					t = N.non_zero + 1;
				for (int q = N.rops[brow]; q < t; q++) //��N�ĵ�ǰ�е�ÿһ������Ԫ
				{
					int ccol = N.data[q].j;
					ctemp[ccol] += M.data[p].e*N.data[q].e; //p������q�����ڵ�ѭ�����ctemp[i]��ʾ����Q��arow�е�i�е�Ԫ��
															//��׼ȷ��˵Ӧ����M��arow����N�ĵ�j�е�Ԫ�س˻�֮��
				}
			}
			for (int ccol = 1; ccol <= Q.col_n; ccol++)
			{
				if (ctemp[ccol])             //M��arow����N�ĵ�ccol�е�Ԫ�سɼ�֮�Ͳ�Ϊ0������Q
				{
					if (++Q.non_zero > MAXSIZE)  //Ҳ������һ����һ�����Ҵ��������Q�ķ���Ԫ�ĸ����������洢��λ����Ӧ��
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
		cout << "�վ���";
		return ERROR;
	}

	cout << "row\t" << "col\t" << "e\t" << endl;
	for (int i = 1; i < M.non_zero + 1; i++)
		cout << M.data[i].i << "\t" << M.data[i].j << "\t" << M.data[i].e << endl;

	return OK;
}