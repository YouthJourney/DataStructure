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

Status CreateAddrList_L(AddrLinkList &L, int n);             //������ϵ�ˣ�
void PrintAddrList(AddrLinkList L);                          //��ʾ��ϵ�ˣ�
Status AddrListInsert_L(AddrLinkList&L, int i, LinkMan e);   //������ϵ�ˣ�
Status AddrListDelete_L(AddrLinkList&L, int i);              //ɾ����ϵ�ˣ�
LinkMan AddrListSearch_L(AddrLinkList &L, int i, LinkMan &e); //������ϵ��