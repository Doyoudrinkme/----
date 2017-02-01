#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include "״̬��.h"

using namespace std;

struct Book {
	string id;
	string name;
	double price;
 };
typedef struct LNode {
	Book data;//�ڵ��������
	struct LNode *next;//�ڵ��ָ����
}LNode,*LinkList;//LinkListΪָ��ṹ��LNode��ָ������
string head_1, head_2, head_3;
int length;

//�����ʼ��
Status InitList_L(LinkList &L) {
	//��������������L
	L = new LNode;//�����½ڵ���Ϊͷ�ڵ㣬��ͷָ��Lָ��ͷ�ڵ�
	L->next = NULL;//ͷ�ڵ�ָ�����ÿ�
	return OK;
}

//������ȡֵ
Status GetElem_L(LinkList L, int i, Book &e) {
	//�ڴ�ͷ�ڵ�ĵ�����L�в��ҵ�i��Ԫ��
	//��e����L�е�i������Ԫ�ص�ֵ
	LinkList p = L->next;
	int j=1;//��ʼ����pָ���һ���ڵ㣬jΪ������
	
	while (j < i&&p) {//˳�������ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ��
		p = p->next;
		++j;//������j��Ӧ��1
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;//��ȡ��i���ڵ��������
	return OK;
}
//��ֵ����
LNode *LocateElem_L(LinkList L, int e) {
	//�ڴ�ͷ�ڵ�ĵ�����L�в���ֵΪe��Ԫ��
	LinkList p = L->next;
	//˳�������ɨ�裬ֱ��pΪ�ջ�p��ָ�ڵ������
	while (p&&p->data.price != e) {
		p = p->next;//pָ����һ���ڵ�
	}
	return p;//���ҳɹ�����ֵΪe�Ľڵ��ַp�����򷵻�NULL
}

//���������
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
	s = new LNode;//�����½ڵ�*s;
	s->data = e;//�����*s����������Ϊe
	s->next = p->next;//�����*s��ָ����ָ����
	p->next = s;//�����*p��ָ����ָ����*s
	++length;
	return OK;
}

//������ɾ��
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
	q = p->next;//��ʱ���汻ɾ�����ĵ�ַ�Ա�ɾ��
	p->next = q->next;//�ı�ɾ�����ǰ������ָ����  q->next=  p->next->next
	delete q;//�ͷ�ɾ�����Ŀռ�
	--length;
	return OK;

}

//ǰ�巨��������
void CreateList_H(LinkList &L, int n) {
	//����λ����n��Ԫ�ص�ֵ��������ͷ�ڵ�ĵ�����L
	LinkList p;
	L = new LNode;
	L->next = NULL;//������ͷ�ڵ�Ŀ�����
	length = 0;
	fstream file;
	file.open("book.txt");
	if (!file) {
		cout << "δ�ҵ�����ļ����޷��򿪣�" << endl;
		exit(ERROR);
	}
	file >> head_1 >> head_2 >> head_3;
	while (!file.eof()) {
		p = new LNode;//�����½��
		file >> p->data.id >> p->data.name >> p->data.price;
		p->next = L->next;
		//���½ڵ���뵽ͷ�ڵ�֮��
		L->next = p;
		//����������1
		length++;
	}
	file.close();
}
//��巨��������
void CreateList_R(LinkList &L, int n) {
	//����λ����n��ֵ����������ͷ���ĵ�����L
	LinkList p, r;
	L = new LNode;
	L->next = NULL;//������ͷ�ڵ�Ŀ�����
	r = L;//βָ��rָ��ͷ�ڵ�
	length = 0;
	fstream file;//���ļ����ж�д����
	file.open("book.txt");
	if (!file) {
		cout << "δ�ҵ�����ļ����޷��򿪣�" << endl;
		exit(ERROR);
	}
	file >> head_1 >> head_2 >> head_3;
	while (!file.eof()) {
		p = new LNode;//�����½ڵ�
		//����Ԫ�ظ����½ڵ�
		file >> p->data.id >> p->data.name >> p->data.price;
		p->next = NULL;
		r->next = p;//���½ڵ�*p����β���*r֮��
		r = p;//rָ���µ�β���*p
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
	cout << "1. ȡֵ\n";
	cout << "2. ����\n";
	cout << "3. ����\n";
	cout << "4. ɾ��\n";
	cout << "5. ���\n";
	cout << "0. �˳�\n\n";

	//����������
	if (InitList_L(L))
		cout << "�ɹ���������\n\n";
	//ʹ�ú�巨����
	CreateList_R(L, length);
	cout << "����book.txt��Ϣ���\n\n";
	/*if (CreateList_R(L, length)) {
		cout << "����book.txt��Ϣ���\n\n";
	}*/
	choose = -1;
	while (choose != 0) {
		cout << "��ѡ�������";
		cin >> choose;
		switch(choose){
			case 1://�����ȡֵ
				cout << "����ȡֵ��ţ�";
				cin >> a;
				if (GetElem_L(L, a, e)) {
					cout << "���ҳɹ�\n";
					cout << "��" << a << " ��ͼ�����Ϣ��\n";
					cout << left << setw(15) << e.id << "\t" << left << setw(50)
						<< e.name << "\t" << left << setw(5) << e.price << endl ;
				} else
					cout << "����ʧ�ܣ�\n";
				break;
			case 2://��ֵ����
				cout << "��������Ҫ���ҵļ۸�\n";
				cin >> price;
				if (LocateElem_L(L, price) != NULL) {
					cout << "���ҳɹ�\n";
					cout << "��Ӧ��Ϣ" << LocateElem_L(L, price)->data.name <<endl;
				} else {
					cout << "����ʧ�ܣ����� " << price << " û���ҵ�\n\n";
				}
				break;
			case 3://������Ĳ���
				cout << "����������λ�ú��鼮��Ϣ����������� ���� �۸񣨿ո�ֿ�����";
				cin >> a;
				cin >> e.id >> e.name >> e.price;
				if (ListInsert_L(L, a, e))
					cout << "����ɹ�\n\n";
				else
					cout << "����ʧ��\n\n";
				break;
			case 4://�������ɾ��
				cout << "������ɾ����λ�ã�";
				cin >> a;
				if (ListDelete_L(L, a))
					cout << "ɾ���ɹ�\n\n";
				else
					cout << "ɾ��ʧ��\n\n";
				break;
			case 5://���������
				cout << "��ǰͼ����Ϣ�����\n\n";
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