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

}
