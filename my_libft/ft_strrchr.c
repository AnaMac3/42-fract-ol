/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:45:39 by amacarul          #+#    #+#             */
/*   Updated: 2024/09/21 18:14:42 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		pos;

	if (s == NULL)
		return (NULL);
	pos = 0;
	while (*s)
	{
		s ++;
		pos ++;
	}
	if (c == '\0')
		return ((char *) s);
	while (pos > 0)
	{
		if (*s == c)
			return ((char *)s);
		s --;
		pos --;
	}
	return (NULL);
}
