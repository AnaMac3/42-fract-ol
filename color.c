/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:14:52 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/10 14:19:16 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int32_t fct_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

/*Calculates the max num of iterations for each point
	- max_x and min_x represent the limits of the visible area on the
	real axis (x) of the fractal
	- x_range: real value range
*/
int	fct_max_iterations(t_fractol *f)
{
	int		max_iter;
	double	x_range;

	x_range = f->max_x - f->min_x;
	max_iter = BASE_ITER + ITER_INCREMENT *(int)log2(2.0 / x_range);
	return (max_iter);
}

/*Calculates a color from the current palette based on the number of
iterations.
	- Interpolates between two colors in the palette based on the 
	progress of the iteration, doing (current iteraton) / max_iterations
	- f->color_index determines the color range in the palette to use
	for the interpolation
	- the final color is calculated using linear interpolation between
	two consecutive colors of the palette
	- the result is returned as a pixel color
*/
int	fct_color_from_palette(t_fractol *f, int n, int max_iterations)
{
	t_color		*start;
	t_color		*end;
	t_color		color;
	float		t;

	t = (float)n / (float)max_iterations;
	f->color_index = (int)(t * 4);
	start = &f->palettes[f->palette_index].colors[f->color_index];
	end = &f->palettes[f->palette_index].colors[f->color_index + 1];
	color.r = (int)(start->r + (end->r - start->r) * (t * 4 - f->color_index));
	color.g = (int)(start->g + (end->g - start->g) * (t * 4 - f->color_index));
	color.b = (int)(start->b + (end->b - start->b) * (t * 4 - f->color_index));
	return (fct_pixel(color.r, color.g, color.b, 255));
}