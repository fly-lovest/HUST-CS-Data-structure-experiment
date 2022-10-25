#include "def.h"

LinkList L;
LISTS Lists;

int num;  //操作序号
int dat;  //插入数据
int i;    //位置符号
int save,e;   //暂存数据
int number;   //多表操作中的序号
char saveName[30];  //暂存表名

int main() {
	printf("-----------------基于链式存储结构的线性表系统--------------------\n\n");  //一级菜单
	printf("1.单表操作\t\t2.多表操作\t\t0.停止操作\n\n请输入你需要的操作：");

	scanf("%d", &num);
	if (num == 1) {       //单表操作（二级菜单）
		printf("\n-----------------单表操作菜单--------------------\n\
1.创造单表        2.销毁单表        3.清空单表\n\
4.输入元素        5.判断空表        6.单表长度\n\
7.位置查找        8.元素查找        9.获取前驱\n\
10.获取后继       11.插入元素       12.删除元素\n\
13.遍历单表       14.文件保存       15.文件读取\n\
0.停止操作        请输入【0~15】\n\n请输入你需要的操作：");
		scanf("%d", &num);  //输入操作
		while (num) {
			switch (num)
			{
			case 1: {  //创造单表
				LNode* p;
				if (InitList(L) == OK) {
					p = L;
					printf("请输入单表数据【输入0停止】：");
					scanf("%d", &dat);
					while (dat) {
						InitList(p->next);
						p = p->next;
						p->data = dat;
						scanf("%d", &dat);
					}
					printf("表创建成功！\n");
				}
				else printf("表存在，无法创建！\n");
				break;
			}
			case 2: {  //销毁单表
				if (DestroyList(L) == OK)printf("单表销毁成功\n");
				else printf("表为NULL，销毁失败！\n");
				break;
			}
			case 3: {  //清空单表
				if (ClearList(L) == OK)printf("单表清空成功\n");
				else printf("表为NULL，清空失败！\n");
				break;
			}
			case 4: {  //输入元素
				if (L== NULL) { printf("表为NULL，无法输入元素！\n"); break; }
				if (ListLength(L)!= 0) { printf("表长不为0，请选择插入元素！\n"); break; }
				LNode* p=L;
				printf("请输入单表数据【输入0停止】：");
				scanf("%d", &dat);
				while (dat) {
					InitList(p->next);
					p = p->next;
					p->data = dat;
					scanf("%d", &dat);
				}
				break;
			}
			case 5: {  //判断空表
				if (ListEmpty(L) == TRUE) { printf("表中无数据\n"); break; }
				if (ListEmpty(L) == FALSE) { printf("表中有数据\n"); break; }
				printf("表为NULL！\n");
				break;
			}
			case 6: {  //单表长度
				if (ListLength(L) == INFEASIBLE)printf("表为NULL！\n");
				else printf("表长为%d\n", ListLength(L));
				break;
			}
			case 7: {  //位置查找
				printf("输入你想查找的元素位置：");
				scanf("%d", &i);
				if (GetElem(L, i, e) == OK) { printf("第%d个元素为%d\n", i, e); break; }
				if (GetElem(L, i, e) == ERROR) { printf("第%d个元素不存在\n", i); break; }
				printf("表为NULL！\n");
				break;
			}
			case 8: {  //元素查找
				printf("输入你想查找的元素：");
				scanf("%d", &save);
				if (LocateElem(L, save) == INFEASIBLE) { printf("表为NULL！\n"); break; }
				if (LocateElem(L, save) == ERROR) { printf("%d在表中不存在\n", save); break; }
				printf("第%d个元素为%d\n", LocateElem(L, save), save);
				break;
			}
			case 9: {  //获得前驱
				int pre; //暂存前驱
				printf("输入你想选择的元素：");
				scanf("%d", &save);
				if (PriorElem(L, save, pre) == INFEASIBLE) { printf("表为NULL！\n"); break; }
				if (PriorElem(L, save, pre) == ERROR) { printf("%d的前驱不存在\n", save); break; }
				printf("你想查找的前驱元素为%d\n", pre);
				break;
			}
			case 10: {  //获得后继
				int next; //暂存后继
				printf("输入你想选择的元素：");
				scanf("%d", &save);
				if (NextElem(L, save, next) == INFEASIBLE) { printf("表为NULL！\n"); break; }
				if (NextElem(L, save, next) == ERROR) { printf("%d的后继不存在\n", save); break; }
				printf("你想查找的后继元素为%d\n", next);
				break;
			}
			case 11: {  //插入元素
				if (L== NULL) { printf("表为NULL！\n"); break; }
				printf("输入你想在第几个元素前插入的元素【先输入位置再输入元素】：");
				scanf("%d%d", &i, &save);
				if (ListInsert(L, i, save) == ERROR) { printf("无法插入在第%d个元素前插入元素\n", i); break; }
				printf("插入成功！遍历为：");
				LNode* p = L->next;
				while(p){
					if (p->next == NULL) { printf("%d", p->data); break; }
					printf("%d ", p->data);
					p = p->next;
				}
				putchar('\n');
				break;
			}
			case 12: {  //删除元素
				if (L == NULL) { printf("表为NULL！\n"); break; }
				printf("输入你想删除第几个元素：");   //判断表空与元素有无
				scanf("%d", &i);
				if (ListDelete(L, i, e) == ERROR) { printf("无法删除在第%d个元素\n", i); break; }
				printf("删除的第%d为%d！遍历为：", i, e);
				LNode* p = L->next;
				while (p) {
					if (p->next == NULL) { printf("%d", p->data); break; }
					printf("%d ", p->data);
					p = p->next;
				}
				putchar('\n');
				break;
			}
			case 13: {  //遍历单表
				if (L == NULL) { printf("表为NULL！\n"); break; }
				if (ListLength(L) == 0) { printf("遍历为：无数据！\n"); break; }
				else {
					printf("遍历为：");
					ListTraverse(L);
					putchar('\n');
				}
				break;
			}
			case 14: {  //文件保存
				char FileName[30] = "data.txt";  //单表文件名
				if (SaveList(L, FileName) == OK)printf("保存成功\n");
				else printf("表为NULL，保存失败！\n");
				break;
			}
			case 15: {  //文件读取
				char FileName[30] = "date.txt";  //储存文件名
				if (LoadList(L, FileName) == INFEASIBLE)printf("表不为NULL，无法读取数据！\n");
				else printf("文件读取成功！\n");
				break;
			}
			default:printf("输出错误，请重新输入！\n");
			}
			printf("\n请输入你需要的操作：");
			scanf("%d", &num);
		}
	}

	if (num == 2) {       //多表操作（二级菜单）
		Lists.length = 0;  //初始化Lists长度
	A:;
		printf("\n-----------------多表操作菜单--------------------\n\
1.创建多表        2.移除某表        3.查找某表\n\
4.单独操作        5.遍历多表        6.清空多表\n\
7.文件保存        8.文件读取\n\
0.停止操作        请输入【0~8】\n\n请输入你需要的操作：");
		scanf("%d", &num);
		while (num) {
			switch (num)
			{
			case 1: {  //创建多表
				printf("输入创建表的名称：");
				scanf("%s", saveName);
				AddList(Lists, saveName);
				printf("请输入数据【输入0停止】：");
				LNode* p = Lists.elem[Lists.length - 1].L;
				scanf("%d", &dat);
				while (dat) {
					InitList(p->next);
					p = p->next;
					p->data = dat;
					scanf("%d", &dat);
				}
				printf("添加成功！\n");
				break;
			}
			case 2: {  //移除某表
				printf("输入你想移除表的表名：");
				scanf("%s", saveName);
				if (RemoveList(Lists, saveName) == ERROR) { printf("无该表名的线性表！\n"); break; }
				else printf("删除成功！\n");
				break;
			}
			case 3: {  //查找某表
				printf("输入你想查找表的表名：");
				scanf("%s", saveName);
				if ((e = LocateList(Lists, saveName)) == ERROR) { printf("无该表名的线性表！\n"); break; }
				printf("查找成功：%s ", saveName);

				if (Lists.elem[e - 1].L == NULL) { printf("表为NULL！\n"); break; }
				if (ListLength(Lists.elem[e - 1].L) == 0) { printf("表中无数据！\n"); break; }
				else {
					ListTraverse(Lists.elem[e - 1].L);
					putchar('\n');
				}
				break;
			}
			case 4: {  //单独操作
				printf("输入你想单独操作表的表名：");
				scanf("%s", saveName);
				if ((number = LocateList(Lists, saveName)) == ERROR) { printf("无该表名的线性表！\n"); break; }  //三级菜单
				printf("\n-----------------多表操作中的单表操作菜单--------------------\n\
1.创建单表        2.销毁单表        3.清空单表\n\
4.输入元素        5.判断空表        6.单表长度\n\
7.位置查找        8.元素查找        9.获取前驱\n\
10.获取后继       11.插入元素       12.删除元素\n\
13.遍历单表       14.文件保存       15.文件读取\n\
16.返回多表菜单\n\
请输入【1~16】\n\n请输入你需要的操作：");
				scanf("%d", &num);   //输入操作
				while (num) {
					switch (num)
					{
					case 1: {  //创建单表
						LNode* p;
						if (InitList(Lists.elem[number - 1].L) == OK) {
							p = Lists.elem[number - 1].L;
							printf("请输入单表数据【输入0停止】：");
							scanf("%d", &dat);
							while (dat) {
								InitList(p->next);
								p = p->next;
								p->data = dat;
								scanf("%d", &dat);
							}
							printf("表创建成功！\n");
						}
						else printf("表存在，无法创建！\n");
						break;
					}
					case 2: {  //销毁单表
						if (DestroyList(Lists.elem[number - 1].L) == OK)printf("单表销毁成功\n");
						else printf("表为NULL，销毁失败！\n");
						break;
					}
					case 3: {  //清空单表
						if (ClearList(Lists.elem[number - 1].L) == OK)printf("单表清空成功\n");
						else printf("表为NULL，清空失败！\n");
						break;
					}
					case 4: {  //输入元素
						if (Lists.elem[number - 1].L == NULL) { printf("表为NULL，无法输入元素！\n"); break; }
						if (ListLength(Lists.elem[number - 1].L)!= 0) { printf("表长不为0，请选择插入元素！\n"); break; }
						printf("请输入单表数据【输入0停止】：");
						LNode* p = Lists.elem[number - 1].L;
						scanf("%d", &dat);
						while (dat) {
							InitList(p->next);
							p = p->next;
							p->data = dat;
							scanf("%d", &dat);
						}
						break;
					}
					case 5: {  //判断空表
						if (ListEmpty(Lists.elem[number - 1].L) == TRUE) { printf("表中无数据\n"); break; }
						if (ListEmpty(Lists.elem[number - 1].L) == FALSE) { printf("表中有数据\n"); break; }
						printf("表为NULL！\n");
						break;
					}
					case 6: {  //单表长度
						if (ListLength(Lists.elem[number - 1].L) == INFEASIBLE)printf("表为NULL！\n");
						else printf("表长为%d\n", ListLength(Lists.elem[number - 1].L));
						break;
					}
					case 7: {  //位置查找
						printf("输入你想查找的元素位置：");
						scanf("%d", &i);
						if (GetElem(Lists.elem[number - 1].L, i, e) == OK) { printf("第%d个元素为%d\n", i, e); break; }
						if (GetElem(Lists.elem[number - 1].L, i, e) == ERROR) { printf("第%d个元素不存在\n", i); break; }
						printf("表为NULL！\n");
						break;
					}
					case 8: {  //元素查找
						printf("输入你想查找的元素：");
						scanf("%d", &dat);
						if (LocateElem(Lists.elem[number - 1].L, dat) == INFEASIBLE) { printf("表为NULL！\n"); break; }
						if (LocateElem(Lists.elem[number - 1].L, dat) == ERROR) { printf("%d在表中不存在\n", dat); break; }
						printf("第%d个元素为%d\n", LocateElem(Lists.elem[number - 1].L, dat), dat);
						break;
					}
					case 9: {  //获得前驱
						int pre; //暂存前驱
						printf("输入你想选择的元素：");
						scanf("%d", &dat);
						if (PriorElem(Lists.elem[number - 1].L, dat, pre) == INFEASIBLE) { printf("表为NULL！\n"); break; }
						if (PriorElem(Lists.elem[number - 1].L, dat, pre) == ERROR) { printf("%d的前驱不存在\n", dat); break; }
						printf("你想查找的前驱元素为%d\n", pre);
						break;
					}
					case 10: {  //获得后继
						int next; //暂存后继
						printf("输入你想选择的元素：");
						scanf("%d", &dat);
						if (NextElem(Lists.elem[number - 1].L, dat, next) == INFEASIBLE) { printf("表为NULL！\n"); break; }
						if (NextElem(Lists.elem[number - 1].L, dat, next) == ERROR) { printf("%d的后继不存在\n", dat); break; }
						printf("你想查找的后继元素为%d\n", next);
						break;
					}
					case 11: {  //插入元素

						printf("输入你想在第几个元素前插入的元素【先输入位置再输入元素】：");
						scanf("%d%d", &i, &dat);  //输入位置和元素
						if (Lists.elem[number - 1].L == NULL) { printf("表为NULL！\n"); break; }
						if (ListInsert(Lists.elem[number - 1].L, i, dat) == ERROR) { printf("无法在第%d个元素前插入元素\n", i); break; }
						printf("插入成功！遍历为：");
						ListTraverse(Lists.elem[number - 1].L);
						putchar('\n');
						break;
					}
					case 12: {  //删除元素
						if (Lists.elem[number - 1].L == NULL) { printf("表为NULL！\n"); break; }
						printf("输入你想删除第几个元素：");
						scanf("%d", &i);
						if (ListDelete(Lists.elem[number - 1].L, i, dat) == ERROR) { printf("无法删除在第%d个元素\n", i); break; }
						printf("删除的第%d为%d！遍历为：", i, dat);
						ListTraverse(Lists.elem[number - 1].L);
						putchar('\n');
						break;
					}
					case 13: {  //遍历单表
						if (Lists.elem[number - 1].L == NULL) { printf("表为NULL！\n"); break; }
						if (ListLength(Lists.elem[number - 1].L) == 0) { printf("遍历为：无数据！\n"); break; }
						else {
							printf("遍历为：");
							ListTraverse(Lists.elem[number - 1].L);
							putchar('\n');
						}
						break;
					}
					case 14: {  //文件保存
						char FileName[30] = "data.txt";  //储存文件名
						if (SaveList(Lists.elem[number - 1].L, FileName) == OK)printf("文件保存成功\n");
						else printf("表为NULL，保存失败！\n");
						break;
					}
					case 15: {  //文件读取
						char FileName[30] = "data.txt";  //储存文件名
						if (LoadList(Lists.elem[number - 1].L, FileName) == INFEASIBLE)printf("表不为NULL，无法读取数据！\n");
						else printf("文件读取成功！\n");
						break;
					}
					case 16: {  //返回多表菜单
						goto A;
						break;
					}
					default:printf("输出错误，请重新输入！\n");
					}
					printf("\n请输入你需要的操作：");
					scanf("%d", &num);
				}
			}
			case 5: {  //遍历多表
				if (Lists.length == 0) { printf("多表无数据！\n"); break; }
				for (i = 0; i < Lists.length; i++) {
					printf("%s ", Lists.elem[i].name);
					if (Lists.elem[i].L == NULL) { printf("表为NULL！\n"); continue; }
					if (ListLength(Lists.elem[i].L) == 0) { printf("无数据！\n"); continue; }
					else {
						ListTraverse(Lists.elem[i].L);
						putchar('\n');
					}
				}
				break;
			}
			case 6: {  //清空多表
				if (Lists.length == 0) { printf("销毁成功！\n"); break; }
				Lists.length = 0;
				printf("销毁成功！\n");
				break;

			}
			case 7: {  //文件保存（多表）
				char Listsname[30] = "Lists.txt"; //多表文件名
				FILE* fp;
				if (Lists.length != 0) {
					fp = fopen(Listsname, "w");
					LNode* p;
					int n;  //嵌套循环，外层Lists循环，内层L循环；

					for (i = 0; i < Lists.length; i++) {
						fprintf(fp, "%s ", Lists.elem[i].name);
						p = Lists.elem[i].L->next;
						while(p){
							if (p->next == NULL) { fprintf(fp, "%d", p->data); break; }
							fprintf(fp, "%d ", p->data);
							p = p->next;
						}
						fprintf(fp, "\n");
					}
					fclose(fp);
					printf("保存成功！\n");
					break;
				}
				printf("无数据可保存！\n");
				break;
			}
			case 8: {  //文件读取（多表）
				char Listsname[30] = "Lists.txt"; //多表文件名

				if (Lists.length == 0) {
					int n;  //嵌套循环，外层Lists循环，内层L循环；
					FILE* fp = fopen(Listsname, "r");

					for (i = 0; feof(fp) == 0; i++) {
						InitList(Lists.elem[i].L);
						LNode* p = Lists.elem[i].L;
						fscanf(fp, "%s", Lists.elem[i].name);
						while(p) {
							InitList(p->next);
							p = p->next;
							if (feof(fp)) break;
							fscanf(fp, "%d", &p->data);
							if (fgetc(fp) == '\n') break;
							
						}

					}
					Lists.length = i - 1;
					fclose(fp);
					printf("文件读取成功\n");
					break;
				}
				printf("多表有数据存在，不可读取！\n");
				break;
			}
			default:printf("输出错误，请重新输入！\n");
			}

			printf("\n请输入你需要的操作：");
			scanf("%d", &num);
		}
	}

	if (num == 0) {       //停止操作
		printf("系统停止！\n");
		return 0;
	}

	printf("输入错误！\n");
	return 0;
}



