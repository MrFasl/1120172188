#include "pch.h"
#include "CppUnitTest.h"
#include "../Sudoku/Sudoku.h"
#include"../Sudoku/Sudoku.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			TraceBack(90);
			Assert::AreEqual(1, suc);
			TraceBack(40);
			Assert::AreEqual(1, suc);
			TraceBack(0);
			Assert::AreEqual(1, suc);
		}
	};
	TEST_CLASS(UnitTest2)
	{
	public:
		TEST_METHOD(TestMethod2)
		{
			TraceBack(100);
			Assert::AreEqual(1, suc);
			Solve_Sudoku("problem.txt");
			Assert::AreEqual(1, suc);
		}
	};
	TEST_CLASS(UnitTest3)
	{
	public:
		TEST_METHOD(TestMethod3)
		{
			Solve_Sudoku("problem.txt");
			Assert::AreNotEqual(0, suc);
		}
	};
	TEST_CLASS(UnitTest4)
	{
	public:
		TEST_METHOD(TestMethod4)
		{
			Assert::AreEqual(false, argcCheck(4));//参数超过三个
		}
		
	};
	TEST_CLASS(UnitTest5)
	{
	public:
		TEST_METHOD(TestMethod5)
		{
			Assert::AreEqual(false, argcCheck(2));//参数少于三个
		}

	};
	TEST_CLASS(UnitTest6)
	{
	public:
		TEST_METHOD(TestMethod6)//判断生成合法
		{
			
			BuildMove(100);
			Assert::AreEqual(countnum, 100);

		}

	};
	TEST_CLASS(UnitTest7)
	{
	public:
		TEST_METHOD(TestMethod7)
		{

			SetVis(3, 3, 1);
			Assert::AreEqual(vis[0][3][1], 1);
			Assert::AreEqual(vis[1][3][1], 1);
			Assert::AreEqual(vis[2][3 / 3 * 3 + 3 / 3][1], 1);
		}

	};

	TEST_CLASS(UnitTest8)
	{
	public:
		TEST_METHOD(TestMethod8)
		{

			ResetVis(3, 3, 1);
			Assert::AreEqual(vis[0][3][1], 0);
			Assert::AreEqual(vis[1][3][1], 0);
			Assert::AreEqual(vis[2][3 / 3 * 3 + 3 / 3][1], 0);
		}

	};
	TEST_CLASS(UnitTest9)
	{
	public:
		TEST_METHOD(TestMethod9)
		{
			Solve_Sudoku("problem.txt");
			prt();
			Assert::AreEqual(true, out);//解数独输出模块的测试
		}

	};
	TEST_CLASS(UnitTest10)//判断填充是否合法的测试
	{
	public:
		TEST_METHOD(TestMethod10)
		{
			Solve_Sudoku("problem.txt");
			Assert::AreEqual(1, judge(8,3,1,3));
		}

	};
}
