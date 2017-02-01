#include<iostream>
#include<fstream>
#include "链栈定义.h"

using namespace std;


int main2() {
	LinkStack s;
	int choose, flag = 0;
	SElemType j, t;
	cout << "1.入栈\n";
	cout << "2.读栈顶元素\n";
	cout << "3.出栈\n";
	cout << "0.t退出\n\n";
	choose = -1;
	if (InitStack(s)) {
		flag = 1;
		cout << "成功对栈进行初始化\n\n";
	} else {
		cout << "初始化失败！\n\n";
	}
	while (choose != 0) {
		cout << "请选择：";
		cin >> choose;
		switch(choose) {
			case 1: {//链栈入栈
				fstream file;
				file.open("SqStack.txt");
				if (!file) {
					cout << "错误！未找到文件！\n\n" << endl;
					exit(ERROR);
				}
				if (flag) {
					flag = 1;
					cout << "进栈元素依次是：\n";
					while (!file.eof()) {
						file >> j;
						if (file.fail())
							break;
						else {
							Push(s, j);
							cout << j << "  ";
						}
					}
					cout << endl << endl;
				} else
					cout << "栈未建立，请重新选择\n\n";
				file.close();
			}
				break;
			case 2: {//取栈的栈顶元素
				if (flag != -1 && flag != 0)
					cout << "栈顶元素是：" << GetTop(s) << endl << endl;
				else
					cout << "栈中无元素，请重新选择\n" << endl;
			}
				break;
			case 3://链栈的出栈
				if (flag) {
					cout << "依次弹出栈顶元素为：\n";
					while (Pop(s, t))
						cout << t << "  ";
					cout << endl << endl;
				} else
					cout << "栈中无元素，请重新选择\n" << endl;
				break;

		}
	}
	
	return 0;
}