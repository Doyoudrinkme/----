#include<iostream>
#include "GraphDefine.h"

using namespace std;
bool visited3[MVNum];

int FirstAdjVex(AMGraph G, int v);  //����v�ĵ�һ���ڽӵ�
int NextAdjVex(AMGraph G, int v, int w);  //����v�����w����һ���ڽӵ�



//�ӵ�v����������ݹ���ȱ���ͼG
void DFS(AMGraph G, int v) {
	//���ʵ�v�����㣬���÷��ʱ�־������Ӧ������Ϊtrue
	cout << G.vexs[v] << "  ";
	visited3[v] = true;
	int w;
	//���μ��v�������ڽӵ�w
	for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
		if (!visited3[w])
			DFS(G, w);
}
//�Է���ͨͼG������ȱ���
void DFSTraverse(AMGraph G) {
	//���ʱ�־�����ʼ��
	for (int v = 0; v < G.vexnum; v++)
		visited3[v] = false;
	for (int v = 0; v < G.vexnum; v++)
		if (!visited3[v])
			DFS(G, v);
}


int main164115() {
	cout << "******��ȱ�����ͨͼ�ݹ��㷨****\n";
	AMGraph G;
	CreateUDN2(G);
	cout << "������ͨͼG������ɣ�\n\n\n";
	int i;
	cout << "�����������ͨͼ����ʼ�㣺\n\n";
	VerTexType c;
	cin >> c;
	for ( i = 0; i < G.vexnum; i++) {
		if (c == G.vexs[i])
			break;
	}
	while (i>=G.vexnum) {
		cout << "�õ㲻���ڣ����������룡\n";
		cout << "�����������ͨͼ����ʼ�㣺\n";
		cin >> c;
		for (i = 0; i < G.vexnum; i++) {
			if (c == G.vexs[i])
				break;
		}
		cout << "�����������������ͨͼ�����\n";
		DFS(G, i);
	}
	//
	DFSTraverse(G);
	system("pause");
	return 0;
}