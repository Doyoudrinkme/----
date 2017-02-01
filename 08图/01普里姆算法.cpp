#include<iostream>
#include "GraphDefine.h"

using namespace std;


//�������飬��¼�Ӷ���U��V-U��Ȩֵ��С��
struct {
	VerTexType adjvex; //��С����U�е��Ǹ�����
	ArcType lowcost;
}closedge[MVNum];
//����ͼG���ڽӾ�����ʽ�洢���Ӷ���u��������G����С������T�����T�ĸ�����

int Min(AMGraph G) {//����Ȩֵ��С�ĵ�
	int index = -1;
	int min = MaxInt;
	for (int i = 0; i < G.vexnum; i++) {
		if (min > closedge[i].lowcost&&closedge[i].lowcost != 0) {
			min = closedge[i].lowcost;
			index = i;
		}
	}
	return index;
}
void MiniSpanTree_Prim(AMGraph G, VerTexType u) {
	int k, i, j;
	VerTexType u0, v0;
	k = LocateVex(G, u);   //kΪ����u���±�,
	for (j = 0; j < G.vexnum; j++) {
		//��V-U��ÿһ������vi����ʼ��closedge
		if (j != k) {
			closedge[j].adjvex = u;
			closedge[j].lowcost = G.arcs[k][j];
		}
	}
	closedge[k].lowcost = 0;//��ʼ����U={u}
	for (i = 1; i < G.vexnum; i++) {
		//ѡ������n-1�����㣬����n-1����
		k = Min(G);
		//���T����һ����㣺��k�����㣬closedge[k]�д��е�ǰ��С��
		u0 = closedge[k].adjvex;//u0Ϊ��С�ߵ�һ�����㣬u0=U
		v0 = G.vexs[k];// v0Ϊ��С�ߵ�һ������ v0=V-U
		cout << "��" << u0 << "-->" << v0 << endl;//�����ǰ����С��
		closedge[k].lowcost = 0; //��k�����㲢��U��
		for (j = 0; j < G.vexnum; j++) {
			if (G.arcs[k][j] < closedge[j].lowcost) {
				//�¶��㲢��U������ѡ����С��
				closedge[j].adjvex = G.vexs[k];
				closedge[j].lowcost = G.arcs[k][j];
			}
		}
	}
}
void main2017��1��15��141218() {
	cout << "****����ķ�㷨****\n";
	AMGraph G;
	CreateUDN(G);
	cout << "����ͼG������ɣ�\n";
	cout << "****��С�����������\n";
	MiniSpanTree_Prim(G, 'a');
	system("pause");
}