#include<iostream>
#include<fstream>
#include "宏.h"
using namespace std;
typedef struct {
	QElemType *base;//初始化时动态分配存储空间
	int front;//头指针
	int rear;//尾指针
}SqQueue;
//循环队列的初始化
Status InitQueue(SqQueue &Q) {  //构造空队列
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)
		exit(OVERFLOW);//存储分配失败
	Q.front = Q.rear = 0;//头指针和尾指针置0，队列为空
	return OK;
}
//求循环队列的长度
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
//循环队列的入队
Status EnQueue(SqQueue &Q, QElemType e) {
	//插入元素e为Q的新队尾元素
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return ERROR;//尾指针在循环意义上加1等于头指针，表示队满
	Q.base[Q.rear] = e;//新元素插入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE;//队尾指针加1
	return OK;
}
//循环队列的出队
Status DeQueue(SqQueue &Q, QElemType &e) {
	//删除队头元素，用e返回
	if (Q.front == Q.rear)
		return ERROR;//队空
	e = Q.base[Q.front];//保存队头元素
	Q.front = (Q.front + 1) % MAXQSIZE;//队头指针加1
	return OK;
}
//取循环队列的队头元素
SElemType GetHead(SqQueue Q) {
	//返回队头元素，不修改队头指针
	if (Q.front != Q.rear)//队非空
		return Q.base[Q.front];//返回队头元素，队头指针不变
}
int main3() {
	int choose, flag = 0;
	SqQueue Q;
	QElemType j, e;
	cout << "1.入队\n";
	cout << "2.读队头元素\n";
	cout << "3.出队\n";
	cout << "0.t退出\n\n";
	choose = -1;
	if (InitQueue(Q)) {
		flag = 1;
		cout << "成功对栈进行初始化\n\n";
	} else {
		cout << "初始化失败！\n\n";
	}
	while (choose != 0) {
		cout << "请选择：";
		cin >> choose;
		switch (choose) {
			case 1: {//链栈入栈
				fstream file;
				file.open("SqStack.txt");
				if (!file) {
					cout << "错误！未找到文件！\n\n" << endl;
					exit(ERROR);
				}
				if (flag) {
					flag = 1;
					cout << "入队的元素依次是：\n";
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
					cout << "队列未建立，请重新选择\n\n";
				file.close();
			}
					break;
			case 2: {//取栈的栈顶元素
				if (flag != -1 && flag != 0)
					cout << "队头元素是：" << GetHead(Q) << endl << endl;
				else
					cout << "队中无元素，请重新选择\n" << endl;
			}
					break;
			case 3://链栈的出栈
				if (flag) {
					cout << "依次弹出队元素为：\n";
					while (DeQueue(Q, e)) {
						flag = -1;
						cout << e << "  ";
					}			
					cout << endl << endl;
				} else
					cout << "栈中无元素，请重新选择\n" << endl;
				break;

		}
	}

	return 0;
}