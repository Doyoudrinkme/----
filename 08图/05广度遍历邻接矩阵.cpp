#include<iostream>
#include "GraphDefine.h"
#define MAXQSIZE 100
using namespace std;

bool visited5[MVNum];
//���ж���Ͳ���
typedef struct {
	ArcType *base;  //��ʼ����̬����洢�ռ�
	int font;  //Ͷָ�룬���в��գ�ָ��ͷԪ��
	int rear;  //βָ�룬���в��գ�ָ���βԪ�ص���һ��λ��
}SqQueue;

//����ն���
void InitQueue(SqQueue &Q) {
	Q.base = new ArcType[MAXQSIZE];
	if (!Q.base)
		exit(1);
	Q.font = Q.rear = 0;
}
//����Ԫ��eΪQ���µĶ�βԪ��
void EnQueue(SqQueue &Q, ArcType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.font)
		return;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
}
//�ж��Ƿ�Ϊ�ն�
bool QueueEmpty(SqQueue Q) {
	if (Q.rear == Q.font)
		return true;
	return false;
}
//��ͷԪ�س��Ӳ���Ϊu
void DeQueue(SqQueue &Q, ArcType &u) {
	u = Q.base[Q.font];
	Q.font = (Q.font + 1) % MAXQSIZE;
}
//��������� �ǵݹ������ͨͼG
void BFS(AMGraph G, int v) {
	SqQueue Q;
	ArcType u;
	ArcType w;
	//���ʵ�v�����㣬���÷��ʱ�־������Ӧ����ֵΪtrue
	cout << G.vexs[v] << " ";
	visited5[v] = true;
	//�������г�ʼ�����ÿ�
	InitQueue(Q);
	EnQueue(Q, v);
	while (!QueueEmpty(Q)) {
		DeQueue(Q, u);  //��ͷԪ�س��ӣ�����Ϊu
		for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) {
			/*���μ��u���������ӵ�w
			  FirstAdjVex(G,u)��ʾu�ĵ�һ���ڽӵ�
			  NextAdjVex(G,u,w)��ʾu�����w����һ���ڽӵ㣬
			  w��0��ʾ�����ڽӵ�
			*/
			if (!visited5[w]) {//wΪu����δ���ʵ��ڽӵ�
				cout << G.vexs[w] << " ";
				visited5[w] = true;
				EnQueue(Q, w);  //w����
			}
		}
	}
}

int main2017��1��12��211148() {
	cout << "*****�����������������ͨͼ*****\n";
	AMGraph G;
	CreateUDN(G);
	cout << "������ͨͼG������ɣ�\n";
	cout << "��������ͨͼ����㣺\n";
	VerTexType c;
	cin >> c;
	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (c == G.vexs[i])
		     break;
	}
	while (i >= G.vexnum) {
		cout << "�õ㲻���ڣ����������룡\n";
		cout << "��������ͨͼ����㣺\n";
		cin >> c;
		int i;
		for (i = 0; i < G.vexnum; i++) {
			if (c == G.vexs[i])
			break;
		}
	}
	cout << "������ȱ�����ͨͼ�Ľ����\n";
	for (i = 0; i < G.vexnum; i++) {   //���� ��ֻ�ܲ��ܱ�������Ԫ�� 2017��1��12��21:01:22
		BFS(G, i);
	}
	//BFS(G, i);
	system("pause");
	return 0;
}