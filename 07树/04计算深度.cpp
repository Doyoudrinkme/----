#include<iostream>
#include "TreeDefine.h"

using namespace std;

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


void main() {
	BiTree tree;
	cout << "�����뽨�������������У�\n";
	CreateBiTree(tree);
	cout << "�������Ϊ��" << Depth(tree) << endl;
	system("pause");
}