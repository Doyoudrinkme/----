#include<iostream>
#include<fstream>
#include "��.h"
using namespace std;
typedef struct {
	QElemType *base;//��ʼ��ʱ��̬����洢�ռ�
	int front;//ͷָ��
	int rear;//βָ��
}SqQueue;
//ѭ�����еĳ�ʼ��
Status InitQueue(SqQueue &Q) {  //����ն���
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)
		exit(OVERFLOW);//�洢����ʧ��
	Q.front = Q.rear = 0;//ͷָ���βָ����0������Ϊ��
	return OK;
}
//��ѭ�����еĳ���
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
//ѭ�����е����
Status EnQueue(SqQueue &Q, QElemType e) {
	//����Ԫ��eΪQ���¶�βԪ��
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return ERROR;//βָ����ѭ�������ϼ�1����ͷָ�룬��ʾ����
	Q.base[Q.rear] = e;//��Ԫ�ز����β
	Q.rear = (Q.rear + 1) % MAXQSIZE;//��βָ���1
	return OK;
}
//ѭ�����еĳ���
Status DeQueue(SqQueue &Q, QElemType &e) {
	//ɾ����ͷԪ�أ���e����
	if (Q.front == Q.rear)
		return ERROR;//�ӿ�
	e = Q.base[Q.front];//�����ͷԪ��
	Q.front = (Q.front + 1) % MAXQSIZE;//��ͷָ���1
	return OK;
}
//ȡѭ�����еĶ�ͷԪ��
SElemType GetHead(SqQueue Q) {
	//���ض�ͷԪ�أ����޸Ķ�ͷָ��
	if (Q.front != Q.rear)//�ӷǿ�
		return Q.base[Q.front];//���ض�ͷԪ�أ���ͷָ�벻��
}
int main3() {
	int choose, flag = 0;
	SqQueue Q;
	QElemType j, e;
	cout << "1.���\n";
	cout << "2.����ͷԪ��\n";
	cout << "3.����\n";
	cout << "0.t�˳�\n\n";
	choose = -1;
	if (InitQueue(Q)) {
		flag = 1;
		cout << "�ɹ���ջ���г�ʼ��\n\n";
	} else {
		cout << "��ʼ��ʧ�ܣ�\n\n";
	}
	while (choose != 0) {
		cout << "��ѡ��";
		cin >> choose;
		switch (choose) {
			case 1: {//��ջ��ջ
				fstream file;
				file.open("SqStack.txt");
				if (!file) {
					cout << "����δ�ҵ��ļ���\n\n" << endl;
					exit(ERROR);
				}
				if (flag) {
					flag = 1;
					cout << "��ӵ�Ԫ�������ǣ�\n";
					while (!file.eof()) {
						file >> j;
						if (file.fail())
							break;
						else {
							EnQueue(Q,j);
							cout << j << "  ";
						}
					}
					cout << endl << endl;
				} else
					cout << "����δ������������ѡ��\n\n";
				file.close();
			}
					break;
			case 2: {//ȡջ��ջ��Ԫ��
				if (flag != -1 && flag != 0)
					cout << "��ͷԪ���ǣ�" << GetHead(Q) << endl << endl;
				else
					cout << "������Ԫ�أ�������ѡ��\n" << endl;
			}
					break;
			case 3://��ջ�ĳ�ջ
				if (flag) {
					cout << "���ε�����Ԫ��Ϊ��\n";
					while (DeQueue(Q, e)) {
						flag = -1;
						cout << e << "  ";
					}			
					cout << endl << endl;
				} else
					cout << "ջ����Ԫ�أ�������ѡ��\n" << endl;
				break;

		}
	}

	return 0;
}