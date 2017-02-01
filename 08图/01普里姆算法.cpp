#include<iostream>
#include "GraphDefine.h"

using namespace std;


//辅助数组，记录从顶点U到V-U的权值最小边
struct {
	VerTexType adjvex; //最小边在U中的那个顶点
	ArcType lowcost;
}closedge[MVNum];
//无向图G以邻接矩阵形式存储，从顶点u出发构造G的最小生成树T，输出T的各条边

int Min(AMGraph G) {//返回权值最小的点
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
	k = LocateVex(G, u);   //k为顶点u的下标,
	for (j = 0; j < G.vexnum; j++) {
		//对V-U的每一个顶点vi，初始化closedge
		if (j != k) {
			closedge[j].adjvex = u;
			closedge[j].lowcost = G.arcs[k][j];
		}
	}
	closedge[k].lowcost = 0;//初始化，U={u}
	for (i = 1; i < G.vexnum; i++) {
		//选择其余n-1个顶点，生成n-1条边
		k = Min(G);
		//求出T的下一个结点：第k个顶点，closedge[k]中存有当前最小边
		u0 = closedge[k].adjvex;//u0为最小边的一个顶点，u0=U
		v0 = G.vexs[k];// v0为最小边的一个顶点 v0=V-U
		cout << "边" << u0 << "-->" << v0 << endl;//输出当前的最小边
		closedge[k].lowcost = 0; //第k个顶点并入U集
		for (j = 0; j < G.vexnum; j++) {
			if (G.arcs[k][j] < closedge[j].lowcost) {
				//新顶点并入U后重新选择最小边
				closedge[j].adjvex = G.vexs[k];
				closedge[j].lowcost = G.arcs[k][j];
			}
		}
	}
}
void main2017年1月15日141218() {
	cout << "****普里姆算法****\n";
	AMGraph G;
	CreateUDN(G);
	cout << "无向图G创建完成！\n";
	cout << "****最小生成树结果：\n";
	MiniSpanTree_Prim(G, 'a');
	system("pause");
}