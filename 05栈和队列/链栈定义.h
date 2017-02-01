#pragma once
#include "宏.h"
#include<iostream>
#include<fstream>
typedef struct StackNode {
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStack;

//链栈初始化
Status InitStack(LinkStack &S);
//链栈入栈
Status Push(LinkStack &S, SElemType e);
//链栈的出栈
Status Pop(LinkStack &S, SElemType &e);
//取链栈的栈顶元素
SElemType GetTop(LinkStack S);

bool StackEmpty(LinkStack S);