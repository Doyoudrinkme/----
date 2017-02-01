#include<iostream>
#include "链栈定义.h"

using namespace std;

const char oper[7] = { '+','-','*','/','(',')','#' };

//判断ch是否为运算符
bool In(char ch) {
	for (int i = 0; i < 7; i++) {
		if (ch == oper[i])
			return true;
	}
	return false;
}
//判断运算符优先级
char Precede(char theta1, char theta2) {
	if ((theta1 == '('&&theta2 == ')') || theta1 == '#'&&theta2 == '#') {
		return '=';
	} else if (theta1 == '(' || theta1 == '#' || theta2 == '(' ||
		(theta1 == '+' || theta1 == '-') && (theta2 == '*' || theta2 == '/'))
		return '<';
	else
		return '>';
}
//计算运算结果
char Operate(char first, char theta, char second) {
	switch (theta) {
		case '+':
			return (first - '0') + (second - '0') + 48;
		case '-':
			return (first - '0') - (second - '0') + 48;
		case '*':
			return (first - '0') * (second - '0') + 48;
		case '/':
			return (first - '0') / (second - '0') + 48;		
	}
	return 0;
}
char EvaluateExpression() {
	LinkStack OPTR, OPND;//定义运算栈和操作栈
	char ch, theta, a, b, x, top;
	InitStack(OPTR);
	InitStack(OPND);
	Push(OPTR, '#');//将表达式起始符压入OPTR栈
	cin >> ch;
	while (ch != '#' || (GetTop(OPTR) != '#')) {
		//表达式没有扫描完成或运算栈顶元素不是"#"
		if (!In(ch)) {
			Push(OPND, ch);
			cin >> ch;
		}
		else {
			//比较运算符栈顶元素和操作数的运算优先级
			switch (Precede(GetTop(OPTR),ch)) {
				case '<':
					Push(OPTR, ch);
					cin >> ch;//当前字符ch压入OPTR栈，读入下一字符ch
					break;
				case '>':
					Pop(OPTR, theta);//弹出OPTR栈顶的运算符
					//弹出两个运算符
					Pop(OPND, b);
					Pop(OPND, a);
					//将运算结果压入OPND
					Push(OPND, Operate(a, theta, b));
				case '='://OPTR的栈顶元素是“（”且ch是“）”
					Pop(OPTR, x);
					cin >> ch;//弹出OPTR栈顶的“（”,读入下一字符ch
					break;
				default:
					break;
			}

		}
	}
	return GetTop(OPND);
}

int menu() {
	int c;
	cout << "0-9以内的多项式计算：" << endl;
	cout << "1.计算" << endl;
	cout << "0.退出\n" << endl;
	cout << "选择：";
	cin >> c;
	return c;
}

int main162217() {
	while (1) {
		switch (menu()) {
			case 1: {
				cout << "请输入要计算的表达式（操作数和结果都在0-9范围内，以#结束）：" << endl;
				char res = EvaluateExpression();//表达式求值
				cout << "结算结果：" << res - 48 << endl << endl;
			}
					break;
			case 0:
				cout << "退出成功！\n";
				exit(0);
		}
	}
}