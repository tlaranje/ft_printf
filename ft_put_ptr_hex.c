/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:00:24 by tlaranje          #+#    #+#             */
/*   Updated: 2025/10/28 11:50:52 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, int up_lo_case)
{
	char	*hex;
	int		len;

	len = 0;
	if (up_lo_case == 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		len += ft_puthex(n / 16, up_lo_case);
	len += write(1, &hex[n % 16], 1);
	return (len);
}

int	ft_putptr(void *ptr)
{
	int		len;

	if (!ptr)
		return (ft_putstr("(nil)"));
	len = 0;
	len += ft_putstr("0x");
	len += ft_puthex((unsigned long)ptr, 0);
	return (len);
}