//函数代码
status InitList(LinkList& L)
{
	if (L == NULL) {
		L = (LinkList)malloc(sizeof(LNode));
		L->next = NULL;
		return OK;
	}
	else return INFEASIBLE;

}

// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
status DestroyList(LinkList& L)
{
	if (L != NULL) {
		free(L);
		L = NULL;
		return OK;

	}
	else return INFEASIBLE;
}

// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
status ClearList(LinkList& L)
{
	LNode* p, * q;
	if (L != NULL) {
		p = L->next;
		while (p) {
			q = p;
			p = p->next;
			free(q);
		}
		L->next = NULL;
		return OK;
	}
	else return INFEASIBLE;
}

// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
status ListEmpty(LinkList L)
{
	if (L != NULL) {
		if (L->next == NULL)return TRUE;
		else return FALSE;

	}
	else return INFEASIBLE;
}

// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
int ListLength(LinkList L)
{
	if (L != NULL) {
		LNode* p;
		int i = 0;
		p = L->next;
		while (p) {
			p = p->next;
			i++;
		}
		return i;
	}
	else return INFEASIBLE;
}

// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status GetElem(LinkList L, int i, ElemType& e)
{
	if (L != NULL) {
		LNode* p = L->next;
		int n = 1;
		if (i < 1) return ERROR;
		while (p && n < i) {
			p = p->next;
			n++;
		}
		if (p == NULL) return ERROR;
		e = p->data;
		return OK;

	}
	else return INFEASIBLE;
}

// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
status LocateElem(LinkList L, ElemType e)
{
	if (L != NULL) {
		LNode* p = L->next;
		int n = 1;

		while (p) {
			if (p->data == e) return n;
			p = p->next;
			n++;
		}
		return ERROR;

	}
	else return INFEASIBLE;
}

// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status PriorElem(LinkList L, ElemType e, ElemType& pre)
{
	if (L != NULL) {
		LNode* p = L->next;
		while (p) {
			if (p->next == NULL)return ERROR;
			if (p->next->data == e) { pre = p->data; return OK; }
			p = p->next;
		}
	}
	else return INFEASIBLE;
}

// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status NextElem(LinkList L, ElemType e, ElemType& next)
{
	if (L != NULL) {
		LNode* p = L->next;
		while (p) {
			if (p->next == NULL)return ERROR;
			if (p->data == e) { next = p->next->data; return OK; }
			p = p->next;
		}
	}
	else return INFEASIBLE;
}

// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status ListInsert(LinkList& L, int i, ElemType e)
{
	if (L != NULL) {
		LNode* p = L->next, * q = L, * newL;
		newL = (LNode*)malloc(sizeof(LNode));
		int n = 1;
		if (i < 1) return ERROR;
		while (p && n <= i) {
			p = p->next;
			q = q->next;
			n++;
		}
		if (n == i) {
			newL->data = e;
			q->next = newL;
			newL->next = p;
			return OK;
		}
		return ERROR;
	}
	else return INFEASIBLE;
}

// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status ListDelete(LinkList& L, int i, ElemType& e)
{
	if (L != NULL) {
		LNode* p = L->next, * q = L;
		int n = 1;
		if (i < 1) return ERROR;
		while (p && n < i) {
			p = p->next;
			q = q->next;
			n++;
		}
		if (n == i && p != NULL) {
			e = p->data;
			q->next = p->next;
			return OK;
		}
		return ERROR;
	}
	else return INFEASIBLE;
}

// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
status ListTraverse(LinkList L)
{
	if (L != NULL) {
		if (L->next == NULL)return OK;
		else {
			LNode* p = L->next;
			while (p) {
				if (p->next == NULL) { printf("%d", p->data); break; }
				printf("%d ", p->data);
				p = p->next;
			}
			return OK;
		}

	}
	else return INFEASIBLE;
}

// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
status SaveList(LinkList L, char FileName[])
{
	FILE* fp;
	if (L != NULL) {
		fp = fopen("FileName", "w");
		LNode* p = L->next;
		while (p) {
			fprintf(fp, "%d ", p->data);
			p = p->next;
		}
		fclose(fp);
		return OK;
	}
	else return INFEASIBLE;
}

// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
status LoadList(LinkList& L, char FileName[])
{
	if (L == NULL) {
		FILE* fp = fopen(FileName, "r");
		if ((fp = fopen("FileName", "r")) == NULL) { printf("Can't open!"); exit(EXIT_FAILURE); }
		L = (LinkList)malloc(sizeof(LinkList));
		LNode* p = L, * q = L;

		while (feof(fp) == 0) {
			q = p;
			p = (LNode*)malloc(sizeof(LNode));
			fscanf(fp, "%d", &p->data);
			q->next = p;
			p->next = NULL;
		}
		q->next = NULL;
		free(p);
		fclose(fp);
		return OK;

	}
	else return INFEASIBLE;
}

// 创建多表
status AddList(LISTS& Lists, char ListName[])
{
	
	Lists.elem[Lists.length].L = NULL;
	int i = 0;
	strcpy(Lists.elem[Lists.length].name, ListName);
	InitList(Lists.elem[Lists.length].L);
	Lists.length ++;
	return OK;
}

// 移除某表
status RemoveList(LISTS& L, char ListName[])
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

// 查找某表
status LocateList(LISTS Lists, char ListName[])// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回ERROR
{
	int n;
	for (n = 0; n < Lists.length; n++) {
		if (!strcmp(Lists.elem[n].name, ListName)) return (n + 1);

	}
	return ERROR;
}
