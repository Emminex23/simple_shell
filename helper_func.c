#include "main.h"
/**
 * _strncmp - Function that copies a string.
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes
 *
 * Return: dest
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
/**
 * _strdup - Function that duplicates a string.
 * @src: source
 *
 * Return: duplicate
 */
char *_strdup(const char *src)
{
	size_t i, len = _strlen(src);
	char *dup = (char *)malloc(len + 1);

	if (src == NULL)
	{
		return (NULL);
	}

	if (dup)
	{
		for (i = 0; i < len; i++)
		{
			dup[i] = src[i];
		}
		dup[len] = '\0';
	}
	return (dup);
}

/**
 * _memcpy - Function that duplicates a string.
 * @src: source
 * @dest: destination
 * @n: number of bytes
 *
 * Return: dest
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	char *d = (char *)dest;
	const char *s = (const char *)src;

	if (!d || !s)
	{
		return (NULL);
	}

	for (i = 0; i < n; i++)
	{
		d[i] = s[i];
	}
	return (dest);
}

/**
 * _strncpy - Function that copies a string.
 * @src: source
 * @dest: destination
 * @n: number of bytes
 *
 * Return: dest
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for ( ; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}

/**
 * exit_shell - Exits the shell
 *
 * Return: Nothing
 */
void exit_shell(void)
{
	exit(EXIT_SUCCESS);
}
