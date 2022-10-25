#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20
typedef int status;
typedef int KeyType;

typedef struct {
	KeyType  key;
	char others[20];
} VertexType; //顶点类型定义


typedef struct ArcNode {         //表结点类型定义
	int adjvex;              //顶点位置编号 
	struct ArcNode* nextarc;	   //下一个表结点指针
} ArcNode;

typedef struct VNode {				//头结点及其数组类型定义
	VertexType data;       	//顶点信息
	ArcNode* firstarc;      	 //指向第一条弧
} VNode, AdjList[MAX_VERTEX_NUM];

typedef  struct {  //邻接表的类型定义
	AdjList vertices;     	 //头结点数组
	int vexnum, arcnum;   	  //顶点数、弧数
} ALGraph;

typedef struct {    //多图的管理表定义
	struct {
		char name[30];
		ALGraph G;
	} elem[10];
	int length;
}LISTS;

void print1(void);
void print2(void);
void print3(void);
status JudgeV(VertexType V[], ALGraph& G); //查找V是否合法
status JudgeVR(VertexType V[], KeyType VR[][2], ALGraph& G);  //查找VR是否合法
status CreateCraph(ALGraph& G, VertexType V[], KeyType VR[][2]); //创建无向图
status DestroyGraph(ALGraph& G); //销毁无向图
int LocateVex(ALGraph G, KeyType u);  //查找顶点
int Compare(ALGraph G, KeyType u, VertexType value); //赋值操作辅助函数比较关键字唯一性
status PutVex(ALGraph& G, KeyType u, VertexType value); //顶点赋值
int FirstAdjVex(ALGraph G, KeyType u);//获得第一邻接点
int NextAdjVex(ALGraph G, KeyType v, KeyType w);//获得下一邻接点
status InsertVex(ALGraph& G, VertexType v);//插入顶点
status DeleteVex(ALGraph& G, KeyType v);//删除顶点
status InsertArc(ALGraph& G, KeyType v, KeyType w);//插入弧
status DeleteArc(ALGraph& G, KeyType v, KeyType w);//删除弧
void DFS(ALGraph G, int v, void (*visit)(VertexType), int visited[]);//深度遍历辅助函数
status DFSTraverse(ALGraph G, void (*visit)(VertexType));//深度遍历
status BFSTraverse(ALGraph G, void (*visit)(VertexType));//广度遍历
void visit(VertexType v);//输出函数
status SaveGraph(ALGraph G, char FileName[]);//保存文件
status LoadGraph(ALGraph& G, char FileName[]);//读取文件

status RemoveList(LISTS& Lists, char ListName[]);//多图移除
status LocateList(LISTS Lists, char ListName[]);//多图查找
status AddList(LISTS& Lists, char ListName[]);//多图表名创建
status MoreSaveGraph(ALGraph G, FILE* fp);//多图文件保存
status MoreLoadGraph(ALGraph &G, FILE* fp); //多图文件读取


