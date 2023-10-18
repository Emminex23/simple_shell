#include "main.h"

/**
 * tokenisation - Tokenizes string
 *
 * @str: input string
 * @delimiter: constant char separating string
 *
 * Return: pointer to next token or NULL if theres no tokens
 */

char *tokenisation(char *str, char delimiter)
{
	static char *next_token;
	char *token = next_token;

	if (str != NULL)
	{
		next_token = str;
	}
	if (next_token == NULL || *next_token == '\0')
	{
		return (NULL);
	}
	while (*next_token != delimiter && *next_token != '\0')
	{
		next_token++;
	}
	if (*next_token == delimiter)
	{
		*next_token = '\0';
		next_token++;
	}
	return (token);
}
