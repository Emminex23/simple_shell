#include "main.h"
/**
 * custom_malloc - memory allocation
 * @size: size to allocate
 *
 * Return: Nothing
 */
void *custom_malloc(size_t size)
{
	size_t *block;

	if (size == 0)
		return (NULL);

	block = malloc(size + sizeof(size_t));
	if (!block)
		return (NULL);

	*block = size;
	return (block + 1);
}

/**
 * custom_free - frees malloc and co
 * @ptr: pointer to free
 *
 * Return: Nothing
 */
void custom_free(void *ptr)
{
	size_t *block;

	if (!ptr)
		return;

	block = (size_t *)ptr - 1;
	free(block);
}
/**
 * custom_memcpy - copies mem
 * @dest: destination
 * @src: source
 * @n: number
 *
 * Return: Nothing
 */
void custom_memcpy(void *dest, void *src, size_t n)
{
	size_t i;
	char *cdest = (char *)dest;
	char *csrc = (char *)src;

	for (i = 0; i < n; i++)
	{
		cdest[i] = csrc[i];
	}
}
/**
 * _realloc - reallocates memory
 * @ptr: pointer
 * @new_size: new size to allocate
 *
 * Return: Nothing
 */
void *_realloc(void *ptr, size_t new_size)
{
	size_t *block;
	size_t old_size;
	void *new_ptr;
	size_t copy_size;

	if (!ptr)
		return (custom_malloc(new_size));

	block = (size_t *)ptr - 1;
	old_size = *block;

	if (new_size == old_size)
	return (ptr);

	if (new_size == 0)
	{
		custom_free(ptr);
		return (custom_malloc(1));
	}

	new_ptr = custom_malloc(new_size);
	if (!new_ptr)
		return (NULL);

	copy_size = (new_size < old_size) ? new_size : old_size;
	custom_memcpy(new_ptr, ptr, copy_size);
	custom_free(ptr);
	return (new_ptr);
}
