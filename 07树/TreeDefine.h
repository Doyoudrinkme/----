#pragma once
#include<iostream>
using namespace std;

typedef struct BiNode {
	char data;
	struct BiNode *lchild, *rchild;
}BiTNode, *BiTree;

void CreateBiTree(BiTree &T);
void InOrderTraverse(BiTree T);
