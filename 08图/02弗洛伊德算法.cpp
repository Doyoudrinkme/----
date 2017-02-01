#include<iostream>
#include "GraphDefine.h"

using namespace std;


int fPath[MVNum][MVNum];//���·���϶���vj��ǰһ��������
int fD[MVNum][MVNum];//��¼����vi��vj֮������·��


//Floyd�㷨������ͼG�и��Զ���i��j֮������·��
void ShortestPath_Floyed(AMGraph G) {
	int i, j, k;
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			fD[i][j] = G.arcs[i][j];
			if (fD[i][j] < MaxInt&&i != j)
				fPath[i][j] = i; //���i��j֮���޻�����j��ǰ����Ϊi
			else
				fPath[i][j] = -1;//���i��j֮���л�����j��ǰ����Ϊ-1
		}
	}
	for (k = 0; k < G.vexnum; k++) {
       for (i = 0; i < G.vexnum; i++) {
		   for (j = 0; j < G.vexnum; j++) {
			   if (fD[i][k] + fD[k][j] < fD[k][j]) {//��j��k��j��һ��·������
				   fD[i][j] = fD[i][k] + fD[k][j];//����D[i][j]
				   fPath[i][j] = fPath[k][j];//����j��ǰ��Ϊk
			   }
		   }
		}
	}
}

void fDisplayPath(AMGraph G, int begin, int temp) {
	if (fPath[begin][temp] != -1) {
		fDisplayPath(G, begin, fPath[begin][temp]);
		cout << G.vexs[fPath[begin][temp]] << "--->";
	}
}

void main2017��1��15��155114() {
	cout << "****���������㷨***\n";
	AMGraph G;
	char start, destination;
	int num_start, num_destination;
	CreateUDN(G);
	ShortestPath_Floyed(G);
	cout << "����������·���������յ����ƣ�";

	cin >> start >> destination;
	num_start = LocateVex(G, start);
	num_destination = LocateVex(G, destination);

	fDisplayPath(G, num_start, num_destination);
	cout << G.vexs[num_destination] << endl;
	cout << "���·���ĳ���Ϊ��" << fD[num_start][num_destination] << endl;

	system("pause");
}