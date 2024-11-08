/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:34:12 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/08 19:08:54 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/*Calculates the max num of iterations for each point
	- max_x and min_x represent the limits of the visible area on the
	real axis (x) of the fractal
	- rval_range: real value range
*/
int	get_max_iterations(t_fractol *f)
{
	int	max_iter;
	double	rval_range;

	rval_range = f->max_x - f->min_x;
	max_iter = BASE_ITER + ITER_INCREMENT *(int)log2(2.0 / rval_range);
	return (max_iter);
}

//tiene que haber una manera de simplificar esta funciń... menos variables
int	get_color_from_palette(t_fractol *f, int n, int max_iterations)
{
	int			index;
	t_color		*start;
	t_color		*end;
	int			r;
	int			g;
	int			b;
	float		t;

	t = (float)n / (float)max_iterations;
	index = (int)(t * 3);
	start = &f->palettes[f->current_palette].colors[index];
	end = &f->palettes[f->current_palette].colors[index + 1];
	r = (int)(start->r + (end->r - start->r) * ((t * 3) - index));
	g = (int)(start->g + (end->g - start->g) * ((t * 3) - index));
	b = (int)(start->b + (end->b - start->b) * ((t * 3) - index));
	return (fct_pixel(r, g, b, 255));
}

//hay que reducir esta función
void	calculate_mandelbrot(t_fractol *f)
{
	int		n;
	double	tmp;
	int		max_iterations;
	int		final_color;

	n = 0;
	max_iterations = get_max_iterations(f);
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = f->min_x + (f->max_x - f->min_x) * ((double)f->x / WIDTH);
	f->cy = f->min_y + (f->max_y - f->min_y) * ((double)f->y / HEIGHT);
	while (n < max_iterations)
	{
		if (f->zx * f->zx + f->zy * f->zy > 4.0)
			break ;
		tmp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = 2.0 * f->zx * f->zy + f->cy;
		f->zx = tmp;
		n ++;
	}
	if (n == max_iterations)
		mlx_put_pixel(f->img, f->x, f->y, 0x000000);
	else
	{
		final_color = get_color_from_palette(f, n, max_iterations);
		mlx_put_pixel(f->img, f->x, f->y, final_color);
	}
}

int	fct_draw_fractal(t_fractol *f)
{
	f->x = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			if (ft_strcmp(f->name, "mandelbrot") == 0)
				calculate_mandelbrot(f);
			else
			{
				ft_putstr_fd("Available fractals: mandelbrot, julia", 2);
				exit(EXIT_FAILURE);
			}
			f->y ++;
		}
		f->x ++;
	}
	mlx_image_to_window(f->mlx, f->img, 0, 0);
	return (0);
}
