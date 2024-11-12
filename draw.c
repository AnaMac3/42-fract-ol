/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:13:01 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/12 13:57:53 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/*Draws the fractal
	- Iterates through each pixel in the x and y axis, from 0 to the
	width and height of the window
	- Computes the corresponding fractal (mandelbrot, julia, burning_ship) 
	for each pixel
	- Displays the resulting image in the window
*/
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
			else if (ft_strcmp(f->name, "burning_ship") == 0)
				fct_burning_ship(f);
			f->y ++;
		}
		f->x ++;
	}
	if (mlx_image_to_window(f->mlx, f->img, 0, 0) == -1)
	{
		mlx_close_window(f->mlx);
		return (EXIT_FAILURE);
	}
	return (0);
}
