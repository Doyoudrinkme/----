//构造霍夫曼树
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

typedef struct {
	int weight;
	int parent, lchild, rchild;
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;

void Select(HuffmanTree HT, int len, int &s1, int &s2) {
	int i, min1 =0x3f3f3f3f, min2 = 0x3f3f3f3f;//先赋予最大值
	for (i = 1; i < len; i++) {//选择最小权值
		if (HT[i].weight < min1&&HT[i].parent == 0) {
			min1 = HT[i].weight;
			s1 = i;
		}
	}
	//将原值暂存，然后先赋予最大值，防止s1被重复选择
	int temp = HT[s1].weight;
	HT[s1].weight = 0x3f3f3f3f;//排除已经选中的s1点
	for (i = 1; i < len; i++) {
		if (HT[i].weight < min2&&HT[i].parent == 0) {
			min2 = HT[i].weight;
			s2 = i;
		}
	}
	HT[s1].weight = temp;
}
//构造霍夫曼树
void CreateHuffmanTree(HuffmanTree &HT, int n) {
	int m, s1, s2, i;
	if (n <= 1)
		return;
	m = 2 * n - 1;
	HT = new HTNode[m + 1];//0号单位未用，所以需要动态分配m+1个单元，HT[m]表示根节点
	for (i = 1; i <= m; ++i) {
		//将1-m号单元中的双亲、左孩子，右孩子的下标都初始化为0
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	cout << "请输入叶子结点的权值：\n";
	//输入前n个单元中叶子结点的权值
	for (i = 1; i < n; i++) {
		cin >> HT[i].weight;
	}
	//初始化结束，开始创建霍夫曼树

	for (i = n + 1; i <= m; i++) {
		//通过n-1次的选择、 删除、合并创建霍夫曼树
		Select(HT, i - 1, s1, s2);
		/*在HT[k](i<=k<=i-1)中选择两个双亲域为0且权值最小的结点
		并返回他们在HT中的序号s1和s2
		*/
		HT[s1].parent = i;
		HT[s2].parent = i;
		//得到新结点i,从森林中删除s1,s2，将s1和s2的双亲有0改为i
		HT[i].lchild = s1;
		HT[i].rchild = s2;//s1，s2分别作为结点i的左右结点
		HT[i].weight = HT[s1].weight + HT[s2].weight;//i的权值为左右孩纸权值之和
	}
}
//从叶子到根逆向求每个字符的霍夫曼编码，存储在编码表HC中
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n) {
	int i, start, c,f;
	HC = new char*[n + 1];  //分配n个字符编码的头指针矢量
	char *cd = new char[n]; //分配临时存放编码的动态数组空间
	cd[n - 1] = '\n';       //编码结束符
	for (i = 1; i <= n; i++) {
		start = n - 1;      //start开始时指向最后，即编码结束位置
		c = i;
		f = HT[i].parent;   //f指向结点c的双亲节点
		while (f != 0) {    //从叶子结点开始向上回溯，直到根节点
			--start;        //回溯一次start向前指一个位置
			if (HT[f].lchild == c)
				cd[start] = '0';   //结点c是f的左孩子，则生成代码0
			else
				cd[start] = '1';   //结点c是f的右孩子，则生成代码1
			c = f;
			f = HT[f].parent;      //继续向上回溯
		}
		HC[i] = new char[n - start];//为第i个字符编码分配空间  //有问题2017年1月10日15:46:22
		strcpy(HC[i], &cd[start]);  //将求得的编码从临时空间cd复制到HC的当行中
	}
	delete cd;                       //释放临时空间
}
void show(HuffmanTree HT, HuffmanCode HC) {
	for (int i = 1; i <= sizeof(HC) + 1; i++) {
		cout << HT[i].weight << "编码为：" << HC[i] << endl;
	}
}
void main154658() {
	HuffmanTree HT;
	HuffmanCode HC;
	int n;
	cout << "请输入叶子结点的个数：\n";
	cin >> n;
	CreateHuffmanTree(HT, n);
	cout << "霍夫曼树建立完毕！\n";
	CreateHuffmanCode(HT, HC, n);
	show(HT, HC);
	system("pause");
}