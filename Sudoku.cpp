// Sudoku.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "iostream"
#include "algorithm"
#include "fstream"
#include "string"
#include "cstring"
#include "cmath"
#include "cstdio"
#include "cstdlib"
#include"Sudoku.h"
using namespace std;
int main(int argc, char** argv)
{
	int N = 0;
	//scanf("%d",&N);
	//FILE *fp1 = fopen(argv[2], "r");

	if (argc == 3 && strcmp(argv[1], "-c") == 0)
	{
		int len = strlen(argv[2]);

		for (int i = 0; i < len; ++i)
		{
			if (argv[2][i] >= '0' && argv[2][i] <= '9')
			{
				N += ((argv[2][i] - '0')*pow((float)10, len - i - 1));
				//printf("%d",N);
			}
			else
			{
				printf("Error!\n");
				return 0;
			}
		}
		BuildMove(N);
		print1();
	}

	else if (argc == 3 && strcmp(argv[1], "-s") == 0)
	{
		cout << argv[2] << endl;
		Solve_Sudoku(argv[2]);
	}

	return 0;
}
