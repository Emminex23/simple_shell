#include "main.h"
/**
 * _strlen - function that evaluates the length of a str
 * @str: pointer to the str
 *
 * Return: the length of the str
 */
unsigned int _strlen(const char *str)
{
	if (*str == '\0')
	{
		return (0);
	}
	return (1 + _strlen(str + 1));
}

/**
 * _print - prints to stdout
 * @str: pointer to str
 *
 * Return: the number of bytes printed
 */
unsigned int _print(char *str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}

/**
 * print_env - prints the current environment
 *
 * Return: Nothing
 */
void print_env(void)
{
	char **env_var = environ;

	while (*env_var)
	{
		_print(*env_var);
		_print("\n");
		env_var++;
	}
}

/**
 * _strcmp - Function that copies a string.
 * @s1: string 1
 * @s2: string 2
 *
 * Return: dest
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
