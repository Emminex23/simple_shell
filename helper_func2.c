#include "main.h"
/**
 * _itoa - int to ascii
 * @buf: buffer
 * @value: value to convert
 *
 * Return: an int
 */

int _itoa(char *buf, int value)
{
	char *start = buf, *end, temp;

	if (value == 0)
	{
		*buf++ = '0';
		*buf = '\0';
		return (1);
	}
	if (value < 0)
	{
		*buf++ = '-';
		value = -value;
	}
	end = buf;

	while (value)
	{
		*end++ = '0' + (value % 10);
		value /= 10;
	}
	*end-- = '\0';
	while (buf < end)
	{
		temp = *buf;
		*buf++ = *end;
		*end-- = temp;
	}
	return (end - start + 1);
}
/**
 * _sprintf - variant of printf
 * @buf: buffer
 * @format: format
 *
 * Return: number of bytes printed
 */
int _sprintf(char *buf, const char *format, ...)
{
	va_list args;
	char *str_arg;
	int written = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 's':
					str_arg = va_arg(args, char *);
					while (*str_arg)
					{
						*buf++ = *str_arg++;
						written++;
					}
					break;
				case 'd':
					written += _itoa(buf, va_arg(args, int));
					while (*buf)
						buf++;
					break;
				default:
					*buf++ = *format;
					written++;
					break;
			}
		} else
		{
			*buf++ = *format;
			written++;
		}
		format++;
	}
	*buf = '\0';
	va_end(args);
	return (written);
}
