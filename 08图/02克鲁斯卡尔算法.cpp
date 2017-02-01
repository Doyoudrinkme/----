#include<iostream>
#include "GraphDefine.h"
using namespace std;
//��������
struct {
	VerTexType Head;  //�ߵ���ʼ��
	VerTexType Tail;  //�ߵ��յ�
	ArcType lowcost;  //���ϵ�Ȩֵ
}Edge[(MVNum*(MVNum-1))/2];

int Vexset[MVNum];
void CreateUDN3(AMGraph &G) {
	int i, j, k;
	cout << "�����ܶ��������ܱ������Կո������\n";
	cin >> G.vexnum >> G.arcnum;
	cout << endl;
	cout << "���������ƣ���a" << endl;
	for (i = 0; i < G.vexnum; i++) {
		cout << "������� " << (i + 1) << " ��������ƣ�\n";
		cin >> G.vexs[i];
	}
	cout << endl;
	//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ��Ϊ����
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}
	cout << "����������Ķ��㼰Ȩֵ���� a b 5" << endl;
	//�����ڽӾ���
	for (k = 0; k < G.arcnum; k++) {
		VerTexType v1, v2;
		ArcType w;
		cout << "�������" << (k + 1) << "�������Ķ��㼰Ȩֵ��";
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = w;
		G.arcs[j][i] = G.arcs[i][j];//��<v1,v2>�ĶԳƱ�<v2,v1>��ȨֵΪw

		Edge[k].lowcost = w;
		Edge[k].Head = v1;
		Edge[k].Tail = v2;
	}
}
void Sort(AMGraph G) {
	int m = G.arcnum - 2;
	int flag = 1;
	while ((m > 0) && flag == 1) {
		flag = 0;
		for (int j = 0; j <= m; j++) {
			if (Edge[j].lowcost > Edge[j + 1].lowcost) {
				flag = 1;

				VerTexType temp_Head = Edge[j].Head;
				Edge[j].Head = Edge[j + 1].Head;
				Edge[j + 1].Head = temp_Head;

				VerTexType temp_Tail = Edge[j].Tail;
				Edge[j].Tail = Edge[j + 1].Tail;
				Edge[j + 1].Tail = temp_Tail;

				ArcType temp_lowcost = Edge[j].lowcost;
				Edge[j].lowcost = Edge[j + 1].lowcost;
				Edge[j + 1].lowcost = temp_lowcost;
			}
		}
		--m;
	}
}
//����ͼG���ڽӾ���洢������G��С������T�����T�ĸ�����
void MiniSpanTree_Kruskal(AMGraph G) {
	int i, j, v1, v2, vs1, vs2;
	Sort(G);//������Edge�е�Ԫ�ذ�Ȩֵ��С��������
	//�������飬��ʾ�������Գ�һ����ͨ����
	for (i = 0; i < G.vexnum; i++)
		Vexset[i] = i;
	//���β鿴�ź��������Edge�еı��Ƿ���ͬһ��ͨ������
	for (i = 0; i < G.arcnum; i++) {
		v1 = LocateVex(G, Edge[i].Head);//v1Ϊ�ߵ���ʼ��Head���±�
		v2 = LocateVex(G, Edge[i].Tail);//v2Ϊ�ߵ��յ�Tail���±�
		vs1 = Vexset[v1];//��ȡ��Edge[i]�Ŀ�ʼ�����ڵ���ͨ����vs1
		vs2 = Vexset[v2];//��ȡ��Edge[i]���յ����ڵ���ͨ����vs2
		if (vs1 != vs2) {
			cout << Edge[i].Head << "--->" << Edge[i].Tail << endl;
			for (j = 0; j < G.vexnum; j++) {
				//�ϲ�vs1��vs2��������������������ͳһ���
				if (Vexset[j] == vs2)
					Vexset[j] = vs1;
			}
		}
	}
}

void main2017��1��13��162546() {
	cout << "****��³˹����*****\n\n";
	AMGraph G;
	CreateUDN3(G);
	cout << "������G������ɣ�\n";
	MiniSpanTree_Kruskal(G);
	system("pause");
}