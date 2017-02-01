#include<iostream>
#include "TreeDefine.h"

using namespace std;

//��ջ����
typedef struct StackNode {
	BiTNode data;
	struct StackNode *next;
}StackNode,*LinkStack;

//ջ��ʼ��
void InitStack(LinkStack &S) {
	S = NULL;
}
//ջ������Ԫ��
void Push(LinkStack &S, BiTree e) {
	StackNode *p = new StackNode;
	p->data = *e;
	p->next = S;
	S = p;
}
void Pop(LinkStack &S, BiTree e) {
	if (S != NULL) {
		*e = S->data;
		StackNode *p = S;
		S = S->next;
		delete p;
	}
}
 
bool StackEmpty(LinkStack S) {
	if (!S)
		return true;
	return false;
}
void InOrderTraverse2(BiTree T) {
	//�������������T �ķǵݹ��㷨
	LinkStack S;
	BiTree p = T;
	BiTree q = new BiTNode;
	InitStack(S);
	
	while (p||!StackEmpty(S) ){
		if (p) {
			Push(S, p);//�ǿո�ָ���ջ������������
			p = p->lchild;
		}
		else {
			Pop(S, q);//pΪ�ո�ָ����ջ�����ʸ��ڵ㣬����������
			cout << q->data;
			p = q->rchild;
		}
	}
}
int main2017��1��5��150223() {
	BiTree tree;
	cout << "�����뽨��������������У�\n";
	CreateBiTree(tree);
	cout << "��������Ľ��Ϊ��\n";
	InOrderTraverse2(tree);
	cout << endl;
	system("pause");
	return 0;
}