/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:13:01 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/10 14:16:21 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int	fct_draw_fractal(t_fractol *f)
{
	f->x = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			if (ft_strcmp(f->name, "mandelbrot") == 0)
				fct_mandelbrot(f);
			else if (ft_strcmp(f->name, "julia") == 0)
				fct_julia(f);
			f->y ++;
		}
		f->x ++;
	}
	if (mlx_image_to_window(f->mlx, f->img, 0, 0) == -1)
	{
		mlx_close_window(f->mlx);
		return(EXIT_FAILURE);
	}
	return (0);
}
