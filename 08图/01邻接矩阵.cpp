#include<iostream>
#include "GraphDefine.h"
using namespace std;



//确定点v在G中的位置

//采用邻接矩阵创建无向网

int main214701() {
	cout << "*********采用邻接矩阵创建无向网*********\n";
	AMGraph G; int i, j;
	CreateUDN(G);
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			if (j != G.vexnum - 1) {   //啥意思？ 2017年1月10日20:48:20
				if (G.arcs[i][j] != MaxInt)
					cout << G.arcs[i][j] << "\t";
				else
					cout << "∞" << "\t";
			}
			else {
				if (G.arcs[i][j] != MaxInt)
					cout << G.arcs[i][j] << "\t";
				else
					cout << "∞" << "\t";
			}
		}
	}
	cout << endl;
	system("pause");
	return 0;
}