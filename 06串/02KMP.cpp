#include <cstring>
#include<iostream>
#include "�Զ����.h"
using namespace std;

Status StrAssign(SString T, char *chars) {
	int i;
	if (strlen(chars) > MAXSTERLEN)
		return ERROR;
	else {
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return OK;
	}
}

//����next����ֵ
void get_next(SString T, int next[]) {
	//��ģʽ��T��next����ֵ������next����
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T[0]) {
		if (j == 0 || T[i] == T[j]) {//�Ƚ�ƥ�䴮 ��������Ԫ���Ƿ�һ��
			++i;
			++j;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}

//����next��������ֵ
void get_nextval(SString T, int nextval[]) {
	//��ģʽ��T��next��������ֵ����������nextval
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i<T[0]) {
		if (j == 0 || T[i] == T[j]) {
			++i;
			++j;
			if (T[i] != T[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else {
			j = nextval[j];
		}
	}
}
//KMP�㷨

int Index_KMP(SString S, SString T, int pos, int next[]) {
	//����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨
	//���У�T�ǿգ�i<=pos<=StrLength(S)
	int i = pos, j = 1;
	while (i <= S[0] && j <= T[0]) {
		if (j == 0 || S[i] == T[j]) {//�����ȽϺ���ַ�
			++i;
			++j;
		} 
		else
			j = next[j];//ģʽ�������ƶ�
	}
	if (j > T[0])//ƥ��ɹ�
		return i - T[0];
	else
		return 0;
}

int main2016��12��10��200842() {
	SString S;
	StrAssign(S, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaba");
	SString T;
	StrAssign(T, "abb");
	int *p = new int[T[0] + 1];//����T��next����
	//get_next(T, p);
	get_nextval(T, p);
	cout << "�������Ӵ��ڵ� " << Index_KMP(S, T, 1, p) << " ���ַ����״�ƥ��\n";
	system("pause");
	return 0;
}