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
} VertexType; //�������Ͷ���


typedef struct ArcNode {         //�������Ͷ���
	int adjvex;              //����λ�ñ�� 
	struct ArcNode* nextarc;	   //��һ������ָ��
} ArcNode;

typedef struct VNode {				//ͷ��㼰���������Ͷ���
	VertexType data;       	//������Ϣ
	ArcNode* firstarc;      	 //ָ���һ����
} VNode, AdjList[MAX_VERTEX_NUM];

typedef  struct {  //�ڽӱ�����Ͷ���
	AdjList vertices;     	 //ͷ�������
	int vexnum, arcnum;   	  //������������
} ALGraph;

typedef struct {    //��ͼ�Ĺ������
	struct {
		char name[30];
		ALGraph G;
	} elem[10];
	int length;
}LISTS;

void print1(void);
void print2(void);
void print3(void);
status JudgeV(VertexType V[], ALGraph& G); //����V�Ƿ�Ϸ�
status JudgeVR(VertexType V[], KeyType VR[][2], ALGraph& G);  //����VR�Ƿ�Ϸ�
status CreateCraph(ALGraph& G, VertexType V[], KeyType VR[][2]); //��������ͼ
status DestroyGraph(ALGraph& G); //��������ͼ
int LocateVex(ALGraph G, KeyType u);  //���Ҷ���
int Compare(ALGraph G, KeyType u, VertexType value); //��ֵ�������������ȽϹؼ���Ψһ��
status PutVex(ALGraph& G, KeyType u, VertexType value); //���㸳ֵ
int FirstAdjVex(ALGraph G, KeyType u);//��õ�һ�ڽӵ�
int NextAdjVex(ALGraph G, KeyType v, KeyType w);//�����һ�ڽӵ�
status InsertVex(ALGraph& G, VertexType v);//���붥��
status DeleteVex(ALGraph& G, KeyType v);//ɾ������
status InsertArc(ALGraph& G, KeyType v, KeyType w);//���뻡
status DeleteArc(ALGraph& G, KeyType v, KeyType w);//ɾ����
void DFS(ALGraph G, int v, void (*visit)(VertexType), int visited[]);//��ȱ�����������
status DFSTraverse(ALGraph G, void (*visit)(VertexType));//��ȱ���
status BFSTraverse(ALGraph G, void (*visit)(VertexType));//��ȱ���
void visit(VertexType v);//�������
status SaveGraph(ALGraph G, char FileName[]);//�����ļ�
status LoadGraph(ALGraph& G, char FileName[]);//��ȡ�ļ�

status RemoveList(LISTS& Lists, char ListName[]);//��ͼ�Ƴ�
status LocateList(LISTS Lists, char ListName[]);//��ͼ����
status AddList(LISTS& Lists, char ListName[]);//��ͼ��������
status MoreSaveGraph(ALGraph G, FILE* fp);//��ͼ�ļ�����
status MoreLoadGraph(ALGraph &G, FILE* fp); //��ͼ�ļ���ȡ


