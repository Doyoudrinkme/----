#include<iostream>
#include<fstream>
#include<string>

#include "宏.h"
using namespace std;
typedef struct {
	char name[20];//姓名
	char sex;//性别
}Person;

//队列的顺序存储结构
typedef struct {
	Person *base;//队列数据元素类型
	int font;//头指针
	int rear;//尾指针
}SqQueue;

SqQueue Mdancers, Fdancers;

//构造空队列
int InitDPQueue(SqQueue &Q) {
	Q.base = new Person[MAXSIZE];
	if (!Q.base) {
		exit(OVERFLOW);
	}
	Q.font = Q.rear = 0;//头尾指针置为0，队列为空
	return OK;
}
//插入元素e为Q的新队尾元素
int EnQueue(SqQueue &Q, Person e) {
	//尾指针在循环意义上加1等于头指针，表明队满
	if ((Q.rear + 1) % MAXSIZE == Q.font)
		return ERROR;
	Q.base[Q.rear + 1] = e;//新元素插入队尾
	Q.rear = (Q.rear + 1) % MAXSIZE;//队尾指针加1；
	return OK;
}
int QueueEmpty(SqQueue &Q) {
	if (Q.font = Q.rear)
		return OK;
	else {
		return ERROR;
	}
}
//删除Q队头元素 e返回
int DeQueue(SqQueue &Q, Person &e) {
	if (Q.font == Q.rear)
		return ERROR;
	e = Q.base[Q.font];//保存队头元素
	Q.font = (Q.font + 1) % MAXSIZE;//队头指针加1
	return OK;
}


//返回队头元素，不修改头指针
Person GetHead(SqQueue Q) {
	if (Q.font != Q.rear)
		return Q.base[Q.font];
}


void DancePartner(Person dancer[], int num) {
	//结构数组dancer中存放舞男舞女，num是数目
	InitDPQueue(Mdancers);//舞男队列初始化
	InitDPQueue(Fdancers);//舞女队列初始化
	Person p;
	//依次将跳舞者根据性别入队
	for (int i = 0; i < num; i++) {
		p = dancer[i];
		if (p.sex = 'F')
			EnQueue(Fdancers, p);
		else {
			EnQueue(Mdancers, p);
		}
	}
	cout << "舞者队列是：" << endl;
	while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers)) {
		DeQueue(Fdancers, p);
		cout << p.name << " ";
		DeQueue(Mdancers, p);
		cout << p.name << " "<<endl;

	}
	if (!QueueEmpty(Fdancers)) {
		//女士队列非空，输出队头女士姓名
		p = GetHead(Fdancers);//取女士队头
		cout << "第一个舞男的搭档：" << endl;
	}
	else if(!QueueEmpty(Mdancers)){
		//男士对列非空，输出队头男士姓名
		p = GetHead(Mdancers);
		cout << "第一个舞女的搭档：" << endl;
	}
}

int main2016年12月5日15() {
	Person dancer[MAXQSIZE];
	int i = 0;
	fstream file;
	file.open("DancePartner.txt");
	if (!file) {
		cout << "错误，未找到文件！\n\n" << endl;	
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