#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr7.1/Pr7.1.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestCreate)
		{
			const int rowCount = 7;
			const int colCount = 9;
			int** q = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				q[i] = new int[colCount];

			Create(q, rowCount, colCount, -41, 23);

			for (int i = 0; i < rowCount; ++i)
				for (int j = 0; j < colCount; ++j)
					Assert::IsTrue(q[i][j] >= -41 && q[i][j] <= 23);

			for (int i = 0; i < rowCount; ++i)
				delete[] q[i];
			delete[] q;
		}

		TEST_METHOD(TestSort)
		{
			const int rowCount = 7;
			const int colCount = 9;
			int** q = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				q[i] = new int[colCount];

			// Заповнення матриці для тестування сортування
			int testArray[rowCount][colCount] = {
				{5, 3, 4, 2, 1, 6, -10, -11, -12},
				{1, 2, 3, 4, 5, 6, -10, -11, -12},
				{6, 5, 4, 3, 2, 1, -10, -11, -12},
				{4, 3, 6, 5, 1, 2, -10, -11, -12},
				{1, 2, 3, 4, 5, 6, -10, -11, -12},
				{6, 5, 4, 3, 2, 1, -10, -11, -12},
				{5, 3, 4, 2, 1, 6, -10, -11, -12}
			};

			for (int i = 0; i < rowCount; ++i)
				for (int j = 0; j < colCount; ++j)
					q[i][j] = testArray[i][j];

			Sort(q, rowCount, colCount);

			for (int j = 0; j < colCount - 1; ++j) {
				for (int i = 0; i < rowCount - 1; ++i) {
					if (q[i][0] == q[i + 1][0]) {
						if (q[i][1] == q[i + 1][1]) {
							Assert::IsTrue(q[i][2] >= q[i + 1][2]);
						}
						else {
							Assert::IsTrue(q[i][1] <= q[i + 1][1]);
						}
					}
					else {
						Assert::IsTrue(q[i][0] <= q[i + 1][0]);
					}
				}
			}

			for (int i = 0; i < rowCount; ++i)
				delete[] q[i];
			delete[] q;
		}



		TEST_METHOD(TestCalc)
		{
			const int rowCount = 7;
			const int colCount = 9;
			int** q = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				q[i] = new int[colCount];

			// Заповнення матриці для тестування функції обчислення
			int testArray[rowCount][colCount] = {
				{1, 2, 3, 4, 5, 6, -10, -11, -12},
				{-1, -2, -3, -4, -5, -6, -10, -11, -12},
				{0, 0, 0, 0, 0, 0, -10, -11, -12},
				{1, -1, 2, -2, 3, -3, -10, -11, -12},
				{2, 4, 6, 8, 10, 12, -10, -11, -12},
				{-2, -4, -6, -8, -10, -12, -10, -11, -12},
				{1, 3, 5, 7, 9, 11, -10, -11, -12}
			};

			for (int i = 0; i < rowCount; ++i)
				for (int j = 0; j < colCount; ++j)
					q[i][j] = testArray[i][j];

			int S, k;
			Calc(q, rowCount, colCount, S, k);

			Assert::AreEqual(S, -251);
			Assert::AreEqual(k, 53);

			for (int i = 0; i < rowCount; ++i)
				delete[] q[i];
			delete[] q;
		}
	};
}
