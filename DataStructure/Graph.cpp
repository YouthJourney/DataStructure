#include"stdafx.h"
#include"Graph.h"
#include"Stack.h"
#include"Queue.h"
#include<iostream>
using namespace std;

// ��G�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1�� 
int LocateVex(ALGraph G, VertexType u)
{
	int i;
	for (i = 0; i < G.vexnum; ++i)
		if (G.vertices[i].data == u)
			return i;
	return -1;
}

Status CreateUDG(ALGraph &G)
{
	int i, j;
	VertexType va, vb;
	ArcNode *p;

	cout << "������ͼ�Ķ������ͱ����� \n";
	cin >> G.vexnum >> G.arcnum;

	cout << "�����붥�����Ϣ��\n";

	for (i = 0; i < G.vexnum; ++i)  // ���춥������ 
	{
		G.vertices[i].firstarc = NULL;
		cin >> G.vertices[i].data;
	}

	cout << "��˳������ÿ����(��)�Ļ�β�ͻ�ͷ(�Կո���Ϊ���):\n";

	for (int k = 0; k < G.arcnum; ++k)	// ����������� 
	{
		cin >> va >> vb;

		i = LocateVex(G, va); // ��β 
		j = LocateVex(G, vb); // ��ͷ 

		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;

		//p->adjvex = NULL; 
		p->nextarc = G.vertices[i].firstarc; // ���ڱ�ͷ 
		G.vertices[i].firstarc = p;

		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->nextarc = G.vertices[j].firstarc; // ���ڱ�ͷ 
		G.vertices[j].firstarc = p;

	}
	return OK;
}

Status CreateUDN(ALGraph &G)
{
	int i, j;
	InfoType w;
	VertexType va, vb;
	ArcNode *p;

	cout << "������ͼ�Ķ������ͱ����� \n";
	cin >> G.vexnum >> G.arcnum;

	cout << "�����붥�����Ϣ��\n";

	for (i = 0; i < G.vexnum; ++i)  // ���춥������ 
	{
		G.vertices[i].firstarc = NULL;
		cin >> G.vertices[i].data;
	}

	cout << "��˳������ÿ����(��)�Ļ�β�ͻ�ͷ(�Կո���Ϊ���):\n";

	for (int k = 0; k < G.arcnum; ++k)	// ����������� 
	{
		cin >> va >> vb>>w;

		i = LocateVex(G, va); // ��β 
		j = LocateVex(G, vb); // ��ͷ 

		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = &w;

		p->nextarc = G.vertices[i].firstarc; // ���ڱ�ͷ 
		G.vertices[i].firstarc = p;

		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->info = &w;
		p->nextarc = G.vertices[j].firstarc; // ���ڱ�ͷ 
		G.vertices[j].firstarc = p;
		
	}
	return OK;
}

Status CreateDG(ALGraph &G)       //��������ͼ;
{
	int i, j;
	VertexType va, vb;
	ArcNode *p;

	cout << "������ͼ�Ķ������ͱ����� \n";
	cin >> G.vexnum >> G.arcnum;

	cout << "�����붥�����Ϣ��\n";

	for (i = 0; i < G.vexnum; ++i)  // ���춥������ 
	{
		G.vertices[i].firstarc = NULL;
		cin >> G.vertices[i].data;
	}

	cout << "��˳������ÿ����(��)�Ļ�β�ͻ�ͷ(�Կո���Ϊ���):\n";

	for (int k = 0; k < G.arcnum; ++k)	// ����������� 
	{
		cin >> va >> vb;

		i = LocateVex(G, va); // ��β 
		j = LocateVex(G, vb); // ��ͷ 

		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;

		p->nextarc = G.vertices[i].firstarc; // ���ڱ�ͷ 
		G.vertices[i].firstarc = p;
	}
	return OK;
}
Status CreateDN(ALGraph &G)        //������������
{
	int i, j;
	InfoType w;
	VertexType va, vb;
	ArcNode *p;

	cout << "������ͼ�Ķ������ͱ����� \n";
	cin >> G.vexnum >> G.arcnum;

	cout << "�����붥�����Ϣ��\n";

	for (i = 0; i < G.vexnum; ++i)  // ���춥������ 
	{
		G.vertices[i].firstarc = NULL;
		cin >> G.vertices[i].data;
	}

	cout << "��˳������ÿ����(��)�Ļ�β�ͻ�ͷ(�Կո���Ϊ���):\n";

	for (int k = 0; k < G.arcnum; ++k)	// ����������� 
	{
		cin >> va >> vb >> w;

		i = LocateVex(G, va); // ��β 
		j = LocateVex(G, vb); // ��ͷ 

		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = &w;

		p->nextarc = G.vertices[i].firstarc; // ���ڱ�ͷ 
		G.vertices[i].firstarc = p;

	}
	return OK;
}
// ����v�ĵ�һ���ڽӶ������š���������G��û���ڽӶ���,�򷵻�-1��
int FirstAdjVex(ALGraph G, VertexType v)
{
	int res = -1;
	if (G.vertices[v].firstarc)
		res = G.vertices[v].firstarc->adjvex;
	return res;	
}

