#include <iostream>
#include "iostream"
#include "algorithm"
#include "fstream"
#include "string"
#include "cstring"
#include "cmath"
#include "cstdio"
#include "cstdlib"
#include<stdio.h>
#include <stdlib.h>
using namespace std;

ofstream print_sudoku("sudoku.txt");

int origin[10] = { 1,2,3,4,5,6,7,9 };

int countnum = 0;
int datacount = 0;
char output[500000000];//开个大缓存区

int sudomap[10][9][9];
int temp[9] = { 1,2,3,4,5,6,7,8,9 };
int p = 0;

int vis[3][10][10];

void ChangeMap(char *rule) //进行变换
{
	for (int i = 0; i < 3; ++i)
	{
		output[datacount++] = origin[(8 + rule[i] - '0') % 9] + '0';
		for (int j = 1; j < 17; ++j)
		{
			output[datacount++] = ' ';
			j++;
			output[datacount++] = origin[((16 - j) / 2 + rule[i] - '0') % 9] + '0';
		}
		output[datacount++] = '\n';
	}
}

void BuildSudoku(char *rule1, char *rule2, char*rule3)
{
	ChangeMap(rule1);
	ChangeMap(rule2);
	ChangeMap(rule3);
	output[datacount++] = '\n';
}

void BuildMove(int N)
{
	char rule1[10][5] = { "036","063" };
	char rule2[10][5] = { "258","285","528","582","825","852" };
	char rule3[10][5] = { "147","174","417","471","714","741" }; //变换规则
	while (1)
	{
		if (next_permutation(origin, origin + 8))
		{
			origin[8] = 8;
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < 6; ++j)
				{
					for (int t = 0; t < 6; ++t)
					{
						BuildSudoku(rule1[i], rule2[j], rule3[t]);
						countnum++;
						if (countnum == N)
							return;
					}
				}
			}
		}
		else
			break;
	}
}
void print1()
{
	print_sudoku << output;
}
int judge(int s, int x, int y, int num)
{//判断填充合法

	for (int i = 0; i < 9; i++)
	{    //当前行、列合法判断
		if (sudomap[s][x][i] == num)
			return 0;
		if (sudomap[s][i][y] == num)
			return 0;
	}
	int area_x = x - x % 3, area_y = y - y % 3;    //计算所处宫格左上角坐标
	for (int i = area_x; i < area_x + 3; i++)    //当前宫格合法判断
		for (int j = area_y; j < area_y + 3; j++)
			if (sudomap[s][i][j] == num)
				return 0;

	return 1;
}

//以下位解数独 

int res[9][9];
int suc;
char OutputData[200000000];
void prt()    //将结果输入大数组中
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (j != 8)
			{
				OutputData[p++] = res[i][j] + '0';
				OutputData[p++] = ' ';
			}
			else
			{
				OutputData[p++] = res[i][j] + '0';
				if (i != 8)
					OutputData[p++] = '\n';
			}
		}

	}
}
void SetVis(int r, int c, int num)  //第r行，第i列和对应九宫格中已经有数num，则使用该函数
{
	vis[0][r][num] = 1;
	vis[1][c][num] = 1;
	vis[2][r / 3 * 3 + c / 3][num] = 1;
}
void ResetVis(int r, int c, int num) //第r行，第i列和对应九宫格中没有数num，则使用该函数
{
	vis[0][r][num] = 0;
	vis[1][c][num] = 0;
	vis[2][r / 3 * 3 + c / 3][num] = 0;
}

bool CheckCanVis(int r, int c, int num)  //检查第r行，第i列是否能放数num
{
	if (vis[0][r][num] == 0 && vis[1][c][num] == 0 && vis[2][r / 3 * 3 + c / 3][num] == 0)
		return true;
	else
		return false;
}

void TraceBack(int n)
{
	if (suc == 1)
		return;

	if (n > 80)  //代表解完当前数独
	{
		prt();
		suc = 1;
		return;
	}

	if (res[n / 9][n % 9] != 0)   //当前格子有数字，跳到下一格
	{
		TraceBack(n + 1);
	}
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			int f = CheckCanVis(n / 9, n % 9, i);

			if (f == 0)
				continue;
			else
			{
				res[n / 9][n % 9] = i;
				SetVis(n / 9, n % 9, res[n / 9][n % 9]);

				TraceBack(n + 1);

				ResetVis(n / 9, n % 9, res[n / 9][n % 9]);
				res[n / 9][n % 9] = 0;
			}
		}
	}
}

int solve(int s, int a, int b)
{
	int init, next_a, next_b;
	init = sudomap[s][a][b];
	next_a = a + (b + 1) / 9;
	next_b = (b + 1) % 9;

	if (a == 9)
		return 1;
	if (sudomap[s][a][b] != 0)
	{
		if (solve(s, next_a, next_b))
			return 1;
	}
	else
	{
		for (int i = 0; i < 9; ++i)
		{
			int trynum = temp[i];
			if (judge(s, a, b, trynum))
			{
				sudomap[s][a][b] = trynum;
				if (solve(s, next_a, next_b))
					return 1;
			}
		}
	}

	sudomap[s][a][b] = init;

	return 0;
}

void Solve_Sudoku(char input[])
{
	FILE *fp1, *fp2;
	fopen_s(&fp1, input, "r");
	if (fopen_s(&fp2, "sudoanswer.txt", "a") != 0)
		cout << "p2打开失败" << endl;
	
	int t = 0;
	int count = 0;
	while (fscanf(fp1, "%d", &res[t / 9][t % 9]) != EOF)  //判断是否到文件尾
	{
		if (count != 0)
		{
			OutputData[p++] = '\n';
			OutputData[p++] = '\n';
		}

		for (t = 1; t < 81; t++)     //读入一个需要求解的数独
			fscanf(fp1, "%d", &res[t / 9][t % 9]);

		suc = 0;

		memset(vis, 0, sizeof(vis));

		for (t = 0; t < 81; t++)
			if (res[t / 9][t % 9] != 0)   //当前格子有数字，跳到下一格
			{
				SetVis(t / 9, t % 9, res[t / 9][t % 9]);
			}

		TraceBack(0);   //回溯求解

		count++;

		t = 0;
	}
	//cout << p << endl;
	//cout << OutputData << endl;
	OutputData[p++] = '\0';
	
	fwrite(OutputData, 1, p, fp2);  //将结果写入文件
	//cout << p << endl;
	fclose(fp1);
	fclose(fp2);
}

#pragma once
