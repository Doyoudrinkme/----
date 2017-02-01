#include<iostream>
#include "GraphDefine.h"

using namespace std;
bool visited3[MVNum];

int FirstAdjVex(AMGraph G, int v);  //返回v的第一个邻接点
int NextAdjVex(AMGraph G, int v, int w);  //返回v相对于w的下一个邻接点



//从第v个顶点出发递归深度遍历图G
void DFS(AMGraph G, int v) {
	//访问第v个顶点，并置访问标志数组相应分量置为true
	cout << G.vexs[v] << "  ";
	visited3[v] = true;
	int w;
	//依次检查v的所有邻接点w
	for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
		if (!visited3[w])
			DFS(G, w);
}
//对非联通图G深度优先遍历
void DFSTraverse(AMGraph G) {
	//访问标志数组初始化
	for (int v = 0; v < G.vexnum; v++)
		visited3[v] = false;
	for (int v = 0; v < G.vexnum; v++)
		if (!visited3[v])
			DFS(G, v);
}


int main164115() {
	cout << "******深度遍历连通图递归算法****\n";
	AMGraph G;
	CreateUDN2(G);
	cout << "无向连通图G创建完成！\n\n\n";
	int i;
	cout << "请输入遍历连通图的起始点：\n\n";
	VerTexType c;
	cin >> c;
	for ( i = 0; i < G.vexnum; i++) {
		if (c == G.vexs[i])
			break;
	}
	while (i>=G.vexnum) {
		cout << "该点不存在，请重新输入！\n";
		cout << "请输入遍历联通图的起始点：\n";
		cin >> c;
		for (i = 0; i < G.vexnum; i++) {
			if (c == G.vexs[i])
				break;
		}
		cout << "深度优先搜索遍历连通图结果：\n";
		DFS(G, i);
	}
	//
	DFSTraverse(G);
	system("pause");
	return 0;
}