#include<iostream>
#include "GraphDefine.h"
using namespace std;

////�����ڽӱ�������ͼ
//int CreateUDG(ALGraph &G) {
//	cout << "�������ܶ��������ܱ������м��Կո������\n";
//	cin >> G.vexnum >> G.arcnum;
//	cout << endl;
//	cout << "���������ƣ���a" << endl;
//	//������㣬�����ͷ���
//	for (int i = 0; i < G.vexnum; i++) {
//		cout << "������� " << (i + 1) << " ��������ƣ�";
//		cin >> G.vertices[i].data;   //���붥��ֵ
//		G.vertices[i].firstarc = NULL; //��ʼ����ͷ����ָ����ΪNULL
//	}
//	cout << endl;
//
//	cout << "������һ���������Ķ��㣬��a b" << endl;
//	for (int k = 0; k < G.arcnum; k++) {
//		cout << "������� " << (k + 1) << " ���������Ķ��㣺";
//		VerTexType v1, v2;
//		cin >> v1 >> v2;   //����һ������������������
//		int i = LocateVex(G, v1);
//		int j = LocateVex(G, v2);
//        //����һ���µı߽�� *p1�������½��*p1���붥��vi�ı߱�ͷ��
//		ArcNode *p1 = new ArcNode;
//		p1->adjvex = j;  //�ڽӵ����Ϊj	
//		p1->nextarc = G.vertices[i].firstarc;
//		G.vertices[i].firstarc = p1;
//
//		//����һ���µı߽�� *p2�������½��*p1���붥��vi�ı߱�ͷ��
//		ArcNode *p2 = new ArcNode;
//		p2->adjvex = i;  //�ڽӵ����Ϊi	
//		p2->nextarc = G.vertices[j].firstarc;
//		G.vertices[j].firstarc = p2;
//	}
//	return OK;
//}

void main231923() {
	cout << "***********�ڽӱ�������ͼ***********\n";
	ALGraph G;
	CreateUDG(G);
	for (int i = 0; i < G.vexnum; i++) {
		VNode temp = G.vertices[i];
		ArcNode *p = temp.firstarc;
		if (p == NULL) {
			cout << G.vertices[i].data;
			cout << endl;
		}
		else {
			cout << temp.data;
			while (p) {
				cout << "->";
				cout << p->adjvex;
				p = p->nextarc;
			}
		}
		cout << endl;
	}
	system("pause");
}