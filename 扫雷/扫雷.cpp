#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include <mmsystem.h>//��������ͷ�ļ� 
#pragma comment(lib,"winmm.lib")//��������ͷ�ļ���
#pragma warning (disable:4699)
#define IMGW 50
//ͼƬ��С

void initmap(int *map,int *m,int *b);
//��ʼ�����ڸ�
void drawmap(int *map, IMAGE pic[11],int *m);
//ǰ���Ѿ�������ͼƬ������Ҫ��ͼ
void mouseEvent(ExMessage* msg, int *map, IMAGE pic[11],int *m,int *b);
//�õ������������
void judge(ExMessage* mouse, int* map, IMAGE pic[11], int* m, int* b);
//�ж���Ϸ�Ƿ����
void showmapnumber(int *map,int *m);
//��ʾ��������
void opennull(int *map, int x, int y,int * m);
//���ٽ��ķǵ��׸�,(x,y)
bool isprime = true;
//�ж���Ϸ�Ƿ����

int main() {
	int level = 0;
	int M, B;
	//���̸��Ը������׵ĸ���
	IMAGE pic[11];
	//�洢���֡��׺Ϳհ׽���
	IMAGE picture[12];
	//�洢"��ӭ����"
	ExMessage mouse;
	//�����Ϣ�ṹ(��ȡ�����ȷ�����޲���)

	system("color E9");
	//��ʾ��ɫ���ƺ������������壨ǰ��ɫ���ͱ�����ɫ
	system("mode con cols=50 lines=25");
	//���ñ�׼�����С

    label:printf("\n\n ##############��ӭִ��ɨ������################\n\n");
		  printf("\n ##################�˵��Ѷȣ�####################\n");
		  printf("\n ###################1.��#######################\n");
		  printf("\n ###################2.һ��#######################\n");
		  printf("\n ###################3.����#######################\n");
		  printf("\n ###########������1/2/3ѡ�������Ѷȣ�############\n");
		  scanf_s("%1d", &level);

		switch (level) 
		{
		case 1:M = 8;
			   B = 5;
			   break;
		case 2:M = 12;
			   B = 15;
		case 3:M = 16;
			   B = 25;
			   break;
		default:printf("\n�����Ѷȵȼ�1-3��ѡ��\n");
			goto label;
		}
		//�Ѷ�����

	int *map=(int*)malloc(sizeof(int)*M*M);
	//MΪ���������Բ���ֱ�Ӷ����ά����
	//�����ǵ���ά������ڴ�����������ֱ����ָ�����ƶ�ά����

	initgraph(IMGW * M, IMGW * M, EW_SHOWCONSOLE);
	//��ʼ������

	loadimage(&pic[0], "images/0.jpg", IMGW, IMGW);
	loadimage(&pic[1], "images/1.jpg", IMGW, IMGW);
	loadimage(&pic[2], "images/2.jpg", IMGW, IMGW);
	loadimage(&pic[3], "images/3.jpg", IMGW, IMGW);
	loadimage(&pic[4], "images/4.jpg", IMGW, IMGW);
	loadimage(&pic[5], "images/5.jpg", IMGW, IMGW);
	loadimage(&pic[6], "images/6.jpg", IMGW, IMGW);
	loadimage(&pic[7], "images/7.jpg", IMGW, IMGW);
	loadimage(&pic[8], "images/8.jpg", IMGW, IMGW);
	loadimage(&pic[9], "images/9.jpg", IMGW, IMGW);
	loadimage(&pic[10], "images/10.png", IMGW, IMGW);
	//����ͼƬ���֡��հ׺���

	loadimage(&picture[0], "images/102.jpg", IMGW * M, IMGW * M);
	loadimage(&picture[1], "images/103.jpg", IMGW * M, IMGW * M);
	loadimage(&picture[2], "images/104.jpg", IMGW * M, IMGW * M);
	loadimage(&picture[3], "images/105.jpg", IMGW * M, IMGW * M);
	loadimage(&picture[4], "images/106.jpg", IMGW * M, IMGW * M);
	loadimage(&picture[5], "images/107.jpg", IMGW * M, IMGW * M);
	loadimage(&picture[6], "images/108.jpg", IMGW * M, IMGW * M);
	loadimage(&picture[7], "images/109.jpg", IMGW * M, IMGW * M);
	loadimage(&picture[8], "images/110.jpg", IMGW * M, IMGW * M);
	loadimage(&picture[9], "images/111.jpg", IMGW * M, IMGW * M);
	loadimage(&picture[10], "images/112.jpg", IMGW * M, IMGW * M);
	loadimage(&picture[11], "images/113.jpg", IMGW * M, IMGW * M);
	//����ͼƬ��ͷ����

	putimage(0,0, &picture[0]);
	PlaySound(TEXT("music/background.wav"), NULL, SND_LOOP | SND_ASYNC);
	//���뱳������
	Sleep(1000);
	putimage(0, 0, &picture[1]);
	Sleep(200);
	putimage(0, 0, &picture[2]);
	Sleep(200);
	putimage(0, 0, &picture[3]);
	Sleep(200);
	putimage(0, 0, &picture[4]);
	Sleep(200);
	putimage(0, 0, &picture[5]);
	Sleep(200);
	putimage(0, 0, &picture[6]);
	Sleep(200);
	putimage(0, 0, &picture[7]);
	Sleep(200);
	putimage(0, 0, &picture[8]);
	Sleep(200);
	putimage(0, 0, &picture[9]);
	Sleep(200);
	putimage(0, 0, &picture[10]);
	Sleep(200);
	putimage(0, 0, &picture[11]);
	Sleep(1000);
	//���ÿ����ͼ����������Ϸ����

	initmap(map,&M,&B);
	/*showmapnumber( map,&M);*/
	while (true) 
	{
		drawmap( map, pic,&M);
		mouseEvent(&mouse,map, pic,&M,&B);
		if (!isprime) 
		{
			int ret = MessageBox(GetHWnd(), (LPCSTR)"��Ӣ�¾��壬����һ�Σ�", (LPCSTR)"Hint", MB_OKCANCEL);
			if (ret == IDOK) 
			{
				//����һ��
				initmap(map,&M,&B);
				PlaySound(TEXT("music/background.wav"), NULL, SND_LOOP | SND_ASYNC);
				drawmap(map, pic,&M);
				isprime = true;
			}
			else 
			{
				free(map);
				//�˳�����
				exit(1);
			}
		}
	}
	getchar();
	//��ֹ����
	system("PAUSE");
	return 0;
}

