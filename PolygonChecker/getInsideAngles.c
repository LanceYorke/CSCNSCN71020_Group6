#include "getInsideAngle.h"

int getInsideAngles(int side1, int side2, int side3) {
	int largestSide;
	double second = 0, third = 0, largest0 = 0, largest1 = 0, largest2 = 0, finallargest = 0, cosinehelper = 0, cosineone = 0, cosinetwo = 0, Angle1 = 0;
	double sin1 = 0, sin2 = 0, Angle2 = 0, Angle3 = 0, isodouble = 0, smallestSize = 0;

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
	}//finds the largest side of all of the angles and marks it down
	largest0 = pow(largestSide, TWOS_COMPLIMENT);
	largest1 = pow(second, TWOS_COMPLIMENT);//uses cosine law to find the first angle witch requires using the square root of all of the sides
	largest2 = pow(third, TWOS_COMPLIMENT);
	finallargest = (largest1 + largest2);
	if (finallargest > 0)// this if statement is used to find out if the largest angle is positive or negative
	{
		cosineone = (largest0 - finallargest);
	}
	else if (finallargest < 0)
	{
		cosineone = (largest0 + finallargest);
	}
	cosinehelper = (NEGATIVE_TWO * second * third);
	cosinetwo = (cosineone / cosinehelper);
	Angle1 = (acos(cosinetwo) * (180/PI));//finds the angle by converting the number that is in radians to degrees
	sin1 = (sin(Angle1 * (180 / PI)));
	sin1 = fabs(sin1);//since sin is weird in VS with this I found I need to reverse the angle to get the correct answer
	sin2 = ((second * sin1) / ((double)largestSide));
	Angle2 = (asin(sin2) * (180 / PI));//uses sin law with the angle I got from cosine and instead uses sine to find the 2nd angle

	Angle3 = (180 - Angle1 - Angle2);
	//finally to get the third angle since all angles in a triangle must add up to 180 degrees I subtract the angles I have recieved by both of them to get the final angle of the triangle
	if (side1 == side2 && side2 == side3 && side1 == side3)
	{
		Angle1 = 60; //for equalateral triangle
		Angle2 = 60;
		Angle3 = 60;
	}
	if (second == third)
	{
		isodouble = (180 - Angle1);//for isoslose triangle
		isodouble = (isodouble / 2);
		Angle2 = isodouble;
		Angle3 = isodouble;
	}
	if (largestSide == second || largestSide == third)
	{
		Angle2 = Angle1;
		Angle3 = (180 - (Angle1 + Angle2));
	}

	printf_s("Your 3 angles are: %f, %f and %f\n", Angle1, Angle2, Angle3);//prints all of the angles
	if ((Angle1 + Angle2 + Angle3) == 180)
	{
		return 1;
	}
	return 0;
}