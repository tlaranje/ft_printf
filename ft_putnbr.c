/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:02:23 by tlaranje          #+#    #+#             */
/*   Updated: 2025/10/27 17:15:42 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(n);
	if (n == '-')
	{
		ft_putchar(n);
		n %= -1;
	}
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	ft_putstr(str);
	return (len);
}

int	ft_putunbr(size_t un)
{
	(void)un;
	return (0);
}
