#include<iostream>

#include "��ջ����.h"
using namespace std;

void conversion(int N,int m) {
	//��������һ���Ǹ�ʮ����������ӡ��������ֵ�İ˽�����
	SElemType e;
	LinkStack S;
	InitStack(S);//��ʼ����ջS
	while (N) {//��N��0ʱѭ��
		Push(S, N % m);//��N��8����õ��İ˽�����ѹ��ջS
		N = N / m;//N����ΪN��8����
	}
	while (!StackEmpty(S)) {
		Pop(S, e);//����ջ��Ԫ��e
		cout << e ;//���e
	}
}
//���ս���ת��
int main5() {
	int m, n, e;
	cout << "����ת����" << endl;
	cout << "����Ǹ�ʮ��������" ;
	cin >> n;
	while (true) {	
		cout << "�����������";
		cin >> m;
		conversion(n, m);
		cout << endl;
	}
	
	system("pause");
}