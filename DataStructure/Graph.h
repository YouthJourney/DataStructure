#pragma once
#include"def.h"

typedef int InfoType;     //存放网的权值；
typedef char VertexType;
typedef enum { DG, DN, AG, AN }GraphKind; // {有向图,有向网,无向图,无向网} 
#define MAX_VERTEX_NUM          20         //最大顶点个数
#define MAX_DEGREE             20        //最大入度


//弧节点结构；
typedef struct ArcNode {
	int adjvex;                    //该弧所指向的顶点的位置；
	struct ArcNode *nextarc;       //指向下一条弧的指针；
	InfoType *info;                //该弧的相关信息的指针（网的权值）；
}ArcNode;

//顶点表节点；
typedef struct VNode {
	VertexType data;          //顶点信息；
	ArcNode   *firstarc;        //指向第一条依附该顶点的弧的指针；
}VNode,AdjList[MAX_VERTEX_NUM];

//图的结构
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;                          //图的当前顶点数和弧数；
	int kind;                                    //图的种类；
}ALGraph;

Status CreateUDN(ALGraph &G);       //采用邻接表表示法，构造无向网G；
int LocateVex(ALGraph G, VertexType u);   //确定v在G中的位置；
Status PrintGraph(ALGraph G);       //打印图；
Status CreateDG(ALGraph &G);        //构造有向图
Status CreateDN(ALGraph &G);        //构造有向网；
Status CreateUDG(ALGraph &G);       //构造无向图；
int LocateVex(ALGraph G, VertexType u); //若G中存在顶点u,则返回该顶点在图中位置。
int FirstAdjVex(ALGraph G, VertexType v);// 返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点。
int NextAdjVex(ALGraph G, VertexType v, VertexType w);// 返回v的(相对于w的)下一个邻接顶点的序号。若w是v的最后一个邻接点;
void DFS(ALGraph G, int v);   //从第v个顶点出发递归地深度优先遍历图G。
void DFSTraverse(ALGraph G); //	对图G作深度优先遍历。
void BFSTraverse(ALGraph G);  //广度优先遍历；
void TopologicalSort(ALGraph G);   //拓扑排序；
void FindInDegree(ALGraph G, int indegree[]);  //求各顶点入度；