#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int side = 0;
#define NUMBER_OF_SIDES	3
#define NUMBER_OF_POINTS 8

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 2:
			printf_s("Rectangle selected.\n");
			int rectanglePoints[NUMBER_OF_POINTS] = { 0, 0, 0, 0, 0, 0, 0, 0 };
			int* rectanglePointsPtr = getRectanglePoints(rectanglePoints);
            int* result1 = analyzeRectangle(rectanglePointsPtr[0], rectanglePointsPtr[1], rectanglePointsPtr[2], rectanglePointsPtr[3], rectanglePointsPtr[4], rectanglePointsPtr[5], rectanglePointsPtr[6], rectanglePointsPtr[7]);
			if (result1[0] == 0) {
				printf_s("Values entered do not form a rectangle\n");
				break;
			}
			printf_s("Area: %d\n", result1[0]);
			printf_s("Perimeter: %d\n", result1[1]);
			break;
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[NUMBER_OF_SIDES] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;

		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("2. Rectangle\n");
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;
	char term;

	printf_s("Enter number: ");

	if (scanf("%d%c", &shapeChoice, &term) != 2 || term != '\n') {
		printf("Invalid value entered.\n");
		return 0;
	}

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");

	for (int i = 0; i < 3; i++)
	{
		if (scanf("%d", &triangleSides[i]) != 1) {
			printf("Invalid value entered\n");
			exit(1);
		}
	}
	return triangleSides;
}

int* getRectanglePoints(int* rectanglePoints)
{
	printf("Enter eight x and y coordinates: ");
	for (int i = 0; i < 8; i++)
	{
		if (scanf("%d", &rectanglePoints[i]) != 1) {
			printf("Invalid value entered\n");
			exit(1);
		}
	}

	return rectanglePoints;
}