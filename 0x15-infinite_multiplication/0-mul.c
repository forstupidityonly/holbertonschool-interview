#include "holberton.h"
#include "stdio.h"
/**
  * reverse - reverse s in place
  * @s: the string to be reversed
  * Return: no
  */
void reverse(char s[])
{
	int i, j;
	char c;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/**
  * itoa - int to ascii
  * @n: the int
  * @s: the array to store int
  * Return: no
  */
void itoa(int n, char s[])
{
	int i;
	int sign = n;

	if (sign < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/**
  * myAtoi - ascii to int
  * @str: the ascii string
  * @errorMsg: passing args easier than redecleration
  * Return: int value of str
  */
int myAtoi(char *str, char *errorMsg)
{
	int res = 0;
	int i = 0;
	int j = 0;

	for (; str[i] != '\0'; ++i)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			while (errorMsg[j])
			{
				_putchar(errorMsg[j]);
				j++;
			}
			_putchar('\n');
			exit(98);
		}
		res = res * 10 + str[i] - '0';
	}
	return (res);
}

/**
  * main - runs the program
  * @argc: argument count
  * @argv: arguments
  * Return: 0 sucess
  */
int main(int argc, char **argv)
{
	char errorMsg[] = "Error";
	int i, j, ans = 0;
	char answer[1000000];

	if (argc != 3)
	{
		while (errorMsg[i])
		{
			_putchar(errorMsg[i]);
			i++;
		}
		_putchar('\n');
		exit(98);
	}
	ans = myAtoi(argv[1], errorMsg) * myAtoi(argv[2], errorMsg);
	printf("Ans: %d", ans);
	itoa(ans, answer);
	while (answer[j])
	{
		_putchar(answer[j]);
		j++;
	}
	_putchar('\n');
	return (0);
}
