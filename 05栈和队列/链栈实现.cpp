#include "��ջ����.h"
Status InitStack(LinkStack &S) {
	S = NULL;
	return OK;
}
//��ջ��ջ
Status Push(LinkStack &S, SElemType e) {
	LinkStack p = new StackNode;//�����½��
	p->data = e;//���½����������Ϊe
	p->next = S;//�½�����ջ��
	S = p;//�޸�ջ��ָ��Ϊp
	return OK;
}
//��ջ�ĳ�ջ
Status Pop(LinkStack &S, SElemType &e) {
	//ɾ��S��ջ��Ԫ�أ���e����
	LinkStack p;
	if (S == NULL)
		return ERROR;//ջ��
	e = S->data;//��ջ��Ԫ�ظ���e
	p = S;//��p��ʱ����ջ��Ԫ�ؿռ䣬�Ա��ͷ�
	S = S->next;//�޸�ջ��ָ��
	delete p;
	return OK;
}
//ȡ��ջ��ջ��Ԫ��
SElemType GetTop(LinkStack S) {
	if (S != NULL)//ջ�ǿ�
		return S->data;//����ջ��Ԫ��ֵ��ջ��ָ�벻��
}
bool StackEmpty(LinkStack S) {
	if (!S)
		return true;
	return false;
}