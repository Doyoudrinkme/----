#include<iostream>
#include"GraphDefine.h"

using namespace std;

bool visited4[MVNum];

//������ȱ����ڽӱ�
void DFS(ALGraph G, int v) {
	cout << G.vertices[v].data << " ";
	visited4[v] = true;
	//���ʵ�v�����㣬���÷��ʱ�־������Ӧ����ֵΪtrue
	ArcNode *p = G.vertices[v].firstarc;  //pָ��v�ı�����ĵ�һ���߽��
	while (p != NULL) { //�߽��ǿ�
		int w = p->adjvex;  //��ʾw��v���ڽӵ�
		if (!visited4[w])
			DFS(G, w);      //���wδ���ʣ���ݹ����DFS
		p = p->nextarc;     //pָ����һ���߽��
	}
}
void main205804() {
	cout << "*********�ڽӱ�ͼ������ȵݹ����*****\n";
	ALGraph G;
	CreateUDG(G);
	
	cout << "�����������ͨͼ����㣺\n";
	VerTexType c;
	cin >> c;
	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (c == G.vertices[i].data)
			break;
	}
	while (i >= G.vexnum) {
		cout << "�õ㲻���ڣ����������룡\n";
		cout << "�����������ͨͼ����㣺\n";
		cin >> c;
		int i;
		for (i = 0; i < G.vexnum; i++) {
			if (c == G.vertices[i].data)
				break;
		}
	}
	cout << "���������������ͼ�����\n";
	DFS(G, i);
	system("pause");
}