/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:16:18 by amacarul          #+#    #+#             */
/*   Updated: 2024/09/23 12:39:50 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		pos;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	pos = 0;
	while (pos < len && s[start + pos] != '\0')
	{
		substr[pos] = s[start + pos];
		pos ++;
	}
	substr[pos] = '\0';
	return (substr);
}
