#include<iostream>
#include<fstream>
#include "��.h"

using namespace std;

typedef struct {
	SElemType *base;//ջ��ָ��
	SElemType *top;//ջ��ָ��
	int stacksize;//ջ���õ��������
}SqStack;

//˳��ջ�ĳ�ʼ��
Status InitDStack(SqStack &S) {
	//Ϊ˳��ջ��̬����һ���������ΪMAXSIZE������ռ�
	S.base = new SElemType[MAXSIZE];
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;//top��ʼ��Ϊbase����ջ
	S.stacksize = MAXSIZE;
	return OK;
}

//˳��ջ����ջ
Status PushDStack(SqStack &S, SElemType e) {
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S.top - S.base == S.stacksize)
		return ERROR;//ջ��
	*(S.top++) = e;//Ԫ��ѹ��ջ����ջ��ָ���1
	return OK;
}
Status PopDStack(SqStack &S, SElemType &e) {
	//ɾ��S��ջ��Ԫ�أ���e������ֵ
	if (S.base == S.top)
		return ERROR;//ջ��
	e = *(--S.top);//ջ��ָ���1����ջ��Ԫ�ظ���e
	return OK;
}
//ȡ˳����ջ��Ԫ��
char GetDStackTop(SqStack S) {	
	if (S.top != S.base)//ջ�ǿ�
		return *(S.top - 1);//����S��ջ��Ԫ�أ����޸�ջ��ָ��
}
int main1() {
	SqStack s;
	int choose, flag = 0;
	SElemType j, e, t;
	cout << "1.��ջ\n";
	cout << "2.��ȡջ��Ԫ��\n";
	cout << "3.��ջ\n";
	cout << "0.�˳�\n\n";
	choose = -1;

	if (InitDStack(s)) {
		flag = 1;
		cout << "�ɹ���ջ���г�ʼ��\n\n";
	} else {
		cout << "��ʼ��ջʧ�ܣ�\n\n";
	}
	while (choose!=0) {
		cout << "��ѡ��";
		cin >> choose;
		switch (choose) {
			case 1: {
				fstream file;
				file.open("SqStack.txt");
				if (!file) {
					cout << "����δ�ҵ��ļ���\n\n" << endl;
					exit(ERROR);
				}
				if (flag) {
					flag = 1;
					cout << "��ջԪ������Ϊ��\n";
					while (!file.eof()) {
						file >> j;
						if (file.fail())
							break;
						else {
							PushDStack(s, j);
							cout << j << " ";
						}
					}
					cout << endl << endl;
				} else
					cout << "ջδ�����������ѡ��";
				file.close();
			}
					break;
			case 2: {//˳��ջ��ջ
				if (flag != -1 && flag!= 0)
					cout << "ջ��Ԫ���ǣ�\n" << GetDStackTop(s) << endl << endl;
				else {
					cout << "ջ����Ԫ�أ�������ѡ��\n" << endl;
				}
				break;
			}
			case 3: {//��ȡջ��Ԫ�� 
				cout << "���ε���ջ��Ԫ�أ�\n";
				while (PopDStack(s, t)) {
					flag = -1;
					cout << t << " ";
				}
				cout << endl << endl;
				break;
			}
		}
		
	}
	return 0;
}