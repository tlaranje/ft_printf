/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:47:30 by tlaranje          #+#    #+#             */
/*   Updated: 2025/10/29 17:07:14 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* static int	handle_format_bonus(const char **format, int nbr)
{
	int	count;
	int	width;
	int	sign;

	count = 0;
	width = 0;
	sign = 0;
	if (format == '-')
		sign = 1;
	if (ft_isdigit(format))
	{
		width = width * 10 + (format - '0');
		count += ft_put_aligned(format, nbr, width, sign);
	}
	return (count);
} */

static int	handle_format(const char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (format == '%')
		count += ft_putchar('%');
	/* else if (format == '-' || ft_isdigit(format))
			count += handle_format_bonus(format, va_arg(args, int)); */
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
		if (*format == '%' && *(format + 1))
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

/* int	main(void)
{
	printf("ft_printf: %d\n", ft_printf("%10d\n", 42));
	int ft_ret, std_ret;
	char *s = "42school";

	printf("\n=========================== BONUS FLAG TESTS ===========================\n\n");

	// 1. Right alignment (default)
	printf("==== Test 1: Right alignment (default) ====\n");
	ft_ret = ft_printf("ft_printf: '%10d'\n", 42);
	std_ret = printf("printf   : '%10d'\n", 42);
	printf("Returned -> ft_printf: %d | printf: %d\n\n", ft_ret, std_ret);

	// 2. Left alignment '-'
	printf("==== Test 2: Left alignment ('-') ====\n");
	ft_ret = ft_printf("ft_printf: '%-10d'\n", 42);
	std_ret = printf("printf   : '%-10d'\n", 42);
	printf("Returned -> ft_printf: %d | printf: %d\n\n", ft_ret, std_ret);

	// 3. Zero padding '0'
	printf("==== Test 3: Zero padding ('0') ====\n");
	ft_ret = ft_printf("ft_printf: '%010d'\n", 42);
	std_ret = printf("printf   : '%010d'\n", 42);
	printf("Returned -> ft_printf: %d | printf: %d\n\n", ft_ret, std_ret);

	// 4. Sign '+' flag
	printf("==== Test 4: Force sign ('+') ====\n");
	ft_ret = ft_printf("ft_printf: '%+d' | '%+d'\n", 42, -42);
	std_ret = printf("printf   : '%+d' | '%+d'\n", 42, -42);
	printf("Returned -> ft_printf: %d | printf: %d\n\n", ft_ret, std_ret);

	// 5. Space flag ' '
	printf("==== Test 5: Space flag (' ') ====\n");
	ft_ret = ft_printf("ft_printf: '% d' | '% d'\n", 42, -42);
	std_ret = printf("printf   : '% d' | '% d'\n", 42, -42);
	printf("Returned -> ft_printf: %d | printf: %d\n\n", ft_ret, std_ret);

	// 6. Hash flag '#' (hexadecimal)
	printf("==== Test 6: Hash flag ('#') ====\n");
	ft_ret = ft_printf("ft_printf: '%#x' | '%#X'\n", 255, 255);
	std_ret = printf("printf   : '%#x' | '%#X'\n", 255, 255);
	printf("Returned -> ft_printf: %d | printf: %d\n\n", ft_ret, std_ret);

	// 7. Combine flags
	printf("==== Test 7: Combine flags ('-+10.5d') ====\n");
	ft_ret = ft_printf("ft_printf: '%-+10.5d'\n", 42);
	std_ret = printf("printf   : '%-+10.5d'\n", 42);
	printf("Returned -> ft_printf: %d | printf: %d\n\n", ft_ret, std_ret);

	// 8. Precision test with integers
	printf("==== Test 8: Precision with integers ('.5d') ====\n");
	ft_ret = ft_printf("ft_printf: '%.5d'\n", 42);
	std_ret = printf("printf   : '%.5d'\n", 42);
	printf("Returned -> ft_printf: %d | printf: %d\n\n", ft_ret, std_ret);

	// 9. Precision test with string
	printf("==== Test 9: Precision with string ('.5s') ====\n");
	ft_ret = ft_printf("ft_printf: '%.5s'\n", s);
	std_ret = printf("printf   : '%.5s'\n", s);
	printf("Returned -> ft_printf: %d | printf: %d\n\n", ft_ret, std_ret);

	// 10. Negative number + zero padding
	printf("==== Test 10: Negative + zero padding ('%%08d') ====\n");
	ft_ret = ft_printf("ft_printf: '%08d'\n", -42);
	std_ret = printf("printf   : '%08d'\n", -42);
	printf("Returned -> ft_printf: %d | printf: %d\n\n", ft_ret, std_ret);
	return (0);
} */
