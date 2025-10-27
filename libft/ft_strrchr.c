/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:33:07 by tlaranje          #+#    #+#             */
/*   Updated: 2025/10/20 16:33:32 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*end = NULL;

	while (*str)
	{
		if (*str == (char)c)
			end = str;
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return ((char *)end);
}
