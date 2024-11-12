/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:44:10 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/11 19:44:54 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/*Sets julia default patterns*/
void	fct_pred_julia_patterns(t_fractol *f)
{
	f->patterns[0] = (t_pattern){"pattern_1", 0.279, 0.00};
	f->patterns[1] = (t_pattern){"pattern_2", -0.8, 0.156};
	f->patterns[2] = (t_pattern){"pattern_3", -0.70176, 0.6506};
	f->patterns[3] = (t_pattern){"pattern_4", 0.285, 0.01};
	f->patterns[4] = (t_pattern){"pattern_5", -0.70176, 0.3504};
	f->patterns[5] = (t_pattern){"pattern_6", -0.4, 0.6};
	f->patterns[6] = (t_pattern){"pattern_7", 0.355, 0.355};
}

/*Sets the values of the Julia set constans (cx, cy) based on the selected
pattern.
	- With "pattern_f", c values will change dynamically when user clicks on
	a point in the window
	- For all other patterns, cx and cy are set to predefined constants
*/
void	fct_set_julia_pattern(t_fractol *f, char *pattern)
{
	int	i;

	if (ft_strcmp(pattern, "pattern_f") == 0)
	{
		f->patterns[0] = (t_pattern){"pattern_f", 0, 0};
		ft_printf("Press Ctrl and click a point in the window\n");
		f->cx = 0;
		f->cy = 0;
		return ;
	}
	fct_pred_julia_patterns(f);
	i = 0;
	while (i < 7)
	{
		if (ft_strcmp(pattern, f->patterns[i].name) == 0)
		{
			f->cx = f->patterns[i].cx;
			f->cy = f->patterns[i].cy;
			f->pattern_index = i;
			return ;
		}
		i ++;
	}
	fct_clean_fractol(f);
	exit(EXIT_FAILURE);
}

/*Initialize the values for Julia set in fractol structure*/
void	fct_init_julia(t_fractol *f, char *pattern)
{
	f->name = "julia";
	f->min_x = -1.5;
	f->max_x = 1.5;
	f->min_y = -1.5;
	f->max_y = 1.5;
	f->offset_x = 0.0;
	f->offset_y = 0;
	fct_set_julia_pattern(f, pattern);
	f->palettes[0].colors[0] = (t_color){3, 47, 254};
	f->palettes[0].colors[1] = (t_color){255, 230, 0};
	f->palettes[0].colors[2] = (t_color){0, 255, 41};
	f->palettes[0].colors[3] = (t_color){255, 137, 0};
	f->palettes[1].colors[0] = (t_color){255, 0, 128};
	f->palettes[1].colors[1] = (t_color){0, 255, 128};
	f->palettes[1].colors[2] = (t_color){128, 0, 255};
	f->palettes[1].colors[3] = (t_color){255, 128, 0};
	f->palettes[2].colors[0] = (t_color){0, 255, 215};
	f->palettes[2].colors[1] = (t_color){83, 0, 176};
	f->palettes[2].colors[2] = (t_color){255, 0, 57};
	f->palettes[2].colors[3] = (t_color){255, 101, 255};
	f->palette_index = 0;
	f->color_index = 0;
}

/*Computes and visualizes the Julia set for the current pixel.
	- Calculates the max num of iterations
	- Sets zx and zy to the complex coordinates corresponding to
	the current pixel
	- Iterates the funcion zn+1 = zn^2 + c to check if a point belongs to set.
	- If the point escapes (zx^2 + zy^2 > 4), it is colored based on the number
	of iterations.
	- If the point stays within the set (does not escape), it is colored black.
	- Determines the number of iterations before the point diverges (tends to
	infinity)
	- Sets the pixel color based on the number of iterations 
*/
void	fct_julia(t_fractol *f)
{
	int		n;
	double	tmp;
	int		max_iterations;

	n = 0;
	max_iterations = fct_max_iterations(f);
	f->zx = f->min_x + (f->max_x - f->min_x) * ((double)f->x / WIDTH);
	f->zy = f->min_y + (f->max_y - f->min_y) * ((double)f->y / HEIGHT);
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
		if (ft_strcmp(f->patterns[0].name, "pattern_f") == 0)
			mlx_mouse_hook(f->mlx, fct_click, (void *)f);
		mlx_put_pixel(f->img, f->x, f->y, f->final_color);
	}
}
