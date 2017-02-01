#include<iostream>
#include<fstream>
#include "宏.h"
using namespace std;

//队列的链式存储结构
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct {
	QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}LinkQueue;

//链队的初始化
Status InitQueue(LinkQueue &Q) {
	//构造空队列
	Q.front = Q.rear = new QNode;//生成新结点作为头结点，队头队尾指针指向该结点
	Q.front->next = NULL;//头结点指针域置空
	return OK;
}
//链队的入队
Status EnQueue(LinkQueue &Q, QElemType e) {
	//插入元素e为Q的新的队尾元素
	QueuePtr p = new QNode;//为入队元素分配结点空间，用指针p指向
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;//将新结点插入到队尾
	Q.rear = p;//修改队尾指针
	return OK;
}
//链队的出队
Status DeQueue(LinkQueue &Q, QElemType &e) {
	//删除队头元素，用e返回
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;//p指向队头元素
	e = p->data;//e保存队头元素的值
	Q.front->next = p->next;//修改头指针
	if (Q.rear == p)
		Q.rear = Q.front;//最后一个元素被删，队尾指针指向队头结点
	delete p;
	return OK;
}
//取链队的队头元素
SElemType GetHead(LinkQueue Q) {
	if (Q.front != Q.rear)
		return Q.front->next->data;//返回队头元素的值，队头指针不变
}
int main4() {
	int choose, flag = 0;
	LinkQueue Q;
	QElemType j, e;
	cout << "1.入队\n";
	cout << "2.读队头元素\n";
	cout << "3.出队\n";
	cout << "0.t退出\n\n";
	choose = -1;
	if (InitQueue(Q)) {
		flag = 1;
		cout << "成功对链队进行初始化\n\n";
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
							EnQueue(Q, j);
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