//��ʼ�����ڸ�
void initmap(int* map,int *m,int *b) {
	int M = *m;
	int B = *b;
	//����ֱ��ȡֵ

	memset(map, 0, M * M * sizeof(int));
	//���ⷴ������ʱ�ϴε�����û�����
	 
	//����B����
	srand((unsigned)time(NULL));
	int x, y;
	for (int i = 0; i < B; )
	{
		x = rand() % M;
		y = rand() % M;
		//����������ʱ������Ϊy������Ϊx���ԣ�0��0��Ϊ����ԭ��
		if (map[y * M + x] == 0)
		{
			map[y * M + x] = -1;
			i++;
		}
	}

	//������������������
	for (int i = 0; i < M; ++i) 
	{
		for (int j = 0; j < M; ++j)
		{
			if (map[i*M+j] == -1) 
			{
				for (int a= i - 1; a <= i + 1; ++a)
				{
					for (int k = j - 1; k <= j + 1; ++k)
					{
						if (a >= 0 && a < M && k >= 0 && k < M && map[a*M+k] != -1)
							++map[a * M + k];
					}
				}
			}
		}
	}

	//+100 ���ڸǼ���
	for (int i = 0; i < M; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			map[i*M+j] += 100;
		}
	}
}

//ǰ���Ѿ�������ͼƬ������Ҫ��ͼ
void drawmap(int *map, IMAGE pic[11],int *m) {
	int M = *m;

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (map[i*M+j] == -1)
			{
				putimage(j * IMGW, i * IMGW, &pic[10]);
			}
			else if (map[i * M + j] >= 0 && map[i * M + j] <= 8)
			{
				putimage(j * IMGW, i * IMGW, pic + map[i * M + j]);
			}
			else
			{
				putimage(j * IMGW, i * IMGW, &pic[9]);
			}
		}
	}
}

