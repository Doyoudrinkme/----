#include <cstring>
#include<iostream>
#include "�Զ����.h"

using namespace std;


//BF�㷨
int Index(SString S, SString T, int pos) {
	//����ģʽT�������е�pos���ַ�֮���sһ�γ��ֵ�λ�ã��������ڣ��򷵻�ֵΪ0
	//���У�T�ǿգ�i<=pos<=StrLength(s)
	int i = pos;
	int j = 1;
	while (i <= S[0] && j <= T[0]) {
		if (S[i] == T[j]) {//�����ȽϺ���ַ�
			++i;
			++j;
		}
		else {//ָ��������¿�ʼƥ��
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
	return 0;
}
int main2016��12��9��22() {
	SString S;
	StrAssign(S, "bbaaabbaba");
	SString T;
	StrAssign(T, "abb");
	cout << "�������Ӵ��ڵ� " << Index(S, T, 1) << " ���ַ����״�ƥ��\n";
	return 0;
}