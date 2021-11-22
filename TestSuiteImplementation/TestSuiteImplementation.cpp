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

		TEST_METHOD(DetermineOutcomeOneSideIs0)
		{
			//This test method is testing if the function return "Not a triangle" when one side is 0 or less than 0

			int side1 = 0; //Invalid side
			int side2 = 5;
			int side3 = 9;

			char* output = "Not a triangle"; //expected output

			char* outputFunction = { analyzeTriangle(side1, side2, side3) };

			Assert::AreEqual(output, outputFunction);

		}

		TEST_METHOD(DetermineOutcomeAllSidesAre0)
		{
			//This test method is testing if the function return "Not a triangle" when all sides are 0 or less than 0

			//Invalid sides
			int side1 = 0; 
			int side2 = -4;
			int side3 = 0;

			char* output = "Not a triangle"; //expected output

			char* outputFunction = { analyzeTriangle(side1, side2, side3) };

			Assert::AreEqual(output, outputFunction);

		}

		TEST_METHOD(DetermineOutcomeEquilateralTriangle)
		{
			//This test method is testing if the function return "Equilateral triangle" when all sides are equal

			int side1 = 4;
			int side2 = 4;
			int side3 = 4;

			char* output = "Equilateral triangle"; //expected output

			char* outputFunction = { analyzeTriangle(side1, side2, side3) };

			Assert::AreEqual(output, outputFunction);

		}

		TEST_METHOD(DetermineOutcomeIsoscelesTriangle)
		{
			//This test method is testing if the function return "Isosceles triangle" when two sides are equal

			int side1 = 4;
			int side2 = 4;
			int side3 = 7;

			char* output = "Isosceles triangle"; //expected output

			char* outputFunction = { analyzeTriangle(side1, side2, side3) };

			Assert::AreEqual(output, outputFunction);

		}

		TEST_METHOD(DetermineOutcomeScaleneTriangle)
		{
			//This test method is testing if the function return "Scalene triangle" when all sides are different

			int side1 = 3;
			int side2 = 8;
			int side3 = 2;

			char* output = "Scalene triangle"; //expected output

			char* outputFunction = { analyzeTriangle(side1, side2, side3) };

			Assert::AreEqual(output, outputFunction);

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
		TEST_METHOD(Getting_insideAnglesfor_Scalene)
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

			result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);
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

			result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);
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

			result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);
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

			result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);
			Assert::AreEqual(expected, result[0]);
		}
	};
}
