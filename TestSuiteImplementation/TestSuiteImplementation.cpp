#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(int, int, int);
extern "C" int getInsideAngles(int, int, int);
extern "C" int* analyzeRectangle(int, int, int, int , int , int, int, int);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSuiteImplementation
{
	TEST_CLASS(UnitTestTriangleSolverFunction)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

		}
	};
	TEST_CLASS(GettingInsideAngles)
	{
	public:
		TEST_METHOD(EqualateralChecker_InsideAngles_Function)
		{
			int side1 = 6;//all sides are the same
			int side2 = 6;
			int side3 = 6;
			int expected = 1;
			int result;

			result = getInsideAngles(side1, side2, side3);

			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(Getting_insideAnglefor_Isosecles)
		{
			int side1 = 3;//two same sides
			int side2 = 5;
			int side3 = 5;
			int expected = 1;
			int result;

			result = getInsideAngles(side1, side2, side3);

			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestMethod3)
		{
			int side1 = 15;//three different sides for scalene
			int side2 = 10;
			int side3 = 6;
			int expected = 1;
			int result;

			result = getInsideAngles(side1, side2, side3);

			Assert::AreEqual(expected, result);
		}
	};
	TEST_CLASS(UnitTestRectangleSolverFunction)
	{
	public:

		TEST_METHOD(analyzeRectangle_perimeter_calculation_test)
		{
			/** This tests the functions capability to calculate the perimeter with the given coordinates:
			(2,3), (8,3), (8,5), and (2,5). The expected result is 12 */
			int x1 = 2;
			int x2 = 8;
			int x3 = 8; 
			int x4 = 2;
			int y1 = 3; 
			int y2 = 3; 
			int y3 = 5; 
			int y4 = 5;
			int *result;
			int expected = 12;

			result = analyzeRectangle(x1, x2, x3, x4, y1, y2, y3, y4);
			Assert::AreEqual(expected, result[1]);
		}

		TEST_METHOD(analyzeRectangle_area_calculation_test)
		{
			/** This tests the functions capability to calculate the area with the given coordinates:
			(2,3), (8,3), (8,5), and (2,5). The expected result is 16 */
			int x1 = 2;
			int x2 = 8;
			int x3 = 8;
			int x4 = 2;
			int y1 = 3;
			int y2 = 3;
			int y3 = 5;
			int y4 = 5;
			int* result;
			int expected = 16;

			result = analyzeRectangle(x1, x2, x3, x4, y1, y2, y3, y4);
			Assert::AreEqual(expected, result[0]);
		}

		TEST_METHOD(analyzeRectangle_perimeter_invalid_recangle_test)
		{
			/** This tests the functions capability to handle coordinates that do  not form a rectangle */
			int x1 = 10;
			int x2 = 1;
			int x3 = 2;
			int x4 = 3;
			int y1 = 17;
			int y2 = 9;
			int y3 = 8;
			int y4 = 7;
			int* result;
			int expected = 0;

			result = analyzeRectangle(x1, x2, x3, x4, y1, y2, y3, y4);
			Assert::AreEqual(expected, result[1]);
		}

		TEST_METHOD(analyzeRectangle_area_invalid_recangle_test)
		{
			/** This tests the functions capability to handle coordinates that do  not form a rectangle */
			int x1 = 10;
			int x2 = 1;
			int x3 = 2;
			int x4 = 3;
			int y1 = 17;
			int y2 = 9;
			int y3 = 8;
			int y4 = 7;
			int* result;
			int expected = 0;

			result = analyzeRectangle(x1, x2, x3, x4, y1, y2, y3, y4);
			Assert::AreEqual(expected, result[0]);
		}
	};
}
