/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:45:39 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/21 12:12:47 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	total_len;
	size_t	i;
	size_t	j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc (total_len + 1);
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i])
	{
		joined[i] = s1[i];
		i ++;
	}
	j = 0;
	while (s2 != NULL && s2[j])
	{
		joined[i + j] = s2[j];
		j ++;
	}
	joined[i + j] = '\0';
	return (joined);
}
