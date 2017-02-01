#include <iostream>
#include "TreeDefine.h"

using namespace std;

//二叉树的二叉线索类型存储表示
typedef struct BiThrNode {
	char data;//结点数据域
	struct BiThrNode *lchild, *rchild;//左右孩子指针
	int LTag, RTag;
}BiThrNode,*BiThrTree;

//全局变量pre
BiThrNode *pre = new BiThrNode;

void CreateBiTree(BiThrTree &T) {
	char ch;
	cin >> ch;
	if (ch == '#') {
		//   cout << "闷兜儿输入了#";
		T = NULL;
	} else {
		T = new BiThrNode;
		T->data = ch;           //生成根节点
		CreateBiTree(T->lchild);//递归创建左子树
		CreateBiTree(T->rchild);//递归创建右子树
	}
}
void InThreading(BiThrTree p) {
	//pre是全局变量。初始化时右孩子为空，便于在树的最左边开始建线索
	if (p) {
		InThreading(p->lchild);//左子树递归线索化
		if (!p->lchild) {
			p->LTag = 1;//给p加上左线索
			p->lchild = pre;//p的左孩子指针指向前驱pre
		} else
			p->LTag = 0;
		if (!pre->rchild) {
			pre->RTag = 1;  //给pre加上右线索
			pre->rchild = p;//pre的右孩子指针指向后继p
		} else
			pre->RTag = 0;
		pre = p;//保持pre指向p的前驱
		InThreading(p->rchild);
	}
}
//中序遍历二叉树T，并将中序线索化，Thrt指向头结点
void InOrderThreading(BiThrTree &Thrt,BiThrTree T) {
	Thrt = new BiThrNode;//建立头结点
	Thrt->LTag= 0;//头结点有左孩子，若树非空，则其左孩子为树根
	Thrt->RTag = 1;//头结点的右孩子指针为右线索
	Thrt->rchild = Thrt;//初始化时，右指针指向自己
	if (!T)
		Thrt->lchild = Thrt;//若树为空，则左指针也指向自己
	else {
		Thrt->lchild = T; //头结点的左孩子指向根
		pre = Thrt;          //pre初始值指向头结点  pre=T 会出错 原因不详2017年1月9日20:44:48
		InThreading(T);   //对T为根的二叉树进行中序线索化
		pre->rchild = Thrt;//pre为最右结点，pre的右线索指向头结点
		pre->RTag = 1;
		Thrt->rchild = pre;//头结点的右线索指向pre
	}
}
//中序遍历二叉线索树T的非递归算法，对每个数据元素直接输出
void InOrderTraverse_Thr(BiThrTree T) {
	//T指向头结点，头结点的左链lchild指向根节点
	BiThrTree p;
	p = T->lchild;//p指向根节点
	while (p != T) {//空树或遍历结束时，p==T
		while (p->LTag==0) {//沿着左孩子向下
			p = p->lchild;//访问其左子树为空的结点
		}
		cout << p->data;
		while (p->RTag == 1 && p->rchild != T) {
			p = p->rchild;//沿着右线索访问后继结点
			cout << p->data;
		}
		p = p->rchild;
	}
}

void main2017年1月9日204455() {
	pre->RTag = 1;
	pre->rchild = NULL;
	BiThrTree tree,Thrt;
	cout << "请输入建立二叉链表的序列：\n";
	CreateBiTree(tree);//先序创建
	//InThreading(tree); //中序遍历二叉树
	//中序遍历二叉树，中序线索化
	InOrderThreading(Thrt, tree);
	cout << "线索化完毕！\n";

	system("pause");
}