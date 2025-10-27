/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:32:54 by tlaranje          #+#    #+#             */
/*   Updated: 2025/10/21 16:24:13 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*add_to_string(char *str, long num, int i)
{
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int			i_len;
	long int	num;
	char		*str;

	num = n;
	i_len = int_len(num);
	str = malloc(sizeof(char) * (i_len + 1));
	if (!str)
		return (NULL);
	str[i_len--] = '\0';
	str = add_to_string(str, num, i_len);
	return (str);
}
