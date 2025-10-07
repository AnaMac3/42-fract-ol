/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:47:13 by amacarul          #+#    #+#             */
/*   Updated: 2024/09/21 18:14:07 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	is_positive(int n, int fd)
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
		ft_putchar_fd(digit + '0', fd);
		divisor /= 10;
	}
}

void	is_negative(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		is_positive(n, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		is_negative(n, fd);
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n > 0)
		is_positive(n, fd);
}
