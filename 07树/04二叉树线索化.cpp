#include <iostream>
#include "TreeDefine.h"

using namespace std;

//�������Ķ����������ʹ洢��ʾ
typedef struct BiThrNode {
	char data;//���������
	struct BiThrNode *lchild, *rchild;//���Һ���ָ��
	int LTag, RTag;
}BiThrNode,*BiThrTree;

//ȫ�ֱ���pre
BiThrNode *pre = new BiThrNode;

void CreateBiTree(BiThrTree &T) {
	char ch;
	cin >> ch;
	if (ch == '#') {
		//   cout << "�ƶ���������#";
		T = NULL;
	} else {
		T = new BiThrNode;
		T->data = ch;           //���ɸ��ڵ�
		CreateBiTree(T->lchild);//�ݹ鴴��������
		CreateBiTree(T->rchild);//�ݹ鴴��������
	}
}
void InThreading(BiThrTree p) {
	//pre��ȫ�ֱ�������ʼ��ʱ�Һ���Ϊ�գ���������������߿�ʼ������
	if (p) {
		InThreading(p->lchild);//�������ݹ�������
		if (!p->lchild) {
			p->LTag = 1;//��p����������
			p->lchild = pre;//p������ָ��ָ��ǰ��pre
		} else
			p->LTag = 0;
		if (!pre->rchild) {
			pre->RTag = 1;  //��pre����������
			pre->rchild = p;//pre���Һ���ָ��ָ����p
		} else
			pre->RTag = 0;
		pre = p;//����preָ��p��ǰ��
		InThreading(p->rchild);
	}
}
//�������������T������������������Thrtָ��ͷ���
void InOrderThreading(BiThrTree &Thrt,BiThrTree T) {
	Thrt = new BiThrNode;//����ͷ���
	Thrt->LTag= 0;//ͷ��������ӣ������ǿգ���������Ϊ����
	Thrt->RTag = 1;//ͷ�����Һ���ָ��Ϊ������
	Thrt->rchild = Thrt;//��ʼ��ʱ����ָ��ָ���Լ�
	if (!T)
		Thrt->lchild = Thrt;//����Ϊ�գ�����ָ��Ҳָ���Լ�
	else {
		Thrt->lchild = T; //ͷ��������ָ���
		pre = Thrt;          //pre��ʼֵָ��ͷ���  pre=T ����� ԭ����2017��1��9��20:44:48
		InThreading(T);   //��TΪ���Ķ�������������������
		pre->rchild = Thrt;//preΪ���ҽ�㣬pre��������ָ��ͷ���
		pre->RTag = 1;
		Thrt->rchild = pre;//ͷ����������ָ��pre
	}
}
//�����������������T�ķǵݹ��㷨����ÿ������Ԫ��ֱ�����
void InOrderTraverse_Thr(BiThrTree T) {
	//Tָ��ͷ��㣬ͷ��������lchildָ����ڵ�
	BiThrTree p;
	p = T->lchild;//pָ����ڵ�
	while (p != T) {//�������������ʱ��p==T
		while (p->LTag==0) {//������������
			p = p->lchild;//������������Ϊ�յĽ��
		}
		cout << p->data;
		while (p->RTag == 1 && p->rchild != T) {
			p = p->rchild;//�������������ʺ�̽��
			cout << p->data;
		}
		p = p->rchild;
	}
}

void main2017��1��9��204455() {
	pre->RTag = 1;
	pre->rchild = NULL;
	BiThrTree tree,Thrt;
	cout << "�����뽨��������������У�\n";
	CreateBiTree(tree);//���򴴽�
	//InThreading(tree); //�������������
	//�������������������������
	InOrderThreading(Thrt, tree);
	cout << "��������ϣ�\n";

	system("pause");
}