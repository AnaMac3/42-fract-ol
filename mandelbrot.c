/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:34:12 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/10 14:20:41 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

void	fct_init_mandelbrot(t_fractol *f)
{
	f->name = "mandelbrot";
	f->min_x = -2.5;
	f->max_x = 1.5;
	f->min_y = -2.0;
	f->max_y = 2.0;
	f->offset_x = 0;
	f->offset_y = 0;
	f->palettes[0].colors[0] = (t_color){255, 20, 147};
	f->palettes[0].colors[1] = (t_color){36, 247, 85};
	f->palettes[0].colors[2] = (t_color){0, 191, 255};
	f->palettes[0].colors[3] = (t_color){75, 0, 130};
	f->palettes[1].colors[0] = (t_color){255, 69, 0};
	f->palettes[1].colors[1] = (t_color){138, 43, 226};
	f->palettes[1].colors[2] = (t_color){0, 20, 209};
	f->palettes[1].colors[3] = (t_color){255, 215, 0};
	f->palettes[2].colors[0] = (t_color){20, 244, 215};
	f->palettes[2].colors[1] = (t_color){255, 136, 0}; 
	f->palettes[2].colors[2] = (t_color){0, 56, 255};
	f->palettes[2].colors[3] = (t_color){187, 101, 222};
	f->palette_index = 0;
	f->color_index = 0;
}

/*Calculates and visualizes the Mandelbrot set for a given point.
	- Iterates the funcion zn+1 = zn2 + c to check if a point belongs to set.
	- If the point escapes (zx2 + zy2 > 4), it is colored based on the number
	of iterations.
	- If the point stays within the set, it is colored black*/
void	fct_mandelbrot(t_fractol *f)
{
	int		n;
	double	tmp;
	int		max_iterations;

	n = 0;
	max_iterations = fct_max_iterations(f);
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = f->min_x + (f->max_x - f->min_x) * ((double)f->x / WIDTH);
	f->cy = f->min_y + (f->max_y - f->min_y) * ((double)f->y / HEIGHT);
	while (++ n < max_iterations)
	{
		if (f->zx * f->zx + f->zy * f->zy > 4.0)
			break ;
		tmp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = 2.0 * f->zx * f->zy + f->cy;
		f->zx = tmp;
	}
	if (n == max_iterations)
		mlx_put_pixel(f->img, f->x, f->y, 0x000000);
	else
	{
		f->final_color = fct_color_from_palette(f, n, max_iterations);
		mlx_put_pixel(f->img, f->x, f->y, f->final_color);
	}
}


