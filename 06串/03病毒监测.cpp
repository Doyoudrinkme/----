#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
typedef struct {
	char ch[600];//���Ƿǿմ����򰴴�������洢��������chΪNULL
	int len;//������
}HString;

int Index_BF(HString S, HString T, int pos) {
	//����ģʽT������S�е�pos���ַ���ʼ��һ�γ��ֵ�λ�ã��������򷵻�0
	//���У�T�ǿգ�1<=pos<=StrLength(S)
	int i, j;
	i = pos; j = 1;
	while (i <= S.len&&j <= T.len) {
		if (S.ch[i] == T.ch[j]) {//�����ȽϺ���ַ�
			++i;
			++j;
		}
		else {//ָ��������¿�ʼƥ��
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.len)
		return i - T.len;
	else
		return 0;
}
void Virus_detection() {
	int num, m, flag, i, j;
	char Vir[600];
	HString Virus, Person, temp;
	ifstream inFile("������Ⱦ�����������.txt");
	ofstream outFile("������Ⱦ���������.txt");
	inFile >> num;//��ȡ������������

	while (num--) {
		//���μ��ÿ�Ӳ���DNA���˵�DNA�Ƿ�ƥ��
		inFile >> Virus.ch + 1;//��ȡDNA����
		inFile >> Person.ch + 1;//��ȡ�˵�DNA����
		strcpy_s(Vir, Virus.ch);
		Virus.len = strlen(Virus.ch) - 1;
		Person.len = strlen(Person.ch) - 1;
		flag = 0;//ƥ���0��
		m = Virus.len;
		for (i = m + 1, j = 1; j <= m; j++)
			Virus.ch[i++]=Virus.ch[j];
		//�򲡶�Ϊ��״���ʽ�������������2��
		//��������ȡ�����г���ΪVirus.len���ַ���
		Virus.ch[2 * m + 1] = '\0';//��ӽ�������
		for (i = 0; i < m; i++) {
			for (j = 1; j <= m; j++)
				temp.ch[j] = Virus.ch[i + j];
			//ȡ��ΪVrius.len�Ļ����ַ���
			temp.ch[m + 1] = '\0';
			temp.len = strlen(temp.ch) - 1;
			flag = Index_BF(Person, temp, 1);//ģʽƥ��
			if (flag)break;//ƥ�伴���˳�ѭ��
		}
		if (flag)
			outFile << Vir + 1 << " " << Person.ch + 1 << " " << "YES" << endl;
		else {
			outFile << Vir + 1 << " " << Person.ch + 1 << " " << "NO" << endl;
		}
		
	}system("pause");
}
int main2017��1��5��142053() {
/*	while (1) {
		Virus_detection();
		system("pause");
	}*/
	Virus_detection();
	system("pause");
	return 0;
}