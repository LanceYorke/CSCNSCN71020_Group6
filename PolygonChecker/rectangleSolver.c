#include <stdio.h>
#include <stdbool.h>
#include "rectangleSolver.h"

char* analyzeRectangle(int x1, int y1, int x2, int y2, int x3,  int y3, int x4, int y4)
{
	int line1 = 0, line2 = 0, line3 = 0, line4 = 0, perimeter= 0, area = 0;

	if (y1 == y2) {
		line1 = x2 - x1;
	}
	if (x2 == x3) {
		line2 = y3 - y2;
	}
	if (y3 == y4) {
		line3 = x3 - x4;
	}
	if (x4 == x1) {
		line4 = y4 - y1;
	}
	if (line1 == 0 || line2 == 0 || line3 == 0 || line4 == 0) {
		printf_s("Values entered do not form a rectangle\n");
	}


	perimeter = line1 + line2 + line3 + line4;
	area = line1 * line2;

	printf_s("Perimeter: %d\n", perimeter);
	printf_s("Area: %d\n", area);

	int AreaAndPerimeter[2] = { area, perimeter };

	return AreaAndPerimeter;

}