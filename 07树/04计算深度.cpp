#include<iostream>
#include "TreeDefine.h"

using namespace std;

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


void main() {
	BiTree tree;
	cout << "请输入建立二叉树的序列：\n";
	CreateBiTree(tree);
	cout << "数的深度为：" << Depth(tree) << endl;
	system("pause");
}