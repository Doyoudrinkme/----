#include<iostream>
#include "GraphDefine.h"

using namespace std;
// �ַ�ջ����
typedef struct {
	char *base;
	char *top;
	int stacksize;
}SqStack;
//��ջ����

//�ַ�ջ��ʼ��
void InitStack(SqStack &S) {
	S.base = new char[MVNum];
	if (!S.base)
		exit(-1);
	S.top = S.base;
	S.stacksize = MVNum;
}

//�ַ�ջ��ջ
void Push(SqStack &S, int i) {
	if (S.top - S.base == S.stacksize)
		return;
	*S.top =i;
	S.top++;
}

//�ַ�ջ��ջ
void Pop(SqStack &S, int i) {
	if (S.top == S.base)
		return;
	i = *--S.top;
}

//�ַ�ջ�õ�ջ������
char GetTop(SqStack &S) {
	if (S.top == S.base)
		exit(1);
	return *(S.top - 1);
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack S) {
	if (S.top == S.base)
		return true;
	return false;
}
//������������ȴ�������
void FindInDegree(ALGraph G) {

}
//����ͼG�����ڽӱ�洢�ṹ
//��G�޻�·��������G��һ����������topo[]������OK������ERROR
int TopologicalSort(ALGraph G, int topo[]) {


}

void mainsj() {

}