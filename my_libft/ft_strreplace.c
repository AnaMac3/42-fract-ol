/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 20:00:23 by root              #+#    #+#             */
/*   Updated: 2025/10/02 20:07:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, char find, char replace)
{
	char	*new_str;
	int		i;

	if (!str)
		return (NULL);
	new_str = ft_strdup(str);
	if (!new_str)
		return (NULL);
	i = 0;
	while (new_str[i] != '\0')
	{
		if (new_str[i] == find)
			new_str[i] = replace;
		i ++;
	}
	return(new_str);
}