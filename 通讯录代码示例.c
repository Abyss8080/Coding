//ͨѶ¼����ʾ��
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define FILENAME "maillist"

typedef struct person {
	char name[20];
	//����
	char address[40];
	//��ַ
	long zip;
	//�ʱ�
	char phone[15];
	//�绰����
} PERSON;

typedef struct address {
	char name[20];
	//����
	char address[40];
	//��ַ
	long zip;
	//�ʱ�
	char phone[15];
	//�绰����
	struct address *next;
} ADDRESS;
typedef ADDRESS *AD_LIST;
//�ѵ�ַ�ṹ��ָ�������AD_LIST

AD_LIST load(void);
int menu_select(void);
AD_LIST insert(AD_LIST head);
void show(AD_LIST head);
void find(AD_LIST head);
AD_LIST delectenode(AD_LIST head);
void save(AD_LIST head);




int main() {
	AD_LIST head;
	//ͨѶ¼ͷָ�룻
	char choice;

	head = load();
	for (;;) {
		choice = menu_select();
		switch (choice) {
			case 1:
				head = insert(head);
				break;
			case 2:
				show(head);
				break;
			case 3:
				find(head);
				break;
			case 4:
				head = delectenode(head);
				break;
			case 5:
				save(head);
				break;
			case 6:
				return 0;
		}
	}
	return 0;
}


int menu_select(void) {
	//�����˵���ѡ����
	char s[80];
	int c;

	printf("\t\t    ͨѶ¼����ϵͳ\n");
	printf("\t\t========================\n");
	printf("\t\t    1.����һ����¼\n");
	printf("\t\t    2.��ʾ���м�¼\n");
	printf("\t\t    3.����������\n");
	printf("\t\t    4.������ɾ��\n");
	printf("\t\t    5.����\n");
	printf("\t\t    6.�˳�\n");

	do {
		printf("\n\n\t��ѡ��~6����");
		gets(s);
		printf("\n");
		c = atoi(s);
		//atoi�ǰ��ַ���ת����ʮ�������͵ĺ������յĻ�����0,����Ļ�����-1
		//int atoi (const char *nptr)
	} while (c < 0 || c > 6);

	return c;
}


AD_LIST load(void) {
	//����һ��ͨѶ¼�ļ�
	AD_LIST p, q, head;
	PERSON per;
	FILE *fp;
//FILE���ļ�����ָ��
//#ifndef _FILE_DEFINED
//struct _iobuf {
//��������char *_ptr; //�ļ��������һ��λ��
//��������int _cnt; //��ǰ�����������λ��
//��������char *_base; //ָ����λ��(�����ļ�����ʼλ��)
//��������int _flag; //�ļ���־
//��������int _file; //�ļ�������id
//��������int _charbuf; //��黺����״��,����޻������򲻶�ȡ
//��������int _bufsiz; //�ļ���������С
//��������char *_tmpfname; //��ʱ�ļ���
//       };
//typedef struct _iobuf FILE;
//#define _FILE_DEFINED
//#endif
//FILE *fopen( char *file, char *open_mode ); //���ļ������ļ����ڴ棬�����ļ���Ϣ�ṹָ��
//int fread( char s, int size, int num, FILE *fp ); //���ֽڶ�ȡ�ļ����ݵ�s��
//�ɹ���ȡ��Ԫ���������� size ���󷵻أ�size ������һ�������������͡�
//��������� num ������ͬ������ܷ�����һ��������ߵ������ļ�ĩβ��
//int fwrite( char s, int size, int num, FILE *fp ); //���ֽڽ�s��ַ�е�����д���ļ���
//char *fgets( char *s, int max_size, FILE *fp); //��һ�����ݵ�������s��
//int fseek( FILE *fp, long offset, int whence); //�ƶ��ļ�ָ�뵽ָ��λ
//void rewind(FILE *fp); //�ص��ļ�ͷ
//long ftell(FILE *fp); //�õ���ǰ�ļ�ƫ��λ��
//fclose(fp); //�ر��ļ���ˢ�»��浽���������
//feof ()����������⵱ǰ�ļ����ϵ��ļ�������ʶ,�ж��Ƿ�������ļ���β
//��ԭ��Ϊ�� int feof (FILE * stream);��⵽�ļ�������ʶ����1�����򷵻�0��
	q = head = NULL;
	if ((fp = fopen(FILENAME, "rb")) == NULL) {
		//rb�������еĶ������ļ����������wb���򿪶������ļ�������д
		printf("Can not open file %s\n", FILENAME);
		return head;
	} else {
		while (!feof(fp))
			//�ļ�û�н���
			if (fread(&per, sizeof(PERSON), 1, fp) == 1) {
				//��ȡ�ɹ�
				p = (AD_LIST)malloc(sizeof(ADDRESS));

				strcpy(p->name, per.name);
				strcpy(p->address, per.address);
				p->zip = per.zip;
				strcpy(p->phone, per.phone);

				head = p;
				p->next = q;
				q = head;
			}
		fclose(fp);
		return head;
	}
}


