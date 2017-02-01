//�����������
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

typedef struct {
	int weight;
	int parent, lchild, rchild;
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;

void Select(HuffmanTree HT, int len, int &s1, int &s2) {
	int i, min1 =0x3f3f3f3f, min2 = 0x3f3f3f3f;//�ȸ������ֵ
	for (i = 1; i < len; i++) {//ѡ����СȨֵ
		if (HT[i].weight < min1&&HT[i].parent == 0) {
			min1 = HT[i].weight;
			s1 = i;
		}
	}
	//��ԭֵ�ݴ棬Ȼ���ȸ������ֵ����ֹs1���ظ�ѡ��
	int temp = HT[s1].weight;
	HT[s1].weight = 0x3f3f3f3f;//�ų��Ѿ�ѡ�е�s1��
	for (i = 1; i < len; i++) {
		if (HT[i].weight < min2&&HT[i].parent == 0) {
			min2 = HT[i].weight;
			s2 = i;
		}
	}
	HT[s1].weight = temp;
}
//�����������
void CreateHuffmanTree(HuffmanTree &HT, int n) {
	int m, s1, s2, i;
	if (n <= 1)
		return;
	m = 2 * n - 1;
	HT = new HTNode[m + 1];//0�ŵ�λδ�ã�������Ҫ��̬����m+1����Ԫ��HT[m]��ʾ���ڵ�
	for (i = 1; i <= m; ++i) {
		//��1-m�ŵ�Ԫ�е�˫�ס����ӣ��Һ��ӵ��±궼��ʼ��Ϊ0
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	cout << "������Ҷ�ӽ���Ȩֵ��\n";
	//����ǰn����Ԫ��Ҷ�ӽ���Ȩֵ
	for (i = 1; i < n; i++) {
		cin >> HT[i].weight;
	}
	//��ʼ����������ʼ������������

	for (i = n + 1; i <= m; i++) {
		//ͨ��n-1�ε�ѡ�� ɾ�����ϲ�������������
		Select(HT, i - 1, s1, s2);
		/*��HT[k](i<=k<=i-1)��ѡ������˫����Ϊ0��Ȩֵ��С�Ľ��
		������������HT�е����s1��s2
		*/
		HT[s1].parent = i;
		HT[s2].parent = i;
		//�õ��½��i,��ɭ����ɾ��s1,s2����s1��s2��˫����0��Ϊi
		HT[i].lchild = s1;
		HT[i].rchild = s2;//s1��s2�ֱ���Ϊ���i�����ҽ��
		HT[i].weight = HT[s1].weight + HT[s2].weight;//i��ȨֵΪ���Һ�ֽȨֵ֮��
	}
}
//��Ҷ�ӵ���������ÿ���ַ��Ļ��������룬�洢�ڱ����HC��
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n) {
	int i, start, c,f;
	HC = new char*[n + 1];  //����n���ַ������ͷָ��ʸ��
	char *cd = new char[n]; //������ʱ��ű���Ķ�̬����ռ�
	cd[n - 1] = '\n';       //���������
	for (i = 1; i <= n; i++) {
		start = n - 1;      //start��ʼʱָ����󣬼��������λ��
		c = i;
		f = HT[i].parent;   //fָ����c��˫�׽ڵ�
		while (f != 0) {    //��Ҷ�ӽ�㿪ʼ���ϻ��ݣ�ֱ�����ڵ�
			--start;        //����һ��start��ǰָһ��λ��
			if (HT[f].lchild == c)
				cd[start] = '0';   //���c��f�����ӣ������ɴ���0
			else
				cd[start] = '1';   //���c��f���Һ��ӣ������ɴ���1
			c = f;
			f = HT[f].parent;      //�������ϻ���
		}
		HC[i] = new char[n - start];//Ϊ��i���ַ��������ռ�  //������2017��1��10��15:46:22
		strcpy(HC[i], &cd[start]);  //����õı������ʱ�ռ�cd���Ƶ�HC�ĵ�����
	}
	delete cd;                       //�ͷ���ʱ�ռ�
}
void show(HuffmanTree HT, HuffmanCode HC) {
	for (int i = 1; i <= sizeof(HC) + 1; i++) {
		cout << HT[i].weight << "����Ϊ��" << HC[i] << endl;
	}
}
void main154658() {
	HuffmanTree HT;
	HuffmanCode HC;
	int n;
	cout << "������Ҷ�ӽ��ĸ�����\n";
	cin >> n;
	CreateHuffmanTree(HT, n);
	cout << "��������������ϣ�\n";
	CreateHuffmanCode(HT, HC, n);
	show(HT, HC);
	system("pause");
}