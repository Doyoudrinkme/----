#include<iostream>
#include"GraphDefine.h"

using namespace std;

bool visited4[MVNum];

//深度优先遍历邻接表
void DFS(ALGraph G, int v) {
	cout << G.vertices[v].data << " ";
	visited4[v] = true;
	//访问第v个顶点，并置访问标志数组相应分量值为true
	ArcNode *p = G.vertices[v].firstarc;  //p指向v的边链表的第一个边结点
	while (p != NULL) { //边结点非空
		int w = p->adjvex;  //表示w是v的邻接点
		if (!visited4[w])
			DFS(G, w);      //如果w未访问，则递归调用DFS
		p = p->nextarc;     //p指向下一个边结点
	}
}
void main205804() {
	cout << "*********邻接表图深度优先递归遍历*****\n";
	ALGraph G;
	CreateUDG(G);
	
	cout << "请输入遍历连通图的起点：\n";
	VerTexType c;
	cin >> c;
	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (c == G.vertices[i].data)
			break;
	}
	while (i >= G.vexnum) {
		cout << "该点不存在，请重新输入！\n";
		cout << "请输入遍历连通图的起点：\n";
		cin >> c;
		int i;
		for (i = 0; i < G.vexnum; i++) {
			if (c == G.vertices[i].data)
				break;
		}
	}
	cout << "深度优先搜索遍历图结果：\n";
	DFS(G, i);
	system("pause");
}