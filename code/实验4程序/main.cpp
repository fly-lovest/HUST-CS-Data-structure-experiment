#include "def.h"

ALGraph G;
LISTS Lists;

int num;  //操作序号
int number; //储存查找图的序号
char saveName[30];  //暂存图名


int main() {
	printf("-----------------基于邻接表的无向图系统--------------------\n\n");  //一级菜单
	printf("1.单图操作\t\t2.多图操作\t\t0.停止操作\n\n请输入你需要的操作：");

	scanf("%d", &num);
	if (num == 1) {       //单图操作（二级菜单）
		printf("\n-----------------单图操作菜单--------------------\n\
1.创建图           2.销毁图             3.查找顶点\n\
4.顶点赋值         5.获得第一邻接顶点   6.获得下一邻接点\n\
7.插入顶点         8.删除顶点           9.插入弧\n\
10.删除弧          11.深度优先搜索遍历  12.广度优先搜索遍历\n\
13.文件保存        14.文件读取          0.停止操作\n\
请输入【0~14】\n\n请输入你需要的操作：");
		G.vexnum = 0, G.arcnum = 0;//初始化顶点数和边数
		scanf("%d", &num);  //输入操作
		while (num) {
			switch (num)
			{
			case 1: {  //创建图
				if (G.vexnum == 0) {
					VertexType V[30];
					KeyType VR[100][2];
					int ans, i = 0;
					printf("请输入顶点数据【以-1为结尾】：");
					do {
						scanf("%d%s", &V[i].key, V[i].others);
					} while (V[i++].key != -1);
					printf("请输入弧数据【以-1为结尾】：");
					i = 0;
					do {
						scanf("%d%d", &VR[i][0], &VR[i][1]);
					} while (VR[i++][0] != -1);
					ans = CreateCraph(G,V,VR);
					if (ans == OK)
					{
						printf("无向图创建成功！遍历为：\n");
						for (i = 0; i < G.vexnum; i++)
						{
							ArcNode* p = G.vertices[i].firstarc;
							printf("%d %s", G.vertices[i].data.key, G.vertices[i].data.others);
							while (p)
							{
								printf(" %d", p->adjvex);
								p = p->nextarc;
							}
							printf("\n");
						}
						printf("\n");
					}
					else printf("无向图创建失败！\n");
				}
				else printf("无向图图存在，无法创建！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 2: {  //销毁图
				if (G.vexnum != 0) {
					DestroyGraph(G);
					printf("无向图销毁成功！\n");
				}
				else printf("无向图为空，无需销毁！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 3: {  //查找顶点
				if (G.vexnum != 0) {
					int e,ans;
					printf("请输入你想查找结点的关键字：");
					scanf("%d", &e);
					ans = LocateVex(G, e);
					if (ans == -1) printf("查找失败！\n");
					else printf("对应结点为 %d,%s\n", G.vertices[ans].data.key, G.vertices[ans].data.others);
				}
				else printf("无向图为空，查找失败！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 4: {  //顶点赋值
				if (G.vexnum != 0) {
					VertexType e;
					int ans, key;
					printf("输入替换的顶点关键字：");
					scanf("%d", &key);
					printf("输入赋值：");
					scanf("%d%s", &e.key, e.others);

					ans = PutVex(G, key, e);
					if (ans == OK) {
						printf("赋值成功，深度搜索遍历为：");
						BFSTraverse(G, visit);
						printf("\n");
					}
					else printf("赋值操作失败！\n");

				}
				else printf("无向图图为空，赋值操作失败！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 5: {  //获得第一邻接点
				if (G.vexnum != 0) {
					int key,ans;
					printf("请输入需要获得第一邻接顶点的关键字：");
					scanf("%d", &key);
					ans = FirstAdjVex(G, key);
					if (ans==-2) printf("顶点无第一邻接顶点\n");
					if(ans==-1)printf("无该顶点!\n");
					if(ans>=0) printf("%d结点的第一邻接点是%d,%s\n", key, G.vertices[ans].data.key, G.vertices[ans].data.others);
				}
				else printf("无向图为空！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 6: {  //获得下一邻接点
				if (G.vexnum != 0) {
					int key,relat,ans;
					printf("输入待查找结点和相对结点：");
					scanf("%d%d", &key,&relat);
					ans = NextAdjVex(G, key,relat);
					if (ans == -1)printf("获取失败！\n");
					else {
						printf("%d相对于%d的顶点为%d,%s\n", key, relat, G.vertices[ans].data.key, G.vertices[ans].data.others);
					}
				}
				else printf("无向图为空，获取失败！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 7: {  //插入顶点
				if (G.vexnum != 0) {
					VertexType e;
					int ans,i;
					printf("输入待插入的顶点数据：");
					scanf("%d%s", &e.key,e.others);
					ans = InsertVex(G, e);
					if (ans == OK)
					{
						printf("插入成功，遍历为：\n");
						for (i = 0; i < G.vexnum; i++)
						{
							ArcNode* p = G.vertices[i].firstarc;
							printf("%d %s", G.vertices[i].data.key, G.vertices[i].data.others);
							while (p)
							{
								printf(" %d", p->adjvex);
								p = p->nextarc;
							}
							printf("\n");
						}
						printf("\n");
					}
					else printf("插入操作失败！\n");
				}
				else printf("无向图为空，请先创建图！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 8: {  //删除顶点
				if (G.vexnum != 0) {
					int e, ans,i;
					printf("请输入删除结点：");
					scanf("%d", &e);
					ans = DeleteVex(G, e);
					if (ans == OK)
					{
						printf("删除成功，遍历为：\n");
						for (i = 0; i < G.vexnum; i++)
						{
							ArcNode* p = G.vertices[i].firstarc;
							printf("%d %s", G.vertices[i].data.key, G.vertices[i].data.others);
							while (p)
							{
								printf(" %d", p->adjvex);
								p = p->nextarc;
							}
							printf("\n");
						}
						printf("\n");
					}
					else printf("删除操作失败！\n");
				}
				else printf("图为空，删除操作失败！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 9: {  //添加弧
				if (G.vexnum != 0) {
					int ans, i,v,w;
					printf("输入待插入的弧数据：");
					scanf("%d%d", &v, &w);
					ans = InsertArc(G, v,w);
					if (ans == OK)
					{
						printf("添加成功，遍历为：\n");
						for (i = 0; i < G.vexnum; i++)
						{
							ArcNode* p = G.vertices[i].firstarc;
							printf("%d %s", G.vertices[i].data.key, G.vertices[i].data.others);
							while (p)
							{
								printf(" %d", p->adjvex);
								p = p->nextarc;
							}
							printf("\n");
						}
						printf("\n");
					}
					else printf("插入操作失败！\n");
				}
				else printf("无向图为空，请先创建图！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 10: {  //删除弧
				if (G.vexnum != 0) {
					int v,w, ans, i;
					printf("请输入删除弧：");
					scanf("%d%d", &v,&w);
					ans = DeleteArc(G, v,w);
					if (ans == OK)
					{
						printf("删除成功，遍历为：\n");
						for (i = 0; i < G.vexnum; i++)
						{
							ArcNode* p = G.vertices[i].firstarc;
							printf("%d %s", G.vertices[i].data.key, G.vertices[i].data.others);
							while (p)
							{
								printf(" %d", p->adjvex);
								p = p->nextarc;
							}
							printf("\n");
						}
						printf("\n");
					}
					else printf("删除操作失败！\n");
				}
				else printf("图为空，删除操作失败！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 11: {  //深度遍历
				if (G.vexnum!= 0) {
					printf("深度优先搜索遍历：");
					DFSTraverse(G, visit);
					putchar('\n');
				}
				else printf("遍历为空！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 12: {  //广度遍历
				if (G.vexnum != 0) {
					printf("广度优先搜索遍历：");
					BFSTraverse(G, visit);
					putchar('\n');
				}
				else printf("遍历为空！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 13: {  //文件保存
				if (G.vexnum != 0) {
					char FileName[30] = "ALGraph.txt";  //目标文件名
					if (SaveGraph(G, FileName) == OK)printf("保存成功！\n");
				}
				else printf("图为空，保存失败！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 14: {  //文件读取
				if (G.vexnum == 0) {
					char FileName[30] = "ALGraph.txt";  //目标文件名
					if (LoadGraph(G, FileName) == OK)printf("读取成功！\n");
				}
				else printf("图不为空，无法读取文件！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			default: {printf("输入错误，请重新输入！\n"); getchar(); getchar();system("cls"); }
			}
			print1();
			scanf("%d", &num);
		}
	}

	if (num == 2) {       //多图操作（二级菜单）
		Lists.length = 0;  //初始化Lists长度
	A:;
		printf("\n-----------------多图操作菜单--------------------\n\
1.创建多图        2.移除某图        3.查找某图\n\
4.单独操作        5.遍历多图        6.清空多图\n\
7.多图文件保存    8.多图文件读取\n\
0.停止操作        请输入【0~8】\n\n请输入你需要的操作：");
		scanf("%d", &num);
		while (num) {
			switch (num)
			{
			case 1: {  //创建多图
				printf("输入创建图的名称：");
				scanf("%s", saveName);
	
				VertexType V[30];
				KeyType VR[100][2];
				int ans, i = 0;
				printf("请输入顶点数据【以-1为结尾】：");
				do {
					scanf("%d%s", &V[i].key, V[i].others);
				} while (V[i++].key != -1);
				printf("请输入弧数据【以-1为结尾】：");
				i = 0;
				do {
					scanf("%d%d", &VR[i][0], &VR[i][1]);
				} while (VR[i++][0] != -1);
				ans = CreateCraph(Lists.elem[Lists.length].G, V,VR);
				if (ans == OK)
				{
					AddList(Lists, saveName);
					printf("创建成功！");
					putchar('\n');
				}
				else printf("创建失败！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 2: {  //移除某图
				printf("输入你想移除图的名称：");
				scanf("%s", saveName);
				if (RemoveList(Lists, saveName) == ERROR) { printf("无该名的无向图！\n"); }
				else printf("删除成功！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 3: {  //查找某图
				printf("输入你想查找树的名称：");
				scanf("%s", saveName);
				if ((number = LocateList(Lists, saveName)) == ERROR) { printf("无该名的无向图！\n"); getchar(); getchar(); system("cls"); break; }
				printf("查找成功：%s \n", saveName);

				if (Lists.elem[number - 1].G.vexnum == 0) { printf("无数据！\n");  }
				else {
					printf("广度搜索遍历：");
					BFSTraverse(Lists.elem[number - 1].G, visit);
					putchar('\n');
				}
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 4: {  //单独操作
				printf("输入你想单独操作图的名称：");
				scanf("%s", saveName);
				if ((number = LocateList(Lists, saveName)) == ERROR) { printf("无该名称的无向图！\n"); getchar(); getchar(); system("cls"); break; }  //三级菜单
				printf("\n-----------------多图操作中的单图操作菜单--------------------\n\
1.创建图           2.销毁图             3.查找顶点\n\
4.顶点赋值         5.获得第一邻接顶点   6.获得下一邻接点\n\
7.插入顶点         8.删除顶点           9.插入弧\n\
10.删除弧          11.深度优先搜索遍历  12.广度优先搜索遍历\n\
13.文件保存        14.文件读取          15.返回多图菜单\n\
请输入【1~15】\n\n请输入你需要的操作：");
				scanf("%d", &num);   //输入操作
				while (num) {
					switch (num)
					{
					case 1: {  //创建图
						if (Lists.elem[number-1].G.vexnum == 0) {
							VertexType V[30];
							KeyType VR[100][2];
							int ans, i = 0;
							printf("请输入结点数据【以-1为结尾】：");
							do {
								scanf("%d%s", &V[i].key, V[i].others);
							} while (V[i++].key != -1);
							printf("请输入弧数据【以-1为结尾】：");
							i = 0;
							do {
								scanf("%d%d", &VR[i][0], &VR[i][1]);
							} while (VR[i++][0] != -1);
							ans = CreateCraph(Lists.elem[number - 1].G, V, VR);
							if (ans == OK)
							{
								printf("无向图创建成功！遍历为：\n");
								for (i = 0; i < Lists.elem[number-1].G.vexnum; i++)
								{
									ArcNode* p = Lists.elem[number-1].G.vertices[i].firstarc;
									printf("%d %s", Lists.elem[number-1].G.vertices[i].data.key, Lists.elem[number-1].G.vertices[i].data.others);
									while (p)
									{
										printf(" %d", p->adjvex);
										p = p->nextarc;
									}
									printf("\n");
								}
								printf("\n");
							}
							else printf("无向图创建失败！\n");
						}
						else printf("无向图图存在，无法创建！\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 2: {  //销毁图
						if (Lists.elem[number-1].G.vexnum != 0) {
							DestroyGraph(Lists.elem[number-1].G);
							printf("无向图销毁成功！\n");
						}
						else printf("无向图为空，无需销毁！\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 3: {  //查找顶点
						if (Lists.elem[number - 1].G.vexnum != 0) {
							int e, ans;
							printf("请输入你想查找结点的关键字：");
							scanf("%d", &e);
							ans = LocateVex(Lists.elem[number - 1].G, e);
							if (ans == -1) printf("查找失败！\n");
							else printf("对应结点为 %d,%s\n", Lists.elem[number - 1].G.vertices[ans].data.key, Lists.elem[number - 1].G.vertices[ans].data.others);
						}
						else printf("无向图为空，查找失败！\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 4: {  //顶点赋值
						if (Lists.elem[number - 1].G.vexnum != 0) {
							VertexType e;
							int ans, key;
							printf("输入替换的顶点关键字：");
							scanf("%d", &key);
							printf("输入赋值：");
							scanf("%d%s", &e.key, e.others);

							ans = PutVex(Lists.elem[number - 1].G, key, e);
							if (ans == OK) {
								printf("赋值成功，深度搜索遍历为：");
								BFSTraverse(Lists.elem[number - 1].G, visit);
								printf("\n");
							}
							else printf("赋值操作失败！\n");

						}
						else printf("无向图图为空，赋值操作失败！\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 5: {  //获得第一邻接点
						if (Lists.elem[number - 1].G.vexnum != 0) {
							int key, ans;
							printf("请输入需要获得第一邻接顶点的关键字：");
							scanf("%d", &key);
							ans = FirstAdjVex(Lists.elem[number - 1].G, key);
							if (ans == -2) printf("顶点无第一邻接顶点\n");
							if (ans == -1)printf("无该顶点!\n");
							if (ans >= 0) printf("%d结点的第一邻接点是%d,%s\n", key, Lists.elem[number - 1].G.vertices[ans].data.key, Lists.elem[number - 1].G.vertices[ans].data.others);
						}
						else printf("无向图为空！\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 6: {  //获得下一邻接点
						if (Lists.elem[number - 1].G.vexnum != 0) {
							int key, relat, ans;
							printf("输入待查找结点和相对结点：");
							scanf("%d%d", &key, &relat);
							ans = NextAdjVex(Lists.elem[number - 1].G, key, relat);
							if (ans == -1)printf("获取失败！\n");
							else {
								printf("%d相对于%d的顶点为%d,%s\n", key, relat, Lists.elem[number - 1].G.vertices[ans].data.key, Lists.elem[number - 1].G.vertices[ans].data.others);
							}
						}
						else printf("无向图为空，获取失败！\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 7: {  //插入顶点
						if (Lists.elem[number - 1].G.vexnum != 0) {
							VertexType e;
							int ans, i;
							printf("输入待插入的顶点数据：");
							scanf("%d%s", &e.key, e.others);
							ans = InsertVex(Lists.elem[number - 1].G, e);
							if (ans == OK)
							{
								printf("插入成功，遍历为：\n");
								for (i = 0; i < Lists.elem[number - 1].G.vexnum; i++)
								{
									ArcNode* p = Lists.elem[number - 1].G.vertices[i].firstarc;
									printf("%d %s", Lists.elem[number - 1].G.vertices[i].data.key, Lists.elem[number - 1].G.vertices[i].data.others);
									while (p)
									{
										printf(" %d", p->adjvex);
										p = p->nextarc;
									}
									printf("\n");
								}
								printf("\n");
							}
							else printf("插入操作失败！\n");
						}
						else printf("无向图为空，请先创建图！\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 8: {  //删除顶点
						if (Lists.elem[number - 1].G.vexnum != 0) {
							int e, ans, i;
							printf("请输入删除结点：");
							scanf("%d", &e);
							ans = DeleteVex(Lists.elem[number - 1].G, e);
							if (ans == OK)
							{
								printf("删除成功，遍历为：\n");
								for (i = 0; i < Lists.elem[number - 1].G.vexnum; i++)
								{
									ArcNode* p = Lists.elem[number - 1].G.vertices[i].firstarc;
									printf("%d %s", Lists.elem[number - 1].G.vertices[i].data.key, Lists.elem[number - 1].G.vertices[i].data.others);
									while (p)
									{
										printf(" %d", p->adjvex);
										p = p->nextarc;
									}
									printf("\n");
								}
								printf("\n");
							}
							else printf("删除操作失败！\n");
						}
						else printf("图为空，删除操作失败！\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 9: {  //添加弧
						if (Lists.elem[number - 1].G.vexnum != 0) {
							int ans, i, v, w;
							printf("输入待插入的弧数据：");
							scanf("%d%d", &v, &w);
							ans = InsertArc(Lists.elem[number - 1].G, v, w);
							if (ans == OK)
							{
								printf("添加成功，遍历为：\n");
								for (i = 0; i < Lists.elem[number - 1].G.vexnum; i++)
								{
									ArcNode* p = Lists.elem[number - 1].G.vertices[i].firstarc;
									printf("%d %s", Lists.elem[number - 1].G.vertices[i].data.key, Lists.elem[number - 1].G.vertices[i].data.others);
									while (p)
									{
										printf(" %d", p->adjvex);
										p = p->nextarc;
									}
									printf("\n");
								}
								printf("\n");
							}
							else printf("插入操作失败！\n");
						}
						else printf("无向图为空，请先创建图！\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 10: {  //删除弧
						if (Lists.elem[number - 1].G.vexnum != 0) {
							int v, w, ans, i;
							printf("请输入删除弧：");
							scanf("%d%d", &v, &w);
							ans = DeleteArc(Lists.elem[number - 1].G, v, w);
							if (ans == OK)
							{
								printf("删除成功，遍历为：\n");
								for (i = 0; i < Lists.elem[number - 1].G.vexnum; i++)
								{
									ArcNode* p = Lists.elem[number - 1].G.vertices[i].firstarc;
									printf("%d %s", Lists.elem[number - 1].G.vertices[i].data.key, Lists.elem[number - 1].G.vertices[i].data.others);
									while (p)
									{
										printf(" %d", p->adjvex);
										p = p->nextarc;
									}
									printf("\n");
								}
								printf("\n");
							}
							else printf("删除操作失败！\n");
						}
						else printf("图为空，删除操作失败！\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 11: {  //深度遍历
						if (Lists.elem[number - 1].G.vexnum != 0) {
							printf("深度优先搜索遍历：");
							DFSTraverse(Lists.elem[number - 1].G, visit);
							putchar('\n');
						}
						else printf("遍历为空！\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 12: {  //广度遍历
						if (Lists.elem[number - 1].G.vexnum != 0) {
							printf("广度优先搜索遍历：");
							BFSTraverse(Lists.elem[number - 1].G, visit);
							putchar('\n');
						}
						else printf("遍历为空！\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 13: {  //文件保存
						if (Lists.elem[number - 1].G.vexnum != 0) {
							char FileName[30] = "ALGraph.txt";  //目标文件名
							if (SaveGraph(Lists.elem[number - 1].G, FileName) == OK)printf("保存成功！\n");
						}
						else printf("图为空，保存失败！\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 14: {  //文件读取
						if (Lists.elem[number - 1].G.vexnum == 0) {
							char FileName[30] = "ALGraph.txt";  //目标文件名
							if (LoadGraph(Lists.elem[number - 1].G, FileName) == OK)printf("读取成功！\n");
						}
						else printf("图不为空，无法读取文件！\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 15: {
						system("cls");
						goto A;
						break;
					}
					default: {printf("输入错误，请重新输入！\n"); getchar();
						getchar();
						system("cls"); }
					}
					print2();
					scanf("%d", &num);
				}
			}
			case 5: {  //遍历多图
				if (Lists.length == 0) { printf("多图无数据！\n"); getchar(); getchar();system("cls"); break; }
				int i;
				for (i = 0; i < Lists.length; i++) {
					printf("%s ", Lists.elem[i].name);
					if (Lists.elem[i].G.vexnum == 0) { printf("无数据！\n"); continue; }
					else {
						printf("广度优先遍历：");
						BFSTraverse(Lists.elem[i].G, visit);
						putchar('\n');
					}
				}
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 6: {  //清空多图
				if (Lists.length == 0) { printf("销毁成功！\n"); getchar(); getchar(); system("cls"); break; }
				Lists.length = 0;
				printf("销毁成功！\n");
				getchar();
				getchar();
				system("cls");
				break;

			}
			case 7: {  //文件保存（多图）
				char Listsname[30] = "ALGraphs.txt"; //目标文件名
				if (Lists.length != 0) {
					int i;
					FILE* fp = fopen(Listsname, "w");
					for (i = 0; i < Lists.length; i++) {
						fprintf(fp, "%s ", Lists.elem[i].name);
						MoreSaveGraph(Lists.elem[i].G, fp);
						if (i != Lists.length - 1)fprintf(fp, "\n");
					}
					fclose(fp);
					printf("保存成功！\n");
					getchar();
					getchar();
					system("cls");
					break;
				}
				printf("无数据可保存！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 8: {  //文件读取（多图）
				char Listsname[30] = "ALGraphs.txt"; //目标文件名
				if (Lists.length == 0) {
					int i;
					FILE* fp = fopen(Listsname, "r");
					for (i = 0; ; i++) {
						fscanf(fp, "%s", Lists.elem[i].name);
						MoreLoadGraph(Lists.elem[i].G, fp);
						Lists.length++;
						if (feof(fp)) break;

					}
					printf("读取成功！\n");
					getchar();
					getchar();
					system("cls");
					break;
				}
				printf("多图管理表有数据存在，不可读取！\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			default: {printf("输入错误，请重新输入！\n"); getchar(); getchar();system("cls"); }
			}
			print3();
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
void print1(void) {
	printf("\n-----------------单图操作菜单--------------------\n\
1.创建图           2.销毁图             3.查找顶点\n\
4.顶点赋值         5.获得第一邻接顶点   6.获得下一邻接点\n\
7.插入顶点         8.删除顶点           9.插入弧\n\
10.删除弧          11.深度优先搜索遍历  12.广度优先搜索遍历\n\
13.文件保存        14.文件读取          0.停止操作\n\
请输入【0~14】\n\n请输入你需要的操作：");
}
void print2(void) {
	printf("\n-----------------多图操作中的单图操作菜单--------------------\n\
1.创建图           2.销毁图             3.查找顶点\n\
4.顶点赋值         5.获得第一邻接顶点   6.获得下一邻接点\n\
7.插入顶点         8.删除顶点           9.插入弧\n\
10.删除弧          11.深度优先搜索遍历  12.广度优先搜索遍历\n\
13.文件保存        14.文件读取          15.返回多图菜单\n\
请输入【1~15】\n\n请输入你需要的操作：");
}
void print3(void) {
	printf("\n-----------------多图操作菜单--------------------\n\
1.创建多图        2.移除某图        3.查找某图\n\
4.单独操作        5.遍历多图        6.清空多图\n\
7.多图文件保存    8.多图文件读取\n\
0.停止操作        请输入【0~8】\n\n请输入你需要的操作：");
}

status JudgeV(VertexType V[], ALGraph& G) {
	int i, j;
	for (i = 0; V[i].key != -1; i++) {
		for (j = i + 1; V[j].key != -1; j++) {
			if (V[i].key == V[j].key) return ERROR;
		}
	}
	if (i > 20) return ERROR;
	else { G.vexnum = i; return OK; }
}  
//比较V的合法性，不合法返回ERROR；

status JudgeVR(VertexType V[], KeyType VR[][2], ALGraph& G) {
	int i, j, m, n = 0;
	for (i = 0, j = 0; VR[i][j] != -1; i++) {
		for (m = 0; V[m].key != -1; m++) {
			if (VR[i][j] == V[m].key) n++;
			if (VR[i][j + 1] == V[m].key) n++;
		}
		if (n != 2) return ERROR;
		n = 0, j = 0;
	}
	G.arcnum = i;
	return OK;
}
//比较VR的合法性，不合法返回ERROR；

status CreateCraph(ALGraph& G, VertexType V[], KeyType VR[][2])
{
	G.vexnum = 0, G.arcnum = 0;
	if (JudgeV(V, G) == ERROR) return ERROR;
	else {
		int i;
		for (i = 0; i < G.vexnum; i++) {
			G.vertices[i].data.key = V[i].key;
			strcpy(G.vertices[i].data.others, V[i].others);
			G.vertices[i].firstarc = NULL;
		}
		if (JudgeVR(V, VR, G) == ERROR) { G.vexnum = 0, G.arcnum = 0; return ERROR; }

		int j;
		for (j = 0; j < G.arcnum; j++) {
			ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = LocateVex(G, VR[j][1]);
			p->nextarc = G.vertices[LocateVex(G, VR[j][0])].firstarc;
			G.vertices[LocateVex(G, VR[j][0])].firstarc = p;

			ArcNode* q = (ArcNode*)malloc(sizeof(ArcNode));
			q->adjvex = LocateVex(G, VR[j][0]);
			q->nextarc = G.vertices[LocateVex(G, VR[j][1])].firstarc;
			G.vertices[LocateVex(G, VR[j][1])].firstarc = q;
		}
	}
	return OK;
}
//根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR，如果有相同的关键字，返回ERROR。

void visit(VertexType v)
{
	printf(" %d %s", v.key, v.others);
}
//输出函数

status DestroyGraph(ALGraph& G)
{
	int i;
	ArcNode* p, * q;
	for (i = 0; i < G.vexnum; i++) {
		p = G.vertices[i].firstarc;
		while (p) {
			q = p->nextarc;
			free(p);
			p = q;
		}
	}
	G.vexnum = 0;
	G.arcnum = 0;
	return OK;
}
//销毁图

int LocateVex(ALGraph G, KeyType u)
{
	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (u == G.vertices[i].data.key)return i;
	}
	return -1;
}
//根据u在图G中查找顶点，查找成功返回位序，否则返回-1

int Compare(ALGraph G, KeyType u, VertexType value) {
	int i, NOu = -1, NOvalue = -1;
	for (i = 0; i < G.vexnum; i++) {
		if (G.vertices[i].data.key == u) NOu = i;
		if (G.vertices[i].data.key == value.key) NOvalue = i;
	}
	if (NOu == -1)return -1;
	if (NOvalue != -1 && NOu != NOvalue)return -1;
	return NOu;
}
//比较赋值操作是否违反关键字唯一性

status PutVex(ALGraph& G, KeyType u, VertexType value)
{
	int n;
	if ((n = Compare(G, u, value)) == -1)return ERROR;
	G.vertices[n].data.key = value.key;
	strcpy(G.vertices[n].data.others, value.others);
	return OK;
}
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；如果查找失败或关键字不唯一，返回ERROR

int FirstAdjVex(ALGraph G, KeyType u)
{
	int n;
	if ((n = LocateVex(G, u)) == -1) return -1;  //查找失败返回-1
	if (G.vertices[n].firstarc == NULL) return -2; //如果查找成功但没有第一邻接点则返回-2
	return G.vertices[n].firstarc->adjvex;
}
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；

int NextAdjVex(ALGraph G, KeyType v, KeyType w)
{
	int iv, iw;
	if ((iv = LocateVex(G, v)) == -1)return -1;
	if ((iw = LocateVex(G, w)) == -1)return -1;

	ArcNode* p = G.vertices[iv].firstarc;
	while (p) {
		if (p->adjvex == iw && p->nextarc != NULL) return p->nextarc->adjvex;
		p = p->nextarc;
	}
	return -1;
}
//根据u在图G中查找顶点，查找成功返回顶点v的邻接顶点相对于w的下一邻接顶点的位序，查找失败返回-1；

status InsertVex(ALGraph& G, VertexType v)
{
	if (LocateVex(G, v.key) != -1) return ERROR;
	if (G.vexnum == MAX_VERTEX_NUM) return ERROR;
	G.vertices[G.vexnum].data.key = v.key;
	strcpy(G.vertices[G.vexnum].data.others, v.others);
	G.vertices[G.vexnum].firstarc = NULL;
	G.vexnum++;
	return OK;
}
//在图G中插入顶点v，成功返回OK,否则返回ERROR

status DeleteVex(ALGraph& G, KeyType v)
{
	int n, i;
	if ((n = LocateVex(G, v)) == -1 || G.vexnum == 1 || G.vexnum == 0) return ERROR;
	ArcNode* p = G.vertices[n].firstarc, * q, * save, * delt;
	while (p) {
		q = p->nextarc;
		save = G.vertices[p->adjvex].firstarc;
		if (save->adjvex == n) G.vertices[p->adjvex].firstarc = save->nextarc;
		else {
			while (save->nextarc) { //删除其他结点的相关边
				if (save->nextarc->adjvex == n) {
					delt = save->nextarc;
					save->nextarc = save->nextarc->nextarc;
					free(delt);
					break;
				}
				save = save->nextarc;
			}
		}
		free(p);
		p = q;
	}
	for (i = n + 1; i < G.vexnum; i++) {
		G.vertices[i - 1] = G.vertices[i];
	}
	G.vexnum--;
	for (i = 0; i < G.vexnum; i++) {
		p = G.vertices[i].firstarc;
		while (p) {
			if (p->adjvex >= n)p->adjvex--;
			p = p->nextarc;
		}
	}
	return OK;
}
//在图G中删除关键字v对应的顶点以及相关的弧，成功返回OK,否则返回ERROR

status InsertArc(ALGraph& G, KeyType v, KeyType w)
{
	int i, j;
	ArcNode* p, * q;
	if ((i = LocateVex(G, v)) == -1 || (j = LocateVex(G, w)) == -1)return ERROR;
	p = G.vertices[i].firstarc;

	while (p) {
		if (p->adjvex == j) { return ERROR; }
		p = p->nextarc;
	}
	p = (ArcNode*)malloc(sizeof(ArcNode));
	q = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = i;
	q->adjvex = j;
	p->nextarc = G.vertices[j].firstarc;
	G.vertices[j].firstarc = p;
	q->nextarc = G.vertices[i].firstarc;
	G.vertices[i].firstarc = q;

	return OK;
}
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR

status DeleteArc(ALGraph& G, KeyType v, KeyType w)
{
	int i, j, n = 0;
	ArcNode* p, * q;
	if ((i = LocateVex(G, v)) == -1 || (j = LocateVex(G, w)) == -1)return ERROR;
	p = G.vertices[i].firstarc;

	if (p->adjvex == j) { G.vertices[i].firstarc = p->nextarc; free(p); }
	else {
		while (p->nextarc) {
			if (p->nextarc->adjvex == j) {
				q = p->nextarc;
				p->nextarc = p->nextarc->nextarc;
				free(q);
				n++;
				break;
			}
			p = p->nextarc;
		}
		if (n == 0)return ERROR;
	}

	q = G.vertices[j].firstarc;
	if (q->adjvex == i) { G.vertices[j].firstarc = q->nextarc; free(q); }
	else {
		while (q->nextarc) {
			if (q->nextarc->adjvex == i) {
				p = q->nextarc;
				q->nextarc = q->nextarc->nextarc;
				free(p);
				break;
			}
			q = q->nextarc;
		}
	}
	return OK;
}
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR

void DFS(ALGraph G, int v, void (*visit)(VertexType), int visited[]) {
	int w;
	visited[v] = 1;
	visit(G.vertices[v].data);
	for (w = FirstAdjVex(G, G.vertices[v].data.key); w >= 0; w = NextAdjVex(G, G.vertices[v].data.key, G.vertices[w].data.key))
		if (!visited[w])     //处理所有未访问的邻接顶点
			DFS(G, w, visit, visited);
}

status DFSTraverse(ALGraph G, void (*visit)(VertexType)) {
	int visited[100], v;
	for (v = 0; v < G.vexnum; v++)    //初始化各顶点未访问状态
		visited[v] = 0;
	for (v = 0; v < G.vexnum; v++)
		if (!visited[v])         //从一个未访问的顶点开始
			DFS(G, v, visit, visited);
	return OK;
}
//对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次

status BFSTraverse(ALGraph G, void (*visit)(VertexType)) {
	int v, w, u, visited[100];
	for (v = 0; v < G.vexnum; v++)
		visited[v] = 0;
	int Que[100], in = 0, out = 0;

	for (v = 0; v < G.vexnum; v++)  //按顶点位置序号依次选择顶点
		if (!visited[v]) {     //遇到未访问过的顶点开始遍历
			visited[v] = 1; visit(G.vertices[v].data); Que[in] = v; in++;
			while (in != out) {
				u = Que[out]; out++;
				for (w = FirstAdjVex(G, G.vertices[u].data.key); w >= 0; w = NextAdjVex(G, G.vertices[u].data.key, G.vertices[w].data.key))
					if (!visited[w])
					{
						visited[w] = 1; visit(G.vertices[w].data); Que[in] = w; in++;
					}
			}
		}
	return OK;
}
//对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次 

status SaveGraph(ALGraph G, char FileName[])
{
	FILE* fp = fopen(FileName, "w");
	int i,j;
	for(i=0;i<G.vexnum;i++){
		fprintf(fp, "%d %s ",G.vertices[i].data.key,G.vertices[i].data.others);
	}
	fprintf(fp, "-1 nil ");
	int VR[20][20];
	
	for (i = 0; i < G.vexnum; i++)
	{
		ArcNode* p = G.vertices[i].firstarc;
		while (p)
		{
			VR[i][p->adjvex]=1;
			p = p->nextarc;
		}
	}
	for (i = 0; i < G.vexnum; i++) {
		for (j = i; j < G.vexnum; j++) {
			if (VR[i][j] == 1)fprintf(fp,"%d %d ", G.vertices[i].data.key, G.vertices[j].data.key);
		}
	}
	fprintf(fp, "-1 -1 ");
	fclose(fp);
	return OK;
}
//将图的数据写入到文件FileName中

status LoadGraph(ALGraph& G, char FileName[])
{
	FILE* fp = fopen(FileName, "r");
	VertexType V[10];
	KeyType VR[100][2];
	int i = 0, n = 0;
	do {
		fscanf(fp, "%d%s", &V[i].key, V[i].others);
	} while (V[i++].key != -1);

	do {
		fscanf(fp, "%d%d", &VR[n][0], &VR[n][1]);
	} while (VR[n++][0] != -1);

	if (CreateCraph(G, V, VR) == ERROR) { fclose(fp); return ERROR; }
	fclose(fp);
	return OK;
}
//读入文件FileName的图数据，创建图的邻接表


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
		if (!strcmp(Lists.elem[n].name, ListName)) return (n+1);

	}
	return ERROR;
}

status AddList(LISTS& Lists, char ListName[])//创建表名
{
	strcpy(Lists.elem[Lists.length].name, ListName);
	Lists.length++;
	return OK;
}

status MoreSaveGraph(ALGraph G, FILE* fp) {
	int i, j;
	for (i = 0; i < G.vexnum; i++) {
		fprintf(fp, "%d %s ", G.vertices[i].data.key, G.vertices[i].data.others);
	}
	fprintf(fp, "-1 nil ");
	int VR[20][20];

	for (i = 0; i < G.vexnum; i++)
	{
		ArcNode* p = G.vertices[i].firstarc;
		while (p)
		{
			VR[i][p->adjvex] = 1;
			p = p->nextarc;
		}
	}
	for (i = 0; i < G.vexnum; i++) {
		for (j = i; j < G.vexnum; j++) {
			if (VR[i][j] == 1)fprintf(fp, "%d %d ", G.vertices[i].data.key, G.vertices[j].data.key);
		}
	}
	fprintf(fp, "-1 -1");
	return OK;
}

status MoreLoadGraph(ALGraph &G, FILE* fp) {
	VertexType V[10];
	KeyType VR[100][2];
	int i = 0, n = 0;
	do {
		fscanf(fp, "%d%s", &V[i].key, V[i].others);
	} while (V[i++].key != -1);

	do {
		fscanf(fp, "%d%d", &VR[n][0], &VR[n][1]);
	} while (VR[n++][0] != -1);

	if (CreateCraph(G, V, VR) == ERROR) return ERROR;
	return OK;
}
