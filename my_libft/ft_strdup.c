/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:57:00 by amacarul          #+#    #+#             */
/*   Updated: 2024/09/21 18:14:19 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*start_dup;

	if (s == NULL)
		return (NULL);
	dup = (char *)malloc(ft_strlen(s) + 1);
	if (dup == NULL)
		return (NULL);
	start_dup = dup;
	while (*s)
	{
		*dup = *s;
		dup ++;
		s ++;
	}
	*dup = '\0';
	return (start_dup);
}
