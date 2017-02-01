#include<iostream>
#include "宏.h"
#include "链栈定义.h"
using namespace std;
 
//检验括号匹配
Status Matching() {
	//表达式以 # 结束
	char ch;
	SElemType x;
	LinkStack S;
	InitStack(S);//初始化空栈
	int flag = 1;//标记匹配结果以控制循环及返回结果

	cin >> ch;//读入第一个字符
	while (ch!='#'&&flag) {
		switch (ch) {
			case '[':
			case '('://若是左括号将其压入栈
				Push(S, ch);
				break;
			case ')'://若是‘）'，则根据当前栈顶元素的值分配情况
				if (!StackEmpty(S) && GetTop(S) == '(')
					Pop(S, x);//若栈非空且栈顶元素是“（”,则正确匹配
				else
					flag = 0;
				break;
			case ']'://若是']'，则根据当前栈顶元素
				if (!StackEmpty(S) && GetTop(S) == '[')
					Pop(S, x);//若栈非空且栈顶元素是“（”,则正确匹配
				else
					flag = 0;
				break;
		}
		cin >> ch;//继续读入下一个字符
	}
	if (StackEmpty(S) && flag)
		return true;
	else
		return false;
}
int main141406() {
	
	while (1) {
		LinkStack S;
		cout << "请输入待匹配的表达式，以#结束" << endl;
		int flag = (int)Matching();
		if (flag)
			cout << "匹配成功！" << endl;
		else
			cout << "匹配失败！" << endl;
		system("pause");
	}
	return 0;
}