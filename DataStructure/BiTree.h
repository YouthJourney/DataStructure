#pragma once
#include"def.h"

typedef char ElenType;

typedef struct BiTNode {
	ElenType data;
	struct BiTNode *lchild, *rchild; //���Һ��ӵ�ָ�룻
}*BiTree;

Status CreateBiTree(BiTree &T);   //������˳�����������
Status PreOrderTraverse(BiTree T, Status(*Visit)(ElenType e));   //������˳�������������
Status InOrderTraverse(BiTree T, Status(*Visit)(ElenType e));    //������˳������������飻
Status PostOrderTraverse(BiTree T, Status(*Visit)(ElenType e));  //������˳�������������
Status LevelOrderTraverse(BiTree T, Status(*Visit)(ElenType e)); //������˳�������������
Status Visit(ElenType e);        //���Ԫ��ֵ��
int BiTreeDepth(BiTree T);       //���������ȣ�
int LeafCount(BiTree T);         //����Ҷ�ӽڵ������
ElenType SearchParent(BiTree T, BiTNode *e);   //����˫�ף�
ElenType LeftSibling(BiTree T, BiTNode *e);    //�������ֵܣ�
ElenType RightSibling(BiTree T, BiTNode *e);   //�����Һ��ӣ