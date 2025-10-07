/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfptrhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:21:38 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/18 12:30:11 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pfptrhex(void *p, size_t *count)
{
	unsigned long	temp_ptr;
	unsigned long	divisor;
	int				digit;
	char			*hex_base;

	if (p == NULL)
	{
		ft_pfstr("(nil)", count);
		return ;
	}
	temp_ptr = (unsigned long)p;
	divisor = 1;
	while (temp_ptr > 15)
	{
		temp_ptr /= 16;
		divisor *= 16;
	}
	ft_pfstr("0x", count);
	hex_base = "0123456789abcdef";
	while (divisor > 0)
	{
		digit = (((unsigned long) p) / divisor) % 16;
		ft_pfchar(hex_base[digit], count);
		divisor /= 16;
	}
}
