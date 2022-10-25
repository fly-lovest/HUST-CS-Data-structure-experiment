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

typedef struct {  //顺序表（顺序结构）的定义
    ElemType* elem;
    int length;
    int listsize;
}SqList;

typedef struct {  //线性表的管理表定义
    struct {
        char name[30];
        SqList L;
    } elem[10];
    int length;
    int listsize;
}LISTS;


/**单表操作**/

//构造空表
status InitList(SqList& L) // 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    if (L.elem == NULL) {
        L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
        return OK;
    }
    else return INFEASIBLE;
}

//销毁单表
status DestroyList(SqList& L)// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    if (L.elem != NULL) {
        free(L.elem);
        L.elem = NULL;
        L.length = 0;
        return OK;
    }
    else return INFEASIBLE;

}

//清空单表
status ClearList(SqList& L)// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{

    if (L.elem != NULL) {
        L.length = 0;
        return OK;
    }
    else return INFEASIBLE;

}

//判断空表
status ListEmpty(SqList L)// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem != NULL) {
        if (L.length == 0)return TRUE;
        else return FALSE;
    }
    else return INFEASIBLE;
}

//单表长度
status ListLength(SqList L)// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    if (L.elem != NULL) {
        return L.length;
    }
    else return INFEASIBLE;
}

//获取元素
status GetElem(SqList L, int i, ElemType& e)// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem != NULL) {
        if (i<1 || i>L.length)return ERROR;
        else {
            e = L.elem[i - 1];
            return OK;
        }
    }
    else return INFEASIBLE;
}

//查找元素
status LocateElem(SqList L, ElemType e)// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回OK；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    if (L.elem != NULL) {
        int i;
        for (i = 0; i < L.length; i++) {
            if (L.elem[i] == e) return (i + 1);
        }
        return ERROR;
    }
    else return INFEASIBLE;
}

//获取前驱
status PriorElem(SqList L, ElemType e, ElemType& pre)// 如果线性表L存在，获取线性表L元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    int i;
    if (L.elem != NULL) {
        for (i = 0; i < L.length; i++) {
            if (L.elem[i] == e && i != 0) {
                pre = L.elem[i - 1];
                return OK;
            }
        }
        return ERROR;
    }
    else return INFEASIBLE;
}

//获取后继
status NextElem(SqList L, ElemType e, ElemType& next)// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    int i;
    if (L.elem != NULL) {
        for (i = 0; i < L.length; i++) {
            if (L.elem[i] == e && i != L.length - 1) {
                next = L.elem[i + 1];
                return OK;
            }
        }
        return ERROR;
    }
    else return INFEASIBLE;
}

//插入元素
status ListInsert(SqList& L, int i, ElemType e)// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem != NULL) {
        if (i<1 || i>L.length + 1) return ERROR;
        if (i == L.length + 1) { L.elem[i - 1] = e; L.length++; return OK; }  //判断是否在最后插入

        int n;
        for (n = L.length; n >= i; n--) L.elem[n] = L.elem[n - 1];

        L.elem[i - 1] = e;
        L.length++;
        return OK;
    }
    else return INFEASIBLE;
}

//删除元素
status ListDelete(SqList& L, int i, ElemType& e)// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem != NULL) {
        if (i<1 || i>L.length)return ERROR;
        int n;
        e = L.elem[i - 1];
        for (n = i; n < L.length; n++) {
            L.elem[n - 1] = L.elem[n];
        }
        L.length--;
        return OK;
    }
    else return INFEASIBLE;
}

//遍历单表
status ListTraverse(SqList L)// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem != NULL) {
        int n;  //循环变量
        for (n = 0; n < L.length; n++) {
            printf("%d ", L.elem[n]);
        }
        return OK;
    }
    else return INFEASIBLE;
}

//文件保存
status  SaveList(SqList L, char *FileName)// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    FILE* fp;
    if (L.elem != NULL) {
        fp = fopen(FileName, "w+");

        int n;
        for (n = 0; n < L.length; n++) {
            if (n == L.length - 1) { fprintf(fp, "%d",L.elem[n]); break; }
            fprintf(fp, "%d ", L.elem[n]);
        }
        fclose(fp);
        return OK;
    }
    else return INFEASIBLE;
}

//文件读取
status  LoadList(SqList& L, char FileName[])// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    if (L.elem == NULL) {
        FILE* fp;
        char ch;//用于遍历文件

        L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;


        if ((fp = fopen(FileName, "r")) == NULL) { printf("Can't open!"); exit(EXIT_FAILURE); }
        while ((ch = getc(fp)) != EOF) { if (ch == ' ')L.length++; } //读取有多少个元素
        L.length++;
        rewind(fp);

        int n;
        for (n = 0; n < L.length; n++) fscanf(fp, "%d", &L.elem[n]);
        fclose(fp);
        return OK;
    }
    else return INFEASIBLE;
}



/**多表操作**/

//建立
status AddList(LISTS& Lists, char ListName[])// 在Lists中增加一个名称为ListName的空线性表。

{
    Lists.elem[Lists.length].L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    Lists.elem[Lists.length].L.length = 0;
    Lists.elem[Lists.length].L.listsize = LIST_INIT_SIZE;

    strcpy(Lists.elem[Lists.length].name, ListName);
    Lists.length++;

    return OK;
}

//移除
status RemoveList(LISTS& Lists, char ListName[])// Lists中删除一个名称为ListName的线性表
{
    int n;
    for (n = 0; n < Lists.length; n++) {
        if (!strcmp(Lists.elem[n].name, ListName)) {
            for (; n < Lists.length - 1; n++) {
                Lists.elem[n] = Lists.elem[n + 1];
            }
            Lists.length--;
            return OK;
        }
    }
    return ERROR;
}

//查找
status LocateList(LISTS Lists, char ListName[])// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回ERROR
{
    int n;
    for (n = 0; n < Lists.length; n++) {
        if (!strcmp(Lists.elem[n].name, ListName)) return (n + 1);

    }
    return ERROR;
}

