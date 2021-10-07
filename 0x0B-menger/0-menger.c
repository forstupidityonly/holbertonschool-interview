#include <stdio.h>
#include <math.h>
#include "menger.h"
/**
* charCalc - maths what char to print block or no block
* @i: height
* @j: width
* Return: ' ', '#'
*/
char charCalc(int i, int j)
{
	for (; i && j; i /= 3, j /= 3)
		if (i % 3 == 1 && j % 3 == 1)
			return (' ');
	return ('#');
}
/**
 * menger - draws a 2D Menger Sponge
 * @level: level to draw
 */
void menger(int level)
{
	int size, i, j;

	if (level < 0)
		return;
	size = pow(3, level);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			printf("%c", charCalc(i, j));
		printf("\n");
	}
}
