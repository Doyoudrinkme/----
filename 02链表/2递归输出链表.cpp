#include<iostream>
#include "链表.h"
using namespace std;

typedef struct LNode {
	ElemType data;//结点的数据域
	LNode *next;//结点的指针域
}LNode,*LinkList;//头指针

//后插法创建链表算法
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
//递归输出链表结点
void TraverseList(LinkList p) {
	if (p == NULL)
		return;//递归终止
	else {
		cout << p->data << endl;
		TraverseList(p->next);//p指向后继结点继续递归
	}
}
int main2() {
	int n;
	LinkList L;
	cout << "请输入元素个数：" << endl;
	cin >> n;
	cout << "请输入链表元素（以空格分开，按回车结束）：" << endl;
	CreateList_L(L, n);//后插法创建链表算法
	cout << "链表中的元素依次为：" << endl;
	TraverseList(L->next);
	cout << endl;
	getchar();
	system("pasue");
	return 0;
}