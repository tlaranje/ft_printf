/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:00:53 by tlaranje          #+#    #+#             */
/*   Updated: 2025/10/22 15:27:21 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*src_ptr;
	unsigned char	*dest_ptr;

	src_ptr = (unsigned char *)src;
	dest_ptr = (unsigned char *)dest;
	if (dest_ptr == src_ptr || size == 0)
		return (dest);
	if (dest_ptr < src_ptr)
	{
		while (size--)
			*dest_ptr++ = *src_ptr++;
	}
	else
	{
		src_ptr += size;
		dest_ptr += size;
		while (size--)
			*--dest_ptr = *--src_ptr;
	}
	return (dest);
}
