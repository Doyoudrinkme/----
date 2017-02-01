#include<iostream>

using namespace std;
#define MAXSIZE 100000000
#define OK 1

typedef struct {
	int key;//关键字域
}ElemType;

typedef struct {
	ElemType *R;
	int length;
}SSTable;

int InitList_SSTable(SSTable & L) {
	L.R = new ElemType[MAXSIZE];
	if (!L.R) {
		cout << "初始化错误！\n";
		return 0;
	}
	L.length = 0;
	return OK;
}
int Insert_SSTable(SSTable &L) {
	int j = 0;
	for (int i = 0; i < MAXSIZE; i++) {
		L.R[i].key = j;
	//	cout<< L.R[i].key << " ";
		L.length++;
		j++;
	}
	return 1;
}
//在顺序表ST中顺序查找关键字等于key的数据元素
int Search_Seq(SSTable ST, int key) {
	for (int i = ST.length; i >= 1; --i) {
		if (ST.R[i].key == key)
			return i;
	}
	return 0;
}
int Search_Seq2(SSTable ST, int key) {
	ST.R[0].key = key;
	int i;
	for ( i = ST.length; ST.R[i].key != key; --i);//从后往前找
	return i;
}
//折半查找有序序列
int Search_Bin(SSTable ST, int key) {
	int low = 1, high = ST.length;//查找区间初值
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (key == ST.R[mid].key)
			return mid;
		else if (key < ST.R[mid].key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}
void Show_End(int result, int testkey) {
	if (result == 0)
		cout << "\n未找到" << testkey << endl;
	else
		cout << "\n找到" << testkey << "位置为：" << result << endl;
	return;
}
void main2017年1月16日154256() {
	SSTable ST;
	InitList_SSTable(ST);
	Insert_SSTable(ST);

	int testkey1 = 197, testkey2 = 2000;
	int result = Search_Seq2(ST, testkey1);
	Show_End(result, testkey1);

	result = Search_Seq2(ST, testkey2);
	Show_End(result, testkey2);


	result = Search_Bin(ST, testkey1);
	Show_End(result, testkey1);

	result = Search_Bin(ST, testkey2);
	Show_End(result, testkey2);

	system("pause");
}