#include<iostream>
#include "��.h"
#include "��ջ����.h"
using namespace std;
 
//��������ƥ��
Status Matching() {
	//���ʽ�� # ����
	char ch;
	SElemType x;
	LinkStack S;
	InitStack(S);//��ʼ����ջ
	int flag = 1;//���ƥ�����Կ���ѭ�������ؽ��

	cin >> ch;//�����һ���ַ�
	while (ch!='#'&&flag) {
		switch (ch) {
			case '[':
			case '('://���������Ž���ѹ��ջ
				Push(S, ch);
				break;
			case ')'://���ǡ���'������ݵ�ǰջ��Ԫ�ص�ֵ�������
				if (!StackEmpty(S) && GetTop(S) == '(')
					Pop(S, x);//��ջ�ǿ���ջ��Ԫ���ǡ�����,����ȷƥ��
				else
					flag = 0;
				break;
			case ']'://����']'������ݵ�ǰջ��Ԫ��
				if (!StackEmpty(S) && GetTop(S) == '[')
					Pop(S, x);//��ջ�ǿ���ջ��Ԫ���ǡ�����,����ȷƥ��
				else
					flag = 0;
				break;
		}
		cin >> ch;//����������һ���ַ�
	}
	if (StackEmpty(S) && flag)
		return true;
	else
		return false;
}
int main141406() {
	
	while (1) {
		LinkStack S;
		cout << "�������ƥ��ı��ʽ����#����" << endl;
		int flag = (int)Matching();
		if (flag)
			cout << "ƥ��ɹ���" << endl;
		else
			cout << "ƥ��ʧ�ܣ�" << endl;
		system("pause");
	}
	return 0;
}