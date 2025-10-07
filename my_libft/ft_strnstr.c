/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:38:50 by amacarul          #+#    #+#             */
/*   Updated: 2024/09/23 12:23:56 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	start;
	size_t	i;

	start = 0;
	if (little[start] == '\0')
		return ((char *)big);
	while (big[start] != '\0' && len > start)
	{
		i = 0;
		while (little[i] && (len > start + i) && (big[start + i] == little[i]))
			i ++;
		if (little[i] == '\0')
			return ((char *)(big + start));
		start ++;
	}
	return (NULL);
}
