#include<iostream>
#include "GraphDefine.h"

using namespace std;

int *D = new int[MVNum];   //��¼���·���ĳ���
bool *S = new bool[MVNum];  //��Ƕ����Ƿ����S����
int *Path = new int[MVNum];  //��¼���·�����ǰ��

void ShortestPath_DIJ(AMGraph G, int v0) {
	int v, i, w, min;
	int n = G.vexnum;  //nΪG�ж�����
    //n���������γ�ʼ��
	for (v = 0; v < n; v++) {
		S[v] = false;//S��ʼΪ��
		//��v0�������յ�����·�����ȳ�ʼ��Ϊ���ϵ�Ȩֵ
		D[v] = G.arcs[v0][v];
		//���v0��v֮���л�����v��ǰ����Ϊv0,��v��ǰ����Ϊ-1
		if (D[v] < MaxInt)
			Path[v] = v0;
		else
			Path[v] = -1;
	}
	S[v0] = true;  //��v0����S
	D[v0] = 0;     //Դ�㵽Դ��ľ���
	//��v0������v�����·������v�ӵ�S��
	for (i = 1; i < n; i++) {
		min = MaxInt;
        //ѡ��һ����ǰ�����·�����յ�Ϊv
		for (w = 0; w < n; w++) {
			if (!S[w] && D[w] < min) {
				v = w;
				min = D[w];
			}
		}
		S[v] = true; //��v����S
		//���´�v0����������V��S�����������ж�������·������
		for(w=0;w<n;w++){
			if (!S[w] && (D[v] + G.arcs[v][w] < D[w])) {
				D[w] = D[v] + G.arcs[v][w];//����D[w]
				Path[w] = v;               //����w��ǰ��Ϊv
			}
		}
	}
}
//��ʾ���·��
void DisplayPath(AMGraph G, int begin, int temp) {
	if (Path[temp] != -1) {
		DisplayPath(G, begin, Path[temp]);
		cout << G.vexs[Path[temp]] << "--->";
	}
}
void main4() {
	cout << "***�Ͻ�˹�����㷨***\n";
	AMGraph G;
	int i, j, num_start, num_destination;
	VerTexType start, destination;
	CreateUDN(G);

	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			if (j != G.vexnum - 1) {   //ɶ��˼�� 2017��1��10��20:48:20
				if (G.arcs[i][j] != MaxInt)
					cout << G.arcs[i][j] << "\t";
				else
					cout << "��" << "\t";
			} else {
				if (G.arcs[i][j] != MaxInt)
					cout << G.arcs[i][j] << "\t";
				else
					cout << "��" << "\t";
			}
		}
	}
	cout << "������������ʼ�㡢�յ����ƣ�\n";
	cin >> start >> destination;
	num_start = LocateVex(G, start);
	num_destination = LocateVex(G, destination);
	ShortestPath_DIJ(G, num_start);
	cout << "���·��Ϊ��\n";
	DisplayPath(G, num_start, num_destination);
	cout << G.vexs[num_destination] << endl;
	system("pause");
}