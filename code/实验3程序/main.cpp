#include "def.h"

BiTree T;
LISTS Lists;

int num;  //�������
int i1;  //���쵥����ȫ�ֱ���
int i2;  //���浽�����ȫ�ֱ���
int i3;  //���Һ����ļ��ֵ
int number; //������ұ�����
char saveName[30];  //�ݴ����


int main() {
	printf("-----------------���ڶ�������Ķ�����ϵͳ--------------------\n\n");  //һ���˵�
	printf("1.��������\t\t2.��������\t\t0.ֹͣ����\n\n����������Ҫ�Ĳ�����");

	scanf("%d", &num);
	if (num == 1) {       //���������������˵���
		printf("\n-----------------���������˵�--------------------\n\
1.���쵥��        2.���ٵ���        3.�������\n\
4.���ҽ��        5.��㸳ֵ        6.�ֵܽ��\n\
7.���ӽ��        8.������        9.ɾ�����\n\
10.�������       11.�������       12.�������\n\
13.�������       14.�ļ�����       15.�ļ���ȡ\n\
0.ֹͣ����        �����롾0~15��\n\n����������Ҫ�Ĳ�����");
		scanf("%d", &num);  //�������
		while (num) {
			switch (num)
			{
			case 1: {  //���쵥��
				if (T == NULL) {
					TElemType definition[100];
					int ans, i = 0;
					printf("�밴�����������ݣ�");
					do {
						scanf("%d%s", &definition[i].key, definition[i].others);
					} while (definition[i++].key != -1);
					i1 = -1; //i1��ʼ��
					ans = CreateBiTree(T, definition);
					if (ans == OK)
					{
						printf("���������ɹ���ǰ�����Ϊ��");
						PreOrderTraverse(T, visit);
						putchar('\n');
					}
					else printf("��������ʧ�ܣ��ؼ��ֲ�Ψһ��\n");
				}
				else printf("�����ڣ��޷�������\n");
				break;
			}
			case 2: {  //���ٵ���
				if (T != NULL) {
					ClearBiTree(T);
					printf("�������ٳɹ���\n");
				}
				else printf("��ΪNULL���������٣�\n");
				break;
			}
			case 3: {  //�������
				if (T != NULL) {
					printf("�������Ϊ%d��\n", BiTreeDepth(T));
				}
				else printf("�������Ϊ0��\n");
				break;
			}
			case 4: {  //���ҽ��
				if (T != NULL) {
					BiTNode* ret_tree;
					int e;
					printf("������������ҵĹؼ��֣�");
					scanf("%d", &e);
					i3 = 0;
					ret_tree = LocateNode(T, e);
					if (ret_tree == NULL) printf("����ʧ�ܣ�\n");
					else printf("��Ӧ���Ϊ %d,%s\n", ret_tree->data.key, ret_tree->data.others);
				}
				else printf("��ΪNULL������ʧ�ܣ�\n");
				break;
			}
			case 5: {  //��㸳ֵ
				if (T != NULL) {
					TElemType e;
					int ans, key;
					printf("������ҵĹؼ��֣�");
					scanf("%d", &key);
					printf("���������滻�ģ�");
					scanf("%d%s", &e.key, e.others);
					i2 = 0;
					ans = Assign(T, key, e);
					if (ans == OK) {
						printf("��ֵ�ɹ����������Ϊ��");
						PreOrderTraverse(T, visit);
						printf("\n");
					}
					else printf("��ֵ����ʧ�ܣ�\n");

				}
				else printf("��ΪNULL����ֵ����ʧ�ܣ�\n");
				break;
			}
			case 6: {  //�ֵܽ��
				if (T != NULL) {
					int key;
					BiTNode* Sibling;
					printf("��������ҽ�㣺");
					scanf("%d", &key);
					Sibling = GetSibling(T, key);
					if (Sibling) printf("�ֵܽ��Ϊ��%d,%s\n", Sibling->data.key, Sibling->data.others);
					else printf("���ֵܽ��!\n");
				}
				else printf("��ΪNULL�����ֵܽ�㣡\n");
				break;
			}
			case 7: {  //���ӽ��
				if (T != NULL) {
					int key;
					BiTNode* ret_tree;
					printf("������ҽ�㣺");
					scanf("%d", &key);
					i3 = 0;
					ret_tree = LocateNode(T, key);
					if (ret_tree == NULL)printf("�޺��ӽ�㣡\n");
					else {
						if (ret_tree->lchild == NULL && ret_tree->rchild == NULL)printf("�޺��ӽ�㣡\n");
						if (ret_tree->lchild != NULL && ret_tree->rchild == NULL)printf("����Ϊ%d,%s���Һ��Ӳ����ڣ�\n", ret_tree->lchild->data.key, ret_tree->lchild->data.others);
						if (ret_tree->lchild == NULL && ret_tree->rchild != NULL)printf("���Ӳ����ڣ��Һ���Ϊ%d,%s��\n", ret_tree->rchild->data.key, ret_tree->rchild->data.others);
						if (ret_tree->lchild != NULL && ret_tree->rchild != NULL)printf("����Ϊ%d,%s���Һ���Ϊ%d,%s��\n", ret_tree->lchild->data.key, ret_tree->lchild->data.others, ret_tree->rchild->data.key, ret_tree->rchild->data.others);
					}
				}
				else printf("��ΪNULL���޺��ӽ�㣡\n");
				break;
			}
			case 8: {  //������
				if (T != NULL) {
					TElemType c;
					int ans, e, LR;
					printf("������ҵĹؼ��֣�");
					scanf("%d", &e);
					printf("�������Ĳ����Ͳ������ݡ�����Ϊ-1��0��1����");
					scanf("%d%d%s", &LR, &c.key, c.others);
					i2 = 0;
					ans = InsertNode(T, e, LR, c);
					if (ans == OK)
					{
						printf("����ɹ����������Ϊ��");
						PreOrderTraverse(T, visit);
						printf("\n");
					}
					else printf("�������ʧ�ܣ�\n");
				}
				else printf("��ΪNULL���������ʧ�ܣ�\n");
				break;
			}
			case 9: {  //ɾ�����
				if (T != NULL) {
					int e, ans;
					printf("������ɾ����㣺");
					scanf("%d", &e);
					ans = DeleteNode(T, e);
					if (ans == OK)
					{
						printf("ɾ���ɹ����������Ϊ��");
						PreOrderTraverse(T, visit);
						printf("\n");
					}
					else printf("ɾ������ʧ�ܣ�\n");
				}
				else printf("��ΪNULL��ɾ������ʧ�ܣ�\n");
				break;
			}
			case 10: {  //�������
				if (T != NULL) {
					printf("���������");
					PreOrderTraverse(T, visit);
					putchar('\n');
				}
				else printf("��ΪNULL������Ϊ�գ�\n");
				break;
			}
			case 11: {  //�������
				if (T != NULL) {
					printf("���������");
					InOrderTraverse(T, visit);
					putchar('\n');
				}
				else printf("��ΪNULL������Ϊ�գ�\n");
				break;
			}
			case 12: {  //�������
				if (T != NULL) {
					printf("���������");
					PostOrderTraverse(T, visit);
					putchar('\n');
				}
				else printf("��ΪNULL������Ϊ�գ�\n");
				break;
			}
			case 13: {  //�������
				if (T != NULL) {
					printf("���������");
					LevelOrderTraverse(T, visit);
					putchar('\n');
				}
				else printf("��ΪNULL������Ϊ�գ�\n");
				break;
			}
			case 14: {  //�ļ�����
				if (T != NULL) {
					char FileName[30] = "tree.txt";  //�����ļ���
					if (SaveBiTree(T, FileName) == OK)printf("����ɹ���\n");
				}
				else printf("��ΪNULL������ʧ�ܣ�\n");
				break;
			}
			case 15: {  //�ļ���ȡ
				if (T == NULL) {
					char FileName[30] = "tree.txt";  //�����ļ���
					if (LoadBiTree(T, FileName) == OK)printf("��ȡ�ɹ���\n");
				}
				else printf("����Ϊ�գ��޷���ȡ�ļ���\n");
				break;
			}
			default:printf("����������������룡\n");
			}
			printf("\n����������Ҫ�Ĳ�����");
			scanf("%d", &num);
		}
	}

	if (num == 2) {       //�������������˵���
	Lists.length = 0;  //��ʼ��Lists����
	A:;
		printf("\n-----------------���������˵�--------------------\n\
1.��������        2.�Ƴ�ĳ��        3.����ĳ��\n\
4.��������        5.��������        6.��ն���\n\
7.�����ļ�����    8.�����ļ���ȡ\n\
0.ֹͣ����        �����롾0~8��\n\n����������Ҫ�Ĳ�����");
		scanf("%d", &num);
		while (num) {
			switch (num)
			{
			case 1: {  //��������
				printf("���봴���������ƣ�");
				scanf("%s", saveName);
				printf("�밴����˳���������ݡ�����-1ֹͣ����");
				TElemType definition[100];
				int ans, i = 0;
				do {
					scanf("%d%s", &definition[i].key, definition[i].others);
				} while (definition[i++].key != -1);
				if (definition[0].key == -1) { Lists.elem[Lists.length].T = NULL; strcpy(Lists.elem[Lists.length].name, saveName); Lists.length++; printf("�����ɹ���\n"); break; }
				if (Compare1(definition) == ERROR) { printf("����ʧ�ܣ��ؼ��ֲ�Ψһ��\n"); break; }
				AddList(Lists, saveName);
				i1 = -1; //i1��ʼ��
				ans = CreateBiTree(Lists.elem[Lists.length-1].T, definition);
				if (ans == OK)
				{
					printf("�����ɹ���");
					putchar('\n');
				}
				else printf("����ʧ�ܣ��ؼ��ֲ�Ψһ��\n");
				break;
			}
			case 2: {  //�Ƴ�ĳ��
				printf("���������Ƴ��������ƣ�");
				scanf("%s", saveName);
				if (RemoveList(Lists, saveName) == ERROR) { printf("�޸����Ķ�������\n"); break; }
				else printf("ɾ���ɹ���\n");
				break;
			}
			case 3: {  //����ĳ��
				printf("������������������ƣ�");
				scanf("%s", saveName);
				if ((number = LocateList(Lists, saveName)) == ERROR) { printf("�޸����Ķ�������\n"); break; }
				printf("���ҳɹ���%s \n", saveName);

				if (Lists.elem[number - 1].T == NULL) { printf("��ΪNULL��\n"); break; }
				if (BiTreeDepth(Lists.elem[number - 1].T) == 0) { printf("���������ݣ�\n"); break; }
				else {
					printf("���������");
					PreOrderTraverse(Lists.elem[number - 1].T,visit);
					putchar('\n');
				}
				break;
			}
			case 4: {  //��������
				printf("�������뵥�������������ƣ�");
				scanf("%s", saveName);
				if ((number = LocateList(Lists, saveName)) == ERROR) { printf("�޸����ƵĶ�������\n"); break; }  //�����˵�
				printf("\n-----------------���������еĵ��������˵�--------------------\n\
1.���쵥��        2.���ٵ���        3.�������\n\
4.���ҽ��        5.��㸳ֵ        6.�ֵܽ��\n\
7.���ӽ��        8.������        9.ɾ�����\n\
10.�������       11.�������       12.�������\n\
13.�������       14.�ļ�����       15.�ļ���ȡ\n\
16.���ض����˵�\n\
�����롾1~16��\n\n����������Ҫ�Ĳ�����");
				scanf("%d", &num);   //�������
				while (num) {
					switch (num)
					{
					case 1: {  //���쵥��
						if (Lists.elem[number - 1].T == NULL) {
							TElemType definition[100];
							int ans, i = 0;
							printf("�밴�����������ݣ�");
							do {
								scanf("%d%s", &definition[i].key, definition[i].others);
							} while (definition[i++].key != -1);
							i1 = -1; //i1��ʼ��
							ans = CreateBiTree(Lists.elem[number - 1].T, definition);
							if (ans == OK)
							{
								printf("���������ɹ���ǰ�����Ϊ��");
								PreOrderTraverse(Lists.elem[number - 1].T, visit);
								putchar('\n');
							}
							else printf("��������ʧ�ܣ��ؼ��ֲ�Ψһ��\n");
						}
						else printf("�����ڣ��޷�������\n");
						break;
					}
					case 2: {  //���ٵ���
						if (Lists.elem[number - 1].T != NULL) {
							ClearBiTree(Lists.elem[number - 1].T);
							printf("�������ٳɹ���\n");
						}
						else printf("��ΪNULL���������٣�\n");
						break;
					}
					case 3: {  //�������
						if (Lists.elem[number - 1].T != NULL) {
							printf("�������Ϊ%d��\n", BiTreeDepth(Lists.elem[number - 1].T));
						}
						else printf("�������Ϊ0��\n");
						break;
					}
					case 4: {  //���ҽ��
						if (Lists.elem[number - 1].T != NULL) {
							BiTNode* ret_tree;
							int e;
							printf("������������ҵĹؼ��֣�");
							scanf("%d", &e);
							i3 = 0;
							ret_tree = LocateNode(Lists.elem[number - 1].T, e);
							if (ret_tree == NULL) printf("����ʧ�ܣ�\n");
							else printf("��Ӧ���Ϊ %d,%s\n", ret_tree->data.key, ret_tree->data.others);
						}
						else printf("��ΪNULL������ʧ�ܣ�\n");
						break;
					}
					case 5: {  //��㸳ֵ
						if (Lists.elem[number - 1].T != NULL) {
							TElemType e;
							int ans, key;
							printf("������ҵĹؼ��֣�");
							scanf("%d", &key);
							printf("���������滻�ģ�");
							scanf("%d%s", &e.key, e.others);
							i2 = 0;
							ans = Assign(Lists.elem[number - 1].T, key, e);
							if (ans == OK) {
								printf("��ֵ�ɹ����������Ϊ��");
								PreOrderTraverse(Lists.elem[number - 1].T, visit);
								printf("\n");
							}
							else printf("��ֵ����ʧ�ܣ�\n");

						}
						else printf("��ΪNULL����ֵ����ʧ�ܣ�\n");
						break;
					}
					case 6: {  //�ֵܽ��
						if (Lists.elem[number - 1].T != NULL) {
							int key;
							BiTNode* Sibling;
							printf("��������ҽ�㣺");
							scanf("%d", &key);
							Sibling = GetSibling(Lists.elem[number - 1].T, key);
							if (Sibling) printf("�ֵܽ��Ϊ��%d,%s\n", Sibling->data.key, Sibling->data.others);
							else printf("���ֵܽ��!\n");
						}
						else printf("��ΪNULL�����ֵܽ�㣡\n");
						break;
					}
					case 7: {  //���ӽ��
						if (Lists.elem[number - 1].T != NULL) {
							int key;
							BiTNode* ret_tree;
							printf("������ҽ�㣺");
							scanf("%d", &key);
							i3 = 0;
							ret_tree = LocateNode(Lists.elem[number - 1].T, key);
							if (ret_tree == NULL)printf("�޺��ӽ�㣡\n");
							else {
								if (ret_tree->lchild == NULL && ret_tree->rchild == NULL)printf("�޺��ӽ�㣡\n");
								if (ret_tree->lchild != NULL && ret_tree->rchild == NULL)printf("����Ϊ%d,%s���Һ��Ӳ����ڣ�\n", ret_tree->lchild->data.key, ret_tree->lchild->data.others);
								if (ret_tree->lchild == NULL && ret_tree->rchild != NULL)printf("���Ӳ����ڣ��Һ���Ϊ%d,%s��\n", ret_tree->rchild->data.key, ret_tree->rchild->data.others);
								if (ret_tree->lchild != NULL && ret_tree->rchild != NULL)printf("����Ϊ%d,%s���Һ���Ϊ%d,%s��\n", ret_tree->lchild->data.key, ret_tree->lchild->data.others, ret_tree->rchild->data.key, ret_tree->rchild->data.others);
							}
						}
						else printf("��ΪNULL���޺��ӽ�㣡\n");
						break;
					}
					case 8: {  //������
						if (Lists.elem[number - 1].T != NULL) {
							TElemType c;
							int ans, e, LR;
							printf("������ҵĹؼ��֣�");
							scanf("%d", &e);
							printf("�������Ĳ����Ͳ������ݡ�����Ϊ-1��0��1����");
							scanf("%d%d%s", &LR, &c.key, c.others);
							i2 = 0;
							ans = InsertNode(Lists.elem[number - 1].T, e, LR, c);
							if (ans == OK)
							{
								printf("����ɹ����������Ϊ��");
								PreOrderTraverse(Lists.elem[number - 1].T, visit);
								printf("\n");
							}
							else printf("�������ʧ�ܣ�\n");
						}
						else printf("��ΪNULL���������ʧ�ܣ�\n");
						break;
					}
					case 9: {  //ɾ�����
						if (Lists.elem[number - 1].T != NULL) {
							int e, ans;
							printf("������ɾ����㣺");
							scanf("%d", &e);
							ans = DeleteNode(Lists.elem[number - 1].T, e);
							if (ans == OK)
							{
								printf("ɾ���ɹ����������Ϊ��");
								PreOrderTraverse(Lists.elem[number - 1].T, visit);
								printf("\n");
							}
							else printf("ɾ������ʧ�ܣ�\n");
						}
						else printf("��ΪNULL��ɾ������ʧ�ܣ�\n");
						break;
					}
					case 10: {  //�������
						if (Lists.elem[number - 1].T != NULL) {
							printf("���������");
							PreOrderTraverse(Lists.elem[number - 1].T, visit);
							putchar('\n');
						}
						else printf("��ΪNULL������Ϊ�գ�\n");
						break;
					}
					case 11: {  //�������
						if (Lists.elem[number - 1].T != NULL) {
							printf("���������");
							InOrderTraverse(Lists.elem[number - 1].T, visit);
							putchar('\n');
						}
						else printf("��ΪNULL������Ϊ�գ�\n");
						break;
					}
					case 12: {  //�������
						if (Lists.elem[number - 1].T != NULL) {
							printf("���������");
							PostOrderTraverse(Lists.elem[number - 1].T, visit);
							putchar('\n');
						}
						else printf("��ΪNULL������Ϊ�գ�\n");
						break;
					}
					case 13: {  //�������
						if (Lists.elem[number - 1].T != NULL) {
							printf("���������");
							LevelOrderTraverse(Lists.elem[number - 1].T, visit);
							putchar('\n');
						}
						else printf("��ΪNULL������Ϊ�գ�\n");
						break;
					}
					case 14: {  //�ļ�����
						if (Lists.elem[number - 1].T != NULL) {
							char FileName[30] = "tree.txt";  //�����ļ���
							if (SaveBiTree(Lists.elem[number - 1].T, FileName) == OK)printf("����ɹ���\n");
						}
						else printf("��ΪNULL������ʧ�ܣ�\n");
						break;
					}
					case 15: {  //�ļ���ȡ
						if (Lists.elem[number - 1].T == NULL) {
							char FileName[30] = "tree.txt";  //�����ļ���
							if (LoadBiTree(Lists.elem[number - 1].T, FileName) == OK)printf("��ȡ�ɹ���\n");
						}
						else printf("����Ϊ�գ��޷���ȡ�ļ���\n");
						break;
					}
					case 16: {  //���ض��˵�
						goto A;
						break;
					}
					default:printf("����������������룡\n");
					}
					printf("\n����������Ҫ�Ĳ�����");
					scanf("%d", &num);
				}
			}
			case 5: {  //��������
				if (Lists.length == 0) { printf("���������ݣ�\n"); break; }
				int i;
				for (i = 0; i < Lists.length; i++) {
					printf("%s ", Lists.elem[i].name);
					if (Lists.elem[i].T == NULL) { printf("�����ݣ�\n"); continue; }
					if (BiTreeDepth(Lists.elem[i].T) == 0) { printf("�����ݣ�\n"); continue; }
					else {
						printf("���������");
						PreOrderTraverse(Lists.elem[i].T,visit);
						putchar('\n');
					}
				}
				break;
			}
			case 6: {  //��ն���
				if (Lists.length == 0) { printf("���ٳɹ���\n"); break; }
				Lists.length = 0;
				printf("���ٳɹ���\n");
				break;

			}
			case 7: {  //�ļ����棨������
				char Listsname[30] = "trees.txt"; //����ļ���
				if (Lists.length != 0) {
					int i; 
					FILE* fp = fopen(Listsname, "w");
					for (i = 0; i < Lists.length; i++) {
						MoreSaveBiTree(Lists.elem[i].name, Lists.elem[i].T, fp);
						if(i!=Lists.length-1)fprintf(fp, "\n");
					}
					fclose(fp);
					printf("����ɹ���\n");
					break;
				}
				printf("�����ݿɱ��棡\n");
				break;
			}
			case 8: {  //�ļ���ȡ��������
				char Listsname[30] = "trees.txt"; //����ļ���
				if (Lists.length == 0) {
					int i;
					FILE* fp = fopen(Listsname, "r");
					for (i = 0; ; i++) {
						fscanf(fp, "%s", Lists.elem[i].name);
						MoreLoadBiTree(Lists.elem[i].T, fp);
						Lists.length++;
						if (feof(fp)) break;
						
					}
					printf("��ȡ�ɹ���\n");
					break;
				}
				printf("��������������ݴ��ڣ����ɶ�ȡ��\n");
				break;
			}
			default:printf("����������������룡\n");
			}

			printf("\n����������Ҫ�Ĳ�����");
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

status Compare1(TElemType definition[]){ //�ȽϽṹ����������û����ͬ�Ĺؼ���
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

status CreateBiTree(BiTree& T, TElemType definition[])//���ݴ���֦�Ķ������ȸ���������definition����һ�ö������������ڵ�ָ�븳ֵ��T������OK���������ͬ�Ĺؼ��֣�����ERROR��
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

status ClearBiTree(BiTree& T)//�����������óɿգ���ɾ�����н�㣬�ͷŽ��ռ�
{
	if (T) {
		ClearBiTree(T->lchild);
		ClearBiTree(T->rchild);
		free(T);
		T = NULL;
	}
	return OK;
}

int BiTreeDepth(BiTree T)//�������T�����
{
	if (T) {

		int nLeft = BiTreeDepth(T->lchild);
		int nRight = BiTreeDepth(T->rchild);
		return nLeft > nRight ? nLeft + 1 : nRight + 1;
	}
	else return 0;
}

BiTNode* LocateNode(BiTree T, KeyType e)//���ҽ��
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

void SaveKey(KeyType save[], BiTree T) { //��TԪ�ر��浽���飻
	if (T) {
		save[i2] = T->data.key;
		i2++;
		save[i2] = -1;
		SaveKey(save, T->lchild);
		SaveKey(save, T->rchild);
	}
	return;
}

status Compare2(KeyType definition[], KeyType e, KeyType E) { //�����ظ��ؼ���
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

status Assign(BiTree& T, KeyType e, TElemType value)//ʵ�ֽ�㸳ֵ
{
	BiTNode* ret_tree;
	i3 = 0;
	if ((ret_tree = LocateNode(T, e)) == NULL)return ERROR;
	KeyType save[100];//���浽����
	SaveKey(save, T);
	if (Compare2(save, e, value.key) == ERROR) return ERROR;
	ret_tree->data.key = value.key;
	strcpy(ret_tree->data.others, value.others);
	return OK;
}

BiTNode* GetSibling(BiTree T, KeyType e)//ʵ�ֻ���ֵܽ��
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

status Compare3(KeyType definition[], KeyType E) { //�����ظ��ؼ���
	int k = 0;
	while (definition[k] != E && definition[k] != -1) {
		k++;
	}
	if (definition[k] == -1)return OK;
	else return ERROR;
}

status InsertNode(BiTree& T, KeyType e, int LR, TElemType c)//������
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

BiTNode* GetBefore(BiTree T, KeyType e)//ʵ�ֻ�ø��׽��
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

status DeleteNode(BiTree& T, KeyType e)//ɾ�����
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

status PreOrderTraverse(BiTree T, void (*visit)(BiTree))//�������������T
{
	if (T) {
		visit(T);
		PreOrderTraverse(T->lchild, visit);
		PreOrderTraverse(T->rchild, visit);
	}
	return OK;
}

status InOrderTraverse(BiTree T, void (*visit)(BiTree))//�������������T
{
	struct BiTNode* st[100];
	//����ָ��ջst[0..maxleng-1]�����ڱ�����ʹ��Ľ�㣬
	//�ں��������з��ʸý����Һ���
	int top = 0;      //�ÿ�ջ
	do {
		while (T) {            //��ָ��t��ʾ��Ϊ�ǿն����� 
			if (top == 100) exit(OVERFLOW);//ջ����,�˳�
			st[top++] = T;             //��ָ���ջ
			T = T->lchild;              //t����������
		}
		//ѭ��������ʾ��ջ��Ԫ�ص�ָ��Ϊ���Ľ����������������
		if (top) {                       //Ϊ�ǿ�ջ   
			T = st[--top];            //������ָ��
			visit(T);    //���ʸ����
			T = T->rchild;                 //׼������������
		}
	} while (top || T); //�����δ���ʣ���������δ����
	return OK;
}

status PostOrderTraverse(BiTree T, void (*visit)(BiTree))//�������������T
{
	if (T) {
		PostOrderTraverse(T->lchild, visit);
		PostOrderTraverse(T->rchild, visit);
		visit(T);
	}
	return OK;
}

status LevelOrderTraverse(BiTree T, void (*visit)(BiTree))//�������������T
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

void SaveFile(BiTree T, FILE* fp) { //�����ļ�����
	if (T) {
		fprintf(fp, " %d %s", T->data.key, T->data.others);
		if (T->lchild == NULL) fprintf(fp, " 0 null");
		SaveFile(T->lchild, fp);
		if (T->rchild == NULL) fprintf(fp, " 0 null");
		SaveFile(T->rchild, fp);
	}
}

status SaveBiTree(BiTree T, char FileName[])//���������Ľ������д�뵽�ļ�FileName��
{
	FILE* fp = fopen(FileName, "w");
	SaveFile(T, fp);
	fclose(fp);
	return OK;
}

status LoadBiTree(BiTree& T, char FileName[])//�����ļ�FileName�Ľ�����ݣ�����������
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

status LocateList(LISTS Lists, char ListName[])// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�ERROR
{
	int n;
	for (n = 0; n < Lists.length; n++) {
		if (!strcmp(Lists.elem[n].name, ListName)) return (n + 1);

	}
	return ERROR;
}

status AddList(LISTS& Lists, char ListName[])//��������
{
	Lists.elem[Lists.length].T = NULL;
	strcpy(Lists.elem[Lists.length].name, ListName);
	Lists.length++;
	return OK;
}

status MoreSaveBiTree(char name[],BiTree T,FILE *fp)//���������Ľ������д�뵽�ļ�FileName��
{
	fprintf(fp, "%s", name);
	SaveFile(T, fp);
	return OK;
}

status MoreLoadBiTree(BiTree& T, FILE* fp)
//�����ļ�FileName�Ľ�����ݣ�����������
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

