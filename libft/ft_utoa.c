/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:41:47 by tlaranje          #+#    #+#             */
/*   Updated: 2025/10/28 14:02:56 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*add_to_string(char *str, unsigned long num, int i)
{
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (num > 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (str);
}

char	*ft_utoa(unsigned long un)
{
	int				i_len;
	char			*str;

	i_len = int_len(un);
	str = malloc(sizeof(char) * (i_len + 1));
	if (!str)
		return (NULL);
	str[i_len--] = '\0';
	str = add_to_string(str, un, i_len);
	return (str);
}
