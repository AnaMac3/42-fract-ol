/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfunsgn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:23:55 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/18 12:30:17 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pfunsgn(unsigned int n, size_t *count)
{
	unsigned int	n_temp;
	unsigned int	divisor;
	int				digit;

	n_temp = n;
	divisor = 1;
	while (n_temp > 9)
	{
		n_temp /= 10;
		divisor *= 10;
	}
	while (divisor > 0)
	{
		digit = (n / divisor) % 10;
		ft_pfchar(digit + '0', count);
		divisor /= 10;
	}
}
