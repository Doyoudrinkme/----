#include<iostream>
#define FALSE 0
#define TRUE 1
#define OK 1
#define m 3  //B-���Ľף�����Ϊ3
using namespace std;

typedef struct BTNode {
	int keynum;  //���ؼ��ֵĸ����������Ĵ�С
	BTNode *parent;  //ָ��˫�׽��
	int key[m + 1];//�ؼ���������0�ŵ�Ԫδ��
	BTNode *ptr[m + 1];//����ָ��ʸ��
}BTNode,*BTree;

//B-���Ĳ��ҽ�����Ͷ���
struct Result {
	BTNode *pt;//ָ���ҵ��Ľ��
	int i;//1..m,�ڽ���еĹؼ������
	int tag;//1,���ҳɹ���0������ʧ��
};

int Search(BTree T, int key) {
	BTree p = T;
	int endnum;
	if (p) {
		endnum = p->keynum;//����׽ڵ�����ļ�¼����
	} else
		return 0;//����û�ҵ�
	//��������ڣ����ǽ���һ��Ϊ�ո����
	int i = 0;
	if (endnum == 0) {
		return i;
	}
	else if(key>=p->key[endnum]){
		//��㲻Ϊ�գ����ǵ�ǰֵ������key����
		i = endnum;
		return i;
	}
	else if (key <= p->key[1]) {
		//��㲻Ϊ�գ����ǵ�ǰֵ������key��С
		return i;
	}
	else {
		for (i = 1; i < endnum; i++) {
			//�к���λ�ã������ڵ�ǰ����������Сֵ֮�䣬���ҵ���
			if (p->key[i] <= key&&key < p->key[i + 1])
				return i;
		}
	}
}
//��x����q����i+1λ����
void Insert(BTree &q, int i, int x, BTree &ap) {
	int j;
	//������λ��֮���keyȫ������һλ
	for (j = m - 1; j > i; j--)
		q->key[j + 1] = q->key[j];
	//��Ӧ�ƶ�����ptr��λ��
	for (j = m; j > i; j--)
		q->ptr[j] = q->ptr[j - 1];
	q->key[i + 1] = x;//����x����λ��
	q->ptr[i + 1] = ap;
	q->keynum++;
}

void split(BTree &q, int s, BTree &ap) {
	/*
	��q->key[s+1,...,m],q->ptr[s+1,...,m]�����½��*ap��Ϊ�ҽ��
	ԭ�����Ϊ�µ������
	�м�ֵ��������ap[0]->key�У��ȴ��ҵ���ת��InsertBTree()Ѱ�ҵ����ʵĲ���λ��*/
	int i;
	ap = new BTNode;
	for (i = s + 1; i <= m; i++) {
		//��q->key[s+1,...,m]���浽ap->key[0,...,m-s+1]��
		//��q->ptr[s+1,...,m]���浽ap->ptr[0,...,m-s+1]��
		ap->key[i - s - 1] = q->key[i];
		ap->ptr[i - s - 1] = q->ptr[i];
	}
	if (ap->ptr[0]) {//��ap������ʱ
		//��ap�����ĸ��׸�Ϊ�Լ�
		for (i = 0; i <= 1; i++)
			ap->ptr[i]->parent = ap;
	}
	ap->keynum = (m - s) - 1;
	ap->parent = q->parent;//��ap�ĸ��ڵ��Ϊq�ĸ��ڵ�
	q->keynum = q->keynum - (m - s);//�޸�q�ļ�¼����

}
//���ɺ�����Ϣ��T,x,ap)���¸��ڵ�*T��ԪT��apΪ����ָ��
void NewRoot(BTree &T, BTree q, int x, BTree &ap) {
	//�½�һ�������Ϊ�µĸ�
	BTree newT = new BTNode;
	newT->key[1] = x;//д���¸���key[1]
	newT->ptr[0] = T;//��ԭ����������Ϊ�¸���������
	newT->ptr[1] = ap;//ap��Ϊ�¸���������
	newT->keynum = 1;
	newT->parent = NULL;//�¸��ĸ��ڵ�Ϊ��
	ap->parent = newT;//ap�ĸ��ڵ�Ϊ�¸�
	T->parent = newT;//T�ĸ��ڵ�Ϊ�¸�
	T = newT;//����Ϊ�¸�������
}
//B-������
int InsertBTree(BTree &T, int K, BTree q, int i) {
	int x = K;
	BTree ap = NULL;
	int finished = FALSE;
	while (q && !finished) {
		//��x��ap�ֱ���뵽q->key[i+1]��q->ptr[i+1]
		Insert(q, i, x, ap);
		if (q->keynum < m)
			finished = true;//�������
		else {//���ѽ��*q
			int s = m / 2;
			split(q, s, ap);
			x = ap->key[0];
			//��q->key[s+1,...,m],q->ptr[s,..m]��q->recptr[s+1...m]�����½��*ap
			q = q->parent;
			if (q)//��˫�׽���в���x�Ĳ���λ��
				i = Search(q, x);
		}
	}
	if (!finished)//T�ǿ������߸��ڵ��Ѿ�����Ϊ*q��*ap
		NewRoot(T, q, x, ap);
	//���ɺ�����Ϣ��T��x,ap)���µĸ��ڵ�*T��ԭT��apΪ����ָ��
	return OK;
}
//B-���Ĳ���
Result SearchBTree(BTree &T, int key) {
	/*
	���ҹؼ���key,���ؽ����pt,i,tag)
	�����ҳɹ�������ֵtag=1,ָ��pt��ָ�ڵ��е�i���ؼ��ֵ���key
	����tag=0.����key�Ĺؼ���Ӧ������ָ��pt��ָ�ڵ��е�i��i+1���ؼ���֮��*
	*/

	BTree p = T;
	BTree q = NULL;
	int found = NULL;
	int i = 0;//��ʼ����pָ������㣬qָ��p��˫��
	while (p && !found) {
		i = Search(p, key);
		/*��p->key[1...keynum]�в���i,ʹ��
		p->key[i]<=key<p->key[i+1]*/
		if (i > 0 && p->key[i] == key)
			found = true;//�ҵ�����ؼ���
		else {
			q = p;
			p = p->ptr[i];
		}
	}
	Result result;
	if (found) {
		result.pt = p;
		result.i = i;
		result.tag = 1;
		return result;
	} else {
		result.pt = q;
		result.i = i;
		result.tag = 0;
		return result;
	}
}
//��ʼ��һ���ո�
void InitialTree(BTree &T) {
	T->keynum = 0;
	T->parent = NULL;
	for (int i = 0; i < m; i++) {
		T->ptr[i] = NULL;
	}
}
void main() {
	BTree T = new BTNode;
	InitialTree(T);
	//����SearchBTree()�ҵ�Ҫ�����λ�ã��õ�һ��Resulit�ṹ��
	Result result;
	int a[11] = { 45,24,53,90,3,12,50,61,70,100 };
	for (int i = 0; i < 10; i++) {
		result = SearchBTree(T, a[i]);
		if (result.tag == 0) {
			InsertBTree(T, a[i], result.pt, result.i);
		}
	}
	cout << "OK" << endl;
	system("pause");
}