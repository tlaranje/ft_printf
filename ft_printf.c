/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:47:30 by tlaranje          #+#    #+#             */
/*   Updated: 2025/10/27 17:16:21 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(const char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, unsigned int));
	else if (format == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (format == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += handle_format(*format, args);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int	len;

	printf("ft_printf(\"Hello, world!\\n\")\n");
	len = ft_printf("Hello, world!\n");
	printf("Len: %d\n\n", len);
	printf("ft_printf(\"Caractere: %%c\", 'A')\n");
	len = ft_printf("Caractere: %c", 'A');
	printf("\nLen: %d\n\n", len);
	printf("ft_printf(\"String: %%s\", \"42 porto\")\n");
	len = ft_printf("String: %s", "42 porto");
	printf("\nLen: %d\n\n", len);
	printf("ft_printf(\"Pointer: %%p\", (void*)0x1234)\n");
	len = ft_printf("Pointer: %p", (void *)0x1234);
	printf("\nLen: %d\n\n", len);
	printf("ft_printf(\"Decimal: %%d\", -1234)\n");
	len = ft_printf("Decimal: %d", -1234);
	printf("\nLen: %d\n\n", len);
	printf("ft_printf(\"Base 10: %%i\", 10)\n");
	len = ft_printf("Base 10: %i", 10);
	printf("\nLen: %d\n\n", len);
	printf("ft_printf(\"Unsigned: %%u\", 1313)\n");
	len = ft_printf("Unsigned: %u", 1313);
	printf("\nLen: %d\n\n", len);
	printf("ft_printf(\"Hex lowercase: %%x\", 255)\n");
	len = ft_printf("Hex lowercase: %x", 255);
	printf("\nLen: %d\n\n", len);
	printf("ft_printf(\"Hex upercase: %%X\", 255)\n");
	len = ft_printf("Hex upercase: %X", 255);
	printf("\nLen: %d\n\n", len);
	printf("ft_printf(\"Percent: %%\")\n");
	len = ft_printf("Percent: %%");
	printf("\nLen: %d\n", len);
	return (0);
}
