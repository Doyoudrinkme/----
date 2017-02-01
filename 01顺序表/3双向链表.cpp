#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;
#define OK 1
#define ERROR 0
#define	OVERFLOW -2
typedef int Status;//函数返回类型，其值是函数结果状态代码
typedef int ElemType;//可定义的数据类型

string head_1, head_2, head_3;
int length;

struct Book {
	string id;
	string name;
	double price;
};
typedef struct DuLNode {
	Book data;  //数据域
	struct DuLNode *prior;//直接前驱
	struct DuLNode *next;  //直接后继
}DuLNode,*DuLinkList;

//构造一个空的双向链表L
Status InitDuList_L(DuLinkList &L) {
	L = new DuLNode;//生成新节点作为头节点，用头指针L指向头节点
	L->next = NULL;
	L->prior = NULL;
	return OK;
}
//在带头结点的双向链表L中查找第i个元素，返回结点的地址
DuLNode *GetElemP_DuL(DuLinkList L, int i) {
	int j = 1;//初始化p,指向第一个结点，j为计数器
	DuLinkList p = L->next;
	//顺序链表向后扫描，直到p指向第i个元素或p为空
	while (j < i&&p) {
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return NULL;//第i个元素不存在
	return p;
}
//双向链表的插入
Status ListInsert_DuL(DuLinkList &L, int i, Book e) {
	DuLinkList s, p;
	if (!(p = GetElemP_DuL(L, i)))//L中确定第i个元素的位置指针p
		return ERROR;
	if (i == 1) {
		s = new DuLNode;//生成新结点 s
		s->data = e;//将结点s数据置为e
		DuLinkList p = L->next;
		L->next = s;
		s->prior = L;
		s->next = p;//将结点*s插入L中
		p->prior = s;
		++length;
	} else if (i == length) {
		//最后一个元素上插入
		s = new DuLNode;//生成新节点
		s->data = e;//将结点s数据置为e
		DuLinkList p = L;
		while (p->next) {
			p = p->next;//将LinkList p指向双向链表结尾
		}
		p->next = s;
		s->prior = p;//将结点*s插入到p后面，插入到L中
		s->next = NULL;
		++length;
	} else {
		s = new DuLNode;//生成新结点*s
		s->data = e;//将结点*s数据域置为e
		s->prior = p->prior;
		p->prior->next = s;
		s->next = p;
		p->prior = s;
		++length;
	}
	return OK;
}

//双向链表的删除
Status ListDelete_DuL(DuLinkList &L, int i) {
	//删除带头结点的双向链表L中第i个位置之前插入元素e
	DuLinkList p;
	//在L中确定第i个元素的位置指针p
	if (!(p = GetElemP_DuL(L, i)))
		return ERROR;
	//删除第一个元素
	if (i == 1)
		L = L->next;
	//删除最后一个元素
	else if (i == length) {
		p->prior->next = NULL;
		delete p;
		--length;
		return OK;
	} else {
		//修改被删除结点的前驱结点的后继指针
		p->prior->next = p->next;
		//修改被删结点的后继结点的前驱指针
		p->next->prior = p->prior;
		--length;
		return OK;
	}
}

//正位序输入n个元素，建立带表头结点的双向链表L，同时建立前驱指针
void CreateDuList_L(DuLinkList &L) {
	//正位序输入n个元素值，建立带表头的双向链表L，同时建立前驱指针
	DuLinkList r, p;
	L = new DuLNode;
	//先建立一个带头结点的空链表
	L->next = NULL;
	r = L;//尾指针r指向头结点
	length = 0;
	fstream file;
	file.open("book.txt");
	if (!file) {
		cout << "未找到相关文件，无法打开！" << endl;
		exit(ERROR);
	}
	file >> head_1 >> head_2 >> head_3;
	while (!file.eof()) {
		p = new DuLNode;//生成新结点
		//输入元素值
		file >> p->data.id >> p->data.name >> p->data.price;
		p->next = NULL;
		r->next = p;//插入到表尾
		r = p;//r指向新的尾结点
		p->prior = L->prior;//插入到表头
		L->prior = p;
		length++;
	}
	file.close();

}
int main() {
	int a, choose;
	Book e;
	DuLinkList L, p;
	cout << "1.插入\n";
	cout << "2.删除\n";
	cout << "3.输出\n";
	cout << "0.退出\n";

	if (InitDuList_L(L))
		cout << "成功建立双向链表！\n\n";
	CreateDuList_L(L);
	cout << "输入book.txt信息完毕\n\n";

	choose = -1;
	while (choose!=0) {
		cout << "请选择：";
		cin >> choose;
		switch (choose) {
			case 1://插入
				cout << "请输入两个数分别代表插入的位置和数值（书的信息：编号&书名&价格):";
				cin >> a;
				cin >> e.id >> e.name >> e.price;
				if (ListInsert_DuL(L, a, e))
					cout << "插入成功\n\n";
				else
					cout << "插入失败\n\n";
				break;
			case 2://双向表的删除
				cout << "请输入要删除的书籍的位置：";
				cin >> a;
				if (ListDelete_DuL(L, a))
					cout << "删除成功！\n\n";
				else
					cout << "删除失败！\n\n";
				break;
			case 3://双向表的输出
				cout << "当前图书系统信息输出：\n";
				p = L->next;
				while (p) {
					cout
						<< left << setw(15) << p->data.id << "\t"
						<< left << setw(50) << p->data.name << "\t"
						<< left << setw(5) << p->data.price << endl;
					p = p->next;
				}
				cout << endl;
				break;
		}
	}
}