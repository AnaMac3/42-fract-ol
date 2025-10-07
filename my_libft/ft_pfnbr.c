/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:57:35 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/18 12:30:09 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	is_positive(int n, size_t *count)
{
	int	n_temp;
	int	digit;
	int	divisor;

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

static void	is_negative(int n, size_t *count)
{
	if (n == -2147483648)
	{
		ft_pfstr("-2147483648", count);
		return ;
	}
	else
	{
		ft_pfchar('-', count);
		n = -n;
		is_positive(n, count);
	}
}

void	ft_pfnbr(int n, size_t *count)
{
	if (n < 0)
		is_negative(n, count);
	else if (n == 0)
		ft_pfchar('0', count);
	else if (n > 0)
		is_positive(n, count);
}
