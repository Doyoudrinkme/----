#ifndef GRAPH
#define GRAPH

#define MaxInt 32767
#define MVNum 100
#define OK 1

typedef char VerTexType;   //���趥�����������Ϊ�ַ���
typedef int ArcType;       //����ߵ�Ȩֵ����Ϊ����
typedef int OtherInfo;      //�ͱ���ص���Ϣ

 //bool visited[MVNum];
#endif
//ͼ���ڽӾ���洢��ʾ
typedef struct {
	VerTexType vexs[MVNum];//�����
	ArcType arcs[MVNum][MVNum];  //�ڽӾ���
	int vexnum, arcnum;          //ͼ�ĵ�ǰ���ͱ���
}AMGraph;
int LocateVex(AMGraph G, VerTexType v);
int CreateUDN(AMGraph &G);   //�����ڽӾ���
int FirstAdjVex(AMGraph G, int v);
int NextAdjVex(AMGraph G, int v, int w);//v�����w����һ���ڽӵ㣬w��0 ��ʾ�����ڽӵ�



//********************************************************************

//ͼ���ڽӱ�洢��ʾ
typedef struct ArcNode {
	int adjvex;  //�ñ���ָ��Ķ����λ��
	struct ArcNode *nextarc;  //ָ����һ���ߵ�ָ��
	OtherInfo info;  //�ͱ���ص���Ϣ
}ArcNode;

typedef struct VNode {
	VerTexType data;  //������Ϣ
	ArcNode *firstarc;  //ָ���һ�������ö���ıߵ�ָ��
}VNode,AdjList[MVNum];  //AdjList��ʾ�ڽӱ�����

typedef struct {
	AdjList vertices; //�ڽӱ�
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͱ���
}ALGraph;

int LocateVex(ALGraph G, VerTexType v);
int CreateUDG(ALGraph &G);
void CreateUDN2(AMGraph &G);

