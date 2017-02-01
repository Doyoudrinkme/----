#include<iostream>
#define FALSE 0
#define TRUE 1
#define OK 1
#define m 3  //B-树的阶，暂设为3
using namespace std;

typedef struct BTNode {
	int keynum;  //结点关键字的个数，即结点的大小
	BTNode *parent;  //指向双亲结点
	int key[m + 1];//关键字数量，0号单元未用
	BTNode *ptr[m + 1];//子树指针矢量
}BTNode,*BTree;

//B-树的查找结果类型定义
struct Result {
	BTNode *pt;//指向找到的结果
	int i;//1..m,在结点中的关键字序号
	int tag;//1,查找成功；0，查找失败
};

int Search(BTree T, int key) {
	BTree p = T;
	int endnum;
	if (p) {
		endnum = p->keynum;//获得首节点包含的记录个数
	} else
		return 0;//返回没找到
	//如果树存在，但是仅有一个为空根结点
	int i = 0;
	if (endnum == 0) {
		return i;
	}
	else if(key>=p->key[endnum]){
		//结点不为空，但是当前值比最大的key还大
		i = endnum;
		return i;
	}
	else if (key <= p->key[1]) {
		//结点不为空，但是当前值比最大的key还小
		return i;
	}
	else {
		for (i = 1; i < endnum; i++) {
			//有合适位置，即处于当前结点的最大和最小值之间，或找到了
			if (p->key[i] <= key&&key < p->key[i + 1])
				return i;
		}
	}
}
//将x插入q结点的i+1位置中
void Insert(BTree &q, int i, int x, BTree &ap) {
	int j;
	//将插入位置之后的key全部后移一位
	for (j = m - 1; j > i; j--)
		q->key[j + 1] = q->key[j];
	//相应移动气候ptr的位置
	for (j = m; j > i; j--)
		q->ptr[j] = q->ptr[j - 1];
	q->key[i + 1] = x;//插入x到该位置
	q->ptr[i + 1] = ap;
	q->keynum++;
}

void split(BTree &q, int s, BTree &ap) {
	/*
	将q->key[s+1,...,m],q->ptr[s+1,...,m]移入新结点*ap作为右结点
	原结点作为新的左侧结点
	中间值被保存在ap[0]->key中，等待找到跳转回InsertBTree()寻找到合适的插入位置*/
	int i;
	ap = new BTNode;
	for (i = s + 1; i <= m; i++) {
		//将q->key[s+1,...,m]保存到ap->key[0,...,m-s+1]中
		//将q->ptr[s+1,...,m]保存到ap->ptr[0,...,m-s+1]中
		ap->key[i - s - 1] = q->key[i];
		ap->ptr[i - s - 1] = q->ptr[i];
	}
	if (ap->ptr[0]) {//当ap有子树时
		//将ap子树的父亲改为自己
		for (i = 0; i <= 1; i++)
			ap->ptr[i]->parent = ap;
	}
	ap->keynum = (m - s) - 1;
	ap->parent = q->parent;//将ap的父节点改为q的父节点
	q->keynum = q->keynum - (m - s);//修改q的记录个数

}
//生成含有信息（T,x,ap)的新根节点*T，元T和ap为子树指针
void NewRoot(BTree &T, BTree q, int x, BTree &ap) {
	//新建一个结点作为新的根
	BTree newT = new BTNode;
	newT->key[1] = x;//写入新根的key[1]
	newT->ptr[0] = T;//将原来的树根作为新根的左子树
	newT->ptr[1] = ap;//ap作为新根的右子树
	newT->keynum = 1;
	newT->parent = NULL;//新根的父节点为空
	ap->parent = newT;//ap的父节点为新根
	T->parent = newT;//T的父节点为新根
	T = newT;//树改为新根引导的
}
//B-树插入
int InsertBTree(BTree &T, int K, BTree q, int i) {
	int x = K;
	BTree ap = NULL;
	int finished = FALSE;
	while (q && !finished) {
		//将x和ap分别插入到q->key[i+1]和q->ptr[i+1]
		Insert(q, i, x, ap);
		if (q->keynum < m)
			finished = true;//插入完成
		else {//分裂结点*q
			int s = m / 2;
			split(q, s, ap);
			x = ap->key[0];
			//将q->key[s+1,...,m],q->ptr[s,..m]和q->recptr[s+1...m]移入新结点*ap
			q = q->parent;
			if (q)//在双亲结点中查找x的插入位置
				i = Search(q, x);
		}
	}
	if (!finished)//T是空树或者根节点已经分裂为*q和*ap
		NewRoot(T, q, x, ap);
	//生成含有信息（T，x,ap)的新的根节点*T，原T和ap为子树指针
	return OK;
}
//B-树的查找
Result SearchBTree(BTree &T, int key) {
	/*
	查找关键字key,返回结果（pt,i,tag)
	若查找成功，特征值tag=1,指针pt所指节点中第i个关键字等于key
	否则，tag=0.等于key的关键字应插入在指针pt所指节点中第i和i+1个关键字之间*
	*/

	BTree p = T;
	BTree q = NULL;
	int found = NULL;
	int i = 0;//初始化，p指向待查结点，q指向p的双亲
	while (p && !found) {
		i = Search(p, key);
		/*在p->key[1...keynum]中查找i,使得
		p->key[i]<=key<p->key[i+1]*/
		if (i > 0 && p->key[i] == key)
			found = true;//找到待查关键字
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
//初始化一个空根
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
	//先用SearchBTree()找到要插入的位置，得到一个Resulit结构体
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