#include<iostream>
#include "TreeDefine.h"

using namespace std;

//链栈定义
typedef struct StackNode {
	BiTNode data;
	struct StackNode *next;
}StackNode,*LinkStack;

//栈初始化
void InitStack(LinkStack &S) {
	S = NULL;
}
//栈顶插入元素
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
	//中序遍历二叉树T 的非递归算法
	LinkStack S;
	BiTree p = T;
	BiTree q = new BiTNode;
	InitStack(S);
	
	while (p||!StackEmpty(S) ){
		if (p) {
			Push(S, p);//非空根指针进栈，遍历左子树
			p = p->lchild;
		}
		else {
			Pop(S, q);//p为空根指针退栈，访问根节点，遍历右子树
			cout << q->data;
			p = q->rchild;
		}
	}
}
int main2017年1月5日150223() {
	BiTree tree;
	cout << "请输入建立二叉链表的序列：\n";
	CreateBiTree(tree);
	cout << "中序遍历的结果为：\n";
	InOrderTraverse2(tree);
	cout << endl;
	system("pause");
	return 0;
}