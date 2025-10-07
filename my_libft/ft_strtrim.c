/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:14:27 by amacarul          #+#    #+#             */
/*   Updated: 2024/09/21 18:14:44 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;
	size_t	total_len;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start ++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end]))
		end --;
	total_len = end - start + 1;
	trimmed = (char *)malloc(total_len + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, (s1 + start), (total_len + 1));
	return (trimmed);
}
