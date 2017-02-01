#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include "状态符.h"

using namespace std;

struct Book {
	string id;
	string name;
	double price;
 };
typedef struct LNode {
	Book data;//节点的数据域
	struct LNode *next;//节点的指针域
}LNode,*LinkList;//LinkList为指向结构体LNode的指针类型
string head_1, head_2, head_3;
int length;

//链表初始化
Status InitList_L(LinkList &L) {
	//构建空链单链表L
	L = new LNode;//生成新节点作为头节点，用头指针L指向头节点
	L->next = NULL;//头节点指针域置空
	return OK;
}

//单链表取值
Status GetElem_L(LinkList L, int i, Book &e) {
	//在带头节点的单链表L中查找第i个元素
	//用e返回L中第i个数据元素的值
	LinkList p = L->next;
	int j=1;//初始化，p指向第一个节点，j为计数器
	
	while (j < i&&p) {//顺链域向后扫描，直到p指向第i个元素或p为空
		p = p->next;
		++j;//计数器j相应加1
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;//获取第i个节点的数据域
	return OK;
}
//按值查找
LNode *LocateElem_L(LinkList L, int e) {
	//在带头节点的单链表L中查找值为e的元素
	LinkList p = L->next;
	//顺链域向后扫描，直到p为空或p所指节点的数据
	while (p&&p->data.price != e) {
		p = p->next;//p指向下一个节点
	}
	return p;//查找成功返回值为e的节点地址p，否则返回NULL
}

//单链表插入
Status ListInsert_L(LinkList &L, int i, Book e) {
	int j = 0;
	LinkList p, s;
	p = L;
	while(p&&j < i - 1) {
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;
	s = new LNode;//生成新节点*s;
	s->data = e;//将结点*s的数据域置为e
	s->next = p->next;//将结点*s的指针域指向结点
	p->next = s;//将结点*p的指针域指向结点*s
	++length;
	return OK;
}

//单链表删除
Status ListDelete_L(LinkList &L, int i) {
	LinkList p, q;
	p = L;
	int j = 0;
	while ((p->next) && (j < i - 1)) {
		p=p->next;
		++j;
	}
	if (!(p->next) || j > i - 1) {
		return ERROR;
	}
	q = p->next;//临时保存被删除结点的地址以备删除
	p->next = q->next;//改变删除结点前驱结点的指针域  q->next=  p->next->next
	delete q;//释放删除结点的空间
	--length;
	return OK;

}

//前插法创建链表
void CreateList_H(LinkList &L, int n) {
	//逆序位输入n个元素的值，建立到头节点的单链表L
	LinkList p;
	L = new LNode;
	L->next = NULL;//建立带头节点的空链表
	length = 0;
	fstream file;
	file.open("book.txt");
	if (!file) {
		cout << "未找到相关文件，无法打开！" << endl;
		exit(ERROR);
	}
	file >> head_1 >> head_2 >> head_3;
	while (!file.eof()) {
		p = new LNode;//生成新结点
		file >> p->data.id >> p->data.name >> p->data.price;
		p->next = L->next;
		//将新节点插入到头节点之后
		L->next = p;
		//链表长度增加1
		length++;
	}
	file.close();
}
//后插法创建链表
void CreateList_R(LinkList &L, int n) {
	//正序位输入n个值，建立带表头结点的单链表L
	LinkList p, r;
	L = new LNode;
	L->next = NULL;//建立带头节点的空链表
	r = L;//尾指针r指向头节点
	length = 0;
	fstream file;//打开文件进行读写操作
	file.open("book.txt");
	if (!file) {
		cout << "未找到相关文件，无法打开！" << endl;
		exit(ERROR);
	}
	file >> head_1 >> head_2 >> head_3;
	while (!file.eof()) {
		p = new LNode;//生成新节点
		//输入元素赋给新节点
		file >> p->data.id >> p->data.name >> p->data.price;
		p->next = NULL;
		r->next = p;//将新节点*p插入尾结点*r之后
		r = p;//r指向新的尾结点*p
		length++;
	}
	file.close();
}
int main1() {
	int  a, c, choose;
	double price;
	Book e;
	string head_1, head_2, head_3;
	LinkList L, p;
	cout << "1. 取值\n";
	cout << "2. 查找\n";
	cout << "3. 插入\n";
	cout << "4. 删除\n";
	cout << "5. 输出\n";
	cout << "0. 退出\n\n";

	//建立单链表
	if (InitList_L(L))
		cout << "成功建立链表\n\n";
	//使用后插法创建
	CreateList_R(L, length);
	cout << "输入book.txt信息完毕\n\n";
	/*if (CreateList_R(L, length)) {
		cout << "输入book.txt信息完毕\n\n";
	}*/
	choose = -1;
	while (choose != 0) {
		cout << "请选择操作：";
		cin >> choose;
		switch(choose){
			case 1://按序号取值
				cout << "输入取值序号：";
				cin >> a;
				if (GetElem_L(L, a, e)) {
					cout << "查找成功\n";
					cout << "第" << a << " 本图书的信息：\n";
					cout << left << setw(15) << e.id << "\t" << left << setw(50)
						<< e.name << "\t" << left << setw(5) << e.price << endl ;
				} else
					cout << "查找失败！\n";
				break;
			case 2://按值查找
				cout << "请输入所要查找的价格：\n";
				cin >> price;
				if (LocateElem_L(L, price) != NULL) {
					cout << "查找成功\n";
					cout << "对应信息" << LocateElem_L(L, price)->data.name <<endl;
				} else {
					cout << "查找失败！定价 " << price << " 没有找到\n\n";
				}
				break;
			case 3://单链表的插入
				cout << "请输入插入的位置和书籍信息，包括：编号 书名 价格（空格分开）：";
				cin >> a;
				cin >> e.id >> e.name >> e.price;
				if (ListInsert_L(L, a, e))
					cout << "插入成功\n\n";
				else
					cout << "插入失败\n\n";
				break;
			case 4://单链表的删除
				cout << "请输入删除的位置：";
				cin >> a;
				if (ListDelete_L(L, a))
					cout << "删除成功\n\n";
				else
					cout << "删除失败\n\n";
				break;
			case 5://单链表输出
				cout << "当前图书信息输出：\n\n";
				p = L->next;
				while (p) {
					cout << left << setw(15) << p->data.id << "\t" << 
						    left << setw(50)<< p->data.name << "\t" <<
						    left << setw(5) << p->data.price << endl;
					p=p->next;
				}
				cout << endl;
				break;		
		}
	     
	}
	//getchar();
	system("pasue");
	return 0;
}