//�õ�����������ݲ���֮�޸�����
void mouseEvent(ExMessage* msg, int *map, IMAGE pic[11],int *m,int *b) {
	int M = *m;
	int B = *b;

	if (peekmessage(msg, EM_MOUSE))
     //�������е��������������
	{
		int i = msg->y / IMGW;
		int j = msg->x / IMGW;
		if (msg->message == WM_LBUTTONDOWN) 
		{
			if (map[i*M+j] >= 99 && map[i * M + j] <= 108) 
			{
				map[i * M + j] -= 100;
				opennull(map, j, i,m);
				/*showmapnumber(map,m);*/
				judge(msg, map, pic,m,b);
				drawmap(map, pic,m);
			}
		}
	}
}

//�ж���Ϸ�Ƿ����
void judge(ExMessage* mouse, int *map, IMAGE pic[11],int *m,int *b) {
	int i = mouse->y / IMGW;
	int j = mouse->x / IMGW;
	int point = 0;
	int M = *m;
	int B = *b;

	if (map[i*M+j] == -1)
	{
		for (int x = 0; x < M; ++x)
		{
			for (int y = 0; y < M; ++y)
			{
				if (map[x*M+y] == 99) 
				{
					map[x * M + y] -= 100;
					//��ʾ���еĵ���
					isprime = false;
					//����ȫ�ֱ�����֪��Ϸ����
					PlaySound(NULL, NULL, 0);
					PlaySound(TEXT("music/explosion.wav"), NULL, SND_FILENAME | SND_ASYNC);
					//ֹͣ�������ֲ����ű�ը��Ч
				}
			}
		}
	}

	//�򿪣�С��9���������ݣ��ĸ�����ΪM*M-B����ʱ��ʤ��
	for (int a = 0; a < M; ++a)
	{
		for (int n = 0; n < M; ++n) 
		{
			if (map[a*M+n] >= 0 && map[a * M + n] <= 8) 
			{
				++point;
			}
		}
	}
	if (point == M * M - B) 
	{
		PlaySound(NULL, NULL, 0);
		PlaySound(TEXT("music/win.wav"), NULL, SND_FILENAME | SND_ASYNC);
		//ֹͣ�������ֲ�����ʤ����Ч
		drawmap(map, pic,m);
		int ret = MessageBox(GetHWnd(), (LPCSTR)"��������񣬹�ϲͨ�أ�\n�ٴν�������", (LPCSTR)"Hint", MB_OKCANCEL);
		if (ret == IDOK) 
		{
			PlaySound(TEXT("music/background.wav"), NULL, SND_LOOP | SND_ASYNC);
			initmap(map,m,b);
			drawmap(map, pic,m);
		}
		else 
		{
			free(map);
			exit(1);
		}
	}
}

//��ʾ�������ݣ��������
void showmapnumber(int *map,int * m) {
	int M = *m;

	for (int i = 0; i < M; ++i) 
	{
		for (int j = 0; j < M; ++j)
		{
			printf("%4d", map[i*M+j]);
		}
		printf("\n");
	}
	printf("\n");
}

//���ٽ��ķǵ��׸�,(x,y)
void opennull(int *map, int x, int y,int *m) {
	int M = *m;

	if (map[y*M+x] == 0) 
	{
		for (int i = y - 1; i <= y + 1; ++i) 
		{
			for (int j = x - 1; j <= x + 1; ++j) 
			{
				if (i >= 0 && i < M && j >= 0 && j < M && map[i * M + j] >= 99 && map[i * M + j] <= 108)
				{
					map[i*M+j] -= 100;
					opennull(map, j, i, m);
				}
			}
		}
	}
}
