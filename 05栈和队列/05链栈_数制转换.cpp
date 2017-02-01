#include<iostream>

#include "链栈定义.h"
using namespace std;

void conversion(int N,int m) {
	//对于任意一个非负十进制数，打印输出与其等值的八进制数
	SElemType e;
	LinkStack S;
	InitStack(S);//初始化空栈S
	while (N) {//当N非0时循环
		Push(S, N % m);//把N与8求余得到的八进制数压入栈S
		N = N / m;//N更新为N与8的商
	}
	while (!StackEmpty(S)) {
		Pop(S, e);//弹出栈顶元素e
		cout << e ;//输出e
	}
}
//按照进制转换
int main5() {
	int m, n, e;
	cout << "进制转换：" << endl;
	cout << "输入非负十进制数：" ;
	cin >> n;
	while (true) {	
		cout << "输入进制数：";
		cin >> m;
		conversion(n, m);
		cout << endl;
	}
	
	system("pause");
}