#include "stdafx.h"
#include"DataStructure.h"
#include<iostream>
using namespace std;

int main()
{
	int Item;  //操作指令；

	do {
		ShowMainMenu();
		cout << "请选择操作指令：";
		cin >> Item;
		system("cls");   //清屏，清除所有显示的信息；

		switch (Item)
		{
		case 1:
			LinkList_L();
			break;
		case 2:
			Stack_S();
			break;
		case 3:
			Array_A();
			break;
		case 4:
			BiTree_B();
			break;
		case 5:
			Graph_G();
			break;
		case 6:
			break;
		default:
			cout << ("ERROR!");
			system("pause");
			break;
		}
		
	} while (Item != 6);

	return 0;
}
