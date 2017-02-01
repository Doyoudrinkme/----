#include<iostream>
#include "GraphDefine.h"

using namespace std;


int fPath[MVNum][MVNum];//最短路径上顶点vj的前一顶点的序号
int fD[MVNum][MVNum];//记录顶点vi和vj之间的最短路径


//Floyd算法求有向图G中各对顶点i和j之间的最短路径
void ShortestPath_Floyed(AMGraph G) {
	int i, j, k;
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			fD[i][j] = G.arcs[i][j];
			if (fD[i][j] < MaxInt&&i != j)
				fPath[i][j] = i; //如果i和j之间无弧，则将j的前驱置为i
			else
				fPath[i][j] = -1;//如果i和j之间有弧，则将j的前驱置为-1
		}
	}
	for (k = 0; k < G.vexnum; k++) {
       for (i = 0; i < G.vexnum; i++) {
		   for (j = 0; j < G.vexnum; j++) {
			   if (fD[i][k] + fD[k][j] < fD[k][j]) {//从j经k到j的一条路径更短
				   fD[i][j] = fD[i][k] + fD[k][j];//更新D[i][j]
				   fPath[i][j] = fPath[k][j];//更改j的前驱为k
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

void main2017年1月15日155114() {
	cout << "****弗洛伊德算法***\n";
	AMGraph G;
	char start, destination;
	int num_start, num_destination;
	CreateUDN(G);
	ShortestPath_Floyed(G);
	cout << "请依次输入路径的起点和终点名称：";

	cin >> start >> destination;
	num_start = LocateVex(G, start);
	num_destination = LocateVex(G, destination);

	fDisplayPath(G, num_start, num_destination);
	cout << G.vexs[num_destination] << endl;
	cout << "最短路径的长度为：" << fD[num_start][num_destination] << endl;

	system("pause");
}