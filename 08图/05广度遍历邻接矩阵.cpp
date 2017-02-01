#include<iostream>
#include "GraphDefine.h"
#define MAXQSIZE 100
using namespace std;

bool visited5[MVNum];
//队列定义和操作
typedef struct {
	ArcType *base;  //初始化动态分配存储空间
	int font;  //投指针，队列不空，指向头元素
	int rear;  //尾指针，队列不空，指向队尾元素的下一个位置
}SqQueue;

//构造空队列
void InitQueue(SqQueue &Q) {
	Q.base = new ArcType[MAXQSIZE];
	if (!Q.base)
		exit(1);
	Q.font = Q.rear = 0;
}
//插入元素e为Q的新的队尾元素
void EnQueue(SqQueue &Q, ArcType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.font)
		return;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
}
//判断是否为空队
bool QueueEmpty(SqQueue Q) {
	if (Q.rear == Q.font)
		return true;
	return false;
}
//队头元素出队并置为u
void DeQueue(SqQueue &Q, ArcType &u) {
	u = Q.base[Q.font];
	Q.font = (Q.font + 1) % MAXQSIZE;
}
//按广度优先 非递归遍历连通图G
void BFS(AMGraph G, int v) {
	SqQueue Q;
	ArcType u;
	ArcType w;
	//访问第v个顶点，并置访问标志数组相应分量值为true
	cout << G.vexs[v] << " ";
	visited5[v] = true;
	//辅助队列初始化，置空
	InitQueue(Q);
	EnQueue(Q, v);
	while (!QueueEmpty(Q)) {
		DeQueue(Q, u);  //队头元素出队，并置为u
		for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) {
			/*依次检查u的所有连接点w
			  FirstAdjVex(G,u)表示u的第一个邻接点
			  NextAdjVex(G,u,w)表示u相对于w的下一个邻接点，
			  w≥0表示存在邻接点
			*/
			if (!visited5[w]) {//w为u的尚未访问的邻接点
				cout << G.vexs[w] << " ";
				visited5[w] = true;
				EnQueue(Q, w);  //w进队
			}
		}
	}
}

int main2017年1月12日211148() {
	cout << "*****广度优先搜索遍历连通图*****\n";
	AMGraph G;
	CreateUDN(G);
	cout << "无向连通图G创建完成！\n";
	cout << "请输入连通图的起点：\n";
	VerTexType c;
	cin >> c;
	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (c == G.vexs[i])
		     break;
	}
	while (i >= G.vexnum) {
		cout << "该点不存在，请重新输入！\n";
		cout << "请输入连通图的起点：\n";
		cin >> c;
		int i;
		for (i = 0; i < G.vexnum; i++) {
			if (c == G.vexs[i])
			break;
		}
	}
	cout << "广度优先遍历连通图的结果：\n";
	for (i = 0; i < G.vexnum; i++) {   //问题 ：只能不能遍历所有元素 2017年1月12日21:01:22
		BFS(G, i);
	}
	//BFS(G, i);
	system("pause");
	return 0;
}