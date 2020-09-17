#pragma once
#include"stdafx.h"
#include"def.h"
#include<string>
#include<iostream>
using namespace std;

typedef struct {
	string name;
	int numble;

}LinkMan;

typedef struct ALNode {
	LinkMan data;
	struct ALNode*next;
}ALNode, *AddrLinkList;

Status CreateAddrList_L(AddrLinkList &L, int n);             //创建联系人；
void PrintAddrList(AddrLinkList L);                          //显示联系人；
Status AddrListInsert_L(AddrLinkList&L, int i, LinkMan e);   //插入联系人；
Status AddrListDelete_L(AddrLinkList&L, int i);              //删除联系人；
LinkMan AddrListSearch_L(AddrLinkList &L, int i, LinkMan &e); //查找联系人