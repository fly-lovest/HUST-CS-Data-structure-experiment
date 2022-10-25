#include "def.h"

SqList L;
LISTS Lists;

int num;  //�������
int dat;  //��������
int i;    //λ�÷���
int save;   //�ݴ�����
char saveName[30];  //�ݴ����

int main() {
	printf("-----------------����˳��洢�ṹ�����Ա�ϵͳ--------------------\n\n");  //һ���˵�
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
				if (InitList(L) == OK) {
					printf("�����뵥�����ݡ�����0ֹͣ����");
					scanf("%d", &dat);
					while (dat) {
						L.elem[L.length] = dat;
						L.length++;
						scanf("%d", &dat);
					}
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
				if (L.elem == NULL) { printf("��ΪNULL���޷�����Ԫ�أ�\n"); break; }
				if (L.length != 0) { printf("����Ϊ0����ѡ�����Ԫ�أ�\n"); break; }
				printf("�����뵥�����ݡ�����0ֹͣ����");
				scanf("%d", &dat);
				while (dat) {
					L.elem[L.length] = dat;
					L.length++;
					scanf("%d", &dat);
				}
				break;
			}
			case 5: {  //�жϿձ�
				if (ListEmpty(L) == TRUE) {printf("����������\n"); break;}
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
				if (GetElem(L, i, save) == OK) { printf("��%d��Ԫ��Ϊ%d\n", i, save); break; }
				if(GetElem(L, i, save) == ERROR) { printf("��%d��Ԫ�ز�����\n", i); break; }
				printf("��ΪNULL��\n");
				break;
			}
			case 8: {  //Ԫ�ز���
				printf("����������ҵ�Ԫ�أ�");
				scanf("%d", &save);
				if(LocateElem(L, save)== INFEASIBLE) { printf("��ΪNULL��\n"); break; }
				if (LocateElem(L, save) == ERROR) { printf("%d�ڱ��в�����\n",save); break; }
				printf("��%d��Ԫ��Ϊ%d\n", LocateElem(L, save), save);
				break;
			}
			case 9: {  //���ǰ��
				int pre; //�ݴ�ǰ��
				printf("��������ѡ���Ԫ�أ�");
				scanf("%d", &save);
				if(PriorElem(L,save,pre)== INFEASIBLE) { printf("��ΪNULL��\n"); break; }
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
				if (L.elem==NULL) { printf("��ΪNULL��\n"); break; }
				printf("���������ڵڼ���Ԫ��ǰ�����Ԫ�ء�������λ��������Ԫ�ء���");
				scanf("%d%d", &i, &save);
				if(ListInsert(L, i,save)==ERROR){ printf("�޷������ڵ�%d��Ԫ��ǰ����Ԫ��\n", i); break; }
				printf("����ɹ�������Ϊ��");
				int n;
				for (n = 0; n < L.length; n++) {
					printf("%d ", L.elem[n]);
				}
				putchar('\n');
				break;
			}
			case 12: {  //ɾ��Ԫ��
				if (L.elem == NULL) { printf("��ΪNULL��\n"); break; }
				printf("���������ڵڼ���Ԫ�أ�");   //�жϱ����Ԫ������
				scanf("%d", &i);
				if (ListDelete(L, i, save) == ERROR) { printf("�޷�ɾ���ڵ�%d��Ԫ��\n", i); break; }
				printf("ɾ���ĵ�%dΪ%d������Ϊ��",i,save);
				int n;
				for (n = 0; n < L.length; n++) {
					printf("%d ", L.elem[n]);
				}
				putchar('\n');
				break;
			}
			case 13: {  //��������
				if (L.elem == NULL) { printf("��ΪNULL��\n"); break; }
				if(L.length==0) { printf("����Ϊ�������ݣ�\n"); break; }
				else {
					printf("����Ϊ��");
					ListTraverse(L);
					putchar('\n');
				}
				break;
			}
			case 14: {  //�ļ�����
				char FileName[30]="date.txt";  //�����ļ���
				if (SaveList(L,FileName) == OK)printf("����ɹ�\n");
				else printf("��ΪNULL������ʧ�ܣ�\n");
				break;
			}
			case 15: {  //�ļ���ȡ
				char FileName[30] = "date.txt";  //�����ļ���
				if (LoadList(L, FileName) == INFEASIBLE)printf("��ΪNULL���޷���ȡ���ݣ�\n");
				else printf("�ļ���ȡ�ɹ���\n");
				break;
			}
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
				scanf("%d", &dat);
				while (dat) {
					Lists.elem[Lists.length - 1].L.elem[Lists.elem[Lists.length - 1].L.length] = dat;
					Lists.elem[Lists.length - 1].L.length++;
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
				if ((save = LocateList(Lists, saveName)) == ERROR) { printf("�޸ñ��������Ա�\n"); break; }
				printf("���ҳɹ���%s ",saveName);

				if (Lists.elem[save - 1].L.elem == NULL) { printf("��ΪNULL��\n"); break; }
				if (Lists.elem[save - 1].L.length == 0) { printf("�����ݣ�\n"); break; }
				else {
					ListTraverse(Lists.elem[save - 1].L);
					putchar('\n');
				}
				break;
			}
			case 4: {  //��������
				printf("�������뵥��������ı�����");
				scanf("%s", saveName);
				if ((save = LocateList(Lists, saveName)) == ERROR) { printf("�޸ñ��������Ա�\n"); break; }  //�����˵�
				printf("\n-----------------�������еĵ�������˵�--------------------\n\
1.���ض��        2.���ٵ���        3.��յ���\n\
4.����Ԫ��        5.�жϿձ�        6.������\n\
7.λ�ò���        8.Ԫ�ز���        9.��ȡǰ��\n\
10.��ȡ���       11.����Ԫ��       12.ɾ��Ԫ��\n\
13.��������       14.�ļ�����       15.�ļ���ȡ\n\
�����롾1~15��\n\n����������Ҫ�Ĳ�����");
				scanf("%d", &num);   //�������
				while (num) {
					switch (num)
					{
					case 1: {  //���ض��
						goto A;
						break;
					}
					case 2: {  //���ٵ���
						if (DestroyList(Lists.elem[save - 1].L) == OK)printf("�������ٳɹ�\n");
						else printf("��ΪNULL������ʧ�ܣ�\n");
						break;
					}
					case 3: {  //��յ���
						if (ClearList(Lists.elem[save - 1].L) == OK)printf("������ճɹ�\n");
						else printf("��ΪNULL�����ʧ�ܣ�\n");
						break;
					}
					case 4: {  //����Ԫ��
						if (Lists.elem[save - 1].L.elem == NULL) { printf("��ΪNULL���޷�����Ԫ�أ�\n"); break; }
						if (Lists.elem[save - 1].L.length != 0) { printf("����Ϊ0����ѡ�����Ԫ�أ�\n"); break; }
						printf("�����뵥�����ݡ�����0ֹͣ����");
						scanf("%d", &dat);
						while (dat) {
							Lists.elem[save - 1].L.elem[Lists.elem[save - 1].L.length] = dat;
							Lists.elem[save - 1].L.length++;
							scanf("%d", &dat);
						}
						break;
					}
					case 5: {  //�жϿձ�
						if (ListEmpty(Lists.elem[save - 1].L) == TRUE) { printf("����������\n"); break; }
						if (ListEmpty(Lists.elem[save - 1].L) == FALSE) { printf("����������\n"); break; }
						printf("��ΪNULL��\n");
						break;
					}
					case 6: {  //������
						if (ListLength(Lists.elem[save - 1].L) == INFEASIBLE)printf("��ΪNULL��\n");
						else printf("��Ϊ%d\n", ListLength(Lists.elem[save - 1].L));
						break;
					}
					case 7: {  //λ�ò���
						printf("����������ҵ�Ԫ��λ�ã�");
						scanf("%d", &i);
						if (GetElem(Lists.elem[save - 1].L, i, dat) == OK) { printf("��%d��Ԫ��Ϊ%d\n", i, dat); break; }
						if (GetElem(Lists.elem[save - 1].L, i, dat) == ERROR) { printf("��%d��Ԫ�ز�����\n", i); break; }
						printf("��ΪNULL��\n");
						break;
					}
					case 8: {  //Ԫ�ز���
						printf("����������ҵ�Ԫ�أ�");
						scanf("%d", &dat);
						if (LocateElem(Lists.elem[save - 1].L, dat) == INFEASIBLE) { printf("��ΪNULL��\n"); break; }
						if (LocateElem(Lists.elem[save - 1].L, dat) == ERROR) { printf("%d�ڱ��в�����\n", dat); break; }
						printf("��%d��Ԫ��Ϊ%d\n", LocateElem(Lists.elem[save - 1].L, dat), dat);
						break;
					}
					case 9: {  //���ǰ��
						int pre; //�ݴ�ǰ��
						printf("��������ѡ���Ԫ�أ�");
						scanf("%d", &dat);
						if (PriorElem(Lists.elem[save - 1].L, dat, pre) == INFEASIBLE) { printf("��ΪNULL��\n"); break; }
						if (PriorElem(Lists.elem[save - 1].L, dat, pre) == ERROR) { printf("%d��ǰ��������\n", dat); break; }
						printf("������ҵ�ǰ��Ԫ��Ϊ%d\n", pre);
						break;
					}
					case 10: {  //��ú��
						int next; //�ݴ���
						printf("��������ѡ���Ԫ�أ�");
						scanf("%d", &dat);
						if (NextElem(Lists.elem[save - 1].L, dat, next) == INFEASIBLE) { printf("��ΪNULL��\n"); break; }
						if (NextElem(Lists.elem[save - 1].L, dat, next) == ERROR) { printf("%d�ĺ�̲�����\n", dat); break; }
						printf("������ҵĺ��Ԫ��Ϊ%d\n", next);
						break;
					}
					case 11: {  //����Ԫ��
						
						printf("���������ڵڼ���Ԫ��ǰ�����Ԫ�ء�������λ��������Ԫ�ء���");
						scanf("%d%d", &i, &dat);  //����λ�ú�Ԫ��
						if (Lists.elem[save - 1].L.elem == NULL) { printf("��ΪNULL��\n"); break; }
						if (ListInsert(Lists.elem[save - 1].L, i, dat) == ERROR) { printf("�޷������ڵ�%d��Ԫ��ǰ����Ԫ��\n", i); break; }
						printf("����ɹ�������Ϊ��");
						int n;
						for (n = 0; n < Lists.elem[save - 1].L.length; n++) {
							printf("%d ", Lists.elem[save - 1].L.elem[n]);
						}
						putchar('\n');
						break;
					}
					case 12: {  //ɾ��Ԫ��
						if (Lists.elem[save - 1].L.elem == NULL) { printf("��ΪNULL��\n"); break; }
						printf("��������ɾ���ڼ���Ԫ�أ�");
						scanf("%d", &i);
						if (ListDelete(Lists.elem[save - 1].L, i, dat) == ERROR) { printf("�޷�ɾ���ڵ�%d��Ԫ��\n", i); break; }
						printf("ɾ���ĵ�%dΪ%d������Ϊ��", i, dat);
						int n;
						for (n = 0; n < Lists.elem[save - 1].L.length; n++) {
							printf("%d ", Lists.elem[save - 1].L.elem[n]);
						}
						putchar('\n');
						break;
					}
					case 13: {  //��������
						if (Lists.elem[save - 1].L.elem == NULL) { printf("��ΪNULL��\n"); break; }
						if (Lists.elem[save - 1].L.length == 0) { printf("����Ϊ�������ݣ�\n"); break; }
						else {
							printf("����Ϊ��");
							ListTraverse(Lists.elem[save - 1].L);
							putchar('\n');
						}
						break;
					}
					case 14: {  //�ļ�����
						char FileName[30] = "date.txt";  //�����ļ���
						if (SaveList(Lists.elem[save - 1].L, FileName) == OK)printf("����ɹ�\n");
						else printf("��ΪNULL������ʧ�ܣ�\n");
						break;
					}
					case 15: {  //�ļ���ȡ
						char FileName[30] = "date.txt";  //�����ļ���
						if (LoadList(Lists.elem[save - 1].L, FileName) == INFEASIBLE)printf("��ΪNULL���޷���ȡ���ݣ�\n");
						else printf("�ļ���ȡ�ɹ���\n");
						break;
					}
					}
					printf("\n����������Ҫ�Ĳ�����");
					scanf("%d", &num);
				}
			}
			case 5: {  //�������
				if (Lists.length == 0) { printf("��������ݣ�\n"); break; }
				for (i = 0; i < Lists.length; i++) {
					printf("%s ", Lists.elem[i].name);
					if (Lists.elem[i].L.elem == NULL) { printf("��ΪNULL��\n"); continue; }
				    if(Lists.elem[i].L.length==0) { printf("�����ݣ�\n"); continue; }
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
					int n;  //Ƕ��ѭ�������Listsѭ�����ڲ�Lѭ����

					for (i = 0; i < Lists.length; i++) {
						fprintf(fp, "%s ", Lists.elem[i].name);
						for (n = 0; n < Lists.elem[i].L.length; n++) {
							if (n == Lists.elem[i].L.length - 1) { fprintf(fp, "%d", Lists.elem[i].L.elem[n]); break; }
							fprintf(fp, "%d ", Lists.elem[i].L.elem[n]);
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
					printf("�ļ���ȡ�ɹ�\n");
					break;
				}
				printf("��������ݴ��ڣ����ɶ�ȡ��\n");
				break;
			}
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