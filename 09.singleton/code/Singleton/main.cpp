#include <iostream>
#include "Singleton.h"

/*����ģʽ��ʵ��*/
/*
int main()
{
	Singleton *s1 = Singleton::getInstance();
	Singleton *s2 = Singleton::getInstance();

	system("pause");
	return 0;
}
*/

/*���̰߳�ȫ ����ģʽ*/
#include <process.h>
#include <Windows.h>

//���̣߳��߳���Ŀ��5
#define THREAD_NUM 5

unsigned int __stdcall CallSingleton(void *pPM)
{
	Singleton *s = Singleton::getInstance();
	int nThreadNum = *(int *)pPM; 
	Sleep(50);
	//printf("�̱߳��Ϊ%d\n", nThreadNum);
	return 0;
}


int main()
{
	HANDLE  handle[THREAD_NUM];

	//�̱߳��
	int threadNum = 0;
	while (threadNum < THREAD_NUM)
	{
		handle[threadNum] = (HANDLE)_beginthreadex(NULL, 0, CallSingleton, &threadNum, 0, NULL);
		//�����߳̽��յ�����ʱ���߳̿��ܸı������i��ֵ
		threadNum++;
	}
	//��֤���߳���ȫ�����н���
	WaitForMultipleObjects(THREAD_NUM, handle, TRUE, INFINITE);

	system("pause");
	return 0;
}