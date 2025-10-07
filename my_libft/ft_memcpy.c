/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:44:36 by amacarul          #+#    #+#             */
/*   Updated: 2024/09/23 12:00:15 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst_temp;
	const unsigned char	*src_temp;
	size_t				pos;

	if (dest == NULL && src == NULL)
		return (NULL);
	dst_temp = (unsigned char *) dest;
	src_temp = (const unsigned char *) src;
	pos = 0;
	while (pos < n)
	{
		dst_temp[pos] = src_temp[pos];
		pos ++;
	}
	return (dest);
}
