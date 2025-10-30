/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:47:30 by tlaranje          #+#    #+#             */
/*   Updated: 2025/10/30 12:01:27 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(const char str, va_list args)
{
	int	len;

	len = 0;
	if (str == 'd' || str == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (str == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (str == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (str == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (str == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (str == 'x')
		len += ft_puthex(va_arg(args, unsigned int), 0);
	else if (str == 'X')
		len += ft_puthex(va_arg(args, unsigned int), 1);
	else if (str == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			len += handle_format(*str, args);
		}
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (len);
}
