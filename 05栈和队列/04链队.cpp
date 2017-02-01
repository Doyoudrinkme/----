#include<iostream>
#include<fstream>
#include "��.h"
using namespace std;

//���е���ʽ�洢�ṹ
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct {
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}LinkQueue;

//���ӵĳ�ʼ��
Status InitQueue(LinkQueue &Q) {
	//����ն���
	Q.front = Q.rear = new QNode;//�����½����Ϊͷ��㣬��ͷ��βָ��ָ��ý��
	Q.front->next = NULL;//ͷ���ָ�����ÿ�
	return OK;
}
//���ӵ����
Status EnQueue(LinkQueue &Q, QElemType e) {
	//����Ԫ��eΪQ���µĶ�βԪ��
	QueuePtr p = new QNode;//Ϊ���Ԫ�ط�����ռ䣬��ָ��pָ��
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;//���½����뵽��β
	Q.rear = p;//�޸Ķ�βָ��
	return OK;
}
//���ӵĳ���
Status DeQueue(LinkQueue &Q, QElemType &e) {
	//ɾ����ͷԪ�أ���e����
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;//pָ���ͷԪ��
	e = p->data;//e�����ͷԪ�ص�ֵ
	Q.front->next = p->next;//�޸�ͷָ��
	if (Q.rear == p)
		Q.rear = Q.front;//���һ��Ԫ�ر�ɾ����βָ��ָ���ͷ���
	delete p;
	return OK;
}
//ȡ���ӵĶ�ͷԪ��
SElemType GetHead(LinkQueue Q) {
	if (Q.front != Q.rear)
		return Q.front->next->data;//���ض�ͷԪ�ص�ֵ����ͷָ�벻��
}
int main4() {
	int choose, flag = 0;
	LinkQueue Q;
	QElemType j, e;
	cout << "1.���\n";
	cout << "2.����ͷԪ��\n";
	cout << "3.����\n";
	cout << "0.t�˳�\n\n";
	choose = -1;
	if (InitQueue(Q)) {
		flag = 1;
		cout << "�ɹ������ӽ��г�ʼ��\n\n";
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
							EnQueue(Q, j);
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