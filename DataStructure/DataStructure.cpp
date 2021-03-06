// DataStructure.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"DataStructure.h"
#include"AddrList.h"
#include"LinkList.h"
#include"Stack.h"
#include"Array.h"
#include"BiTree.h"
#include"Graph.h"
#include<string>
#include<iostream>
using namespace std;

void ShowMainMenu() {
	cout << ("\n");
	cout << "==========================================================\n" << endl;
	cout << "==========================================================\n" << endl;
	cout << "**********欢迎使用数据结构管理系统*************************\n" << endl;
	cout << "-------------------------------------------制作人:以诗之名\n" << endl;
	cout << "**********************************************************\n" << endl;
	cout << "==========================================================\n" << endl;

	cout << "请按任意键进入数据结构管理系统：";
	getchar();
	system("cls");

	cout << ("*******************算法与数据结构******************\n");
	cout << ("*          1  单链表的基本操作及应用                      *\n");
	cout << ("*          2  栈的基本操作及应用                          *\n");
	cout << ("*          3  数组的基本操作及应用                        *\n");
	cout << ("*          4  树的基本操作及应用                          *\n");
	cout << ("*          5  图的基本操作及应用                          *\n");
	cout << ("*          6  退出                                        *\n");
	cout << ("***********************************************************\n");
}

//链表操作菜单；
void ListMenu()
{
	cout << ("\n");
	cout << ("**************单链表的基本操作及应用***************\n");
	cout << ("* 1  创建                                         *\n");
	cout << ("* 2  插入                                         *\n");
	cout << ("* 3  删除                                         *\n");
	cout << ("* 4  查找                                         *\n");
	cout << ("* 5  显示                                         *\n");
	cout << ("* 6  通讯录（应用）                               *\n");
	cout << ("* 7  退出                                         *\n");
	cout << ("***************************************************\n");

}

//通讯录操作菜单；
void AddrMenu() {
	cout << ("\n");
	cout << ("**************通讯录的基本设置***************\n");
	cout << ("* 1  创建联系人                             *\n");
	cout << ("* 2  插入联系人                             *\n");
	cout << ("* 3  删除联系人                             *\n");
	cout << ("* 4  查找联系人                             *\n");
	cout << ("* 5  显示显示联系人                         *\n");
	cout << ("* 6  退出                                   *\n");
	cout << ("*********************************************\n");
}

//栈操作菜单；
void StackMenu()
{
	cout << ("\n");
	cout << ("****************栈的基本操作及应用*****************\n");
	cout << ("* 1  进栈                                         *\n");
	cout << ("* 2  出栈                                         *\n");
	cout << ("* 3  取栈顶元素                                   *\n");
	cout << ("* 4  表达式求解（应用）                           *\n");
	cout << ("* 5  退出                                         *\n");
	cout << ("***************************************************\n");
}

//数组操作菜单；
void ArrayMenu() {
	cout << ("\n");
	cout << ("*************稀疏矩阵的压缩存储及应用**************\n");
	cout << ("* 1  创建                                         *\n");
	cout << ("* 2  显示                                         *\n");
	cout << ("* 3  矩阵乘法（应用）                             *\n");
	cout << ("* 4  退出                                         *\n");
	cout << ("***************************************************\n");
}

void BiTreeMenu()
{
	cout << ("\n");
	cout << ("**************二叉树的基本操作及应用***************\n");
	cout << ("* 1  创建二叉树                                   *\n");
	cout << ("* 2  遍历二叉树（先/中/后）                       *\n");
	cout << ("* 3  计算树的深度                                 *\n");
	cout << ("* 4  计算叶子结点个数                             *\n");
	cout << ("* 5  查找双亲                                     *\n");
	cout << ("* 6  查找兄弟                                     *\n");
	cout << ("* 7  Huffman编码（应用）                          *\n");
	cout << ("* 8  退出                                         *\n");
	cout << ("***************************************************\n");
}

void GraphMenu()
{
	cout << ("\n");
	cout << ("****************图的基本操作及应用******************\n");
	cout << ("* 1  创建无向图                                    *\n");
	cout << ("* 2  创建无向网                                    *\n");
	cout << ("* 3  创建有向图                                    *\n");
	cout << ("* 4  创建有向网                                    *\n");
	cout << ("* 5  遍历                                          *\n");
	cout << ("* 6  拓扑排序                                      *\n");
	cout << ("* 7  最小生成树（应用）                            *\n");
	cout << ("* 8  最短路径（应用）                              *\n");
	cout << ("* 9  关键路径（应用）                              *\n");
	cout << ("* 10 退出                                          *\n");
	cout << ("****************************************************\n");
}

