#include "pch.h"
#include<stdio.h>
using namespace std;
 
bool bSign = false;
int num[9][9] = {
	0,0,0,0,0,2,0,5,0,
	0,7,8,0,0,0,3,0,0,
	0,0,0,0,0,4,0,0,0,
	5,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,1,0,0,
	0,0,0,0,3,0,7,0,8,
	2,0,0,0,0,0,0,4,0,
	0,0,0,0,0,5,0,9,0,
	0,1,0,0,7,0,0,0,0
};
bool book[81] = { false };
/* 输出数独矩阵 */
void Output()
{
	printf("\r\n");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", num[i][j]);
			if (j % 3 == 2)
			{
				printf("   ");
			}
		}
		printf("\r\n");
		if (i % 3 == 2)
		{
			printf("\r\n");
		}
	}
}
 
/* 判断key填入n时是否满足条件 */
bool Check(int n, int key)
{
	/* 判断n所在横列是否合法 */
	for (int i = 0; i < 9; i++)
	{
		/* j为n竖坐标 */
		int j = n / 9;
		if (num[j][i] == key)
			return false;
	}
 
	/* 判断n所在竖列是否合法 */
	for (int i = 0; i < 9; i++)
	{
		/* j为n横坐标 */
		int j = n % 9;
		if (num[i][j] == key)
			return false;
	}
 
	/* x为n所在的小九宫格左顶点竖坐标 */
	int x = n / 9 / 3 * 3;
 
	/* y为n所在的小九宫格左顶点横坐标 */
	int y = n % 9 / 3 * 3;
 
	/* 判断n所在的小九宫格是否合法 */
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
		{
			if (num[i][j] == key)
				return false;
		}
	}
 
	/* 全部合法，返回正确 */
	return true;
}
/* 深搜构造数独 */
void DFS(int n)
{
	/* 所有的都符合，退出递归 */
	if (n > 80)
	{
		bSign = true;
		return;
	}
	/* 当前位不为空时跳过 */
	if (num[n / 9][n % 9] != 0)
	{
		book[n] = true;
		DFS(n + 1);
	}
	/* 否则对当前位进行枚举测试 */
	for (int i = 1; i <= 9; i++)
	{
		/* 满足条件时填入数字 */
		if (Check(n, i) && !book[n])
		{
			num[n / 9][n % 9] = i;
			book[n] = true;
			/* 继续搜索 */
			DFS(n + 1);
			/* 返回时如果构造成功，则直接退出 */
			if (bSign)
				return;
			/* 如果构造不成功，还原当前位 */
			num[n / 9][n % 9] = 0;
			book[n] = false;
		}
	}
}
int main()
{
	DFS(0);
	Output();
	return 0;
}
 
