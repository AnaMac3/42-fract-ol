/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:01:40 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/11 19:40:30 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/*Initialize the values for Burning ship set in fractol structure*/
void	fct_init_burning_ship(t_fractol *f)
{
	f->name = "burning_ship";
	f->min_x = -2.5;
	f->max_x = 1.5;
	f->min_y = -2.5;
	f->max_y = 1.5;
	f->offset_x = 0;
	f->offset_y = 0;
	f->palettes[0].colors[0] = (t_color){0, 255, 255};
	f->palettes[0].colors[1] = (t_color){255, 165, 0};
	f->palettes[0].colors[2] = (t_color){255, 0, 255};
	f->palettes[0].colors[3] = (t_color){204, 255, 0};
	f->palettes[1].colors[0] = (t_color){56, 51, 255};
	f->palettes[1].colors[1] = (t_color){255, 165, 0};
	f->palettes[1].colors[2] = (t_color){255, 255, 0};
	f->palettes[1].colors[3] = (t_color){255, 255, 224};
	f->palettes[2].colors[0] = (t_color){54, 2, 2};
	f->palettes[2].colors[1] = (t_color){92, 252, 11};
	f->palettes[2].colors[2] = (t_color){205, 253, 0};
	f->palettes[2].colors[3] = (t_color){144, 238, 144};
	f->palette_index = 0;
	f->color_index = 0;
}

/*Computes and visualizes the Julia set for the current pixel.
	- Calculates the max num of iterations
	- Sets zx and zy to the initial complex coordinate (0,0)
	- Sets cx and cy to the complex coordinates corresponding to
	the current pixel
	- Iterates the funcion zn+1 = (|zx| + i * |zy|)² + c to check if 
	a point belongs to the set.
	- If the point escapes (|zx|^2 + |zy|^2 > 4), it is colored based 
	on the number of iterations.
	- If the point stays within the set (does not escape), it is colored black.
	- Determines the number of iterations before the point diverges (tends to
	infinity)
	- Sets the pixel color based on the number of iterations 
*/
void	fct_burning_ship(t_fractol *f)
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
		if (fabs(f->zx) * fabs(f->zx) + fabs(f->zy) * fabs(f->zy) > 4.0)
			break ;
		tmp = fabs(f->zx) * fabs(f->zx) - fabs(f->zy) * fabs(f->zy) + f->cx;
		f->zy = 2.0 * fabs(f->zx) * fabs(f->zy) + f->cy;
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
