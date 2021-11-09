#include "getInsideAngle.h"
#include <math.h>
#define NEGATIVE_TWO	-2
#define TWOS_COMPLIMENT	2
#define PI	3.14

int* getInsideAngles(int side1, int side2, int side3) {
	int largestSide;
	double second = 0, third = 0, largest0 = 0, largest1 = 0, largest2 = 0, finallargest = 0, cosinehelper = 0, cosineone = 0, cosinetwo = 0, Angle1 = 0;
	double sin1 = 0, sin2 = 0, Angle2 = 0, Angle3 = 0;
	if (side1 >= side2 && side1 >= side3) {
		largestSide = side1;
		second = (double)side2;
		third = (double)side3;
	}
	if (side2 >= side1 && side2 >= side3) {
		largestSide = side2;
		second = (double)side1;
		third = (double)side3;
	}
	if (side3 >= side1 && side3 >= side2){
		largestSide = side3;
		second = (double)side1;
		third = (double)side2;
	}
	largest0 = pow(largestSide, TWOS_COMPLIMENT);
	largest1 = pow(second, TWOS_COMPLIMENT);
	largest2 = pow(third, TWOS_COMPLIMENT);
	finallargest = (largest1 + largest2);
	if (finallargest > 0)
	{
		cosineone = (largest0 - finallargest);
	}
	else if (finallargest < 0)
	{
		cosineone = (largest0 + finallargest);
	}
	cosinehelper = (NEGATIVE_TWO * second * third);
	cosinetwo = (cosineone / cosinehelper);
	Angle1 = (acos(cosinetwo) * (180/PI));
	sin1 = (sin(Angle1 * (180 / PI)));
	sin1 = fabs(sin1);
	sin2 = ((second * sin1) / ((double)largestSide));
	Angle2 = (asin(sin2) * (180 / PI));

	Angle3 = (180 - Angle1 - Angle2);

	printf("Your 3 angles are: %f, %f and %f\n", Angle1, Angle2, Angle3);

	return 0;
}