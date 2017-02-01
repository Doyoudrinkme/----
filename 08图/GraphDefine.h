#ifndef GRAPH
#define GRAPH

#define MaxInt 32767
#define MVNum 100
#define OK 1

typedef char VerTexType;   //假设顶点的数据类型为字符型
typedef int ArcType;       //假设边的权值类型为整型
typedef int OtherInfo;      //和边相关的信息

 //bool visited[MVNum];
#endif
//图的邻接矩阵存储表示
typedef struct {
	VerTexType vexs[MVNum];//顶点表
	ArcType arcs[MVNum][MVNum];  //邻接矩阵
	int vexnum, arcnum;          //图的当前结点和边数
}AMGraph;
int LocateVex(AMGraph G, VerTexType v);
int CreateUDN(AMGraph &G);   //创建邻接矩阵
int FirstAdjVex(AMGraph G, int v);
int NextAdjVex(AMGraph G, int v, int w);//v相对于w的下一个邻接点，w≥0 表示存在邻接点



//********************************************************************

//图的邻接表存储表示
typedef struct ArcNode {
	int adjvex;  //该边所指向的顶点的位置
	struct ArcNode *nextarc;  //指向下一条边的指针
	OtherInfo info;  //和边相关的信息
}ArcNode;

typedef struct VNode {
	VerTexType data;  //顶点信息
	ArcNode *firstarc;  //指向第一条依附该顶点的边的指针
}VNode,AdjList[MVNum];  //AdjList表示邻接表类型

typedef struct {
	AdjList vertices; //邻接表
	int vexnum, arcnum;//图的当前顶点数和边数
}ALGraph;

int LocateVex(ALGraph G, VerTexType v);
int CreateUDG(ALGraph &G);
void CreateUDN2(AMGraph &G);

