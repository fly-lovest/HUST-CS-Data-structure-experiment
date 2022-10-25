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
typedef int ElemType; //����Ԫ�����Ͷ���

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef struct LNode {  //��������ʽ�ṹ�����Ķ���
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

typedef struct {    //���Ա�Ĺ������
	struct {
		char name[30];
		LinkList L;
	} elem[10];
	int length;
}LISTS;

/*�������*/
// 	���Ա�Ĵ���
status InitList(LinkList& L);

// �������Ա�
status DestroyList(LinkList& L);

// ������Ա�
status ClearList(LinkList& L);


// ���Ա��п�
status ListEmpty(LinkList L);


// ���Ա���
int ListLength(LinkList L);


// ��ȡԪ��
status GetElem(LinkList L, int i, ElemType& e);


// ����Ԫ��
status LocateElem(LinkList L, ElemType e);


// ��ȡǰ��Ԫ��
status PriorElem(LinkList L, ElemType e, ElemType& pre);


// ��ȡ���Ԫ��
status NextElem(LinkList L, ElemType e, ElemType& next);


// ����Ԫ��
status ListInsert(LinkList& L, int i, ElemType e);


// ɾ��Ԫ��
status ListDelete(LinkList& L, int i, ElemType& e);


// �������Ա�
status ListTraverse(LinkList L);


// ���Ա�����ļ�
status SaveList(LinkList L, char FileName[]);


// �ļ��������Ա�
status LoadList(LinkList& L, char FileName[]);

/*������*/
//����
status AddList(LISTS& Lists, char ListName[]);

//�Ƴ�
status RemoveList(LISTS& Lists, char ListName[]);

//����
status LocateList(LISTS Lists, char ListName[]);