void LinkList_L() {
	int i; ElemType e;  //位置i，数据/长度e;
	int n;
	LinkList T = 0;

	do {
		ListMenu();

		cout << (">>>>>请选择：");
		cin >> n;

		switch (n) {
		case 1:
			cout << ("\n--------创建单链表---------\n");
			cout << "请输入链表长度: ";
			cin >> e;
			CreateList_L(T, e);
			cout << "创建链表成功！\n";
			break;
		case 2:
			cout << ("\n--------插入元素-------\n");
			cout << "请输入插入位置：";
			cin >> i;
			cout << "\n请输入插入元素：";
			cin >> e;
			ListInsert_L(T, i, e);
			cout << endl;
			break;
		case 3:
			cout << ("\n--------删除元素-------\n");
			cout << "删除哪一个数据：";
			cin >> i;
			ListDelete_L(T, i);
			cout << endl;
			break;
		case 4:
			cout << ("\n--------查找元素-------\n");
			cout << "查找哪个元素：";
			cin >> i;
			cout << "\n该元素为：" << ListSearch_L(T, i, e) << endl;
			break;
		case 5:
			cout << ("\n--------显示链表-------\n");
			PrintList(T);
			cout << endl;
			break;
		case 6:
			cout << ("--------通讯录---------\n");
			ShowAddrMenu();
			break;
		case 7: break;
		default:
			cout << ("ERROR!") << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (n != 7);
}

void ShowAddrMenu() {
	int i; LinkMan e;  //位置i，数据/长度e;
	int n;
	AddrLinkList T = 0;

	do {
		AddrMenu();

		cout << (">>>>请选择：");
		cin >> n;

		switch (n) {
		case 1:
			cout << ("\n--------创建联系人---------\n");
			cout << "请输入联系人个数: ";
			cin >> i;
			CreateAddrList_L(T, i);
			cout << "创建通讯录成功！\n";
			break;
		case 2:
			cout << ("\n--------插入联系人-------\n");
			cout << "请输入插入位置：";
			cin >> i;
			cout << "\n请输入插入的联系人信息：";
			cin >> e.name >> e.numble;
			AddrListInsert_L(T, i, e);
			cout << endl;
			break;
		case 3:
			cout << ("\n--------删除联系人-------\n");
			cout << "删除哪一个联系人：";
			cin >> i;
			AddrListDelete_L(T, i);
			cout << endl;
			break;
		case 4:
			cout << ("\n--------查找联系人-------\n");
			cout << "查找哪一个联系人：";
			cin >> i;
			AddrListSearch_L(T, i, e);
			cout << "\n该联系人为: " << e.name << "\t" << e.numble << endl;
			break;
		case 5:
			cout << ("\n--------显示联系人-------\n");
			PrintAddrList(T);
			cout << endl;
			break;
		case 6: break;
		default:
			cout << ("ERROR!") << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (n != 6);
}

void Stack_S() {
	ElemType e;  //数据/长度e;
	int n;
	Stack S;
	InitStack(S);

	do {
		StackMenu();

		cout << (">>>>请选择：");
		cin >> n;

		switch (n) {
		case 1:
			cout << ("--------进栈-------\n");
			cout << "请输入进栈元素个数： ";
			int t;
			cin >> t;
			cout << "进栈元素为： ";
			for (int i = 0; i < t; i++)
			{
				cin >> e;
				Push(S, e);
			}
			cout << "进栈成功！\n";
			break;
		case 2:
			cout << ("--------出栈-------\n");
			cout << "出栈元素为： ";
			while (S->next != 0)
			{
				Pop(S, e);
				cout << e << " ";
			}
			cout << endl;
			break;
		case 3:
			cout << ("--------取栈顶元素-------\n");
			GetTop(S, e);
			cout << "栈顶元素为: " << e << endl;
			break;
		case 4:
			cout << ("--------表达式求值-------"); break;
		case 5:break;
		default:
			cout << ("ERROR!") << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (n != 5);
}

void Array_A() {
	int n; 
	//ElemType e;//数据/长度e;
	//int bounds[MAX_BOUNDS];
	//Array A;
	TSMatrix M, N, T;

	do {
		ArrayMenu();

		cout << (">>>>>请选择：");
		cin >> n;

		switch (n) {
		case 1:
			cout << ("---------创建-------\n");
			cout << "创建矩阵：\n";
			CreateSMatrix(M);
			cout << "创建成功！";
			break;
		case 2:
			cout << ("---------显示-------\n");
			PrintSMatrix(M);
			break;
		case 3:
			cout << ("---------矩阵乘法-------\n");
			CreateSMatrix(M);
			CreateSMatrix(N);
			cout << "\n矩阵M*N=T\n";
			MultSMatrix(M, N, T);
			PrintSMatrix(T);

			break;
		case 4:break;
		default:
			cout << ("ERROR!") << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (n != 4);
}

void BiTree_B() {
	int n;
	BiTree T = 0;
	BiTNode *e = new BiTNode;

	do {
		BiTreeMenu();

		cout << (">>>>>请选择：");
		cin >> n;

		switch (n) {
		case 1:
			cout << ("---------创建二叉树--------\n");
			cout << "请按先序顺序输入二叉树（如：ABD00E00C00)\n";
			CreateBiTree(T);
			cout << endl;
			break;
		case 2:
			cout << ("---------*遍历二叉树-------\n");
			cout << "选择遍历方式： 1.先序遍历；2.中序遍历；3.后序遍历；4.层序遍历；\n";
			cout << "您选择的遍历方式为：";
			int i;
			cin >> i;
			switch (i)
			{
			case 1:
				cout << "先序遍历结果为： ";
				PreOrderTraverse(T, Visit);
				break;
			case 2:
				cout << "中序遍历结果为： ";
				InOrderTraverse(T, Visit);
				break;
			case 3:
				cout << "后序遍历结果为： ";
				PostOrderTraverse(T, Visit);
				break;
			case 4:
				cout << "层序遍历结果为： ";
				LevelOrderTraverse(T, Visit);
				break;
			default:
				cout << ("ERROR!") << endl;
				break;
			}
			cout << endl;
			break;
		case 3:
			cout << ("---------计算树的深度------\n");
			cout << "树的深度为： ";
			cout << BiTreeDepth(T) << endl;;
			break;
		case 4:
			cout << ("---------计算叶子结点个数-------\n");
			cout << "叶子节点个数为： ";
			cout << LeafCount(T) << endl;
			break;
		case 5:
			cout << ("---------查找双亲-------\n");
			cout << "请输入要查找双亲的节点： ";
			cin >> e->data;
			cout << "该节点的双亲是： " << SearchParent(T, e) << endl;
			break;
		case 6:
			cout << ("---------查找兄弟-------\n");
			cout << "请输入要查找兄弟的节点： ";
			cin >> e->data;
			cout << "该节点的右兄弟是： " << RightSibling(T, e) << endl;
			cout << "该节点的左兄弟是： " << LeftSibling(T, e) << endl;
			break;
		case 7:
			cout << ("---------Huffman编码-------\n");
			break;
		case 8:break;
		default:
			cout << ("ERROR!") << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (n != 8);
}

void Graph_G() {
	int n;
	ALGraph G;
	do {
		GraphMenu();

		cout << (">>>>>请选择：");
		cin >> n;
		switch (n) {
		case 1:
			cout << ("---------创建无向图-------\n");
			CreateUDG(G);
			PrintGraph(G);
			break;
		case 2:
			cout << ("---------创建无向网-------\n");
			CreateUDN(G);
			PrintGraph(G);
			break;
		case 3:
			cout << ("---------创建有向图-------\n"); 
			CreateDG(G);
			PrintGraph(G);
			break;
		case 4:
			cout << ("---------创建有向网-------\n"); 
			CreateDN(G);
			PrintGraph(G);
			break;
		case 5:
			cout << ("---------遍历-------\n");
			cout << "深度优先遍历结果为： ";
			DFSTraverse(G);
			cout << "\n深度优先遍历结果为： ";
			BFSTraverse(G);
			cout << endl;
			break;
		case 6:
			cout << ("---------拓扑排序-------\n");
			TopologicalSort(G);
			cout << endl;
			break;
		case 7:
			cout << ("---------最小生成树-------\n"); break;
		case 8:
			cout << ("---------最短路径-------\n"); break;
		case 9:
			cout << ("---------关键路径-------\n"); break;
		case 10:break;
		default:
			cout << ("ERROR!") << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (n != 10);
}
