#include<iostream>
#include<fstream>
#include "��ջ����.h"

using namespace std;


int main2() {
	LinkStack s;
	int choose, flag = 0;
	SElemType j, t;
	cout << "1.��ջ\n";
	cout << "2.��ջ��Ԫ��\n";
	cout << "3.��ջ\n";
	cout << "0.t�˳�\n\n";
	choose = -1;
	if (InitStack(s)) {
		flag = 1;
		cout << "�ɹ���ջ���г�ʼ��\n\n";
	} else {
		cout << "��ʼ��ʧ�ܣ�\n\n";
	}
	while (choose != 0) {
		cout << "��ѡ��";
		cin >> choose;
		switch(choose) {
			case 1: {//��ջ��ջ
				fstream file;
				file.open("SqStack.txt");
				if (!file) {
					cout << "����δ�ҵ��ļ���\n\n" << endl;
					exit(ERROR);
				}
				if (flag) {
					flag = 1;
					cout << "��ջԪ�������ǣ�\n";
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
					cout << "ջδ������������ѡ��\n\n";
				file.close();
			}
				break;
			case 2: {//ȡջ��ջ��Ԫ��
				if (flag != -1 && flag != 0)
					cout << "ջ��Ԫ���ǣ�" << GetTop(s) << endl << endl;
				else
					cout << "ջ����Ԫ�أ�������ѡ��\n" << endl;
			}
				break;
			case 3://��ջ�ĳ�ջ
				if (flag) {
					cout << "���ε���ջ��Ԫ��Ϊ��\n";
					while (Pop(s, t))
						cout << t << "  ";
					cout << endl << endl;
				} else
					cout << "ջ����Ԫ�أ�������ѡ��\n" << endl;
				break;

		}
	}
	
	return 0;
}