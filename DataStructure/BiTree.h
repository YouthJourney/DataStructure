#pragma once
#include"def.h"

typedef char ElenType;

typedef struct BiTNode {
	ElenType data;
	struct BiTNode *lchild, *rchild; //左右孩子的指针；
}*BiTree;

Status CreateBiTree(BiTree &T);   //按先序顺序构造二叉树；
Status PreOrderTraverse(BiTree T, Status(*Visit)(ElenType e));   //按先序顺序遍历二叉树；
Status InOrderTraverse(BiTree T, Status(*Visit)(ElenType e));    //按中序顺序遍历二叉树书；
Status PostOrderTraverse(BiTree T, Status(*Visit)(ElenType e));  //按后序顺序遍历二叉树；
Status LevelOrderTraverse(BiTree T, Status(*Visit)(ElenType e)); //按层序顺序遍历二叉树；
Status Visit(ElenType e);        //输出元素值；
int BiTreeDepth(BiTree T);       //求二叉树深度；
int LeafCount(BiTree T);         //计算叶子节点个数；
ElenType SearchParent(BiTree T, BiTNode *e);   //查找双亲；
ElenType LeftSibling(BiTree T, BiTNode *e);    //查找左兄弟；
ElenType RightSibling(BiTree T, BiTNode *e);   //查找右孩子；