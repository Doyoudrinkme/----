#include<iostream>
#include<string>
#define EEROR -1
#define MAXSIZE 100
#include "TreeDefine.h"
using namespace std;

//�ַ�ջ����
typedef struct {
	char *base;
	char *top;
	int stacksize;
}SqStack;
//��ջ����
typedef struct {
	BiTree *base;
	BiTree *top;
	int stacksize;
}BiTreeStack;

//�ַ�ջ��ʼ��
void InitStack(SqStack &S) {
	S.base = new char[MAXSIZE];
	if (!S.base)
		exit(-1);
	S.top = S.base;
	S.stacksize = MAXSIZE;
}
//��ջ��ʼ��
void InitBiTreeStack(BiTreeStack &S) {
	S.base = new BiTree[MAXSIZE];
	if (!S.base)
		exit(-1);
	S.top = S.base;
	S.stacksize = MAXSIZE;
}
//�ַ�ջ��ջ
void Push(SqStack &S, char e) {
	if (S.top - S.base == S.stacksize)
		return;
	*S.top = e;
	S.top++;
}
//��ջ��ջ
void PushBiTree(BiTreeStack &S, BiTree e) {
	if (S.top - S.base == S.stacksize)
		return;
	*S.top = e;
	S.top++;
}
//�ַ�ջ��ջ
void Pop(SqStack &S, char e) {
	if (S.top == S.base)
		return;
	e = *--S.top;
}
//��ջ��ջ
void PopBiTree(BiTreeStack &S, BiTree &e) {
	if (S.top == S.base)
		return;
	e = *--S.top;
}
//�ַ�ջ�õ�ջ������
char GetTop(SqStack &S) {
	if (S.top == S.base)
		exit(1);
	return *(S.top - 1);
}
//�жϷ������ȼ�
char Precede(char t1, char t2) {
	char f;
	switch (t2) {
		case '+':
			if (t1 == '(' || t1 == '#')
				f = '<';
			else f = '>';
			break;
		case '-':
			if (t1 == '(' || t1 == '#')
				f = '<';
			else f = '>';
			break;
		case '*':
		//if (t1== '*' || t1 == '/' || t1 = ')')
		    if (t1 == '*' || t1 == '/' || t1 == ')')
				f = '>';
			else f = '<';
			break;
		case '/':
			if (t1 == '*' || t1 == '/' || t1 == ')')
				f = '>';
			else
				f = '<';
			break;
	
		case '(':
			if (t1 != ')')
				f = '<';
			break;
		case ')':
			if (t1 == '(') 
				f = '=';
			else
				f = '>';
			break;
		case '#':
			if (t1 == '(')
				f = '=';
			else
				f = '>';
			break;
	}
	return f;
}
//�ж�c�Ƿ��������
int In(char c) {
	switch (c) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '#':
		case '(':
		case ')':return 1; break;
		default:
			return 0;
	}
}
//���㺯��
int GetValue(char theta, int a, int b) {
	int c;
	switch (theta) {
		case '+':c = a + b; break;
		case '-':c = a -b; break;
		case '^':c = a * b; break;
		case '/':c = a / b; break;
		default:
			break;
	}
	return c;
}
//�����򵥶�����
void CreateExpTree(BiTree &T,BiTree a, BiTree b, char ch) {
	T = new BiTNode;
	T->data = ch;
	T->lchild = a;
	T->rchild = b;
}
//�������ʽ��
void InitExpTree(BiTree &T) {
    SqStack OPTR;
	BiTreeStack EXPT;
	char ch, theta, x;
	BiTree a, b;
	InitStack(OPTR);
	Push(OPTR, '#');
	InitBiTreeStack(EXPT);
	cin >> ch;
	while (ch!='#'||GetTop(OPTR)!='#') {
		if (!In(ch)) {
			CreateExpTree(T, NULL, NULL, ch);
			PushBiTree(EXPT, T);
			cin >> ch;
		}
		else {
			switch (Precede(GetTop(OPTR),ch)) {
				case '<':
					Push(OPTR, ch);
					cin >> ch;
					break;
				case '>':
					Pop(OPTR, theta);
					PopBiTree(EXPT, b);
					PopBiTree(EXPT, a);
					CreateExpTree(T, a, b, theta);
					PushBiTree(EXPT, T);
					break;
				case '=':
					Pop(OPTR, x);
					cin >> ch;
					break;
			}
		}
	}
}
//���ʽ����ֵ
int EvaluateExTree(BiTree T) {
	int lvalue = 0;
	int rvalue=0;
	if (T->lchild == NULL&&T->rchild == NULL)
		return T->data - '0';
	else {
		lvalue = EvaluateExTree(T->lchild);
		rvalue = EvaluateExTree(T->rchild);
		return GetValue(T->data, lvalue, rvalue);//
	}

}
void main191900() {
	cout << "�������������ʽ������#�������м��������Ǹ�λ����\n" << endl;
	BiTree T;
	InitExpTree(T);
	cout << EvaluateExTree(T) << endl;
	system("pause");
}