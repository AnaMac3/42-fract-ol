/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:12:45 by amacarul          #+#    #+#             */
/*   Updated: 2024/09/23 12:09:46 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*char_s;

	char_s = (const unsigned char *) s;
	while (n > 0)
	{
		if (*char_s == (unsigned char) c)
			return ((void *)char_s);
		char_s ++;
		n --;
	}
	return (NULL);
}
