/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:25:08 by amacarul          #+#    #+#             */
/*   Updated: 2024/09/21 18:12:19 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	pos;
	int	sign;
	int	nb;

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
