#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;
#define OK 1
#define ERROR 0
#define	OVERFLOW -2
typedef int Status;//�����������ͣ���ֵ�Ǻ������״̬����
typedef int ElemType;//�ɶ������������

string head_1, head_2, head_3;
int length;

struct Book {
	string id;
	string name;
	double price;
};
typedef struct DuLNode {
	Book data;  //������
	struct DuLNode *prior;//ֱ��ǰ��
	struct DuLNode *next;  //ֱ�Ӻ��
}DuLNode,*DuLinkList;

//����һ���յ�˫������L
Status InitDuList_L(DuLinkList &L) {
	L = new DuLNode;//�����½ڵ���Ϊͷ�ڵ㣬��ͷָ��Lָ��ͷ�ڵ�
	L->next = NULL;
	L->prior = NULL;
	return OK;
}
//�ڴ�ͷ����˫������L�в��ҵ�i��Ԫ�أ����ؽ��ĵ�ַ
DuLNode *GetElemP_DuL(DuLinkList L, int i) {
	int j = 1;//��ʼ��p,ָ���һ����㣬jΪ������
	DuLinkList p = L->next;
	//˳���������ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ��
	while (j < i&&p) {
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return NULL;//��i��Ԫ�ز�����
	return p;
}
//˫������Ĳ���
Status ListInsert_DuL(DuLinkList &L, int i, Book e) {
	DuLinkList s, p;
	if (!(p = GetElemP_DuL(L, i)))//L��ȷ����i��Ԫ�ص�λ��ָ��p
		return ERROR;
	if (i == 1) {
		s = new DuLNode;//�����½�� s
		s->data = e;//�����s������Ϊe
		DuLinkList p = L->next;
		L->next = s;
		s->prior = L;
		s->next = p;//�����*s����L��
		p->prior = s;
		++length;
	} else if (i == length) {
		//���һ��Ԫ���ϲ���
		s = new DuLNode;//�����½ڵ�
		s->data = e;//�����s������Ϊe
		DuLinkList p = L;
		while (p->next) {
			p = p->next;//��LinkList pָ��˫�������β
		}
		p->next = s;
		s->prior = p;//�����*s���뵽p���棬���뵽L��
		s->next = NULL;
		++length;
	} else {
		s = new DuLNode;//�����½��*s
		s->data = e;//�����*s��������Ϊe
		s->prior = p->prior;
		p->prior->next = s;
		s->next = p;
		p->prior = s;
		++length;
	}
	return OK;
}

//˫�������ɾ��
Status ListDelete_DuL(DuLinkList &L, int i) {
	//ɾ����ͷ����˫������L�е�i��λ��֮ǰ����Ԫ��e
	DuLinkList p;
	//��L��ȷ����i��Ԫ�ص�λ��ָ��p
	if (!(p = GetElemP_DuL(L, i)))
		return ERROR;
	//ɾ����һ��Ԫ��
	if (i == 1)
		L = L->next;
	//ɾ�����һ��Ԫ��
	else if (i == length) {
		p->prior->next = NULL;
		delete p;
		--length;
		return OK;
	} else {
		//�޸ı�ɾ������ǰ�����ĺ��ָ��
		p->prior->next = p->next;
		//�޸ı�ɾ���ĺ�̽���ǰ��ָ��
		p->next->prior = p->prior;
		--length;
		return OK;
	}
}

//��λ������n��Ԫ�أ���������ͷ����˫������L��ͬʱ����ǰ��ָ��
void CreateDuList_L(DuLinkList &L) {
	//��λ������n��Ԫ��ֵ����������ͷ��˫������L��ͬʱ����ǰ��ָ��
	DuLinkList r, p;
	L = new DuLNode;
	//�Ƚ���һ����ͷ���Ŀ�����
	L->next = NULL;
	r = L;//βָ��rָ��ͷ���
	length = 0;
	fstream file;
	file.open("book.txt");
	if (!file) {
		cout << "δ�ҵ�����ļ����޷��򿪣�" << endl;
		exit(ERROR);
	}
	file >> head_1 >> head_2 >> head_3;
	while (!file.eof()) {
		p = new DuLNode;//�����½��
		//����Ԫ��ֵ
		file >> p->data.id >> p->data.name >> p->data.price;
		p->next = NULL;
		r->next = p;//���뵽��β
		r = p;//rָ���µ�β���
		p->prior = L->prior;//���뵽��ͷ
		L->prior = p;
		length++;
	}
	file.close();

}
int main() {
	int a, choose;
	Book e;
	DuLinkList L, p;
	cout << "1.����\n";
	cout << "2.ɾ��\n";
	cout << "3.���\n";
	cout << "0.�˳�\n";

	if (InitDuList_L(L))
		cout << "�ɹ�����˫������\n\n";
	CreateDuList_L(L);
	cout << "����book.txt��Ϣ���\n\n";

	choose = -1;
	while (choose!=0) {
		cout << "��ѡ��";
		cin >> choose;
		switch (choose) {
			case 1://����
				cout << "�������������ֱ��������λ�ú���ֵ�������Ϣ�����&����&�۸�):";
				cin >> a;
				cin >> e.id >> e.name >> e.price;
				if (ListInsert_DuL(L, a, e))
					cout << "����ɹ�\n\n";
				else
					cout << "����ʧ��\n\n";
				break;
			case 2://˫����ɾ��
				cout << "������Ҫɾ�����鼮��λ�ã�";
				cin >> a;
				if (ListDelete_DuL(L, a))
					cout << "ɾ���ɹ���\n\n";
				else
					cout << "ɾ��ʧ�ܣ�\n\n";
				break;
			case 3://˫�������
				cout << "��ǰͼ��ϵͳ��Ϣ�����\n";
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