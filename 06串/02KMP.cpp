#include <cstring>
#include<iostream>
#include "自定义宏.h"
using namespace std;

Status StrAssign(SString T, char *chars) {
	int i;
	if (strlen(chars) > MAXSTERLEN)
		return ERROR;
	else {
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return OK;
	}
}

//计算next函数值
void get_next(SString T, int next[]) {
	//求模式串T的next函数值并存入next数组
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T[0]) {
		if (j == 0 || T[i] == T[j]) {//比较匹配串 相邻两个元素是否一致
			++i;
			++j;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}

//计算next函数修正值
void get_nextval(SString T, int nextval[]) {
	//求模式串T的next函数修正值并存入数组nextval
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i<T[0]) {
		if (j == 0 || T[i] == T[j]) {
			++i;
			++j;
			if (T[i] != T[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else {
			j = nextval[j];
		}
	}
}
//KMP算法

int Index_KMP(SString S, SString T, int pos, int next[]) {
	//利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法
	//其中，T非空，i<=pos<=StrLength(S)
	int i = pos, j = 1;
	while (i <= S[0] && j <= T[0]) {
		if (j == 0 || S[i] == T[j]) {//继续比较后继字符
			++i;
			++j;
		} 
		else
			j = next[j];//模式串向右移动
	}
	if (j > T[0])//匹配成功
		return i - T[0];
	else
		return 0;
}

int main2016年12月10日200842() {
	SString S;
	StrAssign(S, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaba");
	SString T;
	StrAssign(T, "abb");
	int *p = new int[T[0] + 1];//生成T的next数组
	//get_next(T, p);
	get_nextval(T, p);
	cout << "主串和子串在第 " << Index_KMP(S, T, 1, p) << " 个字符处首次匹配\n";
	system("pause");
	return 0;
}