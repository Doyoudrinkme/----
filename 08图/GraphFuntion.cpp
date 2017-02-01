#include<iostream>
#include"GraphDefine.h"
using namespace std;

bool visited[MVNum];
int LocateVex(AMGraph G, VerTexType v) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == v)
			return i;
	}
	return -1;
}
int LocateVex(ALGraph G, VerTexType v) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vertices[i].data == v)
			return i;
	}
	return -1;
}

int CreateUDN(AMGraph &G) {
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
	}
	cout << "*****无向网G创建完成******\n";
	return OK;
}
//寻找v的第一个邻接点
int FirstAdjVex(AMGraph G, int v) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.arcs[v][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}
//v相对于w的下一个邻接点，w≥0 表示存在邻接点
int NextAdjVex(AMGraph G, int v, int w) {
	for (int i = w; i < G.vexnum; i++) {
		if (G.arcs[v][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}





//采用邻接表创建无向图
int CreateUDG(ALGraph &G) {
	cout << "请输入总顶点数，总边数，中间以空格隔开：\n";
	cin >> G.vexnum >> G.arcnum;
	cout << endl;
	cout << "输入点的名称，如a" << endl;
	//输入各点，构造表头结点
	for (int i = 0; i < G.vexnum; i++) {
		cout << "请输入第 " << (i + 1) << " 个点的名称：";
		cin >> G.vertices[i].data;   //输入顶点值
		G.vertices[i].firstarc = NULL; //初始化表头结点的指针域为NULL
	}
	cout << endl;

	cout << "请输入一条边依附的顶点，如a b" << endl;
	for (int k = 0; k < G.arcnum; k++) {
		cout << "请输入第 " << (k + 1) << " 条边依附的顶点：";
		VerTexType v1, v2;
		cin >> v1 >> v2;   //输入一条边依附的两个顶点
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		//生成一个新的边结点 *p1，并将新结点*p1插入顶点vi的边表头部
		ArcNode *p1 = new ArcNode;
		p1->adjvex = j;  //邻接点序号为j	
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;

		//生成一个新的边结点 *p2，并将新结点*p1插入顶点vi的边表头部
		ArcNode *p2 = new ArcNode;
		p2->adjvex = i;  //邻接点序号为i	
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2;
	}
	cout << "无向连通图G创建完成！\n";
	return OK;
}

void CreateUDN2(AMGraph &G) {
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
	//初始化邻接矩阵，边的权值置为0
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = 0;
		}
	}
	cout << "输入边依附的顶点及权值，如 a b 5" << endl;
	//构造邻接矩阵
	for (k = 0; k < G.arcnum; k++) {
		VerTexType v1, v2;
		cout << "请输入第" << (k + 1) << "条依附的顶点及权值：";
		cin >> v1 >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[j][i] = G.arcs[i][j] = 1;//置<v1,v2>的对称边<v2,v1>的权值为w
	}
	cout << "*****无向网G创建完成******\n";
}
