//通讯录代码示例
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define FILENAME "maillist"

typedef struct person {
	char name[20];
	//姓名
	char address[40];
	//地址
	long zip;
	//邮编
	char phone[15];
	//电话号码
} PERSON;

typedef struct address {
	char name[20];
	//姓名
	char address[40];
	//地址
	long zip;
	//邮编
	char phone[15];
	//电话号码
	struct address *next;
} ADDRESS;
typedef ADDRESS *AD_LIST;
//把地址结构的指针改名叫AD_LIST

AD_LIST load(void);
int menu_select(void);
AD_LIST insert(AD_LIST head);
void show(AD_LIST head);
void find(AD_LIST head);
AD_LIST delectenode(AD_LIST head);
void save(AD_LIST head);




int main() {
	AD_LIST head;
	//通讯录头指针；
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
	//给出菜单可选操作
	char s[80];
	int c;

	printf("\t\t    通讯录管理系统\n");
	printf("\t\t========================\n");
	printf("\t\t    1.插入一条记录\n");
	printf("\t\t    2.显示所有记录\n");
	printf("\t\t    3.按姓名查找\n");
	printf("\t\t    4.按姓名删除\n");
	printf("\t\t    5.存盘\n");
	printf("\t\t    6.退出\n");

	do {
		printf("\n\n\t请选择（~6）：");
		gets(s);
		printf("\n");
		c = atoi(s);
		//atoi是把字符串转换成十进制整型的函数，空的话返回0,过大的话返回-1
		//int atoi (const char *nptr)
	} while (c < 0 || c > 6);

	return c;
}


AD_LIST load(void) {
	//下载一个通讯录文件
	AD_LIST p, q, head;
	PERSON per;
	FILE *fp;
//FILE是文件类型指针
//#ifndef _FILE_DEFINED
//struct _iobuf {
//　　　　char *_ptr; //文件输入的下一个位置
//　　　　int _cnt; //当前缓冲区的相对位置
//　　　　char *_base; //指基础位置(即是文件的起始位置)
//　　　　int _flag; //文件标志
//　　　　int _file; //文件描述符id
//　　　　int _charbuf; //检查缓冲区状况,如果无缓冲区则不读取
//　　　　int _bufsiz; //文件缓冲区大小
//　　　　char *_tmpfname; //临时文件名
//       };
//typedef struct _iobuf FILE;
//#define _FILE_DEFINED
//#endif
//FILE *fopen( char *file, char *open_mode ); //打开文件，读文件到内存，返回文件信息结构指针
//int fread( char s, int size, int num, FILE *fp ); //按字节读取文件内容到s中
//成功读取的元素总数会以 size 对象返回，size 对象是一个整型数据类型。
//如果总数与 num 参数不同，则可能发生了一个错误或者到达了文件末尾。
//int fwrite( char s, int size, int num, FILE *fp ); //按字节将s地址中的数据写到文件中
//char *fgets( char *s, int max_size, FILE *fp); //读一行数据到缓冲区s中
//int fseek( FILE *fp, long offset, int whence); //移动文件指针到指定位
//void rewind(FILE *fp); //回到文件头
//long ftell(FILE *fp); //得到当前文件偏移位置
//fclose(fp); //关闭文件，刷新缓存到物理磁盘上
//feof ()函数用来检测当前文件流上的文件结束标识,判断是否读到了文件结尾
//其原型为： int feof (FILE * stream);检测到文件结束标识返回1，否则返回0。
	q = head = NULL;
	if ((fp = fopen(FILENAME, "rb")) == NULL) {
		//rb：打开已有的二进制文件，允许读；wb：打开二进制文件，允许写
		printf("Can not open file %s\n", FILENAME);
		return head;
	} else {
		while (!feof(fp))
			//文件没有结束
			if (fread(&per, sizeof(PERSON), 1, fp) == 1) {
				//读取成功
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
	//输入一个新的记录
	AD_LIST temp, p;

	p = head;
	temp = (AD_LIST)malloc(sizeof(ADDRESS));

	printf("\n\t请输入姓名:");
	gets(temp->name);
	printf("\n\t请输入通信地址:");
	gets(temp->address);
	fflush(stdin);
//功 能: 清除读写缓冲区，在需要立即把输出缓冲区的数据进行物理写入时
//头文件：stdio.h
//原型:int fflush(FILE *stream)
//其中stream是要冲洗的流
	printf("\n\t请输入邮编地址:");
	scanf("%ld", &temp->zip);
	fflush(stdin);
	printf("\n\t请输入电话号码:");
	gets(temp->phone);
	fflush(stdin);

	head = temp;
	temp->next = p;

	return head;
}



void save(AD_LIST head) {
	//保存输入的通讯录地址
	AD_LIST p;
	FILE *fp;
	PERSON per;

	if ((fp = fopen(FILENAME, "wb")) == NULL) {
		printf("Can not open file %s\n", FILENAME);
		return ;

		//因为返回的类型是void
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
	//显示通讯录
	AD_LIST p;
	p = head;

	printf("%-30s%-40s%-20s%-40s", "姓名", "地址", "邮编", "电话号码");
	while (p != NULL) {
		printf("%-30s", p->name);
		printf("%-40s", p->address);
		printf("%-20s", p->zip);
		printf("%-40", p->phone);

		p = p->next;
	}
}


void find(AD_LIST head) {
	//找到一个通讯录记录
	AD_LIST p;
	char name[20];
	int flag = 0;

	printf("请输入要查找的人的姓名：");
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
		printf("\n\t\t查无此人\n\n");
	}
}


AD_LIST delectenode(AD_LIST head) {
	//删除一个通讯录记录
	AD_LIST  q, p;
	char name[20];
	int flag = 0;

	printf("请输入想删除的人的姓名：");
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
		printf("\n\t\t查无此人\n\n");

	return head;
}












