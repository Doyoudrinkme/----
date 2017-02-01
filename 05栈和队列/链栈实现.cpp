#include "链栈定义.h"
Status InitStack(LinkStack &S) {
	S = NULL;
	return OK;
}
//链栈入栈
Status Push(LinkStack &S, SElemType e) {
	LinkStack p = new StackNode;//生成新结点
	p->data = e;//将新结点数据域置为e
	p->next = S;//新结点插入栈顶
	S = p;//修改栈顶指针为p
	return OK;
}
//链栈的出栈
Status Pop(LinkStack &S, SElemType &e) {
	//删除S的栈顶元素，用e返回
	LinkStack p;
	if (S == NULL)
		return ERROR;//栈空
	e = S->data;//将栈顶元素赋给e
	p = S;//用p临时保存栈顶元素空间，以备释放
	S = S->next;//修改栈顶指针
	delete p;
	return OK;
}
//取链栈的栈顶元素
SElemType GetTop(LinkStack S) {
	if (S != NULL)//栈非空
		return S->data;//返回栈顶元素值，栈顶指针不变
}
bool StackEmpty(LinkStack S) {
	if (!S)
		return true;
	return false;
}