// ����v��(�����w��)��һ���ڽӶ������š���w��v�����һ��
// �ڽӵ�,	�򷵻�-1��
int NextAdjVex(ALGraph G, VertexType v, VertexType w)
{
	ArcNode *p;
	int res = -1;
	p = G.vertices[v].firstarc;
	while (p)
	{
		if (p->adjvex == w)
		{
			if (p->nextarc)
				res = p->nextarc->adjvex;
			break;
		}
		p = p->nextarc;
	}
	return res;
}

bool visited[MAX_VERTEX_NUM];	// ���ʱ�־����(ȫ����) 

//	�ӵ�v����������ݹ��������ȱ���ͼG��
void DFS(ALGraph G, int v)
{
	visited[v] = true;
	cout << G.vertices[v].data<<"-->";
	for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
		if (visited[w]==false)
			DFS(G, w);
}

void DFSTraverse(ALGraph G) {

	for (int v = 0; v < G.vexnum; v++)
		visited[v] = false;
	for (int v = 0; v < G.vexnum; v++)
		if (!visited[v])
			DFS(G, v);                  //����δ���ʵĶ������DFS��
}

Status PrintGraph(ALGraph G)
{
	ArcNode *p;
	cout<<("\n");

	cout<<("��ͼ���ڽӱ�Ϊ:\n");

	for (int i = 0; i<G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;
		
		while (p != 0)
		{
			cout << "w(" << G.vertices[i].data << ",";
			cout << G.vertices[p->adjvex].data<<")  ";
			p = p->nextarc;
		}
		cout << endl; //���У������һ����ͷ�����ӵĽڵ� ; 
	}
	
	return OK;
}

void BFSTraverse(ALGraph G)  //������ȱ�����
{
	LinkQueue Q;
	int v, w, u;
	for (v = 0; v < G.vexnum; v++)
		visited[v] = false;
	InitQueue(&Q);

	for(v=0;v<G.vexnum;v++)
		if (!visited[v])
		{
			visited[v] = true;
			cout << G.vertices[v].data << "-->";
			EnQueue(&Q,v);
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q,&u);
				for(w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,u,w))
					if (!visited[w])
					{
						visited[w] = true;
						cout << G.vertices[w].data << "-->";
						EnQueue(&Q,w);
					}
			}
		}
}

void FindInDegree(ALGraph G, int indegree[])
{
	for (int i = 0; i < G.vexnum; i++)
		indegree[i] = 0;
	for(int i=0;i<G.vexnum;i++)
		while (G.vertices[i].firstarc)
		{
			indegree[G.vertices[i].firstarc->adjvex]++;
			G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
		}
}

void TopologicalSort(ALGraph G)
{
	int indegree[MAX_DEGREE];
	Stack S;
	ArcNode *p;
	int i;
	FindInDegree(G, indegree);
	InitStack(S);
	for ( i = 0; i < G.vexnum; i++)
		if (!indegree[i])
			Push(S, i);
	int count = 0;
	cout << "����������Ϊ�� ";
	while (!StackEmpty(S))
	{
		Pop(S, i);
		cout << G.vertices[i].data << " ";
		++count;
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)
		{
			int k = p->adjvex;
			if (!(--indegree[k]))
				Push(S, k);
		}

	}

	if (count < G.vexnum)
		cout << "��ͼ�л�·!";
}