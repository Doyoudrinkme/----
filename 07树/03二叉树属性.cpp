#include<iostream>
#include "TreeDefine.h"

using namespace std;

void Copy(BiTree T, BiTree &NewT) {
	if (T == NULL) {
		//����ǿ������ݹ����
		NewT = NULL;
		return;
	}
	else {
		NewT = new BiTNode;
		NewT->data = T->data;
		Copy(T->lchild, NewT->lchild);//�ݹ鸴��������
		Copy(T->rchild, NewT->rchild);//�ݹ鸴��������
	}
}

int Depth(BiTree T) {
	int m, n;
	if (T == NULL)
		return 0;//�������Ϊ0���ݹ����
	else {
		m = Depth(T->lchild);//�ݹ��������������ȼ�Ϊm
		n = Depth(T->rchild);//�ݹ��������������ȼ�Ϊn
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
	cout << "�����뽨�������������У�\n";
	CreateBiTree(tree);

	Copy(tree, new_tree);
	cout << "���Ƶõ������е��������У�\n";
	InOrderTraverse(new_tree);

	cout << "�������Ϊ��" << Depth(tree) << endl;
	cout << "������Ϊ��" << NodeCount(tree) << endl;
	cout << endl;
	system("pause");
}