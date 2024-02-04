#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include <mmsystem.h>//导入声音头文件 
#pragma comment(lib,"winmm.lib")//导入声音头文件库
#pragma warning (disable:4699)
#define IMGW 50
//图片大小

void initmap(int *map,int *m,int *b);
//初始化且掩盖
void drawmap(int *map, IMAGE pic[11],int *m);
//前面已经加载了图片，现在要贴图
void mouseEvent(ExMessage* msg, int *map, IMAGE pic[11],int *m,int *b);
//得到鼠标点击的数据
void judge(ExMessage* mouse, int* map, IMAGE pic[11], int* m, int* b);
//判断游戏是否结束
void showmapnumber(int *map,int *m);
//显示数组数据
void opennull(int *map, int x, int y,int * m);
//打开临近的非地雷格,(x,y)
bool isprime = true;
//判断游戏是否结束

int main() {
	int level = 0;
	int M, B;
	//棋盘各自个数和雷的个数
	IMAGE pic[11];
	//存储数字、雷和空白界面
	IMAGE picture[12];
	//存储"欢迎界面"
	ExMessage mouse;
	//鼠标消息结构(获取坐标和确认有无操作)

	system("color E9");
	//显示颜色控制函数，设置字体（前景色）和背景颜色
	system("mode con cols=50 lines=25");
	//设置标准输入大小

    label:printf("\n\n ##############欢迎执行扫雷任务！################\n\n");
		  printf("\n ##################菜单难度：####################\n");
		  printf("\n ###################1.简单#######################\n");
		  printf("\n ###################2.一般#######################\n");
		  printf("\n ###################3.困难#######################\n");
		  printf("\n ###########请输入1/2/3选择任务难度：############\n");
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
		default:printf("\n请在难度等级1-3中选择！\n");
			goto label;
		}
		//难度设置

	int *map=(int*)malloc(sizeof(int)*M*M);
	//M为变量，所以不能直接定义二维数组
	//但考虑到二维数组的内存连续，可以直接用指针类似二维数组

	initgraph(IMGW * M, IMGW * M, EW_SHOWCONSOLE);
	//初始化窗口

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
	//加载图片数字、空白和雷

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
	//加载图片开头动画

	putimage(0,0, &picture[0]);
	PlaySound(TEXT("music/background.wav"), NULL, SND_LOOP | SND_ASYNC);
	//载入背景音乐
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
	//设置开场和间隔，声明游戏规则

	initmap(map,&M,&B);
	/*showmapnumber( map,&M);*/
	while (true) 
	{
		drawmap( map, pic,&M);
		mouseEvent(&mouse,map, pic,&M,&B);
		if (!isprime) 
		{
			int ret = MessageBox(GetHWnd(), (LPCSTR)"你英勇就义，再试一次？", (LPCSTR)"Hint", MB_OKCANCEL);
			if (ret == IDOK) 
			{
				//再来一次
				initmap(map,&M,&B);
				PlaySound(TEXT("music/background.wav"), NULL, SND_LOOP | SND_ASYNC);
				drawmap(map, pic,&M);
				isprime = true;
			}
			else 
			{
				free(map);
				//退出程序
				exit(1);
			}
		}
	}
	getchar();
	//防止闪退
	system("PAUSE");
	return 0;
}

//初始化且掩盖
void initmap(int* map,int *m,int *b) {
	int M = *m;
	int B = *b;
	//方便直接取值

	memset(map, 0, M * M * sizeof(int));
	//避免反复利用时上次的数据没有清空
	 
	//生成B个雷
	srand((unsigned)time(NULL));
	int x, y;
	for (int i = 0; i < B; )
	{
		x = rand() % M;
		y = rand() % M;
		//程序建立坐标时，以行为y，以列为x，以（0，0）为坐标原点
		if (map[y * M + x] == 0)
		{
			map[y * M + x] = -1;
			i++;
		}
	}

	//补足除雷外的数组数据
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

	//+100 ：掩盖加密
	for (int i = 0; i < M; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			map[i*M+j] += 100;
		}
	}
}

//前面已经加载了图片，现在要贴图
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

//得到鼠标点击的数据并随之修改数组
void mouseEvent(ExMessage* msg, int *map, IMAGE pic[11],int *m,int *b) {
	int M = *m;
	int B = *b;

	if (peekmessage(msg, EM_MOUSE))
     //如果鼠标有点击，传入点击数据
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

//判断游戏是否结束
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
					//显示所有的地雷
					isprime = false;
					//利用全局变量告知游戏结束
					PlaySound(NULL, NULL, 0);
					PlaySound(TEXT("music/explosion.wav"), NULL, SND_FILENAME | SND_ASYNC);
					//停止背景音乐并播放爆炸音效
				}
			}
		}
	}

	//打开（小于9的数组数据）的格子数为M*M-B个的时候胜出
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
		//停止背景音乐并播放胜利音效
		drawmap(map, pic,m);
		int ret = MessageBox(GetHWnd(), (LPCSTR)"你完成任务，恭喜通关！\n再次接受任务？", (LPCSTR)"Hint", MB_OKCANCEL);
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

//显示数组数据，做检测用
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

//打开临近的非地雷格,(x,y)
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
