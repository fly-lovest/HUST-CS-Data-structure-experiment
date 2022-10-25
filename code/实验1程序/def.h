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

typedef struct {  //˳���˳��ṹ���Ķ���
    ElemType* elem;
    int length;
    int listsize;
}SqList;

typedef struct {  //���Ա�Ĺ������
    struct {
        char name[30];
        SqList L;
    } elem[10];
    int length;
    int listsize;
}LISTS;


/**�������**/

//����ձ�
status InitList(SqList& L) // ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    if (L.elem == NULL) {
        L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
        return OK;
    }
    else return INFEASIBLE;
}

//���ٵ���
status DestroyList(SqList& L)// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
    if (L.elem != NULL) {
        free(L.elem);
        L.elem = NULL;
        L.length = 0;
        return OK;
    }
    else return INFEASIBLE;

}

//��յ���
status ClearList(SqList& L)// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{

    if (L.elem != NULL) {
        L.length = 0;
        return OK;
    }
    else return INFEASIBLE;

}

//�жϿձ�
status ListEmpty(SqList L)// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
    if (L.elem != NULL) {
        if (L.length == 0)return TRUE;
        else return FALSE;
    }
    else return INFEASIBLE;
}

//������
status ListLength(SqList L)// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    if (L.elem != NULL) {
        return L.length;
    }
    else return INFEASIBLE;
}

//��ȡԪ��
status GetElem(SqList L, int i, ElemType& e)// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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

//����Ԫ��
status LocateElem(SqList L, ElemType e)// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų�����OK�����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
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

//��ȡǰ��
status PriorElem(SqList L, ElemType e, ElemType& pre)// ������Ա�L���ڣ���ȡ���Ա�LԪ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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

//��ȡ���
status NextElem(SqList L, ElemType e, ElemType& next)// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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

//����Ԫ��
status ListInsert(SqList& L, int i, ElemType e)// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if (L.elem != NULL) {
        if (i<1 || i>L.length + 1) return ERROR;
        if (i == L.length + 1) { L.elem[i - 1] = e; L.length++; return OK; }  //�ж��Ƿ���������

        int n;
        for (n = L.length; n >= i; n--) L.elem[n] = L.elem[n - 1];

        L.elem[i - 1] = e;
        L.length++;
        return OK;
    }
    else return INFEASIBLE;
}

//ɾ��Ԫ��
status ListDelete(SqList& L, int i, ElemType& e)// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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

//��������
status ListTraverse(SqList L)// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    if (L.elem != NULL) {
        int n;  //ѭ������
        for (n = 0; n < L.length; n++) {
            printf("%d ", L.elem[n]);
        }
        return OK;
    }
    else return INFEASIBLE;
}

//�ļ�����
status  SaveList(SqList L, char *FileName)// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
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

//�ļ���ȡ
status  LoadList(SqList& L, char FileName[])// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
    if (L.elem == NULL) {
        FILE* fp;
        char ch;//���ڱ����ļ�

        L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;


        if ((fp = fopen(FileName, "r")) == NULL) { printf("Can't open!"); exit(EXIT_FAILURE); }
        while ((ch = getc(fp)) != EOF) { if (ch == ' ')L.length++; } //��ȡ�ж��ٸ�Ԫ��
        L.length++;
        rewind(fp);

        int n;
        for (n = 0; n < L.length; n++) fscanf(fp, "%d", &L.elem[n]);
        fclose(fp);
        return OK;
    }
    else return INFEASIBLE;
}



/**������**/

//����
status AddList(LISTS& Lists, char ListName[])// ��Lists������һ������ΪListName�Ŀ����Ա�

{
    Lists.elem[Lists.length].L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    Lists.elem[Lists.length].L.length = 0;
    Lists.elem[Lists.length].L.listsize = LIST_INIT_SIZE;

    strcpy(Lists.elem[Lists.length].name, ListName);
    Lists.length++;

    return OK;
}

//�Ƴ�
status RemoveList(LISTS& Lists, char ListName[])// Lists��ɾ��һ������ΪListName�����Ա�
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

//����
status LocateList(LISTS Lists, char ListName[])// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�ERROR
{
    int n;
    for (n = 0; n < Lists.length; n++) {
        if (!strcmp(Lists.elem[n].name, ListName)) return (n + 1);

    }
    return ERROR;
}

