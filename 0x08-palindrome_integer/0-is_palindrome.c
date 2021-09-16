#include "palindrome.h"

/**
 * is_palindrome - checks palindrome number.
 *
 * @n:  unsigned integer
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	int r, sum, temp;

	sum = 0;
	temp = n;

	while (n > 0)
	{
		r = n % 10;
		sum = (sum * 10) + r;
		n = n / 10;
	}
	if (temp == sum)
		return (1);

	return (0);
}
