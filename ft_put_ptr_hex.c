/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:00:24 by tlaranje          #+#    #+#             */
/*   Updated: 2025/10/27 17:15:28 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(size_t n, size_t up_lo_case)
{
	char	*hex;
	int		len;

	if(up_lo_case == 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, up_lo_case);
	len += write(1, &hex[n % 16], 1);
	return (len);
}

int	ft_putptr(void *ptr)
{
	size_t	num;
	int		len;

	len = 0;
	num = (size_t)ptr;
	len += ft_putstr("0x");
	len += ft_puthex(num, 0);
	return (len);
}
