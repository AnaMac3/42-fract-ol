/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:19:39 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/18 12:30:06 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pfhex(unsigned int n, int mode, size_t *count)
{
	unsigned int	n_temp;
	unsigned int	divisor;
	int				digit;
	char			*hex_base;

	n_temp = n;
	divisor = 1;
	while (n_temp > 15)
	{
		n_temp /= 16;
		divisor *= 16;
	}
	if (mode == 1)
		hex_base = "0123456789abcdef";
	else if (mode == 2)
		hex_base = "0123456789ABCDEF";
	while (divisor > 0)
	{
		digit = (n / divisor) % 16;
		ft_pfchar(hex_base[digit], count);
		divisor /= 16;
	}
}
