#pragma once
#include"def.h"

typedef int InfoType;     //�������Ȩֵ��
typedef char VertexType;
typedef enum { DG, DN, AG, AN }GraphKind; // {����ͼ,������,����ͼ,������} 
#define MAX_VERTEX_NUM          20         //��󶥵����
#define MAX_DEGREE             20        //������


//���ڵ�ṹ��
typedef struct ArcNode {
	int adjvex;                    //�û���ָ��Ķ����λ�ã�
	struct ArcNode *nextarc;       //ָ����һ������ָ�룻
	InfoType *info;                //�û��������Ϣ��ָ�루����Ȩֵ����
}ArcNode;

//�����ڵ㣻
typedef struct VNode {
	VertexType data;          //������Ϣ��
	ArcNode   *firstarc;        //ָ���һ�������ö���Ļ���ָ�룻
}VNode,AdjList[MAX_VERTEX_NUM];

//ͼ�Ľṹ
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;                          //ͼ�ĵ�ǰ�������ͻ�����
	int kind;                                    //ͼ�����ࣻ
}ALGraph;

Status CreateUDN(ALGraph &G);       //�����ڽӱ��ʾ��������������G��
int LocateVex(ALGraph G, VertexType u);   //ȷ��v��G�е�λ�ã�
Status PrintGraph(ALGraph G);       //��ӡͼ��
Status CreateDG(ALGraph &G);        //��������ͼ
Status CreateDN(ALGraph &G);        //������������
Status CreateUDG(ALGraph &G);       //��������ͼ��
int LocateVex(ALGraph G, VertexType u); //��G�д��ڶ���u,�򷵻ظö�����ͼ��λ�á�
int FirstAdjVex(ALGraph G, VertexType v);// ����v�ĵ�һ���ڽӶ������š���������G��û���ڽӶ��㡣
int NextAdjVex(ALGraph G, VertexType v, VertexType w);// ����v��(�����w��)��һ���ڽӶ������š���w��v�����һ���ڽӵ�;
void DFS(ALGraph G, int v);   //�ӵ�v����������ݹ��������ȱ���ͼG��
void DFSTraverse(ALGraph G); //	��ͼG��������ȱ�����
void BFSTraverse(ALGraph G);  //������ȱ�����
void TopologicalSort(ALGraph G);   //��������
void FindInDegree(ALGraph G, int indegree[]);  //���������ȣ