#include<iostream>
#include "TreeDefine.h"
using namespace std;

//二叉链表定义


void main2017年1月6日143828() {
	BiTree tree;
	cout << "请输入建立二叉链表的序列：\n";
	CreateBiTree(tree);
	cout << "中序遍历的结果为：\n";
	InOrderTraverse(tree);
	cout << endl;
	system("pause");
}