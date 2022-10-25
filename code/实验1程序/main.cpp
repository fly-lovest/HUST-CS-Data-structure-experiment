#include "def.h"

SqList L;
LISTS Lists;

int num;  //操作序号
int dat;  //插入数据
int i;    //位置符号
int save;   //暂存数据
char saveName[30];  //暂存表名

int main() {
	printf("-----------------基于顺序存储结构的线性表系统--------------------\n\n");  //一级菜单
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
				if (InitList(L) == OK) {
					printf("请输入单表数据【输入0停止】：");
					scanf("%d", &dat);
					while (dat) {
						L.elem[L.length] = dat;
						L.length++;
						scanf("%d", &dat);
					}
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
				if (L.elem == NULL) { printf("表为NULL，无法输入元素！\n"); break; }
				if (L.length != 0) { printf("表长不为0，请选择插入元素！\n"); break; }
				printf("请输入单表数据【输入0停止】：");
				scanf("%d", &dat);
				while (dat) {
					L.elem[L.length] = dat;
					L.length++;
					scanf("%d", &dat);
				}
				break;
			}
			case 5: {  //判断空表
				if (ListEmpty(L) == TRUE) {printf("表中无数据\n"); break;}
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
				if (GetElem(L, i, save) == OK) { printf("第%d个元素为%d\n", i, save); break; }
				if(GetElem(L, i, save) == ERROR) { printf("第%d个元素不存在\n", i); break; }
				printf("表为NULL！\n");
				break;
			}
			case 8: {  //元素查找
				printf("输入你想查找的元素：");
				scanf("%d", &save);
				if(LocateElem(L, save)== INFEASIBLE) { printf("表为NULL！\n"); break; }
				if (LocateElem(L, save) == ERROR) { printf("%d在表中不存在\n",save); break; }
				printf("第%d个元素为%d\n", LocateElem(L, save), save);
				break;
			}
			case 9: {  //获得前驱
				int pre; //暂存前驱
				printf("输入你想选择的元素：");
				scanf("%d", &save);
				if(PriorElem(L,save,pre)== INFEASIBLE) { printf("表为NULL！\n"); break; }
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
				if (L.elem==NULL) { printf("表为NULL！\n"); break; }
				printf("输入你想在第几个元素前插入的元素【先输入位置再输入元素】：");
				scanf("%d%d", &i, &save);
				if(ListInsert(L, i,save)==ERROR){ printf("无法插入在第%d个元素前插入元素\n", i); break; }
				printf("插入成功！遍历为：");
				int n;
				for (n = 0; n < L.length; n++) {
					printf("%d ", L.elem[n]);
				}
				putchar('\n');
				break;
			}
			case 12: {  //删除元素
				if (L.elem == NULL) { printf("表为NULL！\n"); break; }
				printf("输入你想在第几个元素：");   //判断表空与元素有无
				scanf("%d", &i);
				if (ListDelete(L, i, save) == ERROR) { printf("无法删除在第%d个元素\n", i); break; }
				printf("删除的第%d为%d！遍历为：",i,save);
				int n;
				for (n = 0; n < L.length; n++) {
					printf("%d ", L.elem[n]);
				}
				putchar('\n');
				break;
			}
			case 13: {  //遍历单表
				if (L.elem == NULL) { printf("表为NULL！\n"); break; }
				if(L.length==0) { printf("遍历为：无数据！\n"); break; }
				else {
					printf("遍历为：");
					ListTraverse(L);
					putchar('\n');
				}
				break;
			}
			case 14: {  //文件保存
				char FileName[30]="date.txt";  //单表文件名
				if (SaveList(L,FileName) == OK)printf("保存成功\n");
				else printf("表为NULL，保存失败！\n");
				break;
			}
			case 15: {  //文件读取
				char FileName[30] = "date.txt";  //储存文件名
				if (LoadList(L, FileName) == INFEASIBLE)printf("表不为NULL，无法读取数据！\n");
				else printf("文件读取成功！\n");
				break;
			}
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
				scanf("%d", &dat);
				while (dat) {
					Lists.elem[Lists.length - 1].L.elem[Lists.elem[Lists.length - 1].L.length] = dat;
					Lists.elem[Lists.length - 1].L.length++;
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
				if ((save = LocateList(Lists, saveName)) == ERROR) { printf("无该表名的线性表！\n"); break; }
				printf("查找成功：%s ",saveName);

				if (Lists.elem[save - 1].L.elem == NULL) { printf("表为NULL！\n"); break; }
				if (Lists.elem[save - 1].L.length == 0) { printf("无数据！\n"); break; }
				else {
					ListTraverse(Lists.elem[save - 1].L);
					putchar('\n');
				}
				break;
			}
			case 4: {  //单独操作
				printf("输入你想单独操作表的表名：");
				scanf("%s", saveName);
				if ((save = LocateList(Lists, saveName)) == ERROR) { printf("无该表名的线性表！\n"); break; }  //三级菜单
				printf("\n-----------------多表操作中的单表操作菜单--------------------\n\
1.返回多表        2.销毁单表        3.清空单表\n\
4.输入元素        5.判断空表        6.单表长度\n\
7.位置查找        8.元素查找        9.获取前驱\n\
10.获取后继       11.插入元素       12.删除元素\n\
13.遍历单表       14.文件保存       15.文件读取\n\
请输入【1~15】\n\n请输入你需要的操作：");
				scanf("%d", &num);   //输入操作
				while (num) {
					switch (num)
					{
					case 1: {  //返回多表
						goto A;
						break;
					}
					case 2: {  //销毁单表
						if (DestroyList(Lists.elem[save - 1].L) == OK)printf("单表销毁成功\n");
						else printf("表为NULL，销毁失败！\n");
						break;
					}
					case 3: {  //清空单表
						if (ClearList(Lists.elem[save - 1].L) == OK)printf("单表清空成功\n");
						else printf("表为NULL，清空失败！\n");
						break;
					}
					case 4: {  //输入元素
						if (Lists.elem[save - 1].L.elem == NULL) { printf("表为NULL，无法输入元素！\n"); break; }
						if (Lists.elem[save - 1].L.length != 0) { printf("表长不为0，请选择插入元素！\n"); break; }
						printf("请输入单表数据【输入0停止】：");
						scanf("%d", &dat);
						while (dat) {
							Lists.elem[save - 1].L.elem[Lists.elem[save - 1].L.length] = dat;
							Lists.elem[save - 1].L.length++;
							scanf("%d", &dat);
						}
						break;
					}
					case 5: {  //判断空表
						if (ListEmpty(Lists.elem[save - 1].L) == TRUE) { printf("表中无数据\n"); break; }
						if (ListEmpty(Lists.elem[save - 1].L) == FALSE) { printf("表中有数据\n"); break; }
						printf("表为NULL！\n");
						break;
					}
					case 6: {  //单表长度
						if (ListLength(Lists.elem[save - 1].L) == INFEASIBLE)printf("表为NULL！\n");
						else printf("表长为%d\n", ListLength(Lists.elem[save - 1].L));
						break;
					}
					case 7: {  //位置查找
						printf("输入你想查找的元素位置：");
						scanf("%d", &i);
						if (GetElem(Lists.elem[save - 1].L, i, dat) == OK) { printf("第%d个元素为%d\n", i, dat); break; }
						if (GetElem(Lists.elem[save - 1].L, i, dat) == ERROR) { printf("第%d个元素不存在\n", i); break; }
						printf("表为NULL！\n");
						break;
					}
					case 8: {  //元素查找
						printf("输入你想查找的元素：");
						scanf("%d", &dat);
						if (LocateElem(Lists.elem[save - 1].L, dat) == INFEASIBLE) { printf("表为NULL！\n"); break; }
						if (LocateElem(Lists.elem[save - 1].L, dat) == ERROR) { printf("%d在表中不存在\n", dat); break; }
						printf("第%d个元素为%d\n", LocateElem(Lists.elem[save - 1].L, dat), dat);
						break;
					}
					case 9: {  //获得前驱
						int pre; //暂存前驱
						printf("输入你想选择的元素：");
						scanf("%d", &dat);
						if (PriorElem(Lists.elem[save - 1].L, dat, pre) == INFEASIBLE) { printf("表为NULL！\n"); break; }
						if (PriorElem(Lists.elem[save - 1].L, dat, pre) == ERROR) { printf("%d的前驱不存在\n", dat); break; }
						printf("你想查找的前驱元素为%d\n", pre);
						break;
					}
					case 10: {  //获得后继
						int next; //暂存后继
						printf("输入你想选择的元素：");
						scanf("%d", &dat);
						if (NextElem(Lists.elem[save - 1].L, dat, next) == INFEASIBLE) { printf("表为NULL！\n"); break; }
						if (NextElem(Lists.elem[save - 1].L, dat, next) == ERROR) { printf("%d的后继不存在\n", dat); break; }
						printf("你想查找的后继元素为%d\n", next);
						break;
					}
					case 11: {  //插入元素
						
						printf("输入你想在第几个元素前插入的元素【先输入位置再输入元素】：");
						scanf("%d%d", &i, &dat);  //输入位置和元素
						if (Lists.elem[save - 1].L.elem == NULL) { printf("表为NULL！\n"); break; }
						if (ListInsert(Lists.elem[save - 1].L, i, dat) == ERROR) { printf("无法插入在第%d个元素前插入元素\n", i); break; }
						printf("插入成功！遍历为：");
						int n;
						for (n = 0; n < Lists.elem[save - 1].L.length; n++) {
							printf("%d ", Lists.elem[save - 1].L.elem[n]);
						}
						putchar('\n');
						break;
					}
					case 12: {  //删除元素
						if (Lists.elem[save - 1].L.elem == NULL) { printf("表为NULL！\n"); break; }
						printf("输入你想删除第几个元素：");
						scanf("%d", &i);
						if (ListDelete(Lists.elem[save - 1].L, i, dat) == ERROR) { printf("无法删除在第%d个元素\n", i); break; }
						printf("删除的第%d为%d！遍历为：", i, dat);
						int n;
						for (n = 0; n < Lists.elem[save - 1].L.length; n++) {
							printf("%d ", Lists.elem[save - 1].L.elem[n]);
						}
						putchar('\n');
						break;
					}
					case 13: {  //遍历单表
						if (Lists.elem[save - 1].L.elem == NULL) { printf("表为NULL！\n"); break; }
						if (Lists.elem[save - 1].L.length == 0) { printf("遍历为：无数据！\n"); break; }
						else {
							printf("遍历为：");
							ListTraverse(Lists.elem[save - 1].L);
							putchar('\n');
						}
						break;
					}
					case 14: {  //文件保存
						char FileName[30] = "date.txt";  //储存文件名
						if (SaveList(Lists.elem[save - 1].L, FileName) == OK)printf("保存成功\n");
						else printf("表为NULL，保存失败！\n");
						break;
					}
					case 15: {  //文件读取
						char FileName[30] = "date.txt";  //储存文件名
						if (LoadList(Lists.elem[save - 1].L, FileName) == INFEASIBLE)printf("表不为NULL，无法读取数据！\n");
						else printf("文件读取成功！\n");
						break;
					}
					}
					printf("\n请输入你需要的操作：");
					scanf("%d", &num);
				}
			}
			case 5: {  //遍历多表
				if (Lists.length == 0) { printf("多表无数据！\n"); break; }
				for (i = 0; i < Lists.length; i++) {
					printf("%s ", Lists.elem[i].name);
					if (Lists.elem[i].L.elem == NULL) { printf("表为NULL！\n"); continue; }
				    if(Lists.elem[i].L.length==0) { printf("无数据！\n"); continue; }
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
					int n;  //嵌套循环，外层Lists循环，内层L循环；

					for (i = 0; i < Lists.length; i++) {
						fprintf(fp, "%s ", Lists.elem[i].name);
						for (n = 0; n < Lists.elem[i].L.length; n++) {
							if (n == Lists.elem[i].L.length - 1) { fprintf(fp, "%d", Lists.elem[i].L.elem[n]); break; }
							fprintf(fp, "%d ", Lists.elem[i].L.elem[n]);
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
						Lists.elem[i].L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
						fscanf(fp, "%s", Lists.elem[i].name);
						for (n = 0;; n++) {
							if (feof(fp)) break;
							fscanf(fp, "%d", &Lists.elem[i].L.elem[n]);
							if (fgetc(fp) == '\n') break;
						}
						Lists.elem[i].L.length = n+1;
					}
					Lists.length = i-1;
					fclose(fp);
					printf("文件读取成功\n");
					break;
				}
				printf("多表有数据存在，不可读取！\n");
				break;
			}
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