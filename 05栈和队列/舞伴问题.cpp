#include<iostream>
#include<fstream>
#include<string>

#include "��.h"
using namespace std;
typedef struct {
	char name[20];//����
	char sex;//�Ա�
}Person;

//���е�˳��洢�ṹ
typedef struct {
	Person *base;//��������Ԫ������
	int font;//ͷָ��
	int rear;//βָ��
}SqQueue;

SqQueue Mdancers, Fdancers;

//����ն���
int InitDPQueue(SqQueue &Q) {
	Q.base = new Person[MAXSIZE];
	if (!Q.base) {
		exit(OVERFLOW);
	}
	Q.font = Q.rear = 0;//ͷβָ����Ϊ0������Ϊ��
	return OK;
}
//����Ԫ��eΪQ���¶�βԪ��
int EnQueue(SqQueue &Q, Person e) {
	//βָ����ѭ�������ϼ�1����ͷָ�룬��������
	if ((Q.rear + 1) % MAXSIZE == Q.font)
		return ERROR;
	Q.base[Q.rear + 1] = e;//��Ԫ�ز����β
	Q.rear = (Q.rear + 1) % MAXSIZE;//��βָ���1��
	return OK;
}
int QueueEmpty(SqQueue &Q) {
	if (Q.font = Q.rear)
		return OK;
	else {
		return ERROR;
	}
}
//ɾ��Q��ͷԪ�� e����
int DeQueue(SqQueue &Q, Person &e) {
	if (Q.font == Q.rear)
		return ERROR;
	e = Q.base[Q.font];//�����ͷԪ��
	Q.font = (Q.font + 1) % MAXSIZE;//��ͷָ���1
	return OK;
}


//���ض�ͷԪ�أ����޸�ͷָ��
Person GetHead(SqQueue Q) {
	if (Q.font != Q.rear)
		return Q.base[Q.font];
}


void DancePartner(Person dancer[], int num) {
	//�ṹ����dancer�д��������Ů��num����Ŀ
	InitDPQueue(Mdancers);//���ж��г�ʼ��
	InitDPQueue(Fdancers);//��Ů���г�ʼ��
	Person p;
	//���ν������߸����Ա����
	for (int i = 0; i < num; i++) {
		p = dancer[i];
		if (p.sex = 'F')
			EnQueue(Fdancers, p);
		else {
			EnQueue(Mdancers, p);
		}
	}
	cout << "���߶����ǣ�" << endl;
	while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers)) {
		DeQueue(Fdancers, p);
		cout << p.name << " ";
		DeQueue(Mdancers, p);
		cout << p.name << " "<<endl;

	}
	if (!QueueEmpty(Fdancers)) {
		//Ůʿ���зǿգ������ͷŮʿ����
		p = GetHead(Fdancers);//ȡŮʿ��ͷ
		cout << "��һ�����еĴ��" << endl;
	}
	else if(!QueueEmpty(Mdancers)){
		//��ʿ���зǿգ������ͷ��ʿ����
		p = GetHead(Mdancers);
		cout << "��һ����Ů�Ĵ��" << endl;
	}
}

int main2016��12��5��15() {
	Person dancer[MAXQSIZE];
	int i = 0;
	fstream file;
	file.open("DancePartner.txt");
	if (!file) {
		cout << "����δ�ҵ��ļ���\n\n" << endl;	
		system("pause");
		exit(ERROR);
	}
	/*while (!file.eof()) {
		cout << dancer[i].name << dancer[i].sex;
		i++;
	}*/
	while (!file.eof()) {
		file >> dancer[i].name >> dancer[i].sex;
		i++;
	}
	DancePartner(dancer, i + 1);
	system("pause");
}