/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:44:10 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/10 14:20:24 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

void	fct_set_julia_pattern(t_fractol *f, char *pattern)
{
	int	i;

	f->patterns[0] = (t_pattern){"pattern_1", 0.279, 0.00};
	f->patterns[1] = (t_pattern){"pattern_2", -0.8, 0.156};
	f->patterns[2] = (t_pattern){"pattern_3", -0.70176, 0.6506};
	f->patterns[3] = (t_pattern){"pattern_4", 0.285, 0.01};
	f->patterns[4] = (t_pattern){"pattern_5", 0.279, 0.0};
	f->patterns[5] = (t_pattern){"pattern_6", -0.4, 0.6};
	f->patterns[6] = (t_pattern){"pattern_7", 0.355, 0.355};
	i = 0;
	while (i < 7)
	{
		if (ft_strcmp(pattern, f->patterns[i].name) == 0)
		{
			f->cx = f->patterns[i].cx;
			f->cy = f->patterns[i].cy;
			f->pattern_index = i;
			return;
		}
		i ++;
	}
	fct_free_fractol(f);
	exit(EXIT_FAILURE);
}

void	fct_init_julia(t_fractol *f, char *pattern)
{
	f->name = "julia";
	fct_set_julia_pattern(f, pattern);
	f->min_x = -1.5;
	f->max_x = 1.5;
	f->min_y = -1.5; 
	f->max_y = 1.5;
	f->offset_x = 0.0;
	f->offset_y = 0;
	f->palettes[0].colors[0] = (t_color){3, 47, 254};   // Azul eléctrico (intensificado)
	f->palettes[0].colors[1] = (t_color){255, 230, 0};   // Amarillo brillante (intensificado)
	f->palettes[0].colors[2] = (t_color){0, 255, 41};    // Verde neón (intensificado)
	f->palettes[0].colors[3] = (t_color){255, 137, 0}; 
	f->palettes[1].colors[0] = (t_color){255, 0, 128};   // Rosa fucsia
	f->palettes[1].colors[1] = (t_color){0, 255, 128};   // Verde menta neón
	f->palettes[1].colors[2] = (t_color){128, 0, 255};   // Púrpura eléctrico
	f->palettes[1].colors[3] = (t_color){255, 128, 0};
	f->palettes[2].colors[0] = (t_color){0, 255, 215};   // Turquesa neón (intensificado)
	f->palettes[2].colors[1] = (t_color){83, 0, 176};   // Púrpura eléctrico (intensificado)
	f->palettes[2].colors[2] = (t_color){255, 0, 57};    // Rojo neón (intensificado)
	f->palettes[2].colors[3] = (t_color){255, 101, 255};
	f->palette_index = 0;
	f->color_index = 0;
}

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
	f->final_color = fct_color_from_palette(f, n, max_iterations);
	mlx_put_pixel(f->img, f->x, f->y, f->final_color);
}
