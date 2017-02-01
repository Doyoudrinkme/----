#pragma once
#include "��.h"
#include<iostream>
#include<fstream>
typedef struct StackNode {
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStack;

//��ջ��ʼ��
Status InitStack(LinkStack &S);
//��ջ��ջ
Status Push(LinkStack &S, SElemType e);
//��ջ�ĳ�ջ
Status Pop(LinkStack &S, SElemType &e);
//ȡ��ջ��ջ��Ԫ��
SElemType GetTop(LinkStack S);

bool StackEmpty(LinkStack S);