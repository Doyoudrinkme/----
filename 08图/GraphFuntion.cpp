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
	cout << "�����ܶ��������ܱ������Կո������\n";
	cin >> G.vexnum >> G.arcnum;
	cout << endl;
	cout << "���������ƣ���a" << endl;
	for (i = 0; i < G.vexnum; i++) {
		cout << "������� " << (i + 1) << " ��������ƣ�\n";
		cin >> G.vexs[i];
	}
	cout << endl;
	//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ��Ϊ����
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}
	cout << "����������Ķ��㼰Ȩֵ���� a b 5" << endl;
	//�����ڽӾ���
	for (k = 0; k < G.arcnum; k++) {
		VerTexType v1, v2;
		ArcType w;
		cout << "�������" << (k + 1) << "�������Ķ��㼰Ȩֵ��";
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = w;
		G.arcs[j][i] = G.arcs[i][j];//��<v1,v2>�ĶԳƱ�<v2,v1>��ȨֵΪw
	}
	cout << "*****������G�������******\n";
	return OK;
}
//Ѱ��v�ĵ�һ���ڽӵ�
int FirstAdjVex(AMGraph G, int v) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.arcs[v][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}
//v�����w����һ���ڽӵ㣬w��0 ��ʾ�����ڽӵ�
int NextAdjVex(AMGraph G, int v, int w) {
	for (int i = w; i < G.vexnum; i++) {
		if (G.arcs[v][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}





//�����ڽӱ�������ͼ
int CreateUDG(ALGraph &G) {
	cout << "�������ܶ��������ܱ������м��Կո������\n";
	cin >> G.vexnum >> G.arcnum;
	cout << endl;
	cout << "���������ƣ���a" << endl;
	//������㣬�����ͷ���
	for (int i = 0; i < G.vexnum; i++) {
		cout << "������� " << (i + 1) << " ��������ƣ�";
		cin >> G.vertices[i].data;   //���붥��ֵ
		G.vertices[i].firstarc = NULL; //��ʼ����ͷ����ָ����ΪNULL
	}
	cout << endl;

	cout << "������һ���������Ķ��㣬��a b" << endl;
	for (int k = 0; k < G.arcnum; k++) {
		cout << "������� " << (k + 1) << " ���������Ķ��㣺";
		VerTexType v1, v2;
		cin >> v1 >> v2;   //����һ������������������
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		//����һ���µı߽�� *p1�������½��*p1���붥��vi�ı߱�ͷ��
		ArcNode *p1 = new ArcNode;
		p1->adjvex = j;  //�ڽӵ����Ϊj	
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;

		//����һ���µı߽�� *p2�������½��*p1���붥��vi�ı߱�ͷ��
		ArcNode *p2 = new ArcNode;
		p2->adjvex = i;  //�ڽӵ����Ϊi	
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2;
	}
	cout << "������ͨͼG������ɣ�\n";
	return OK;
}

void CreateUDN2(AMGraph &G) {
	int i, j, k;
	cout << "�����ܶ��������ܱ������Կո������\n";
	cin >> G.vexnum >> G.arcnum;
	cout << endl;
	cout << "���������ƣ���a" << endl;
	for (i = 0; i < G.vexnum; i++) {
		cout << "������� " << (i + 1) << " ��������ƣ�\n";
		cin >> G.vexs[i];
	}
	cout << endl;
	//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ��Ϊ0
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = 0;
		}
	}
	cout << "����������Ķ��㼰Ȩֵ���� a b 5" << endl;
	//�����ڽӾ���
	for (k = 0; k < G.arcnum; k++) {
		VerTexType v1, v2;
		cout << "�������" << (k + 1) << "�������Ķ��㼰Ȩֵ��";
		cin >> v1 >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[j][i] = G.arcs[i][j] = 1;//��<v1,v2>�ĶԳƱ�<v2,v1>��ȨֵΪw
	}
	cout << "*****������G�������******\n";
}
