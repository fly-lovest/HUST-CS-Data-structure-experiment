#include "def.h"

BiTree T;
LISTS Lists;

int num;  //操作序号
int i1;  //创造单树的全局变量
int i2;  //储存到数组的全局变量
int i3;  //查找函数的监控值
int number; //储存查找表的序号
char saveName[30];  //暂存表名


int main() {
	printf("-----------------基于二叉链表的二叉树系统--------------------\n\n");  //一级菜单
	printf("1.单树操作\t\t2.多树操作\t\t0.停止操作\n\n请输入你需要的操作：");

	scanf("%d", &num);
	if (num == 1) {       //单树操作（二级菜单）
		printf("\n-----------------单树操作菜单--------------------\n\
1.创造单树        2.销毁单树        3.树的深度\n\
4.查找结点        5.结点赋值        6.兄弟结点\n\
7.孩子结点        8.插入结点        9.删除结点\n\
10.先序遍历       11.中序遍历       12.后序遍历\n\
13.按层遍历       14.文件保存       15.文件读取\n\
0.停止操作        请输入【0~15】\n\n请输入你需要的操作：");
		scanf("%d", &num);  //输入操作
		while (num) {
			switch (num)
			{
			case 1: {  //创造单树
				if (T == NULL) {
					TElemType definition[100];
					int ans, i = 0;
					printf("请按先序输入数据：");
					do {
						scanf("%d%s", &definition[i].key, definition[i].others);
					} while (definition[i++].key != -1);
					i1 = -1; //i1初始化
					ans = CreateBiTree(T, definition);
					if (ans == OK)
					{
						printf("单树创建成功！前序遍历为：");
						PreOrderTraverse(T, visit);
						putchar('\n');
					}
					else printf("单树创建失败！关键字不唯一！\n");
				}
				else printf("树存在，无法创建！\n");
				break;
			}
			case 2: {  //销毁单树
				if (T != NULL) {
					ClearBiTree(T);
					printf("单树销毁成功！\n");
				}
				else printf("树为NULL，无需销毁！\n");
				break;
			}
			case 3: {  //树的深度
				if (T != NULL) {
					printf("此树深度为%d！\n", BiTreeDepth(T));
				}
				else printf("此树深度为0！\n");
				break;
			}
			case 4: {  //查找结点
				if (T != NULL) {
					BiTNode* ret_tree;
					int e;
					printf("请输入你想查找的关键字：");
					scanf("%d", &e);
					i3 = 0;
					ret_tree = LocateNode(T, e);
					if (ret_tree == NULL) printf("查找失败！\n");
					else printf("对应结点为 %d,%s\n", ret_tree->data.key, ret_tree->data.others);
				}
				else printf("树为NULL，查找失败！\n");
				break;
			}
			case 5: {  //结点赋值
				if (T != NULL) {
					TElemType e;
					int ans, key;
					printf("输入查找的关键字：");
					scanf("%d", &key);
					printf("输入你想替换的：");
					scanf("%d%s", &e.key, e.others);
					i2 = 0;
					ans = Assign(T, key, e);
					if (ans == OK) {
						printf("赋值成功，先序遍历为：");
						PreOrderTraverse(T, visit);
						printf("\n");
					}
					else printf("赋值操作失败！\n");

				}
				else printf("树为NULL，赋值操作失败！\n");
				break;
			}
			case 6: {  //兄弟结点
				if (T != NULL) {
					int key;
					BiTNode* Sibling;
					printf("请输入查找结点：");
					scanf("%d", &key);
					Sibling = GetSibling(T, key);
					if (Sibling) printf("兄弟结点为：%d,%s\n", Sibling->data.key, Sibling->data.others);
					else printf("无兄弟结点!\n");
				}
				else printf("树为NULL，无兄弟结点！\n");
				break;
			}
			case 7: {  //孩子结点
				if (T != NULL) {
					int key;
					BiTNode* ret_tree;
					printf("输入查找结点：");
					scanf("%d", &key);
					i3 = 0;
					ret_tree = LocateNode(T, key);
					if (ret_tree == NULL)printf("无孩子结点！\n");
					else {
						if (ret_tree->lchild == NULL && ret_tree->rchild == NULL)printf("无孩子结点！\n");
						if (ret_tree->lchild != NULL && ret_tree->rchild == NULL)printf("左孩子为%d,%s；右孩子不存在！\n", ret_tree->lchild->data.key, ret_tree->lchild->data.others);
						if (ret_tree->lchild == NULL && ret_tree->rchild != NULL)printf("左孩子不存在；右孩子为%d,%s！\n", ret_tree->rchild->data.key, ret_tree->rchild->data.others);
						if (ret_tree->lchild != NULL && ret_tree->rchild != NULL)printf("左孩子为%d,%s；右孩子为%d,%s！\n", ret_tree->lchild->data.key, ret_tree->lchild->data.others, ret_tree->rchild->data.key, ret_tree->rchild->data.others);
					}
				}
				else printf("树为NULL，无孩子结点！\n");
				break;
			}
			case 8: {  //插入结点
				if (T != NULL) {
					TElemType c;
					int ans, e, LR;
					printf("输入查找的关键字：");
					scanf("%d", &e);
					printf("输入插入的操作和插入数据【操作为-1、0、1】：");
					scanf("%d%d%s", &LR, &c.key, c.others);
					i2 = 0;
					ans = InsertNode(T, e, LR, c);
					if (ans == OK)
					{
						printf("插入成功，先序遍历为：");
						PreOrderTraverse(T, visit);
						printf("\n");
					}
					else printf("插入操作失败！\n");
				}
				else printf("树为NULL，插入操作失败！\n");
				break;
			}
			case 9: {  //删除结点
				if (T != NULL) {
					int e, ans;
					printf("请输入删除结点：");
					scanf("%d", &e);
					ans = DeleteNode(T, e);
					if (ans == OK)
					{
						printf("删除成功，先序遍历为：");
						PreOrderTraverse(T, visit);
						printf("\n");
					}
					else printf("删除操作失败！\n");
				}
				else printf("树为NULL，删除操作失败！\n");
				break;
			}
			case 10: {  //先序遍历
				if (T != NULL) {
					printf("先序遍历：");
					PreOrderTraverse(T, visit);
					putchar('\n');
				}
				else printf("树为NULL，遍历为空！\n");
				break;
			}
			case 11: {  //中序遍历
				if (T != NULL) {
					printf("中序遍历：");
					InOrderTraverse(T, visit);
					putchar('\n');
				}
				else printf("树为NULL，遍历为空！\n");
				break;
			}
			case 12: {  //后序遍历
				if (T != NULL) {
					printf("后序遍历：");
					PostOrderTraverse(T, visit);
					putchar('\n');
				}
				else printf("树为NULL，遍历为空！\n");
				break;
			}
			case 13: {  //按层遍历
				if (T != NULL) {
					printf("按层遍历：");
					LevelOrderTraverse(T, visit);
					putchar('\n');
				}
				else printf("树为NULL，遍历为空！\n");
				break;
			}
			case 14: {  //文件保存
				if (T != NULL) {
					char FileName[30] = "tree.txt";  //单表文件名
					if (SaveBiTree(T, FileName) == OK)printf("保存成功！\n");
				}
				else printf("树为NULL，保存失败！\n");
				break;
			}
			case 15: {  //文件读取
				if (T == NULL) {
					char FileName[30] = "tree.txt";  //储存文件名
					if (LoadBiTree(T, FileName) == OK)printf("读取成功！\n");
				}
				else printf("树不为空，无法读取文件！\n");
				break;
			}
			default:printf("输入错误，请重新输入！\n");
			}
			printf("\n请输入你需要的操作：");
			scanf("%d", &num);
		}
	}

	if (num == 2) {       //多表操作（二级菜单）
	Lists.length = 0;  //初始化Lists长度
	A:;
		printf("\n-----------------多树操作菜单--------------------\n\
1.创建多树        2.移除某树        3.查找某树\n\
4.单独操作        5.遍历多树        6.清空多树\n\
7.多树文件保存    8.多树文件读取\n\
0.停止操作        请输入【0~8】\n\n请输入你需要的操作：");
		scanf("%d", &num);
		while (num) {
			switch (num)
			{
			case 1: {  //创建多树
				printf("输入创建树的名称：");
				scanf("%s", saveName);
				printf("请按先序顺序输入数据【输入-1停止】：");
				TElemType definition[100];
				int ans, i = 0;
				do {
					scanf("%d%s", &definition[i].key, definition[i].others);
				} while (definition[i++].key != -1);
				if (definition[0].key == -1) { Lists.elem[Lists.length].T = NULL; strcpy(Lists.elem[Lists.length].name, saveName); Lists.length++; printf("创建成功！\n"); break; }
				if (Compare1(definition) == ERROR) { printf("创建失败！关键字不唯一！\n"); break; }
				AddList(Lists, saveName);
				i1 = -1; //i1初始化
				ans = CreateBiTree(Lists.elem[Lists.length-1].T, definition);
				if (ans == OK)
				{
					printf("创建成功！");
					putchar('\n');
				}
				else printf("创建失败！关键字不唯一！\n");
				break;
			}
			case 2: {  //移除某树
				printf("输入你想移除树的名称：");
				scanf("%s", saveName);
				if (RemoveList(Lists, saveName) == ERROR) { printf("无该名的二叉树！\n"); break; }
				else printf("删除成功！\n");
				break;
			}
			case 3: {  //查找某树
				printf("输入你想查找树的名称：");
				scanf("%s", saveName);
				if ((number = LocateList(Lists, saveName)) == ERROR) { printf("无该名的二叉树！\n"); break; }
				printf("查找成功：%s \n", saveName);

				if (Lists.elem[number - 1].T == NULL) { printf("树为NULL！\n"); break; }
				if (BiTreeDepth(Lists.elem[number - 1].T) == 0) { printf("树中无数据！\n"); break; }
				else {
					printf("先序遍历：");
					PreOrderTraverse(Lists.elem[number - 1].T,visit);
					putchar('\n');
				}
				break;
			}
			case 4: {  //单独操作
				printf("输入你想单独操作树的名称：");
				scanf("%s", saveName);
				if ((number = LocateList(Lists, saveName)) == ERROR) { printf("无该名称的二叉树！\n"); break; }  //三级菜单
				printf("\n-----------------多树操作中的单树操作菜单--------------------\n\
1.创造单树        2.销毁单树        3.树的深度\n\
4.查找结点        5.结点赋值        6.兄弟结点\n\
7.孩子结点        8.插入结点        9.删除结点\n\
10.先序遍历       11.中序遍历       12.后序遍历\n\
13.按层遍历       14.文件保存       15.文件读取\n\
16.返回多树菜单\n\
请输入【1~16】\n\n请输入你需要的操作：");
				scanf("%d", &num);   //输入操作
				while (num) {
					switch (num)
					{
					case 1: {  //创造单树
						if (Lists.elem[number - 1].T == NULL) {
							TElemType definition[100];
							int ans, i = 0;
							printf("请按先序输入数据：");
							do {
								scanf("%d%s", &definition[i].key, definition[i].others);
							} while (definition[i++].key != -1);
							i1 = -1; //i1初始化
							ans = CreateBiTree(Lists.elem[number - 1].T, definition);
							if (ans == OK)
							{
								printf("单树创建成功！前序遍历为：");
								PreOrderTraverse(Lists.elem[number - 1].T, visit);
								putchar('\n');
							}
							else printf("单树创建失败！关键字不唯一！\n");
						}
						else printf("树存在，无法创建！\n");
						break;
					}
					case 2: {  //销毁单树
						if (Lists.elem[number - 1].T != NULL) {
							ClearBiTree(Lists.elem[number - 1].T);
							printf("单树销毁成功！\n");
						}
						else printf("树为NULL，无需销毁！\n");
						break;
					}
					case 3: {  //树的深度
						if (Lists.elem[number - 1].T != NULL) {
							printf("此树深度为%d！\n", BiTreeDepth(Lists.elem[number - 1].T));
						}
						else printf("此树深度为0！\n");
						break;
					}
					case 4: {  //查找结点
						if (Lists.elem[number - 1].T != NULL) {
							BiTNode* ret_tree;
							int e;
							printf("请输入你想查找的关键字：");
							scanf("%d", &e);
							i3 = 0;
							ret_tree = LocateNode(Lists.elem[number - 1].T, e);
							if (ret_tree == NULL) printf("查找失败！\n");
							else printf("对应结点为 %d,%s\n", ret_tree->data.key, ret_tree->data.others);
						}
						else printf("树为NULL，查找失败！\n");
						break;
					}
					case 5: {  //结点赋值
						if (Lists.elem[number - 1].T != NULL) {
							TElemType e;
							int ans, key;
							printf("输入查找的关键字：");
							scanf("%d", &key);
							printf("输入你想替换的：");
							scanf("%d%s", &e.key, e.others);
							i2 = 0;
							ans = Assign(Lists.elem[number - 1].T, key, e);
							if (ans == OK) {
								printf("赋值成功，先序遍历为：");
								PreOrderTraverse(Lists.elem[number - 1].T, visit);
								printf("\n");
							}
							else printf("赋值操作失败！\n");

						}
						else printf("树为NULL，赋值操作失败！\n");
						break;
					}
					case 6: {  //兄弟结点
						if (Lists.elem[number - 1].T != NULL) {
							int key;
							BiTNode* Sibling;
							printf("请输入查找结点：");
							scanf("%d", &key);
							Sibling = GetSibling(Lists.elem[number - 1].T, key);
							if (Sibling) printf("兄弟结点为：%d,%s\n", Sibling->data.key, Sibling->data.others);
							else printf("无兄弟结点!\n");
						}
						else printf("树为NULL，无兄弟结点！\n");
						break;
					}
					case 7: {  //孩子结点
						if (Lists.elem[number - 1].T != NULL) {
							int key;
							BiTNode* ret_tree;
							printf("输入查找结点：");
							scanf("%d", &key);
							i3 = 0;
							ret_tree = LocateNode(Lists.elem[number - 1].T, key);
							if (ret_tree == NULL)printf("无孩子结点！\n");
							else {
								if (ret_tree->lchild == NULL && ret_tree->rchild == NULL)printf("无孩子结点！\n");
								if (ret_tree->lchild != NULL && ret_tree->rchild == NULL)printf("左孩子为%d,%s；右孩子不存在！\n", ret_tree->lchild->data.key, ret_tree->lchild->data.others);
								if (ret_tree->lchild == NULL && ret_tree->rchild != NULL)printf("左孩子不存在；右孩子为%d,%s！\n", ret_tree->rchild->data.key, ret_tree->rchild->data.others);
								if (ret_tree->lchild != NULL && ret_tree->rchild != NULL)printf("左孩子为%d,%s；右孩子为%d,%s！\n", ret_tree->lchild->data.key, ret_tree->lchild->data.others, ret_tree->rchild->data.key, ret_tree->rchild->data.others);
							}
						}
						else printf("树为NULL，无孩子结点！\n");
						break;
					}
					case 8: {  //插入结点
						if (Lists.elem[number - 1].T != NULL) {
							TElemType c;
							int ans, e, LR;
							printf("输入查找的关键字：");
							scanf("%d", &e);
							printf("输入插入的操作和插入数据【操作为-1、0、1】：");
							scanf("%d%d%s", &LR, &c.key, c.others);
							i2 = 0;
							ans = InsertNode(Lists.elem[number - 1].T, e, LR, c);
							if (ans == OK)
							{
								printf("插入成功，先序遍历为：");
								PreOrderTraverse(Lists.elem[number - 1].T, visit);
								printf("\n");
							}
							else printf("插入操作失败！\n");
						}
						else printf("树为NULL，插入操作失败！\n");
						break;
					}
					case 9: {  //删除结点
						if (Lists.elem[number - 1].T != NULL) {
							int e, ans;
							printf("请输入删除结点：");
							scanf("%d", &e);
							ans = DeleteNode(Lists.elem[number - 1].T, e);
							if (ans == OK)
							{
								printf("删除成功，先序遍历为：");
								PreOrderTraverse(Lists.elem[number - 1].T, visit);
								printf("\n");
							}
							else printf("删除操作失败！\n");
						}
						else printf("树为NULL，删除操作失败！\n");
						break;
					}
					case 10: {  //先序遍历
						if (Lists.elem[number - 1].T != NULL) {
							printf("先序遍历：");
							PreOrderTraverse(Lists.elem[number - 1].T, visit);
							putchar('\n');
						}
						else printf("树为NULL，遍历为空！\n");
						break;
					}
					case 11: {  //中序遍历
						if (Lists.elem[number - 1].T != NULL) {
							printf("中序遍历：");
							InOrderTraverse(Lists.elem[number - 1].T, visit);
							putchar('\n');
						}
						else printf("树为NULL，遍历为空！\n");
						break;
					}
					case 12: {  //后序遍历
						if (Lists.elem[number - 1].T != NULL) {
							printf("后序遍历：");
							PostOrderTraverse(Lists.elem[number - 1].T, visit);
							putchar('\n');
						}
						else printf("树为NULL，遍历为空！\n");
						break;
					}
					case 13: {  //按层遍历
						if (Lists.elem[number - 1].T != NULL) {
							printf("按层遍历：");
							LevelOrderTraverse(Lists.elem[number - 1].T, visit);
							putchar('\n');
						}
						else printf("树为NULL，遍历为空！\n");
						break;
					}
					case 14: {  //文件保存
						if (Lists.elem[number - 1].T != NULL) {
							char FileName[30] = "tree.txt";  //单表文件名
							if (SaveBiTree(Lists.elem[number - 1].T, FileName) == OK)printf("保存成功！\n");
						}
						else printf("树为NULL，保存失败！\n");
						break;
					}
					case 15: {  //文件读取
						if (Lists.elem[number - 1].T == NULL) {
							char FileName[30] = "tree.txt";  //储存文件名
							if (LoadBiTree(Lists.elem[number - 1].T, FileName) == OK)printf("读取成功！\n");
						}
						else printf("树不为空，无法读取文件！\n");
						break;
					}
					case 16: {  //返回多表菜单
						goto A;
						break;
					}
					default:printf("输入错误，请重新输入！\n");
					}
					printf("\n请输入你需要的操作：");
					scanf("%d", &num);
				}
			}
			case 5: {  //遍历多树
				if (Lists.length == 0) { printf("多树无数据！\n"); break; }
				int i;
				for (i = 0; i < Lists.length; i++) {
					printf("%s ", Lists.elem[i].name);
					if (Lists.elem[i].T == NULL) { printf("无数据！\n"); continue; }
					if (BiTreeDepth(Lists.elem[i].T) == 0) { printf("无数据！\n"); continue; }
					else {
						printf("先序遍历：");
						PreOrderTraverse(Lists.elem[i].T,visit);
						putchar('\n');
					}
				}
				break;
			}
			case 6: {  //清空多树
				if (Lists.length == 0) { printf("销毁成功！\n"); break; }
				Lists.length = 0;
				printf("销毁成功！\n");
				break;

			}
			case 7: {  //文件保存（多树）
				char Listsname[30] = "trees.txt"; //多表文件名
				if (Lists.length != 0) {
					int i; 
					FILE* fp = fopen(Listsname, "w");
					for (i = 0; i < Lists.length; i++) {
						MoreSaveBiTree(Lists.elem[i].name, Lists.elem[i].T, fp);
						if(i!=Lists.length-1)fprintf(fp, "\n");
					}
					fclose(fp);
					printf("保存成功！\n");
					break;
				}
				printf("无数据可保存！\n");
				break;
			}
			case 8: {  //文件读取（多树）
				char Listsname[30] = "trees.txt"; //多表文件名
				if (Lists.length == 0) {
					int i;
					FILE* fp = fopen(Listsname, "r");
					for (i = 0; ; i++) {
						fscanf(fp, "%s", Lists.elem[i].name);
						MoreLoadBiTree(Lists.elem[i].T, fp);
						Lists.length++;
						if (feof(fp)) break;
						
					}
					printf("读取成功！\n");
					break;
				}
				printf("多树管理表有数据存在，不可读取！\n");
				break;
			}
			default:printf("输入错误，请重新输入！\n");
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


/*函数*/

status Compare1(TElemType definition[]){ //比较结构数组里面有没有相同的关键字
	int j, k;
	for (j = 0; definition[j].key != -1; j++) {
		if (definition[j].key != 0) {
			for (k = j + 1; definition[k].key != -1; k++) {
				if (definition[k].key == definition[j].key)
					return ERROR;
			}
		}
	}
}

status CreateBiTree(BiTree& T, TElemType definition[])//根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，如果有相同的关键字，返回ERROR。
{
	if (Compare1(definition) == ERROR) return ERROR;
	i1++;
	if (definition[i1].key == 0) T = NULL;
	else {
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
		T->data.key = definition[i1].key;
		strcpy(T->data.others, definition[i1].others);
		CreateBiTree(T->lchild, definition);
		CreateBiTree(T->rchild, definition);
	}
	return OK;
}

void visit(BiTree T)
{
	printf(" %d,%s", T->data.key, T->data.others);
}

status ClearBiTree(BiTree& T)//将二叉树设置成空，并删除所有结点，释放结点空间
{
	if (T) {
		ClearBiTree(T->lchild);
		ClearBiTree(T->rchild);
		free(T);
		T = NULL;
	}
	return OK;
}

int BiTreeDepth(BiTree T)//求二叉树T的深度
{
	if (T) {

		int nLeft = BiTreeDepth(T->lchild);
		int nRight = BiTreeDepth(T->rchild);
		return nLeft > nRight ? nLeft + 1 : nRight + 1;
	}
	else return 0;
}

BiTNode* LocateNode(BiTree T, KeyType e)//查找结点
{
static	BiTNode* ret_tree=NULL;

	if (T) {
		if (e == T->data.key) {
			ret_tree = T;
			i3++;
		}
			ret_tree = LocateNode(T->lchild, e);
			ret_tree = LocateNode(T->rchild, e);
	}
	if (i3 == 0)ret_tree = NULL;
	return ret_tree;
}

void SaveKey(KeyType save[], BiTree T) { //将T元素保存到数组；
	if (T) {
		save[i2] = T->data.key;
		i2++;
		save[i2] = -1;
		SaveKey(save, T->lchild);
		SaveKey(save, T->rchild);
	}
	return;
}

status Compare2(KeyType definition[], KeyType e, KeyType E) { //查找重复关键字
	int j = 0, k = 0;
	while (definition[j] != e && definition[j] != -1) {
		j++;
	}
	while (definition[k] != E && definition[k] != -1) {
		k++;
	}
	if (j == k || definition[k] == -1)return OK;
	else return ERROR;
}

status Assign(BiTree& T, KeyType e, TElemType value)//实现结点赋值
{
	BiTNode* ret_tree;
	i3 = 0;
	if ((ret_tree = LocateNode(T, e)) == NULL)return ERROR;
	KeyType save[100];//保存到数组
	SaveKey(save, T);
	if (Compare2(save, e, value.key) == ERROR) return ERROR;
	ret_tree->data.key = value.key;
	strcpy(ret_tree->data.others, value.others);
	return OK;
}

BiTNode* GetSibling(BiTree T, KeyType e)//实现获得兄弟结点
{
	BiTNode* ret_tree = NULL;
	if (T) {
		if (T->rchild != NULL && e == T->rchild->data.key) { ret_tree = T->lchild; return ret_tree; }
		if (T->lchild != NULL && e == T->lchild->data.key) { ret_tree = T->rchild; return ret_tree; }

		ret_tree = GetSibling(T->lchild, e);
		ret_tree = GetSibling(T->rchild, e);
	}
	return ret_tree;
}

status Compare3(KeyType definition[], KeyType E) { //查找重复关键字
	int k = 0;
	while (definition[k] != E && definition[k] != -1) {
		k++;
	}
	if (definition[k] == -1)return OK;
	else return ERROR;
}

status InsertNode(BiTree& T, KeyType e, int LR, TElemType c)//插入结点
{
	BiTNode* ret_tree, * new_tree;
	new_tree = (BiTNode*)malloc(sizeof(BiTNode));
	new_tree->rchild = NULL;
	new_tree->lchild = NULL;
	i3 = 0;
	if ((ret_tree = LocateNode(T, e)) == NULL) return ERROR;
	KeyType save[100];
	SaveKey(save, T);
	if (Compare3(save, c.key) == ERROR)return ERROR;

	if (LR == 0) {
		new_tree->rchild = ret_tree->lchild;
		ret_tree->lchild = new_tree;
		new_tree->data.key = c.key;
		strcpy(new_tree->data.others, c.others);
		return OK;
	}
	if (LR == 1) {
		new_tree->rchild = ret_tree->rchild;
		ret_tree->rchild = new_tree;
		new_tree->data.key = c.key;
		strcpy(new_tree->data.others, c.others);
		return OK;
	}
	if (LR == -1) {
		new_tree->rchild = T->rchild;
		new_tree->lchild = T->lchild;
		T->rchild = new_tree;
		T->lchild = NULL;
		new_tree->data.key = T->data.key;
		strcpy(new_tree->data.others, T->data.others);
		T->data.key = c.key;
		strcpy(T->data.others, c.others);
		return OK;
	}
}

BiTNode* GetBefore(BiTree T, KeyType e)//实现获得父亲结点
{
	BiTNode* ret_tree = NULL;
	if (T) {
		if (T->rchild != NULL && e == T->rchild->data.key) { ret_tree = T; return ret_tree; }
		if (T->lchild != NULL && e == T->lchild->data.key) { ret_tree = T; return ret_tree; }

		ret_tree = GetBefore(T->lchild, e);
		ret_tree = GetBefore(T->rchild, e);
	}
	return ret_tree;
}

status DeleteNode(BiTree& T, KeyType e)//删除结点
{
	BiTNode* bef_tree, * rtree, * ltree;
	if (T->data.key == e) {
		if (T->rchild == NULL && T->lchild == NULL) { free(T); T = NULL; return OK; }
		if (T->rchild == NULL && T->lchild != NULL) { bef_tree = T; T = T->lchild; free(bef_tree); return OK; }
		if (T->rchild != NULL && T->lchild == NULL) { bef_tree = T; T = T->rchild; free(bef_tree); return OK; }
		if (T->rchild != NULL && T->lchild != NULL) {
			bef_tree = T;
			ltree = T->lchild;
			while (ltree->rchild != NULL) {
				ltree = ltree->rchild;
			}
			ltree->rchild = T->rchild;
			T = T->lchild;
			free(bef_tree);
			return OK;
		}
	}
	bef_tree = GetBefore(T, e);
	if (bef_tree == NULL)return ERROR;
	if (bef_tree->rchild != NULL && bef_tree->rchild->data.key == e) {
		rtree = bef_tree->rchild;
		if (rtree->rchild == NULL && rtree->lchild == NULL) { free(rtree); bef_tree->rchild = NULL; return OK; }
		if (rtree->rchild == NULL && rtree->lchild != NULL) { bef_tree->rchild = rtree->lchild; free(rtree); return OK; }
		if (rtree->rchild != NULL && rtree->lchild == NULL) { bef_tree->rchild = rtree->rchild; free(rtree); return OK; }
		if (rtree->rchild != NULL && rtree->lchild != NULL) {
			bef_tree->rchild = rtree->lchild;
			ltree = rtree->lchild;
			while (ltree->rchild != NULL) {
				ltree = ltree->rchild;
			}
			ltree->rchild = rtree->rchild;
			free(rtree);
			return  OK;
		}
	}

	if (bef_tree->lchild != NULL && bef_tree->lchild->data.key == e) {
		ltree = bef_tree->lchild;
		if (ltree->rchild == NULL && ltree->lchild == NULL) { free(ltree); bef_tree->lchild = NULL; return OK; }
		if (ltree->rchild == NULL && ltree->lchild != NULL) { bef_tree->lchild = ltree->lchild; free(ltree); return OK; }
		if (ltree->rchild != NULL && ltree->lchild == NULL) { bef_tree->lchild = ltree->rchild; free(ltree); return OK; }
		if (ltree->rchild != NULL && ltree->lchild != NULL) {
			bef_tree->lchild = ltree->lchild;
			rtree = ltree->lchild;
			while (rtree->rchild != NULL) {
				rtree = rtree->rchild;
			}
			rtree->rchild = ltree->rchild;
			free(ltree);
			return  OK;
		}
	}
}

status PreOrderTraverse(BiTree T, void (*visit)(BiTree))//先序遍历二叉树T
{
	if (T) {
		visit(T);
		PreOrderTraverse(T->lchild, visit);
		PreOrderTraverse(T->rchild, visit);
	}
	return OK;
}

status InOrderTraverse(BiTree T, void (*visit)(BiTree))//中序遍历二叉树T
{
	struct BiTNode* st[100];
	//定义指针栈st[0..maxleng-1]，用于保存访问过的结点，
	//在后续操作中访问该结点的右孩子
	int top = 0;      //置空栈
	do {
		while (T) {            //根指针t表示的为非空二叉树 
			if (top == 100) exit(OVERFLOW);//栈已满,退出
			st[top++] = T;             //根指针进栈
			T = T->lchild;              //t移向左子树
		}
		//循环结束表示以栈顶元素的指向为根的结点左子树遍历结束
		if (top) {                       //为非空栈   
			T = st[--top];            //弹出根指针
			visit(T);    //访问根结点
			T = T->rchild;                 //准备遍历右子树
		}
	} while (top || T); //父结点未访问，或右子树未遍历
	return OK;
}

status PostOrderTraverse(BiTree T, void (*visit)(BiTree))//后序遍历二叉树T
{
	if (T) {
		PostOrderTraverse(T->lchild, visit);
		PostOrderTraverse(T->rchild, visit);
		visit(T);
	}
	return OK;
}

status LevelOrderTraverse(BiTree T, void (*visit)(BiTree))//按层遍历二叉树T
{
	BiTree sq[100];
	int out = 0, in = 0;
	sq[in] = T;
	in++;
	while (in - out) {
		T = sq[out];
		visit(T);
		if (T->lchild) {
			sq[in] = T->lchild;
			in++;
		}
		if (T->rchild) {
			sq[in] = T->rchild;
			in++;
		}
		out++;
	}
	return OK;
}

void SaveFile(BiTree T, FILE* fp) { //辅助文件保存
	if (T) {
		fprintf(fp, " %d %s", T->data.key, T->data.others);
		if (T->lchild == NULL) fprintf(fp, " 0 null");
		SaveFile(T->lchild, fp);
		if (T->rchild == NULL) fprintf(fp, " 0 null");
		SaveFile(T->rchild, fp);
	}
}

status SaveBiTree(BiTree T, char FileName[])//将二叉树的结点数据写入到文件FileName中
{
	FILE* fp = fopen(FileName, "w");
	SaveFile(T, fp);
	fclose(fp);
	return OK;
}

status LoadBiTree(BiTree& T, char FileName[])//读入文件FileName的结点数据，创建二叉树
{
	FILE* fp = fopen(FileName, "r");
	int n = 0;
	TElemType definition[100];
	while (!feof(fp)) {
		fscanf(fp, "%d%s", &definition[n].key, definition[n].others);
		n++;
	}
	definition[n++].key = -1;
	if (Compare1(definition) == ERROR) { fclose(fp); return ERROR; }
	i1 = -1;
	CreateBiTree(T, definition);
	fclose(fp);
	return OK;
}

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

status LocateList(LISTS Lists, char ListName[])// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回ERROR
{
	int n;
	for (n = 0; n < Lists.length; n++) {
		if (!strcmp(Lists.elem[n].name, ListName)) return (n + 1);

	}
	return ERROR;
}

status AddList(LISTS& Lists, char ListName[])//创建表名
{
	Lists.elem[Lists.length].T = NULL;
	strcpy(Lists.elem[Lists.length].name, ListName);
	Lists.length++;
	return OK;
}

status MoreSaveBiTree(char name[],BiTree T,FILE *fp)//将二叉树的结点数据写入到文件FileName中
{
	fprintf(fp, "%s", name);
	SaveFile(T, fp);
	return OK;
}

status MoreLoadBiTree(BiTree& T, FILE* fp)
//读入文件FileName的结点数据，创建二叉树
{
	KeyType key;
	char others[20];
	fscanf(fp, "%d %s", &key, others);
	if (key != 0) {
		T = (BiTree)malloc(sizeof(BiTNode));
		if (key != -1) {
			T->data.key = key;
			strcpy(T->data.others, others);
			MoreLoadBiTree(T->lchild, fp);
			MoreLoadBiTree(T->rchild, fp);
		}
	}
	else if (key == 0) {
		T = NULL;
		return OK;
	}
	return OK;
}

