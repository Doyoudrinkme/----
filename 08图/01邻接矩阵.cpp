#include<iostream>
#include "GraphDefine.h"
using namespace std;



//ȷ����v��G�е�λ��

//�����ڽӾ��󴴽�������

int main214701() {
	cout << "*********�����ڽӾ��󴴽�������*********\n";
	AMGraph G; int i, j;
	CreateUDN(G);
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			if (j != G.vexnum - 1) {   //ɶ��˼�� 2017��1��10��20:48:20
				if (G.arcs[i][j] != MaxInt)
					cout << G.arcs[i][j] << "\t";
				else
					cout << "��" << "\t";
			}
			else {
				if (G.arcs[i][j] != MaxInt)
					cout << G.arcs[i][j] << "\t";
				else
					cout << "��" << "\t";
			}
		}
	}
	cout << endl;
	system("pause");
	return 0;
}