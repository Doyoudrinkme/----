#include "TreeDefine.h"

//��������������
void CreateBiTree(BiTree &T) {
	char ch;
	cin >> ch;
	if (ch == '#') {
     //   cout << "�ƶ���������#";
		T = NULL;		
	}
	else {
		T = new BiTNode;
		T->data = ch;           //���ɸ��ڵ�
		CreateBiTree(T->lchild);//�ݹ鴴��������
		CreateBiTree(T->rchild);//�ݹ鴴��������
	}
}
void InOrderTraverse(BiTree T) {
	//�������
	if (T) {
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}