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
typedef int ElemType; //数据元素类型定义

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef struct LNode {  //单链表（链式结构）结点的定义
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

typedef struct {    //线性表的管理表定义
	struct {
		char name[30];
		LinkList L;
	} elem[10];
	int length;
}LISTS;

/*单表操作*/
// 	线性表的创建
status InitList(LinkList& L);

// 销毁线性表
status DestroyList(LinkList& L);

// 清空线性表
status ClearList(LinkList& L);


// 线性表判空
status ListEmpty(LinkList L);


// 线性表长度
int ListLength(LinkList L);


// 获取元素
status GetElem(LinkList L, int i, ElemType& e);


// 查找元素
status LocateElem(LinkList L, ElemType e);


// 获取前驱元素
status PriorElem(LinkList L, ElemType e, ElemType& pre);


// 获取后继元素
status NextElem(LinkList L, ElemType e, ElemType& next);


// 插入元素
status ListInsert(LinkList& L, int i, ElemType e);


// 删除元素
status ListDelete(LinkList& L, int i, ElemType& e);


// 遍历线性表
status ListTraverse(LinkList L);


// 线性表存入文件
status SaveList(LinkList L, char FileName[]);


// 文件读入线性表
status LoadList(LinkList& L, char FileName[]);

/*多表操作*/
//建立
status AddList(LISTS& Lists, char ListName[]);

//移除
status RemoveList(LISTS& Lists, char ListName[]);

//查找
status LocateList(LISTS Lists, char ListName[]);
