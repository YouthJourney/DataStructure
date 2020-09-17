#include"stdafx.h"
#include"Graph.h"
#include"Stack.h"
#include"Queue.h"
#include<iostream>
using namespace std;

// 若G中存在顶点u,则返回该顶点在图中位置;否则返回-1。 
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

	cout << "请输入图的顶点数和边数： \n";
	cin >> G.vexnum >> G.arcnum;

	cout << "请输入顶点的信息：\n";

	for (i = 0; i < G.vexnum; ++i)  // 构造顶点向量 
	{
		G.vertices[i].firstarc = NULL;
		cin >> G.vertices[i].data;
	}

	cout << "请顺序输入每条弧(边)的弧尾和弧头(以空格作为间隔):\n";

	for (int k = 0; k < G.arcnum; ++k)	// 构造表结点链表 
	{
		cin >> va >> vb;

		i = LocateVex(G, va); // 弧尾 
		j = LocateVex(G, vb); // 弧头 

		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;

		//p->adjvex = NULL; 
		p->nextarc = G.vertices[i].firstarc; // 插在表头 
		G.vertices[i].firstarc = p;

		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->nextarc = G.vertices[j].firstarc; // 插在表头 
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

	cout << "请输入图的顶点数和边数： \n";
	cin >> G.vexnum >> G.arcnum;

	cout << "请输入顶点的信息：\n";

	for (i = 0; i < G.vexnum; ++i)  // 构造顶点向量 
	{
		G.vertices[i].firstarc = NULL;
		cin >> G.vertices[i].data;
	}

	cout << "请顺序输入每条弧(边)的弧尾和弧头(以空格作为间隔):\n";

	for (int k = 0; k < G.arcnum; ++k)	// 构造表结点链表 
	{
		cin >> va >> vb>>w;

		i = LocateVex(G, va); // 弧尾 
		j = LocateVex(G, vb); // 弧头 

		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = &w;

		p->nextarc = G.vertices[i].firstarc; // 插在表头 
		G.vertices[i].firstarc = p;

		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->info = &w;
		p->nextarc = G.vertices[j].firstarc; // 插在表头 
		G.vertices[j].firstarc = p;
		
	}
	return OK;
}

Status CreateDG(ALGraph &G)       //构造有向图;
{
	int i, j;
	VertexType va, vb;
	ArcNode *p;

	cout << "请输入图的顶点数和边数： \n";
	cin >> G.vexnum >> G.arcnum;

	cout << "请输入顶点的信息：\n";

	for (i = 0; i < G.vexnum; ++i)  // 构造顶点向量 
	{
		G.vertices[i].firstarc = NULL;
		cin >> G.vertices[i].data;
	}

	cout << "请顺序输入每条弧(边)的弧尾和弧头(以空格作为间隔):\n";

	for (int k = 0; k < G.arcnum; ++k)	// 构造表结点链表 
	{
		cin >> va >> vb;

		i = LocateVex(G, va); // 弧尾 
		j = LocateVex(G, vb); // 弧头 

		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;

		p->nextarc = G.vertices[i].firstarc; // 插在表头 
		G.vertices[i].firstarc = p;
	}
	return OK;
}
Status CreateDN(ALGraph &G)        //构造有向网；
{
	int i, j;
	InfoType w;
	VertexType va, vb;
	ArcNode *p;

	cout << "请输入图的顶点数和边数： \n";
	cin >> G.vexnum >> G.arcnum;

	cout << "请输入顶点的信息：\n";

	for (i = 0; i < G.vexnum; ++i)  // 构造顶点向量 
	{
		G.vertices[i].firstarc = NULL;
		cin >> G.vertices[i].data;
	}

	cout << "请顺序输入每条弧(边)的弧尾和弧头(以空格作为间隔):\n";

	for (int k = 0; k < G.arcnum; ++k)	// 构造表结点链表 
	{
		cin >> va >> vb >> w;

		i = LocateVex(G, va); // 弧尾 
		j = LocateVex(G, vb); // 弧头 

		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = &w;

		p->nextarc = G.vertices[i].firstarc; // 插在表头 
		G.vertices[i].firstarc = p;

	}
	return OK;
}
// 返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点,则返回-1。
int FirstAdjVex(ALGraph G, VertexType v)
{
	int res = -1;
	if (G.vertices[v].firstarc)
		res = G.vertices[v].firstarc->adjvex;
	return res;	
}

// 返回v的(相对于w的)下一个邻接顶点的序号。若w是v的最后一个
// 邻接点,	则返回-1。
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

bool visited[MAX_VERTEX_NUM];	// 访问标志数组(全局量) 

//	从第v个顶点出发递归地深度优先遍历图G。
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
			DFS(G, v);                  //对尚未访问的顶点调用DFS；
}

Status PrintGraph(ALGraph G)
{
	ArcNode *p;
	cout<<("\n");

	cout<<("该图的邻接表为:\n");

	for (int i = 0; i<G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;
		
		while (p != 0)
		{
			cout << "w(" << G.vertices[i].data << ",";
			cout << G.vertices[p->adjvex].data<<")  ";
			p = p->nextarc;
		}
		cout << endl; //换行，输出下一个表头所连接的节点 ; 
	}
	
	return OK;
}

void BFSTraverse(ALGraph G)  //广度优先遍历；
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
	cout << "拓扑排序结果为： ";
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
		cout << "该图有回路!";
}