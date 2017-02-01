#include<iostream>
#include "GraphDefine.h"

using namespace std;
// 字符栈定义
typedef struct {
	char *base;
	char *top;
	int stacksize;
}SqStack;
//树栈定义

//字符栈初始化
void InitStack(SqStack &S) {
	S.base = new char[MVNum];
	if (!S.base)
		exit(-1);
	S.top = S.base;
	S.stacksize = MVNum;
}

//字符栈入栈
void Push(SqStack &S, int i) {
	if (S.top - S.base == S.stacksize)
		return;
	*S.top =i;
	S.top++;
}

//字符栈出栈
void Pop(SqStack &S, int i) {
	if (S.top == S.base)
		return;
	i = *--S.top;
}

//字符栈得到栈顶函数
char GetTop(SqStack &S) {
	if (S.top == S.base)
		exit(1);
	return *(S.top - 1);
}
//判断栈是否为空
bool StackEmpty(SqStack S) {
	if (S.top == S.base)
		return true;
	return false;
}
//求出各顶点的入度存入数组
void FindInDegree(ALGraph G) {

}
//有向图G采用邻接表存储结构
//若G无回路，则生成G的一个拓扑序列topo[]并返回OK，否则ERROR
int TopologicalSort(ALGraph G, int topo[]) {


}

void mainsj() {

}