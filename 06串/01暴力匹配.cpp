#include <cstring>
#include<iostream>
#include "自定义宏.h"

using namespace std;


//BF算法
int Index(SString S, SString T, int pos) {
	//返回模式T在主串中第pos个字符之后第s一次出现的位置，若不存在，则返回值为0
	//其中，T非空，i<=pos<=StrLength(s)
	int i = pos;
	int j = 1;
	while (i <= S[0] && j <= T[0]) {
		if (S[i] == T[j]) {//继续比较后继字符
			++i;
			++j;
		}
		else {//指针后退重新开始匹配
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
	return 0;
}
int main2016年12月9日22() {
	SString S;
	StrAssign(S, "bbaaabbaba");
	SString T;
	StrAssign(T, "abb");
	cout << "主串和子串在第 " << Index(S, T, 1) << " 个字符处首次匹配\n";
	return 0;
}