#include<iostream>
#include "����.h"
using namespace std;

typedef struct LNode {
	ElemType data;//����������
	LNode *next;//����ָ����
}LNode,*LinkList;//ͷָ��

//��巨���������㷨
void CreateList_L(LinkList &L, int n) {
	L = new LNode;
	L->next = NULL;
	LNode *p, *r;
	r = L;
	for (int i = 0; i < n; i++) {
		p = new LNode;
		cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}
//�ݹ����������
void TraverseList(LinkList p) {
	if (p == NULL)
		return;//�ݹ���ֹ
	else {
		cout << p->data << endl;
		TraverseList(p->next);//pָ���̽������ݹ�
	}
}
int main2() {
	int n;
	LinkList L;
	cout << "������Ԫ�ظ�����" << endl;
	cin >> n;
	cout << "����������Ԫ�أ��Կո�ֿ������س���������" << endl;
	CreateList_L(L, n);//��巨���������㷨
	cout << "�����е�Ԫ������Ϊ��" << endl;
	TraverseList(L->next);
	cout << endl;
	getchar();
	system("pasue");
	return 0;
}