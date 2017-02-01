#include<iostream>
#include "GraphDefine.h"

using namespace std;

int *D = new int[MVNum];   //记录最短路径的长度
bool *S = new bool[MVNum];  //标记顶点是否进入S集合
int *Path = new int[MVNum];  //记录最短路顶点的前驱

void ShortestPath_DIJ(AMGraph G, int v0) {
	int v, i, w, min;
	int n = G.vexnum;  //n为G中顶点数
    //n个顶点依次初始化
	for (v = 0; v < n; v++) {
		S[v] = false;//S初始为空
		//将v0到各个终点的最短路径长度初始化为弧上的权值
		D[v] = G.arcs[v0][v];
		//如果v0和v之间有弧，则将v的前驱置为v0,则将v的前驱置为-1
		if (D[v] < MaxInt)
			Path[v] = v0;
		else
			Path[v] = -1;
	}
	S[v0] = true;  //将v0加入S
	D[v0] = 0;     //源点到源点的距离
	//求v0到顶点v的最短路径，将v加到S集
	for (i = 1; i < n; i++) {
		min = MaxInt;
        //选择一条当前的最短路径，终点为v
		for (w = 0; w < n; w++) {
			if (!S[w] && D[w] < min) {
				v = w;
				min = D[w];
			}
		}
		S[v] = true; //将v加入S
		//更新从v0出发到集合V？S上所有上所有顶点的最短路径长度
		for(w=0;w<n;w++){
			if (!S[w] && (D[v] + G.arcs[v][w] < D[w])) {
				D[w] = D[v] + G.arcs[v][w];//更新D[w]
				Path[w] = v;               //更改w的前驱为v
			}
		}
	}
}
//显示最短路径
void DisplayPath(AMGraph G, int begin, int temp) {
	if (Path[temp] != -1) {
		DisplayPath(G, begin, Path[temp]);
		cout << G.vexs[Path[temp]] << "--->";
	}
}
void main4() {
	cout << "***迪杰斯特拉算法***\n";
	AMGraph G;
	int i, j, num_start, num_destination;
	VerTexType start, destination;
	CreateUDN(G);

	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			if (j != G.vexnum - 1) {   //啥意思？ 2017年1月10日20:48:20
				if (G.arcs[i][j] != MaxInt)
					cout << G.arcs[i][j] << "\t";
				else
					cout << "∞" << "\t";
			} else {
				if (G.arcs[i][j] != MaxInt)
					cout << G.arcs[i][j] << "\t";
				else
					cout << "∞" << "\t";
			}
		}
	}
	cout << "请依次输入起始点、终点名称：\n";
	cin >> start >> destination;
	num_start = LocateVex(G, start);
	num_destination = LocateVex(G, destination);
	ShortestPath_DIJ(G, num_start);
	cout << "最短路径为：\n";
	DisplayPath(G, num_start, num_destination);
	cout << G.vexs[num_destination] << endl;
	system("pause");
}