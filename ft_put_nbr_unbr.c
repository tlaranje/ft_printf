/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_unbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:02:23 by tlaranje          #+#    #+#             */
/*   Updated: 2025/10/28 13:10:12 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	int		len;
	char	*str;

	str = ft_itoa(n);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	ft_putunbr(unsigned long un)
{
	int		len;
	char	*str;

	str = ft_utoa(un);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
