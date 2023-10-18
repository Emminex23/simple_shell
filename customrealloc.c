#include "main.h"

/*
 * custom_realloc - realloc function
 *
 * @ptr: pointer to memory block to resize
 * @new_size: new size of memory blocks in bytes
 *
 * Return: pointer to newly resized memory block
 */

void *custom_realloc(void *ptr, size_t new_size)
{
	void *new_ptr = malloc(new_size);
	size_t old_size = malloc_usable_size(ptr);
	size_t copy_size = (new_size < old_size) ? new_size : old_size;

	if (ptr == NULL)
	{
		return (malloc(new_size));
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_ptr == NULL)
	{
		return (NULL);
	}
	memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}
