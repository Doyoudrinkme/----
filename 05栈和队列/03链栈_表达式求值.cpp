#include<iostream>
#include "��ջ����.h"

using namespace std;

const char oper[7] = { '+','-','*','/','(',')','#' };

//�ж�ch�Ƿ�Ϊ�����
bool In(char ch) {
	for (int i = 0; i < 7; i++) {
		if (ch == oper[i])
			return true;
	}
	return false;
}
//�ж���������ȼ�
char Precede(char theta1, char theta2) {
	if ((theta1 == '('&&theta2 == ')') || theta1 == '#'&&theta2 == '#') {
		return '=';
	} else if (theta1 == '(' || theta1 == '#' || theta2 == '(' ||
		(theta1 == '+' || theta1 == '-') && (theta2 == '*' || theta2 == '/'))
		return '<';
	else
		return '>';
}
//����������
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
	LinkStack OPTR, OPND;//��������ջ�Ͳ���ջ
	char ch, theta, a, b, x, top;
	InitStack(OPTR);
	InitStack(OPND);
	Push(OPTR, '#');//�����ʽ��ʼ��ѹ��OPTRջ
	cin >> ch;
	while (ch != '#' || (GetTop(OPTR) != '#')) {
		//���ʽû��ɨ����ɻ�����ջ��Ԫ�ز���"#"
		if (!In(ch)) {
			Push(OPND, ch);
			cin >> ch;
		}
		else {
			//�Ƚ������ջ��Ԫ�غͲ��������������ȼ�
			switch (Precede(GetTop(OPTR),ch)) {
				case '<':
					Push(OPTR, ch);
					cin >> ch;//��ǰ�ַ�chѹ��OPTRջ��������һ�ַ�ch
					break;
				case '>':
					Pop(OPTR, theta);//����OPTRջ���������
					//�������������
					Pop(OPND, b);
					Pop(OPND, a);
					//��������ѹ��OPND
					Push(OPND, Operate(a, theta, b));
				case '='://OPTR��ջ��Ԫ���ǡ�������ch�ǡ�����
					Pop(OPTR, x);
					cin >> ch;//����OPTRջ���ġ�����,������һ�ַ�ch
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
	cout << "0-9���ڵĶ���ʽ���㣺" << endl;
	cout << "1.����" << endl;
	cout << "0.�˳�\n" << endl;
	cout << "ѡ��";
	cin >> c;
	return c;
}

int main162217() {
	while (1) {
		switch (menu()) {
			case 1: {
				cout << "������Ҫ����ı��ʽ���������ͽ������0-9��Χ�ڣ���#��������" << endl;
				char res = EvaluateExpression();//���ʽ��ֵ
				cout << "��������" << res - 48 << endl << endl;
			}
					break;
			case 0:
				cout << "�˳��ɹ���\n";
				exit(0);
		}
	}
}