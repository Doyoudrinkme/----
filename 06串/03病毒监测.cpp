#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
typedef struct {
	char ch[600];//若是非空串，则按串唱分配存储区，否则ch为NULL
	int len;//串长度
}HString;

int Index_BF(HString S, HString T, int pos) {
	//返回模式T在主串S中第pos个字符开始第一次出现的位置，不存在则返回0
	//其中，T非空，1<=pos<=StrLength(S)
	int i, j;
	i = pos; j = 1;
	while (i <= S.len&&j <= T.len) {
		if (S.ch[i] == T.ch[j]) {//继续比较后继字符
			++i;
			++j;
		}
		else {//指针后退重新开始匹配
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.len)
		return i - T.len;
	else
		return 0;
}
void Virus_detection() {
	int num, m, flag, i, j;
	char Vir[600];
	HString Virus, Person, temp;
	ifstream inFile("病毒感染检测输入数据.txt");
	ofstream outFile("病毒感染检测输出结果.txt");
	inFile >> num;//读取待检测的任务数

	while (num--) {
		//依次检测每队病毒DNA和人的DNA是否匹配
		inFile >> Virus.ch + 1;//读取DNA序列
		inFile >> Person.ch + 1;//读取人的DNA序列
		strcpy_s(Vir, Virus.ch);
		Virus.len = strlen(Virus.ch) - 1;
		Person.len = strlen(Person.ch) - 1;
		flag = 0;//匹配非0；
		m = Virus.len;
		for (i = m + 1, j = 1; j <= m; j++)
			Virus.ch[i++]=Virus.ch[j];
		//因病毒为环状，故将病毒长度扩大2倍
		//即可线性取到所有长度为Virus.len的字符串
		Virus.ch[2 * m + 1] = '\0';//添加结束符号
		for (i = 0; i < m; i++) {
			for (j = 1; j <= m; j++)
				temp.ch[j] = Virus.ch[i + j];
			//取长为Vrius.len的环形字符串
			temp.ch[m + 1] = '\0';
			temp.len = strlen(temp.ch) - 1;
			flag = Index_BF(Person, temp, 1);//模式匹配
			if (flag)break;//匹配即可退出循环
		}
		if (flag)
			outFile << Vir + 1 << " " << Person.ch + 1 << " " << "YES" << endl;
		else {
			outFile << Vir + 1 << " " << Person.ch + 1 << " " << "NO" << endl;
		}
		
	}system("pause");
}
int main2017年1月5日142053() {
/*	while (1) {
		Virus_detection();
		system("pause");
	}*/
	Virus_detection();
	system("pause");
	return 0;
}