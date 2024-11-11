/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:39:48 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/11 17:39:51 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/*Zooms in on a fractal, centering on the mouse position.
	- Gets the current mouse position in the window.
	- Converts the mouse coordinates to corresponding coordinates
	in the complex plane (mouse_cx, mouse_cy).
	- Adjusts the visible area (min_x, max_x, min_y, max_y)
	of the fractal based on the mouse position and zoom factor.
	- Redraws the fractal.
*/
void	fct_zoom(t_fractol *f, double zoom_factor)
{
	int32_t	mouse_x;
	int32_t	mouse_y;
	double	mouse_cx;
	double	mouse_cy;

	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	mouse_cx = f->min_x + (f->max_x - f->min_x) * (mouse_x / (double)WIDTH);
	mouse_cy = f->min_y + (f->max_y - f->min_y) * (mouse_y / (double)HEIGHT);
	f->min_x = mouse_cx - (mouse_cx - f->min_x) / zoom_factor;
	f->max_x = mouse_cx + (f->max_x - mouse_cx) / zoom_factor;
	f->min_y = mouse_cy - (mouse_cy - f->min_y) / zoom_factor;
	f->max_y = mouse_cy + (f->max_y - mouse_cy) / zoom_factor;
	fct_draw_fractal(f);
}

/*Selects the next palette of colors*/
void	fct_change_color(t_fractol *f)
{
	f->palette_index = (f->palette_index + 1) % 3;
	ft_printf("showing palette num: %i\n", f->palette_index);
	fct_draw_fractal(f);
}

/*Selects the next pattern from the Julia set*/
void	fct_change_julia(t_fractol *f)
{
	f->pattern_index = (f->pattern_index + 1) % 7;
	fct_set_julia_pattern(f, f->patterns[f->pattern_index].name);
	ft_printf("showing %s\n", f->patterns[f->pattern_index].name);
	fct_draw_fractal(f);
}
