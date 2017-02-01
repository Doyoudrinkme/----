#include<iostream>
#define ENDFLAG '#'
using namespace std;

typedef struct {
	char key;
}ElementType;

typedef struct BSTNode {
	ElementType data;//���������
	BSTNode *lchild, *rchild;//���Һ���ָ��
}BSTNode,*BSTree;

//�����������ĵݹ���ң����ҳɹ����ظ�����Ԫ�ؽ���ָ�룬���򷵻ؿ�ָ��
BSTree SearchBST(BSTree T, char key) {
	if ((!T) || key == T->data.key)
		return T;
	else if (key < T->data.key)
		return SearchBST(T->lchild, key);
	else
		return SearchBST(T->rchild, key);
}
//�����������Ĳ���
void InsertBST(BSTree &T, ElementType e) {
	//������������T�в����ڹؼ��ֵ���e.key������Ԫ��ʱ��������Ԫ��
	if (!T) {//�ҵ�����λ�ã��ݹ����
		BSTree S = new BSTNode;//���ɽ��*S
		S->data = e;//�½��*S����������Ϊe
		S->lchild = S->rchild = NULL;//�½��*S��ΪҶ�ӽ��
		T = S;//���½��*S���ӵ����ҵ��Ĳ���λ��
	}
	else if (e.key < T->data.key)
		InsertBST(T->lchild, e);    //��*S����������
	else if (e.key > T->data.key)
		InsertBST(T->rchild, e);    //��*S����������
}
//�����������Ĵ���
void CreateBST(BSTree &T) {
	T = NULL;
	ElementType e;
	cin >> e.key;
	while (e.key != ENDFLAG) {//
		InsertBST(T, e);
		cin >> e.key;
	}
}
//�Ӷ���������T��ɾ���ؼ��ֵ���key�Ľ��
void DeleteBST(BSTree &T, char key) {
	BSTree p = T;BSTree f = NULL;
	BSTree q;    BSTree s;
	//���ҽ��
	while (p) {
		if (p->data.key == key)
			break;
		f = p;//fΪp��˫�׽��
		if (p->data.key>key)//��*p����������������
			p = p->lchild;
		else
			p = p->rchild;
	}
	if (!p)
		return;//�Ҳ�����ɾ������򷵻�
//	q = p;
	if ((p->lchild) && (p->rchild)) {//��ɾ�����*p����������������
		q = p;
		s = p->lchild;
		while (s->rchild) {//��*p���������м�������ǰ����㣬�������½��
			q = s;
			s = s->rchild;//���ҵ���ͷ
		}
		p->data = s->data;//sָ��ɾ������ǰ��
		if (q != p)
			q->rchild = s->lchild;//�ؽ�*q��������
		else
			q->lchild = s->lchild;//�ؽ�*q��������
		delete s;
	}
	else {
		if (!p->rchild) {//��ɾ���*p����������ֻ��Ҫ�ؽ���������
			q = p;
			p = p->lchild;
		}
		else if (!p->lchild) {//��ɾ�����*p����������ֻ��Ҫ�ؽ���������
			q = p;
			p = p->rchild;
		}
		//��p��ָ��������ҽӵ���˫�׽��*f��Ӧλ��
		if (!f)
			T = p;//��ɾ�����Ϊ���ڵ�
		else if (q == f->lchild)
			f->lchild = p;//�ҽӵ�*f��������λ��
		else
			f->rchild = p;//�ҽӵ�*f��������λ��
		delete q;
	}
}
//�������
void InOrderTraverse(BSTree &T) {
	if (T) {
		InOrderTraverse(T->lchild);
		cout << T->data.key;
		InOrderTraverse(T->rchild);
	}
}
void main2017��1��16��223223() {
	BSTree T;
	cout << "�����������ַ����ûس����֣���#��������\n";
	CreateBST(T);
	cout << "��ǰ����������б��������\n";
	InOrderTraverse(T);
	char key;
	cout << "��������ҵ��ַ���";
	cin >> key;
	BSTree result = SearchBST(T, key);
	if (result) {
		cout << "�ҵ��ַ� " << key << endl;
	} else
		cout << "δ�ҵ�" << key << endl;
	cout << "�������ɾ�����ַ�\n";
	cin >> key;
	DeleteBST(T, key);
	cout << "��ǰ���������������������\n";
	InOrderTraverse(T);

	system("pause");
}