#include<Windows.h>
#include<iostream>
#define Max 5//每五个人检查一下红黑客情况
#define MaxTime 10000
#define Red 1
#define Black 0
HANDLE full;//船上可不可以坐满
HANDLE customers;
HANDLE boat;//有没有船
HANDLE mcos;
int reds = 0;
int blacks = 0;
int coscount = 0;
int boatcount = 0;

//返回[left, right]的随机数
int randNext(int left, int right)
{
	static unsigned int seed = 0;
	seed++;
	srand((unsigned)time(NULL) + seed * seed);
	return rand() % (right - left + 1) + left;
}

DWORD WINAPI Boat(LPVOID lpParamter) {
	while (true) {
		int rand_time = randNext(0, 1000);
		Sleep(rand_time);
		ReleaseSemaphore(full, 1, NULL);
		ReleaseSemaphore(boat, 1, NULL);
		boatcount++;
		printf("Boat %d is over!\t\n\n", boatcount);
	}
}

DWORD WINAPI Customers(LPVOID lpParamter) {
	while (true) {
		int rand_time = randNext(0, 100);
		Sleep(rand_time);
		WaitForSingleObject(customers, INFINITE);
		//printf("customers applied successed！\t\n");
		WaitForSingleObject(mcos, INFINITE);
		//printf("mcos applied successed！\t\n");
		int color = randNext(0, 1);
		if (color == Red)
			reds++;
		else if (color == Black)
			blacks++;
		coscount++;
		printf("coscount==%d\t\n", coscount);
		if (coscount == 5) {
			WaitForSingleObject(full,INFINITE);
			WaitForSingleObject(boat, INFINITE);
			printf("Boat is ready!\t\n");
			int readyred = 0;
			if (!(reds == 3 && blacks == 1 || reds == 1 && blacks == 3))
			{
				if (blacks >= 4)
				{
					blacks = blacks - 4;
				}
				else if (reds >= 2 && reds <= 3)
				{
					reds = reds - 2;
					blacks = blacks - 2;
					readyred = 2;
				}
				else if (reds >= 4)
				{
					reds = reds - 4;
					readyred = 4;
				}
				coscount = coscount - 4;
				printf("Customer:Red %d, Black %d.\t\n", readyred, 4 - readyred);
				ReleaseSemaphore(customers, 4, NULL);
			}
		}
		ReleaseSemaphore(mcos, 1, NULL);
	}
}


/*
HANDLE full;
HANDLE customers;
HANDLE boat;
HANDLE mred;
HANDLE mblack;
int reds = 0;
int blacks = 0;*/
int main() {
	full = CreateSemaphore(NULL, 1, 1, NULL);
	customers = CreateSemaphore(NULL, Max, Max, NULL);
	boat= CreateSemaphore(NULL, 1, 1, NULL);
	mcos = CreateSemaphore(NULL, 1, 1, NULL);
	HANDLE Pro_Thread = CreateThread(NULL, 0, Customers, NULL, 0, NULL);
	HANDLE Con_Thread = CreateThread(NULL, 0, Boat, NULL, 0, NULL);
	HANDLE handle[2] = { Pro_Thread,Con_Thread };
	Sleep(MaxTime);
	CloseHandle(Pro_Thread);
	CloseHandle(Con_Thread);
	return 0;
}