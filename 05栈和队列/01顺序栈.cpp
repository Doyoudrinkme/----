#include<iostream>
#include<fstream>
#include "宏.h"

using namespace std;

typedef struct {
	SElemType *base;//栈底指针
	SElemType *top;//栈顶指针
	int stacksize;//栈可用的最大容量
}SqStack;

//顺序栈的初始化
Status InitDStack(SqStack &S) {
	//为顺序栈动态分配一个最大容量为MAXSIZE的数组空间
	S.base = new SElemType[MAXSIZE];
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;//top初始化为base，空栈
	S.stacksize = MAXSIZE;
	return OK;
}

//顺序栈的入栈
Status PushDStack(SqStack &S, SElemType e) {
	//插入元素e为新的栈顶元素
	if (S.top - S.base == S.stacksize)
		return ERROR;//栈满
	*(S.top++) = e;//元素压入栈顶，栈顶指针加1
	return OK;
}
Status PopDStack(SqStack &S, SElemType &e) {
	//删除S的栈顶元素，用e返回其值
	if (S.base == S.top)
		return ERROR;//栈空
	e = *(--S.top);//栈顶指针减1，将栈顶元素赋给e
	return OK;
}
//取顺序表的栈顶元素
char GetDStackTop(SqStack S) {	
	if (S.top != S.base)//栈非空
		return *(S.top - 1);//返回S的栈顶元素，不修改栈顶指针
}
int main1() {
	SqStack s;
	int choose, flag = 0;
	SElemType j, e, t;
	cout << "1.入栈\n";
	cout << "2.读取栈顶元素\n";
	cout << "3.出栈\n";
	cout << "0.退出\n\n";
	choose = -1;

	if (InitDStack(s)) {
		flag = 1;
		cout << "成功对栈进行初始化\n\n";
	} else {
		cout << "初始化栈失败！\n\n";
	}
	while (choose!=0) {
		cout << "请选择：";
		cin >> choose;
		switch (choose) {
			case 1: {
				fstream file;
				file.open("SqStack.txt");
				if (!file) {
					cout << "错误！未找到文件！\n\n" << endl;
					exit(ERROR);
				}
				if (flag) {
					flag = 1;
					cout << "进栈元素依次为：\n";
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
					cout << "栈未建立，请从新选择！";
				file.close();
			}
					break;
			case 2: {//顺序栈出栈
				if (flag != -1 && flag!= 0)
					cout << "栈顶元素是：\n" << GetDStackTop(s) << endl << endl;
				else {
					cout << "栈中无元素，请重新选择\n" << endl;
				}
				break;
			}
			case 3: {//读取栈顶元素 
				cout << "依次弹出栈顶元素：\n";
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