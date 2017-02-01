#include<iostream>
#include "TreeDefine.h"

using namespace std;

void Copy(BiTree T, BiTree &NewT) {
	if (T == NULL) {
		//如果是空树，递归结束
		NewT = NULL;
		return;
	}
	else {
		NewT = new BiTNode;
		NewT->data = T->data;
		Copy(T->lchild, NewT->lchild);//递归复制左子树
		Copy(T->rchild, NewT->rchild);//递归复制右子树
	}
}

int Depth(BiTree T) {
	int m, n;
	if (T == NULL)
		return 0;//空树深度为0，递归结束
	else {
		m = Depth(T->lchild);//递归计算左子树的深度记为m
		n = Depth(T->rchild);//递归计算右子树的深度记为n
		if (m > n)
			return m + 1;
		else
			return n + 1;
	}
}

int NodeCount(BiTree T) {
	if (T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

void main231135() {
	BiTree tree, new_tree;
	cout << "请输入建立二叉树的序列：\n";
	CreateBiTree(tree);

	Copy(tree, new_tree);
	cout << "复制得到新树中的中序序列：\n";
	InOrderTraverse(new_tree);

	cout << "树的深度为：" << Depth(tree) << endl;
	cout << "结点个数为：" << NodeCount(tree) << endl;
	cout << endl;
	system("pause");
}