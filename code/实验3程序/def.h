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
} TElemType; //二叉树结点类型定义


typedef struct BiTNode {  //二叉链表结点的定义
	TElemType  data;
	struct BiTNode* lchild, * rchild;
} BiTNode, * BiTree;

typedef struct {    //多树的管理表定义
	struct {
		char name[30];
		BiTree T;
	} elem[10];
	int length;
}LISTS;

status Compare1(TElemType definition[]); //比较结构数组里面是否有重复的关键字
status CreateBiTree(BiTree& T, TElemType definition[]); //根据结构数组创造树
status ClearBiTree(BiTree& T);//将二叉树清空并销毁
int BiTreeDepth(BiTree T);//求二叉树的深度
BiTNode* LocateNode(BiTree T, KeyType e);//查找关键字为e的结点并返回结点指针
void SaveKey(KeyType save[], BiTree T);//将T中的关键字保存到数组里
status Compare2(KeyType definition[], KeyType e, KeyType E);//比较关键字数组里面的e与E是否是同一个值
status Assign(BiTree& T, KeyType e, TElemType value);//将value赋给关键字为e的结点
BiTNode* GetSibling(BiTree T, KeyType e);//返回关键字为e的兄弟结点
status Compare3(KeyType definition[], KeyType E);//查找数组里有没有与E相同的关键字
status InsertNode(BiTree& T, KeyType e, int LR, TElemType c);//插入结点c，e为查找结点，LR为操作参数
BiTNode* GetBefore(BiTree T, KeyType e);//获得关键字为e的父结点
status DeleteNode(BiTree& T, KeyType e);//删除关键字为e的结点
status PreOrderTraverse(BiTree T, void (*visit)(BiTree));//先序遍历
status InOrderTraverse(BiTree T, void (*visit)(BiTree));//中序遍历
status PostOrderTraverse(BiTree T, void (*visit)(BiTree));//后续遍历
status LevelOrderTraverse(BiTree T, void (*visit)(BiTree));//按层遍历
void visit(BiTree T);//输出结点T的数据
status SaveBiTree(BiTree T, char FileName[]);//将T的所有数据先序存到文件中
void SaveFile(BiTree T, FILE* fp);//辅助文件储存
status LoadBiTree(BiTree& T, char FileName[]);//将文件数据存到T中

status RemoveList(LISTS& Lists, char ListName[]);//多树移除
status LocateList(LISTS Lists, char ListName[]);//多树查找
status AddList(LISTS& Lists, char ListName[]);//创建
status MoreSaveBiTree(char name[], BiTree T, FILE* fp);//文件保存（多树）
status MoreLoadBiTree(BiTree& T, FILE* fp);//文件读取（多树）