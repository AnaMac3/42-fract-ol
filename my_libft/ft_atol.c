/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:48:39 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/14 10:49:18 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//String to number (long int)
long int	ft_atol(const char *nptr)
{
	int			pos;
	int			sign;
	long int	nb;

	pos = 0;
	sign = 1;
	nb = 0;
	while ((nptr[pos] >= 9 && nptr[pos] <= 13) || nptr[pos] == 32)
		pos ++;
	if (nptr[pos] == '+')
		pos ++;
	else if (nptr[pos] == '-')
	{
		sign = -1;
		pos ++;
	}
	while (nptr[pos] >= '0' && nptr[pos] <= '9')
	{
		nb = nb * 10 + (nptr[pos] - '0');
		pos ++;
	}
	return (nb * sign);
}