AD_LIST insert(AD_LIST head) {
	//����һ���µļ�¼
	AD_LIST temp, p;

	p = head;
	temp = (AD_LIST)malloc(sizeof(ADDRESS));

	printf("\n\t����������:");
	gets(temp->name);
	printf("\n\t������ͨ�ŵ�ַ:");
	gets(temp->address);
	fflush(stdin);
//�� ��: �����д������������Ҫ��������������������ݽ�������д��ʱ
//ͷ�ļ���stdio.h
//ԭ��:int fflush(FILE *stream)
//����stream��Ҫ��ϴ����
	printf("\n\t�������ʱ��ַ:");
	scanf("%ld", &temp->zip);
	fflush(stdin);
	printf("\n\t������绰����:");
	gets(temp->phone);
	fflush(stdin);

	head = temp;
	temp->next = p;

	return head;
}



void save(AD_LIST head) {
	//���������ͨѶ¼��ַ
	AD_LIST p;
	FILE *fp;
	PERSON per;

	if ((fp = fopen(FILENAME, "wb")) == NULL) {
		printf("Can not open file %s\n", FILENAME);
		return ;

		//��Ϊ���ص�������void
	} else {
		p = head;
		while (p != NULL) {
			strcpy(per.name, p->name );
			strcpy(per.address, p->address );
			per.zip = p->zip;
			strcpy(per.phone, p->phone );

			if (fwrite(&per, sizeof(PERSON), 1, fp) != 1)
				printf("FILE write error.\n");

			p = p->next;
		}
		fclose(fp);
	}
}


void show(AD_LIST head) {
	//��ʾͨѶ¼
	AD_LIST p;
	p = head;

	printf("%-30s%-40s%-20s%-40s", "����", "��ַ", "�ʱ�", "�绰����");
	while (p != NULL) {
		printf("%-30s", p->name);
		printf("%-40s", p->address);
		printf("%-20s", p->zip);
		printf("%-40", p->phone);

		p = p->next;
	}
}


void find(AD_LIST head) {
	//�ҵ�һ��ͨѶ¼��¼
	AD_LIST p;
	char name[20];
	int flag = 0;

	printf("������Ҫ���ҵ��˵�������");
	gets(name);

	p = head;
	while (p != NULL) {
		if (strcmp(name, p->name) == 0) {
			printf("Name:%s\n", p->name);
			printf("Address:%s\n", p->address);
			printf("Zip:%ld\n", p->zip);
			printf("Phone:%s\n", p->phone);
			flag = 1;

		}
		p = p->next;
	}

	if (flag == 0) {
		printf("\n\t\t���޴���\n\n");
	}
}


AD_LIST delectenode(AD_LIST head) {
	//ɾ��һ��ͨѶ¼��¼
	AD_LIST  q, p;
	char name[20];
	int flag = 0;

	printf("��������ɾ�����˵�������");
	gets(name);

	p = q = head;
	while (p != NULL) {
		if (strcmp(name, p->name) == 0) {
			if (head == p)
				head = p->next;
			else
				q->next = p->next;

			free(p);
			p = q->next;

			flag = 1;
		} else {
			q = p;
			p = p->next;
		}
	}
	if (flag == 0)
		printf("\n\t\t���޴���\n\n");

	return head;
}












