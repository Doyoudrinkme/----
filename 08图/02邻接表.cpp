#include<iostream>
#include "GraphDefine.h"
using namespace std;

////采用邻接表创建无向图
//int CreateUDG(ALGraph &G) {
//	cout << "请输入总顶点数，总边数，中间以空格隔开：\n";
//	cin >> G.vexnum >> G.arcnum;
//	cout << endl;
//	cout << "输入点的名称，如a" << endl;
//	//输入各点，构造表头结点
//	for (int i = 0; i < G.vexnum; i++) {
//		cout << "请输入第 " << (i + 1) << " 个点的名称：";
//		cin >> G.vertices[i].data;   //输入顶点值
//		G.vertices[i].firstarc = NULL; //初始化表头结点的指针域为NULL
//	}
//	cout << endl;
//
//	cout << "请输入一条边依附的顶点，如a b" << endl;
//	for (int k = 0; k < G.arcnum; k++) {
//		cout << "请输入第 " << (k + 1) << " 条边依附的顶点：";
//		VerTexType v1, v2;
//		cin >> v1 >> v2;   //输入一条边依附的两个顶点
//		int i = LocateVex(G, v1);
//		int j = LocateVex(G, v2);
//        //生成一个新的边结点 *p1，并将新结点*p1插入顶点vi的边表头部
//		ArcNode *p1 = new ArcNode;
//		p1->adjvex = j;  //邻接点序号为j	
//		p1->nextarc = G.vertices[i].firstarc;
//		G.vertices[i].firstarc = p1;
//
//		//生成一个新的边结点 *p2，并将新结点*p1插入顶点vi的边表头部
//		ArcNode *p2 = new ArcNode;
//		p2->adjvex = i;  //邻接点序号为i	
//		p2->nextarc = G.vertices[j].firstarc;
//		G.vertices[j].firstarc = p2;
//	}
//	return OK;
//}

void main231923() {
	cout << "***********邻接表创建无向图***********\n";
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