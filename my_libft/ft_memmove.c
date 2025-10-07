/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:02:36 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/21 12:14:25 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*char_dest;
	const unsigned char		*char_src;
	size_t					pos;

	if (src == NULL || dest == NULL)
		return (NULL);
	char_dest = (unsigned char *) dest;
	char_src = (const unsigned char *) src;
	if (char_dest < char_src || char_dest >= char_src + n)
	{
		pos = 0;
		while (pos < n)
		{
			char_dest[pos] = char_src[pos];
			pos ++;
		}
	}
	else
	{
		char_dest += n;
		char_src += n;
		while (n--)
			*(--char_dest) = *(--char_src);
	}
	return (dest);
}
