#include<iostream>
#define ENDFLAG '#'
using namespace std;

typedef struct {
	char key;
}ElementType;

typedef struct BSTNode {
	ElementType data;//结点数据域
	BSTNode *lchild, *rchild;//左右孩子指针
}BSTNode,*BSTree;

//二叉排序树的递归查找，查找成功返回该数据元素结点的指针，否则返回空指针
BSTree SearchBST(BSTree T, char key) {
	if ((!T) || key == T->data.key)
		return T;
	else if (key < T->data.key)
		return SearchBST(T->lchild, key);
	else
		return SearchBST(T->rchild, key);
}
//二叉排序树的插入
void InsertBST(BSTree &T, ElementType e) {
	//当二叉排序树T中不存在关键字等于e.key的数据元素时，则插入该元素
	if (!T) {//找到插入位置，递归结束
		BSTree S = new BSTNode;//生成结点*S
		S->data = e;//新结点*S的数据域置为e
		S->lchild = S->rchild = NULL;//新结点*S作为叶子结点
		T = S;//把新结点*S链接到已找到的插入位置
	}
	else if (e.key < T->data.key)
		InsertBST(T->lchild, e);    //将*S插入左子树
	else if (e.key > T->data.key)
		InsertBST(T->rchild, e);    //将*S插入右子树
}
//二叉排序树的创建
void CreateBST(BSTree &T) {
	T = NULL;
	ElementType e;
	cin >> e.key;
	while (e.key != ENDFLAG) {//
		InsertBST(T, e);
		cin >> e.key;
	}
}
//从二叉排序树T中删除关键字等于key的结点
void DeleteBST(BSTree &T, char key) {
	BSTree p = T;BSTree f = NULL;
	BSTree q;    BSTree s;
	//查找结点
	while (p) {
		if (p->data.key == key)
			break;
		f = p;//f为p的双亲结点
		if (p->data.key>key)//在*p的左子树继续查找
			p = p->lchild;
		else
			p = p->rchild;
	}
	if (!p)
		return;//找不到被删除结点则返回
//	q = p;
	if ((p->lchild) && (p->rchild)) {//被删除结点*p的左右子树均不空
		q = p;
		s = p->lchild;
		while (s->rchild) {//在*p的左子树中继续查找前驱结点，即最右下结点
			q = s;
			s = s->rchild;//向右到尽头
		}
		p->data = s->data;//s指向被删除结点的前驱
		if (q != p)
			q->rchild = s->lchild;//重接*q的右子树
		else
			q->lchild = s->lchild;//重接*q的左子树
		delete s;
	}
	else {
		if (!p->rchild) {//被删结点*p无右子树，只需要重接其左子树
			q = p;
			p = p->lchild;
		}
		else if (!p->lchild) {//被删除结点*p无左子树，只需要重接其右子树
			q = p;
			p = p->rchild;
		}
		//将p所指向的子树挂接到其双亲结点*f相应位置
		if (!f)
			T = p;//被删除结点为根节点
		else if (q == f->lchild)
			f->lchild = p;//挂接到*f的左子树位置
		else
			f->rchild = p;//挂接到*f的右子树位置
		delete q;
	}
}
//中序遍历
void InOrderTraverse(BSTree &T) {
	if (T) {
		InOrderTraverse(T->lchild);
		cout << T->data.key;
		InOrderTraverse(T->rchild);
	}
}
void main2017年1月16日223223() {
	BSTree T;
	cout << "请输入若干字符，用回车区分，以#结束输入\n";
	CreateBST(T);
	cout << "当前有序二叉树中遍历结果：\n";
	InOrderTraverse(T);
	char key;
	cout << "输入带查找的字符：";
	cin >> key;
	BSTree result = SearchBST(T, key);
	if (result) {
		cout << "找到字符 " << key << endl;
	} else
		cout << "未找到" << key << endl;
	cout << "请输入待删除的字符\n";
	cin >> key;
	DeleteBST(T, key);
	cout << "当前有序二叉树中序遍历结果：\n";
	InOrderTraverse(T);

	system("pause");
}