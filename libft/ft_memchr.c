/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:28:50 by tlaranje          #+#    #+#             */
/*   Updated: 2025/10/22 12:08:33 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char	*src_ptr;

	src_ptr = (unsigned char *)src;
	while (len--)
	{
		if (*src_ptr == (unsigned char)c)
			return ((char *)src_ptr);
		src_ptr++;
	}
	return (NULL);
}
