/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:22:55 by tlaranje          #+#    #+#             */
/*   Updated: 2025/10/23 16:38:24 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t len)
{
	int	*array;

	if (len != 0 && nmemb > SIZE_MAX / len)
		return (NULL);
	array = malloc(nmemb * len);
	if (!array)
		return (NULL);
	ft_memset(array, 0, nmemb * len);
	return (array);
}
