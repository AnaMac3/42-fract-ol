/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:49:33 by amacarul          #+#    #+#             */
/*   Updated: 2024/09/21 18:13:22 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*putnbr_char(int n, char *str, size_t len)
{
	int	divisor;
	int	i;

	divisor = 1;
	if (n < 0)
		len --;
	while (len > 1)
	{
		divisor *= 10;
		len --;
	}
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		n = -n;
		i ++;
	}
	while (divisor > 0)
	{
		str[i ++] = ((n / divisor) % 10) + '0';
		divisor /= 10;
	}
	str[i] = '\0';
	return (str);
}

static size_t	nblen(int n)
{
	int	n_temp;
	int	count;

	n_temp = n;
	count = 0;
	if (n_temp == 0)
		return (1);
	else if (n_temp < 0)
	{
		if (n_temp == -2147483648)
			return (11);
		else
		{
			n_temp = -n_temp;
			count ++;
		}
	}
	while (n_temp > 0)
	{
		n_temp /= 10;
		count ++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	nb_total_len;

	nb_total_len = nblen(n) + 1;
	str = (char *)malloc(nb_total_len * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		ft_strlcpy(str, "0", 2);
	else if (n == -2147483648)
		ft_strlcpy(str, "-2147483648", 12);
	else
		putnbr_char(n, str, nblen(n));
	return (str);
}
