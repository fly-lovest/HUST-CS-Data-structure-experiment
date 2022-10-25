#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int KeyType;
typedef struct {
	KeyType  key;
	char others[20];
} TElemType; //������������Ͷ���


typedef struct BiTNode {  //����������Ķ���
	TElemType  data;
	struct BiTNode* lchild, * rchild;
} BiTNode, * BiTree;

typedef struct {    //�����Ĺ������
	struct {
		char name[30];
		BiTree T;
	} elem[10];
	int length;
}LISTS;

status Compare1(TElemType definition[]); //�ȽϽṹ���������Ƿ����ظ��Ĺؼ���
status CreateBiTree(BiTree& T, TElemType definition[]); //���ݽṹ���鴴����
status ClearBiTree(BiTree& T);//����������ղ�����
int BiTreeDepth(BiTree T);//������������
BiTNode* LocateNode(BiTree T, KeyType e);//���ҹؼ���Ϊe�Ľ�㲢���ؽ��ָ��
void SaveKey(KeyType save[], BiTree T);//��T�еĹؼ��ֱ��浽������
status Compare2(KeyType definition[], KeyType e, KeyType E);//�ȽϹؼ������������e��E�Ƿ���ͬһ��ֵ
status Assign(BiTree& T, KeyType e, TElemType value);//��value�����ؼ���Ϊe�Ľ��
BiTNode* GetSibling(BiTree T, KeyType e);//���عؼ���Ϊe���ֵܽ��
status Compare3(KeyType definition[], KeyType E);//������������û����E��ͬ�Ĺؼ���
status InsertNode(BiTree& T, KeyType e, int LR, TElemType c);//������c��eΪ���ҽ�㣬LRΪ��������
BiTNode* GetBefore(BiTree T, KeyType e);//��ùؼ���Ϊe�ĸ����
status DeleteNode(BiTree& T, KeyType e);//ɾ���ؼ���Ϊe�Ľ��
status PreOrderTraverse(BiTree T, void (*visit)(BiTree));//�������
status InOrderTraverse(BiTree T, void (*visit)(BiTree));//�������
status PostOrderTraverse(BiTree T, void (*visit)(BiTree));//��������
status LevelOrderTraverse(BiTree T, void (*visit)(BiTree));//�������
void visit(BiTree T);//������T������
status SaveBiTree(BiTree T, char FileName[]);//��T��������������浽�ļ���
void SaveFile(BiTree T, FILE* fp);//�����ļ�����
status LoadBiTree(BiTree& T, char FileName[]);//���ļ����ݴ浽T��

status RemoveList(LISTS& Lists, char ListName[]);//�����Ƴ�
status LocateList(LISTS Lists, char ListName[]);//��������
status AddList(LISTS& Lists, char ListName[]);//����
status MoreSaveBiTree(char name[], BiTree T, FILE* fp);//�ļ����棨������
status MoreLoadBiTree(BiTree& T, FILE* fp);//�ļ���ȡ��������