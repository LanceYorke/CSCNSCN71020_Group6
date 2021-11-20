#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(int, int, int);

extern "C" {
#include "main.h"
#include "getInsideAngle.h"
#include "triangleSolver.h"
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTriangleSolverFunction
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

}
