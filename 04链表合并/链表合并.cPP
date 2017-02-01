#include<iostream>
#include<fstream>
#include<string>


using namespace std;
#define ERROR 0
typedef struct LNode {
	int data;//结点的数据域
	struct LNode *next;//结点的指针域
}LNode,*List;//List为指向结构体LNode的指针类型

int m, n;
char st = 'A';
void InitList(List &L) {//创建链表
	L = new LNode;
	L->next = NULL;
}
//链表数据的输入
void ListInput(List &L, int n) {
	List p, r;
	r = L;
	char filename[20] = { 0 };
	cout << "请输入顺序表L" << st << "的数据文件名称（文件名+“.txt”，如" << st << ".txt):" << endl;
	++st;
	gets_s(filename);
	//cout << "输入的文件名：" << filename << endl;
	fstream file;
	file.open(filename);
	if (!file) {
		cout << "未找到文件，无法打开！";
		exit(ERROR);
	}
	while (!file.eof()) {
		p = new LNode;
		file >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
		n++;
	}
	file.close();
}
bool LocateElem(List L, int e) {
	List p = L->next;
	while (p!=NULL) {
		if (p->data == e)
			return true;
		p = p->next;
	}
	return false;
}
//将e插入到List中
void ListInsert(List &L, int e) {
	List p = new LNode;
	p->data = e;
	p->next = L->next;
	L->next = p;
}
//将所有在线性表LB中但不在LA中的数据元素插入到LA中
void unionList(List &LA, List&LB) {
	int e;
	List p = LB->next;
	while (p!=NULL) {
		e = p->data;
		if (!LocateElem(LA, e))//LA中不存在和e相同的数据元素，插入
			ListInsert(LA, e);
		p = p->next;
	}
}
void ListOutput(List L) {
	List p = L->next;
	while (p!=NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int main() {
	List LA, LB;
	InitList(LA);	
	InitList(LB);

	ListInput(LA, n);	
    ListOutput(LA);

	ListInput(LB, m);	
	ListOutput(LB);

	unionList(LA, LB);

	cout << "LA和LB合并后的集合为：\n";
	ListOutput(LA);
	getchar();
	return 0;
}