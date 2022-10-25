#include "def.h"

LinkList L;
LISTS Lists;

int num;  //�������
int dat;  //��������
int i;    //λ�÷���
int save,e;   //�ݴ�����
int number;   //�������е����
char saveName[30];  //�ݴ����

int main() {
	printf("-----------------������ʽ�洢�ṹ�����Ա�ϵͳ--------------------\n\n");  //һ���˵�
	printf("1.�������\t\t2.������\t\t0.ֹͣ����\n\n����������Ҫ�Ĳ�����");

	scanf("%d", &num);
	if (num == 1) {       //��������������˵���
		printf("\n-----------------��������˵�--------------------\n\
1.���쵥��        2.���ٵ���        3.��յ���\n\
4.����Ԫ��        5.�жϿձ�        6.������\n\
7.λ�ò���        8.Ԫ�ز���        9.��ȡǰ��\n\
10.��ȡ���       11.����Ԫ��       12.ɾ��Ԫ��\n\
13.��������       14.�ļ�����       15.�ļ���ȡ\n\
0.ֹͣ����        �����롾0~15��\n\n����������Ҫ�Ĳ�����");
		scanf("%d", &num);  //�������
		while (num) {
			switch (num)
			{
			case 1: {  //���쵥��
				LNode* p;
				if (InitList(L) == OK) {
					p = L;
					printf("�����뵥�����ݡ�����0ֹͣ����");
					scanf("%d", &dat);
					while (dat) {
						InitList(p->next);
						p = p->next;
						p->data = dat;
						scanf("%d", &dat);
					}
					printf("�����ɹ���\n");
				}
				else printf("����ڣ��޷�������\n");
				break;
			}
			case 2: {  //���ٵ���
				if (DestroyList(L) == OK)printf("�������ٳɹ�\n");
				else printf("��ΪNULL������ʧ�ܣ�\n");
				break;
			}
			case 3: {  //��յ���
				if (ClearList(L) == OK)printf("������ճɹ�\n");
				else printf("��ΪNULL�����ʧ�ܣ�\n");
				break;
			}
			case 4: {  //����Ԫ��
				if (L== NULL) { printf("��ΪNULL���޷�����Ԫ�أ�\n"); break; }
				if (ListLength(L)!= 0) { printf("����Ϊ0����ѡ�����Ԫ�أ�\n"); break; }
				LNode* p=L;
				printf("�����뵥�����ݡ�����0ֹͣ����");
				scanf("%d", &dat);
				while (dat) {
					InitList(p->next);
					p = p->next;
					p->data = dat;
					scanf("%d", &dat);
				}
				break;
			}
			case 5: {  //�жϿձ�
				if (ListEmpty(L) == TRUE) { printf("����������\n"); break; }
				if (ListEmpty(L) == FALSE) { printf("����������\n"); break; }
				printf("��ΪNULL��\n");
				break;
			}
			case 6: {  //������
				if (ListLength(L) == INFEASIBLE)printf("��ΪNULL��\n");
				else printf("��Ϊ%d\n", ListLength(L));
				break;
			}
			case 7: {  //λ�ò���
				printf("����������ҵ�Ԫ��λ�ã�");
				scanf("%d", &i);
				if (GetElem(L, i, e) == OK) { printf("��%d��Ԫ��Ϊ%d\n", i, e); break; }
				if (GetElem(L, i, e) == ERROR) { printf("��%d��Ԫ�ز�����\n", i); break; }
				printf("��ΪNULL��\n");
				break;
			}
			case 8: {  //Ԫ�ز���
				printf("����������ҵ�Ԫ�أ�");
				scanf("%d", &save);
				if (LocateElem(L, save) == INFEASIBLE) { printf("��ΪNULL��\n"); break; }
				if (LocateElem(L, save) == ERROR) { printf("%d�ڱ��в�����\n", save); break; }
				printf("��%d��Ԫ��Ϊ%d\n", LocateElem(L, save), save);
				break;
			}
			case 9: {  //���ǰ��
				int pre; //�ݴ�ǰ��
				printf("��������ѡ���Ԫ�أ�");
				scanf("%d", &save);
				if (PriorElem(L, save, pre) == INFEASIBLE) { printf("��ΪNULL��\n"); break; }
				if (PriorElem(L, save, pre) == ERROR) { printf("%d��ǰ��������\n", save); break; }
				printf("������ҵ�ǰ��Ԫ��Ϊ%d\n", pre);
				break;
			}
			case 10: {  //��ú��
				int next; //�ݴ���
				printf("��������ѡ���Ԫ�أ�");
				scanf("%d", &save);
				if (NextElem(L, save, next) == INFEASIBLE) { printf("��ΪNULL��\n"); break; }
				if (NextElem(L, save, next) == ERROR) { printf("%d�ĺ�̲�����\n", save); break; }
				printf("������ҵĺ��Ԫ��Ϊ%d\n", next);
				break;
			}
			case 11: {  //����Ԫ��
				if (L== NULL) { printf("��ΪNULL��\n"); break; }
				printf("���������ڵڼ���Ԫ��ǰ�����Ԫ�ء�������λ��������Ԫ�ء���");
				scanf("%d%d", &i, &save);
				if (ListInsert(L, i, save) == ERROR) { printf("�޷������ڵ�%d��Ԫ��ǰ����Ԫ��\n", i); break; }
				printf("����ɹ�������Ϊ��");
				LNode* p = L->next;
				while(p){
					if (p->next == NULL) { printf("%d", p->data); break; }
					printf("%d ", p->data);
					p = p->next;
				}
				putchar('\n');
				break;
			}
			case 12: {  //ɾ��Ԫ��
				if (L == NULL) { printf("��ΪNULL��\n"); break; }
				printf("��������ɾ���ڼ���Ԫ�أ�");   //�жϱ����Ԫ������
				scanf("%d", &i);
				if (ListDelete(L, i, e) == ERROR) { printf("�޷�ɾ���ڵ�%d��Ԫ��\n", i); break; }
				printf("ɾ���ĵ�%dΪ%d������Ϊ��", i, e);
				LNode* p = L->next;
				while (p) {
					if (p->next == NULL) { printf("%d", p->data); break; }
					printf("%d ", p->data);
					p = p->next;
				}
				putchar('\n');
				break;
			}
			case 13: {  //��������
				if (L == NULL) { printf("��ΪNULL��\n"); break; }
				if (ListLength(L) == 0) { printf("����Ϊ�������ݣ�\n"); break; }
				else {
					printf("����Ϊ��");
					ListTraverse(L);
					putchar('\n');
				}
				break;
			}
			case 14: {  //�ļ�����
				char FileName[30] = "data.txt";  //�����ļ���
				if (SaveList(L, FileName) == OK)printf("����ɹ�\n");
				else printf("��ΪNULL������ʧ�ܣ�\n");
				break;
			}
			case 15: {  //�ļ���ȡ
				char FileName[30] = "date.txt";  //�����ļ���
				if (LoadList(L, FileName) == INFEASIBLE)printf("��ΪNULL���޷���ȡ���ݣ�\n");
				else printf("�ļ���ȡ�ɹ���\n");
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
		printf("\n-----------------�������˵�--------------------\n\
1.�������        2.�Ƴ�ĳ��        3.����ĳ��\n\
4.��������        5.�������        6.��ն��\n\
7.�ļ�����        8.�ļ���ȡ\n\
0.ֹͣ����        �����롾0~8��\n\n����������Ҫ�Ĳ�����");
		scanf("%d", &num);
		while (num) {
			switch (num)
			{
			case 1: {  //�������
				printf("���봴��������ƣ�");
				scanf("%s", saveName);
				AddList(Lists, saveName);
				printf("���������ݡ�����0ֹͣ����");
				LNode* p = Lists.elem[Lists.length - 1].L;
				scanf("%d", &dat);
				while (dat) {
					InitList(p->next);
					p = p->next;
					p->data = dat;
					scanf("%d", &dat);
				}
				printf("��ӳɹ���\n");
				break;
			}
			case 2: {  //�Ƴ�ĳ��
				printf("���������Ƴ���ı�����");
				scanf("%s", saveName);
				if (RemoveList(Lists, saveName) == ERROR) { printf("�޸ñ��������Ա�\n"); break; }
				else printf("ɾ���ɹ���\n");
				break;
			}
			case 3: {  //����ĳ��
				printf("����������ұ�ı�����");
				scanf("%s", saveName);
				if ((e = LocateList(Lists, saveName)) == ERROR) { printf("�޸ñ��������Ա�\n"); break; }
				printf("���ҳɹ���%s ", saveName);

				if (Lists.elem[e - 1].L == NULL) { printf("��ΪNULL��\n"); break; }
				if (ListLength(Lists.elem[e - 1].L) == 0) { printf("���������ݣ�\n"); break; }
				else {
					ListTraverse(Lists.elem[e - 1].L);
					putchar('\n');
				}
				break;
			}
			case 4: {  //��������
				printf("�������뵥��������ı�����");
				scanf("%s", saveName);
				if ((number = LocateList(Lists, saveName)) == ERROR) { printf("�޸ñ��������Ա�\n"); break; }  //�����˵�
				printf("\n-----------------�������еĵ�������˵�--------------------\n\
1.��������        2.���ٵ���        3.��յ���\n\
4.����Ԫ��        5.�жϿձ�        6.������\n\
7.λ�ò���        8.Ԫ�ز���        9.��ȡǰ��\n\
10.��ȡ���       11.����Ԫ��       12.ɾ��Ԫ��\n\
13.��������       14.�ļ�����       15.�ļ���ȡ\n\
16.���ض��˵�\n\
�����롾1~16��\n\n����������Ҫ�Ĳ�����");
				scanf("%d", &num);   //�������
				while (num) {
					switch (num)
					{
					case 1: {  //��������
						LNode* p;
						if (InitList(Lists.elem[number - 1].L) == OK) {
							p = Lists.elem[number - 1].L;
							printf("�����뵥�����ݡ�����0ֹͣ����");
							scanf("%d", &dat);
							while (dat) {
								InitList(p->next);
								p = p->next;
								p->data = dat;
								scanf("%d", &dat);
							}
							printf("�����ɹ���\n");
						}
						else printf("����ڣ��޷�������\n");
						break;
					}
					case 2: {  //���ٵ���
						if (DestroyList(Lists.elem[number - 1].L) == OK)printf("�������ٳɹ�\n");
						else printf("��ΪNULL������ʧ�ܣ�\n");
						break;
					}
					case 3: {  //��յ���
						if (ClearList(Lists.elem[number - 1].L) == OK)printf("������ճɹ�\n");
						else printf("��ΪNULL�����ʧ�ܣ�\n");
						break;
					}
					case 4: {  //����Ԫ��
						if (Lists.elem[number - 1].L == NULL) { printf("��ΪNULL���޷�����Ԫ�أ�\n"); break; }
						if (ListLength(Lists.elem[number - 1].L)!= 0) { printf("����Ϊ0����ѡ�����Ԫ�أ�\n"); break; }
						printf("�����뵥�����ݡ�����0ֹͣ����");
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
					case 5: {  //�жϿձ�
						if (ListEmpty(Lists.elem[number - 1].L) == TRUE) { printf("����������\n"); break; }
						if (ListEmpty(Lists.elem[number - 1].L) == FALSE) { printf("����������\n"); break; }
						printf("��ΪNULL��\n");
						break;
					}
					case 6: {  //������
						if (ListLength(Lists.elem[number - 1].L) == INFEASIBLE)printf("��ΪNULL��\n");
						else printf("��Ϊ%d\n", ListLength(Lists.elem[number - 1].L));
						break;
					}
					case 7: {  //λ�ò���
						printf("����������ҵ�Ԫ��λ�ã�");
						scanf("%d", &i);
						if (GetElem(Lists.elem[number - 1].L, i, e) == OK) { printf("��%d��Ԫ��Ϊ%d\n", i, e); break; }
						if (GetElem(Lists.elem[number - 1].L, i, e) == ERROR) { printf("��%d��Ԫ�ز�����\n", i); break; }
						printf("��ΪNULL��\n");
						break;
					}
					case 8: {  //Ԫ�ز���
						printf("����������ҵ�Ԫ�أ�");
						scanf("%d", &dat);
						if (LocateElem(Lists.elem[number - 1].L, dat) == INFEASIBLE) { printf("��ΪNULL��\n"); break; }
						if (LocateElem(Lists.elem[number - 1].L, dat) == ERROR) { printf("%d�ڱ��в�����\n", dat); break; }
						printf("��%d��Ԫ��Ϊ%d\n", LocateElem(Lists.elem[number - 1].L, dat), dat);
						break;
					}
					case 9: {  //���ǰ��
						int pre; //�ݴ�ǰ��
						printf("��������ѡ���Ԫ�أ�");
						scanf("%d", &dat);
						if (PriorElem(Lists.elem[number - 1].L, dat, pre) == INFEASIBLE) { printf("��ΪNULL��\n"); break; }
						if (PriorElem(Lists.elem[number - 1].L, dat, pre) == ERROR) { printf("%d��ǰ��������\n", dat); break; }
						printf("������ҵ�ǰ��Ԫ��Ϊ%d\n", pre);
						break;
					}
					case 10: {  //��ú��
						int next; //�ݴ���
						printf("��������ѡ���Ԫ�أ�");
						scanf("%d", &dat);
						if (NextElem(Lists.elem[number - 1].L, dat, next) == INFEASIBLE) { printf("��ΪNULL��\n"); break; }
						if (NextElem(Lists.elem[number - 1].L, dat, next) == ERROR) { printf("%d�ĺ�̲�����\n", dat); break; }
						printf("������ҵĺ��Ԫ��Ϊ%d\n", next);
						break;
					}
					case 11: {  //����Ԫ��

						printf("���������ڵڼ���Ԫ��ǰ�����Ԫ�ء�������λ��������Ԫ�ء���");
						scanf("%d%d", &i, &dat);  //����λ�ú�Ԫ��
						if (Lists.elem[number - 1].L == NULL) { printf("��ΪNULL��\n"); break; }
						if (ListInsert(Lists.elem[number - 1].L, i, dat) == ERROR) { printf("�޷��ڵ�%d��Ԫ��ǰ����Ԫ��\n", i); break; }
						printf("����ɹ�������Ϊ��");
						ListTraverse(Lists.elem[number - 1].L);
						putchar('\n');
						break;
					}
					case 12: {  //ɾ��Ԫ��
						if (Lists.elem[number - 1].L == NULL) { printf("��ΪNULL��\n"); break; }
						printf("��������ɾ���ڼ���Ԫ�أ�");
						scanf("%d", &i);
						if (ListDelete(Lists.elem[number - 1].L, i, dat) == ERROR) { printf("�޷�ɾ���ڵ�%d��Ԫ��\n", i); break; }
						printf("ɾ���ĵ�%dΪ%d������Ϊ��", i, dat);
						ListTraverse(Lists.elem[number - 1].L);
						putchar('\n');
						break;
					}
					case 13: {  //��������
						if (Lists.elem[number - 1].L == NULL) { printf("��ΪNULL��\n"); break; }
						if (ListLength(Lists.elem[number - 1].L) == 0) { printf("����Ϊ�������ݣ�\n"); break; }
						else {
							printf("����Ϊ��");
							ListTraverse(Lists.elem[number - 1].L);
							putchar('\n');
						}
						break;
					}
					case 14: {  //�ļ�����
						char FileName[30] = "data.txt";  //�����ļ���
						if (SaveList(Lists.elem[number - 1].L, FileName) == OK)printf("�ļ�����ɹ�\n");
						else printf("��ΪNULL������ʧ�ܣ�\n");
						break;
					}
					case 15: {  //�ļ���ȡ
						char FileName[30] = "data.txt";  //�����ļ���
						if (LoadList(Lists.elem[number - 1].L, FileName) == INFEASIBLE)printf("��ΪNULL���޷���ȡ���ݣ�\n");
						else printf("�ļ���ȡ�ɹ���\n");
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
			case 5: {  //�������
				if (Lists.length == 0) { printf("��������ݣ�\n"); break; }
				for (i = 0; i < Lists.length; i++) {
					printf("%s ", Lists.elem[i].name);
					if (Lists.elem[i].L == NULL) { printf("��ΪNULL��\n"); continue; }
					if (ListLength(Lists.elem[i].L) == 0) { printf("�����ݣ�\n"); continue; }
					else {
						ListTraverse(Lists.elem[i].L);
						putchar('\n');
					}
				}
				break;
			}
			case 6: {  //��ն��
				if (Lists.length == 0) { printf("���ٳɹ���\n"); break; }
				Lists.length = 0;
				printf("���ٳɹ���\n");
				break;

			}
			case 7: {  //�ļ����棨���
				char Listsname[30] = "Lists.txt"; //����ļ���
				FILE* fp;
				if (Lists.length != 0) {
					fp = fopen(Listsname, "w");
					LNode* p;
					int n;  //Ƕ��ѭ�������Listsѭ�����ڲ�Lѭ����

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
					printf("����ɹ���\n");
					break;
				}
				printf("�����ݿɱ��棡\n");
				break;
			}
			case 8: {  //�ļ���ȡ�����
				char Listsname[30] = "Lists.txt"; //����ļ���

				if (Lists.length == 0) {
					int n;  //Ƕ��ѭ�������Listsѭ�����ڲ�Lѭ����
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
					printf("�ļ���ȡ�ɹ�\n");
					break;
				}
				printf("��������ݴ��ڣ����ɶ�ȡ��\n");
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



//��������
status InitList(LinkList& L)
{
	if (L == NULL) {
		L = (LinkList)malloc(sizeof(LNode));
		L->next = NULL;
		return OK;
	}
	else return INFEASIBLE;

}

// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
status DestroyList(LinkList& L)
{
	if (L != NULL) {
		free(L);
		L = NULL;
		return OK;

	}
	else return INFEASIBLE;
}

// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
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

// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
status ListEmpty(LinkList L)
{
	if (L != NULL) {
		if (L->next == NULL)return TRUE;
		else return FALSE;

	}
	else return INFEASIBLE;
}

// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
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

// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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

// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
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

// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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

// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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

// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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

// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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

// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
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

// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
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

// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
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

// �������
status AddList(LISTS& Lists, char ListName[])
{
	
	Lists.elem[Lists.length].L = NULL;
	int i = 0;
	strcpy(Lists.elem[Lists.length].name, ListName);
	InitList(Lists.elem[Lists.length].L);
	Lists.length ++;
	return OK;
}

// �Ƴ�ĳ��
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

// ����ĳ��
status LocateList(LISTS Lists, char ListName[])// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�ERROR
{
	int n;
	for (n = 0; n < Lists.length; n++) {
		if (!strcmp(Lists.elem[n].name, ListName)) return (n + 1);

	}
	return ERROR;
}
