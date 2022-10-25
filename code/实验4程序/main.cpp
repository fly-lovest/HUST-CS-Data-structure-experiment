#include "def.h"

ALGraph G;
LISTS Lists;

int num;  //�������
int number; //�������ͼ�����
char saveName[30];  //�ݴ�ͼ��


int main() {
	printf("-----------------�����ڽӱ������ͼϵͳ--------------------\n\n");  //һ���˵�
	printf("1.��ͼ����\t\t2.��ͼ����\t\t0.ֹͣ����\n\n����������Ҫ�Ĳ�����");

	scanf("%d", &num);
	if (num == 1) {       //��ͼ�����������˵���
		printf("\n-----------------��ͼ�����˵�--------------------\n\
1.����ͼ           2.����ͼ             3.���Ҷ���\n\
4.���㸳ֵ         5.��õ�һ�ڽӶ���   6.�����һ�ڽӵ�\n\
7.���붥��         8.ɾ������           9.���뻡\n\
10.ɾ����          11.���������������  12.���������������\n\
13.�ļ�����        14.�ļ���ȡ          0.ֹͣ����\n\
�����롾0~14��\n\n����������Ҫ�Ĳ�����");
		G.vexnum = 0, G.arcnum = 0;//��ʼ���������ͱ���
		scanf("%d", &num);  //�������
		while (num) {
			switch (num)
			{
			case 1: {  //����ͼ
				if (G.vexnum == 0) {
					VertexType V[30];
					KeyType VR[100][2];
					int ans, i = 0;
					printf("�����붥�����ݡ���-1Ϊ��β����");
					do {
						scanf("%d%s", &V[i].key, V[i].others);
					} while (V[i++].key != -1);
					printf("�����뻡���ݡ���-1Ϊ��β����");
					i = 0;
					do {
						scanf("%d%d", &VR[i][0], &VR[i][1]);
					} while (VR[i++][0] != -1);
					ans = CreateCraph(G,V,VR);
					if (ans == OK)
					{
						printf("����ͼ�����ɹ�������Ϊ��\n");
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
					else printf("����ͼ����ʧ�ܣ�\n");
				}
				else printf("����ͼͼ���ڣ��޷�������\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 2: {  //����ͼ
				if (G.vexnum != 0) {
					DestroyGraph(G);
					printf("����ͼ���ٳɹ���\n");
				}
				else printf("����ͼΪ�գ��������٣�\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 3: {  //���Ҷ���
				if (G.vexnum != 0) {
					int e,ans;
					printf("������������ҽ��Ĺؼ��֣�");
					scanf("%d", &e);
					ans = LocateVex(G, e);
					if (ans == -1) printf("����ʧ�ܣ�\n");
					else printf("��Ӧ���Ϊ %d,%s\n", G.vertices[ans].data.key, G.vertices[ans].data.others);
				}
				else printf("����ͼΪ�գ�����ʧ�ܣ�\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 4: {  //���㸳ֵ
				if (G.vexnum != 0) {
					VertexType e;
					int ans, key;
					printf("�����滻�Ķ���ؼ��֣�");
					scanf("%d", &key);
					printf("���븳ֵ��");
					scanf("%d%s", &e.key, e.others);

					ans = PutVex(G, key, e);
					if (ans == OK) {
						printf("��ֵ�ɹ��������������Ϊ��");
						BFSTraverse(G, visit);
						printf("\n");
					}
					else printf("��ֵ����ʧ�ܣ�\n");

				}
				else printf("����ͼͼΪ�գ���ֵ����ʧ�ܣ�\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 5: {  //��õ�һ�ڽӵ�
				if (G.vexnum != 0) {
					int key,ans;
					printf("��������Ҫ��õ�һ�ڽӶ���Ĺؼ��֣�");
					scanf("%d", &key);
					ans = FirstAdjVex(G, key);
					if (ans==-2) printf("�����޵�һ�ڽӶ���\n");
					if(ans==-1)printf("�޸ö���!\n");
					if(ans>=0) printf("%d���ĵ�һ�ڽӵ���%d,%s\n", key, G.vertices[ans].data.key, G.vertices[ans].data.others);
				}
				else printf("����ͼΪ�գ�\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 6: {  //�����һ�ڽӵ�
				if (G.vexnum != 0) {
					int key,relat,ans;
					printf("��������ҽ�����Խ�㣺");
					scanf("%d%d", &key,&relat);
					ans = NextAdjVex(G, key,relat);
					if (ans == -1)printf("��ȡʧ�ܣ�\n");
					else {
						printf("%d�����%d�Ķ���Ϊ%d,%s\n", key, relat, G.vertices[ans].data.key, G.vertices[ans].data.others);
					}
				}
				else printf("����ͼΪ�գ���ȡʧ�ܣ�\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 7: {  //���붥��
				if (G.vexnum != 0) {
					VertexType e;
					int ans,i;
					printf("���������Ķ������ݣ�");
					scanf("%d%s", &e.key,e.others);
					ans = InsertVex(G, e);
					if (ans == OK)
					{
						printf("����ɹ�������Ϊ��\n");
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
					else printf("�������ʧ�ܣ�\n");
				}
				else printf("����ͼΪ�գ����ȴ���ͼ��\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 8: {  //ɾ������
				if (G.vexnum != 0) {
					int e, ans,i;
					printf("������ɾ����㣺");
					scanf("%d", &e);
					ans = DeleteVex(G, e);
					if (ans == OK)
					{
						printf("ɾ���ɹ�������Ϊ��\n");
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
					else printf("ɾ������ʧ�ܣ�\n");
				}
				else printf("ͼΪ�գ�ɾ������ʧ�ܣ�\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 9: {  //��ӻ�
				if (G.vexnum != 0) {
					int ans, i,v,w;
					printf("���������Ļ����ݣ�");
					scanf("%d%d", &v, &w);
					ans = InsertArc(G, v,w);
					if (ans == OK)
					{
						printf("��ӳɹ�������Ϊ��\n");
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
					else printf("�������ʧ�ܣ�\n");
				}
				else printf("����ͼΪ�գ����ȴ���ͼ��\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 10: {  //ɾ����
				if (G.vexnum != 0) {
					int v,w, ans, i;
					printf("������ɾ������");
					scanf("%d%d", &v,&w);
					ans = DeleteArc(G, v,w);
					if (ans == OK)
					{
						printf("ɾ���ɹ�������Ϊ��\n");
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
					else printf("ɾ������ʧ�ܣ�\n");
				}
				else printf("ͼΪ�գ�ɾ������ʧ�ܣ�\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 11: {  //��ȱ���
				if (G.vexnum!= 0) {
					printf("�����������������");
					DFSTraverse(G, visit);
					putchar('\n');
				}
				else printf("����Ϊ�գ�\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 12: {  //��ȱ���
				if (G.vexnum != 0) {
					printf("�����������������");
					BFSTraverse(G, visit);
					putchar('\n');
				}
				else printf("����Ϊ�գ�\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 13: {  //�ļ�����
				if (G.vexnum != 0) {
					char FileName[30] = "ALGraph.txt";  //Ŀ���ļ���
					if (SaveGraph(G, FileName) == OK)printf("����ɹ���\n");
				}
				else printf("ͼΪ�գ�����ʧ�ܣ�\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 14: {  //�ļ���ȡ
				if (G.vexnum == 0) {
					char FileName[30] = "ALGraph.txt";  //Ŀ���ļ���
					if (LoadGraph(G, FileName) == OK)printf("��ȡ�ɹ���\n");
				}
				else printf("ͼ��Ϊ�գ��޷���ȡ�ļ���\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			default: {printf("����������������룡\n"); getchar(); getchar();system("cls"); }
			}
			print1();
			scanf("%d", &num);
		}
	}

	if (num == 2) {       //��ͼ�����������˵���
		Lists.length = 0;  //��ʼ��Lists����
	A:;
		printf("\n-----------------��ͼ�����˵�--------------------\n\
1.������ͼ        2.�Ƴ�ĳͼ        3.����ĳͼ\n\
4.��������        5.������ͼ        6.��ն�ͼ\n\
7.��ͼ�ļ�����    8.��ͼ�ļ���ȡ\n\
0.ֹͣ����        �����롾0~8��\n\n����������Ҫ�Ĳ�����");
		scanf("%d", &num);
		while (num) {
			switch (num)
			{
			case 1: {  //������ͼ
				printf("���봴��ͼ�����ƣ�");
				scanf("%s", saveName);
	
				VertexType V[30];
				KeyType VR[100][2];
				int ans, i = 0;
				printf("�����붥�����ݡ���-1Ϊ��β����");
				do {
					scanf("%d%s", &V[i].key, V[i].others);
				} while (V[i++].key != -1);
				printf("�����뻡���ݡ���-1Ϊ��β����");
				i = 0;
				do {
					scanf("%d%d", &VR[i][0], &VR[i][1]);
				} while (VR[i++][0] != -1);
				ans = CreateCraph(Lists.elem[Lists.length].G, V,VR);
				if (ans == OK)
				{
					AddList(Lists, saveName);
					printf("�����ɹ���");
					putchar('\n');
				}
				else printf("����ʧ�ܣ�\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 2: {  //�Ƴ�ĳͼ
				printf("���������Ƴ�ͼ�����ƣ�");
				scanf("%s", saveName);
				if (RemoveList(Lists, saveName) == ERROR) { printf("�޸���������ͼ��\n"); }
				else printf("ɾ���ɹ���\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 3: {  //����ĳͼ
				printf("������������������ƣ�");
				scanf("%s", saveName);
				if ((number = LocateList(Lists, saveName)) == ERROR) { printf("�޸���������ͼ��\n"); getchar(); getchar(); system("cls"); break; }
				printf("���ҳɹ���%s \n", saveName);

				if (Lists.elem[number - 1].G.vexnum == 0) { printf("�����ݣ�\n");  }
				else {
					printf("�������������");
					BFSTraverse(Lists.elem[number - 1].G, visit);
					putchar('\n');
				}
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 4: {  //��������
				printf("�������뵥������ͼ�����ƣ�");
				scanf("%s", saveName);
				if ((number = LocateList(Lists, saveName)) == ERROR) { printf("�޸����Ƶ�����ͼ��\n"); getchar(); getchar(); system("cls"); break; }  //�����˵�
				printf("\n-----------------��ͼ�����еĵ�ͼ�����˵�--------------------\n\
1.����ͼ           2.����ͼ             3.���Ҷ���\n\
4.���㸳ֵ         5.��õ�һ�ڽӶ���   6.�����һ�ڽӵ�\n\
7.���붥��         8.ɾ������           9.���뻡\n\
10.ɾ����          11.���������������  12.���������������\n\
13.�ļ�����        14.�ļ���ȡ          15.���ض�ͼ�˵�\n\
�����롾1~15��\n\n����������Ҫ�Ĳ�����");
				scanf("%d", &num);   //�������
				while (num) {
					switch (num)
					{
					case 1: {  //����ͼ
						if (Lists.elem[number-1].G.vexnum == 0) {
							VertexType V[30];
							KeyType VR[100][2];
							int ans, i = 0;
							printf("�����������ݡ���-1Ϊ��β����");
							do {
								scanf("%d%s", &V[i].key, V[i].others);
							} while (V[i++].key != -1);
							printf("�����뻡���ݡ���-1Ϊ��β����");
							i = 0;
							do {
								scanf("%d%d", &VR[i][0], &VR[i][1]);
							} while (VR[i++][0] != -1);
							ans = CreateCraph(Lists.elem[number - 1].G, V, VR);
							if (ans == OK)
							{
								printf("����ͼ�����ɹ�������Ϊ��\n");
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
							else printf("����ͼ����ʧ�ܣ�\n");
						}
						else printf("����ͼͼ���ڣ��޷�������\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 2: {  //����ͼ
						if (Lists.elem[number-1].G.vexnum != 0) {
							DestroyGraph(Lists.elem[number-1].G);
							printf("����ͼ���ٳɹ���\n");
						}
						else printf("����ͼΪ�գ��������٣�\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 3: {  //���Ҷ���
						if (Lists.elem[number - 1].G.vexnum != 0) {
							int e, ans;
							printf("������������ҽ��Ĺؼ��֣�");
							scanf("%d", &e);
							ans = LocateVex(Lists.elem[number - 1].G, e);
							if (ans == -1) printf("����ʧ�ܣ�\n");
							else printf("��Ӧ���Ϊ %d,%s\n", Lists.elem[number - 1].G.vertices[ans].data.key, Lists.elem[number - 1].G.vertices[ans].data.others);
						}
						else printf("����ͼΪ�գ�����ʧ�ܣ�\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 4: {  //���㸳ֵ
						if (Lists.elem[number - 1].G.vexnum != 0) {
							VertexType e;
							int ans, key;
							printf("�����滻�Ķ���ؼ��֣�");
							scanf("%d", &key);
							printf("���븳ֵ��");
							scanf("%d%s", &e.key, e.others);

							ans = PutVex(Lists.elem[number - 1].G, key, e);
							if (ans == OK) {
								printf("��ֵ�ɹ��������������Ϊ��");
								BFSTraverse(Lists.elem[number - 1].G, visit);
								printf("\n");
							}
							else printf("��ֵ����ʧ�ܣ�\n");

						}
						else printf("����ͼͼΪ�գ���ֵ����ʧ�ܣ�\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 5: {  //��õ�һ�ڽӵ�
						if (Lists.elem[number - 1].G.vexnum != 0) {
							int key, ans;
							printf("��������Ҫ��õ�һ�ڽӶ���Ĺؼ��֣�");
							scanf("%d", &key);
							ans = FirstAdjVex(Lists.elem[number - 1].G, key);
							if (ans == -2) printf("�����޵�һ�ڽӶ���\n");
							if (ans == -1)printf("�޸ö���!\n");
							if (ans >= 0) printf("%d���ĵ�һ�ڽӵ���%d,%s\n", key, Lists.elem[number - 1].G.vertices[ans].data.key, Lists.elem[number - 1].G.vertices[ans].data.others);
						}
						else printf("����ͼΪ�գ�\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 6: {  //�����һ�ڽӵ�
						if (Lists.elem[number - 1].G.vexnum != 0) {
							int key, relat, ans;
							printf("��������ҽ�����Խ�㣺");
							scanf("%d%d", &key, &relat);
							ans = NextAdjVex(Lists.elem[number - 1].G, key, relat);
							if (ans == -1)printf("��ȡʧ�ܣ�\n");
							else {
								printf("%d�����%d�Ķ���Ϊ%d,%s\n", key, relat, Lists.elem[number - 1].G.vertices[ans].data.key, Lists.elem[number - 1].G.vertices[ans].data.others);
							}
						}
						else printf("����ͼΪ�գ���ȡʧ�ܣ�\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 7: {  //���붥��
						if (Lists.elem[number - 1].G.vexnum != 0) {
							VertexType e;
							int ans, i;
							printf("���������Ķ������ݣ�");
							scanf("%d%s", &e.key, e.others);
							ans = InsertVex(Lists.elem[number - 1].G, e);
							if (ans == OK)
							{
								printf("����ɹ�������Ϊ��\n");
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
							else printf("�������ʧ�ܣ�\n");
						}
						else printf("����ͼΪ�գ����ȴ���ͼ��\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 8: {  //ɾ������
						if (Lists.elem[number - 1].G.vexnum != 0) {
							int e, ans, i;
							printf("������ɾ����㣺");
							scanf("%d", &e);
							ans = DeleteVex(Lists.elem[number - 1].G, e);
							if (ans == OK)
							{
								printf("ɾ���ɹ�������Ϊ��\n");
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
							else printf("ɾ������ʧ�ܣ�\n");
						}
						else printf("ͼΪ�գ�ɾ������ʧ�ܣ�\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 9: {  //��ӻ�
						if (Lists.elem[number - 1].G.vexnum != 0) {
							int ans, i, v, w;
							printf("���������Ļ����ݣ�");
							scanf("%d%d", &v, &w);
							ans = InsertArc(Lists.elem[number - 1].G, v, w);
							if (ans == OK)
							{
								printf("��ӳɹ�������Ϊ��\n");
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
							else printf("�������ʧ�ܣ�\n");
						}
						else printf("����ͼΪ�գ����ȴ���ͼ��\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 10: {  //ɾ����
						if (Lists.elem[number - 1].G.vexnum != 0) {
							int v, w, ans, i;
							printf("������ɾ������");
							scanf("%d%d", &v, &w);
							ans = DeleteArc(Lists.elem[number - 1].G, v, w);
							if (ans == OK)
							{
								printf("ɾ���ɹ�������Ϊ��\n");
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
							else printf("ɾ������ʧ�ܣ�\n");
						}
						else printf("ͼΪ�գ�ɾ������ʧ�ܣ�\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 11: {  //��ȱ���
						if (Lists.elem[number - 1].G.vexnum != 0) {
							printf("�����������������");
							DFSTraverse(Lists.elem[number - 1].G, visit);
							putchar('\n');
						}
						else printf("����Ϊ�գ�\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 12: {  //��ȱ���
						if (Lists.elem[number - 1].G.vexnum != 0) {
							printf("�����������������");
							BFSTraverse(Lists.elem[number - 1].G, visit);
							putchar('\n');
						}
						else printf("����Ϊ�գ�\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 13: {  //�ļ�����
						if (Lists.elem[number - 1].G.vexnum != 0) {
							char FileName[30] = "ALGraph.txt";  //Ŀ���ļ���
							if (SaveGraph(Lists.elem[number - 1].G, FileName) == OK)printf("����ɹ���\n");
						}
						else printf("ͼΪ�գ�����ʧ�ܣ�\n");
						getchar();
						getchar();
						system("cls");
						break;
					}
					case 14: {  //�ļ���ȡ
						if (Lists.elem[number - 1].G.vexnum == 0) {
							char FileName[30] = "ALGraph.txt";  //Ŀ���ļ���
							if (LoadGraph(Lists.elem[number - 1].G, FileName) == OK)printf("��ȡ�ɹ���\n");
						}
						else printf("ͼ��Ϊ�գ��޷���ȡ�ļ���\n");
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
					default: {printf("����������������룡\n"); getchar();
						getchar();
						system("cls"); }
					}
					print2();
					scanf("%d", &num);
				}
			}
			case 5: {  //������ͼ
				if (Lists.length == 0) { printf("��ͼ�����ݣ�\n"); getchar(); getchar();system("cls"); break; }
				int i;
				for (i = 0; i < Lists.length; i++) {
					printf("%s ", Lists.elem[i].name);
					if (Lists.elem[i].G.vexnum == 0) { printf("�����ݣ�\n"); continue; }
					else {
						printf("������ȱ�����");
						BFSTraverse(Lists.elem[i].G, visit);
						putchar('\n');
					}
				}
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 6: {  //��ն�ͼ
				if (Lists.length == 0) { printf("���ٳɹ���\n"); getchar(); getchar(); system("cls"); break; }
				Lists.length = 0;
				printf("���ٳɹ���\n");
				getchar();
				getchar();
				system("cls");
				break;

			}
			case 7: {  //�ļ����棨��ͼ��
				char Listsname[30] = "ALGraphs.txt"; //Ŀ���ļ���
				if (Lists.length != 0) {
					int i;
					FILE* fp = fopen(Listsname, "w");
					for (i = 0; i < Lists.length; i++) {
						fprintf(fp, "%s ", Lists.elem[i].name);
						MoreSaveGraph(Lists.elem[i].G, fp);
						if (i != Lists.length - 1)fprintf(fp, "\n");
					}
					fclose(fp);
					printf("����ɹ���\n");
					getchar();
					getchar();
					system("cls");
					break;
				}
				printf("�����ݿɱ��棡\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			case 8: {  //�ļ���ȡ����ͼ��
				char Listsname[30] = "ALGraphs.txt"; //Ŀ���ļ���
				if (Lists.length == 0) {
					int i;
					FILE* fp = fopen(Listsname, "r");
					for (i = 0; ; i++) {
						fscanf(fp, "%s", Lists.elem[i].name);
						MoreLoadGraph(Lists.elem[i].G, fp);
						Lists.length++;
						if (feof(fp)) break;

					}
					printf("��ȡ�ɹ���\n");
					getchar();
					getchar();
					system("cls");
					break;
				}
				printf("��ͼ����������ݴ��ڣ����ɶ�ȡ��\n");
				getchar();
				getchar();
				system("cls");
				break;
			}
			default: {printf("����������������룡\n"); getchar(); getchar();system("cls"); }
			}
			print3();
			scanf("%d", &num);
		}
	}

	if (num == 0) {       //ֹͣ����
		printf("ϵͳֹͣ��\n");
		return 0;
	}

	printf("�������\n");
	return 0;
}


/*����*/
void print1(void) {
	printf("\n-----------------��ͼ�����˵�--------------------\n\
1.����ͼ           2.����ͼ             3.���Ҷ���\n\
4.���㸳ֵ         5.��õ�һ�ڽӶ���   6.�����һ�ڽӵ�\n\
7.���붥��         8.ɾ������           9.���뻡\n\
10.ɾ����          11.���������������  12.���������������\n\
13.�ļ�����        14.�ļ���ȡ          0.ֹͣ����\n\
�����롾0~14��\n\n����������Ҫ�Ĳ�����");
}
void print2(void) {
	printf("\n-----------------��ͼ�����еĵ�ͼ�����˵�--------------------\n\
1.����ͼ           2.����ͼ             3.���Ҷ���\n\
4.���㸳ֵ         5.��õ�һ�ڽӶ���   6.�����һ�ڽӵ�\n\
7.���붥��         8.ɾ������           9.���뻡\n\
10.ɾ����          11.���������������  12.���������������\n\
13.�ļ�����        14.�ļ���ȡ          15.���ض�ͼ�˵�\n\
�����롾1~15��\n\n����������Ҫ�Ĳ�����");
}
void print3(void) {
	printf("\n-----------------��ͼ�����˵�--------------------\n\
1.������ͼ        2.�Ƴ�ĳͼ        3.����ĳͼ\n\
4.��������        5.������ͼ        6.��ն�ͼ\n\
7.��ͼ�ļ�����    8.��ͼ�ļ���ȡ\n\
0.ֹͣ����        �����롾0~8��\n\n����������Ҫ�Ĳ�����");
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
//�Ƚ�V�ĺϷ��ԣ����Ϸ�����ERROR��

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
//�Ƚ�VR�ĺϷ��ԣ����Ϸ�����ERROR��

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
//����V��VR����ͼT������OK�����V��VR����ȷ������ERROR���������ͬ�Ĺؼ��֣�����ERROR��

void visit(VertexType v)
{
	printf(" %d %s", v.key, v.others);
}
//�������

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
//����ͼ

int LocateVex(ALGraph G, KeyType u)
{
	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (u == G.vertices[i].data.key)return i;
	}
	return -1;
}
//����u��ͼG�в��Ҷ��㣬���ҳɹ�����λ�򣬷��򷵻�-1

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
//�Ƚϸ�ֵ�����Ƿ�Υ���ؼ���Ψһ��

status PutVex(ALGraph& G, KeyType u, VertexType value)
{
	int n;
	if ((n = Compare(G, u, value)) == -1)return ERROR;
	G.vertices[n].data.key = value.key;
	strcpy(G.vertices[n].data.others, value.others);
	return OK;
}
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ö���ֵ�޸ĳ�value������OK���������ʧ�ܻ�ؼ��ֲ�Ψһ������ERROR

int FirstAdjVex(ALGraph G, KeyType u)
{
	int n;
	if ((n = LocateVex(G, u)) == -1) return -1;  //����ʧ�ܷ���-1
	if (G.vertices[n].firstarc == NULL) return -2; //������ҳɹ���û�е�һ�ڽӵ��򷵻�-2
	return G.vertices[n].firstarc->adjvex;
}
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���u�ĵ�һ�ڽӶ���λ�򣬷��򷵻�-1��

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
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���v���ڽӶ��������w����һ�ڽӶ����λ�򣬲���ʧ�ܷ���-1��

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
//��ͼG�в��붥��v���ɹ�����OK,���򷵻�ERROR

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
			while (save->nextarc) { //ɾ������������ر�
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
//��ͼG��ɾ���ؼ���v��Ӧ�Ķ����Լ���صĻ����ɹ�����OK,���򷵻�ERROR

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
//��ͼG�����ӻ�<v,w>���ɹ�����OK,���򷵻�ERROR

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
//��ͼG��ɾ����<v,w>���ɹ�����OK,���򷵻�ERROR

void DFS(ALGraph G, int v, void (*visit)(VertexType), int visited[]) {
	int w;
	visited[v] = 1;
	visit(G.vertices[v].data);
	for (w = FirstAdjVex(G, G.vertices[v].data.key); w >= 0; w = NextAdjVex(G, G.vertices[v].data.key, G.vertices[w].data.key))
		if (!visited[w])     //��������δ���ʵ��ڽӶ���
			DFS(G, w, visit, visited);
}

status DFSTraverse(ALGraph G, void (*visit)(VertexType)) {
	int visited[100], v;
	for (v = 0; v < G.vexnum; v++)    //��ʼ��������δ����״̬
		visited[v] = 0;
	for (v = 0; v < G.vexnum; v++)
		if (!visited[v])         //��һ��δ���ʵĶ��㿪ʼ
			DFS(G, v, visit, visited);
	return OK;
}
//��ͼG������������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��

status BFSTraverse(ALGraph G, void (*visit)(VertexType)) {
	int v, w, u, visited[100];
	for (v = 0; v < G.vexnum; v++)
		visited[v] = 0;
	int Que[100], in = 0, out = 0;

	for (v = 0; v < G.vexnum; v++)  //������λ���������ѡ�񶥵�
		if (!visited[v]) {     //����δ���ʹ��Ķ��㿪ʼ����
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
//��ͼG���й�������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ�� 

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
//��ͼ������д�뵽�ļ�FileName��

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
//�����ļ�FileName��ͼ���ݣ�����ͼ���ڽӱ�


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

status LocateList(LISTS Lists, char ListName[])// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�ERROR
{
	int n;
	for (n = 0; n < Lists.length; n++) {
		if (!strcmp(Lists.elem[n].name, ListName)) return (n+1);

	}
	return ERROR;
}

status AddList(LISTS& Lists, char ListName[])//��������
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
