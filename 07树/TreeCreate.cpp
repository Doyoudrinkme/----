#include "TreeDefine.h"

//先序建立二叉链表
void CreateBiTree(BiTree &T) {
	char ch;
	cin >> ch;
	if (ch == '#') {
     //   cout << "闷兜儿输入了#";
		T = NULL;		
	}
	else {
		T = new BiTNode;
		T->data = ch;           //生成根节点
		CreateBiTree(T->lchild);//递归创建左子树
		CreateBiTree(T->rchild);//递归创建右子树
	}
}
void InOrderTraverse(BiTree T) {
	//中序遍历
	if (T) {
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}