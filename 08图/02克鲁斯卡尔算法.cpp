#include<iostream>
#include "GraphDefine.h"
using namespace std;
//辅助数组
struct {
	VerTexType Head;  //边的起始点
	VerTexType Tail;  //边的终点
	ArcType lowcost;  //边上的权值
}Edge[(MVNum*(MVNum-1))/2];

int Vexset[MVNum];
void CreateUDN3(AMGraph &G) {
	int i, j, k;
	cout << "输入总顶点数，总边数，以空格隔开：\n";
	cin >> G.vexnum >> G.arcnum;
	cout << endl;
	cout << "输入点的名称，如a" << endl;
	for (i = 0; i < G.vexnum; i++) {
		cout << "请输入第 " << (i + 1) << " 个点的名称：\n";
		cin >> G.vexs[i];
	}
	cout << endl;
	//初始化邻接矩阵，边的权值置为极大
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}
	cout << "输入边依附的顶点及权值，如 a b 5" << endl;
	//构造邻接矩阵
	for (k = 0; k < G.arcnum; k++) {
		VerTexType v1, v2;
		ArcType w;
		cout << "请输入第" << (k + 1) << "条依附的顶点及权值：";
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = w;
		G.arcs[j][i] = G.arcs[i][j];//置<v1,v2>的对称边<v2,v1>的权值为w

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
//无向图G以邻接矩阵存储，构造G最小生成树T，输出T的各条边
void MiniSpanTree_Kruskal(AMGraph G) {
	int i, j, v1, v2, vs1, vs2;
	Sort(G);//将数组Edge中的元素按权值从小到大排序
	//辅助数组，表示各顶点自成一个连通分量
	for (i = 0; i < G.vexnum; i++)
		Vexset[i] = i;
	//依次查看排好序的数组Edge中的边是否在同一连通分量上
	for (i = 0; i < G.arcnum; i++) {
		v1 = LocateVex(G, Edge[i].Head);//v1为边的起始点Head的下标
		v2 = LocateVex(G, Edge[i].Tail);//v2为边的终点Tail的下标
		vs1 = Vexset[v1];//获取边Edge[i]的开始点所在的连通分量vs1
		vs2 = Vexset[v2];//获取边Edge[i]的终点所在的联通分量vs2
		if (vs1 != vs2) {
			cout << Edge[i].Head << "--->" << Edge[i].Tail << endl;
			for (j = 0; j < G.vexnum; j++) {
				//合并vs1和vs2两个分量，即两个集合统一编号
				if (Vexset[j] == vs2)
					Vexset[j] = vs1;
			}
		}
	}
}

void main2017年1月13日162546() {
	cout << "****克鲁斯卡尔*****\n\n";
	AMGraph G;
	CreateUDN3(G);
	cout << "无向网G创建完成！\n";
	MiniSpanTree_Kruskal(G);
	system("pause");
}