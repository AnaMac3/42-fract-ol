/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:39:06 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/10 17:12:23 by amacarul         ###   ########.fr       */
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

void	fct_change_julia(t_fractol *f)
{
	f->pattern_index = (f->pattern_index + 1) % 7;
	fct_set_julia_pattern(f, f->patterns[f->pattern_index].name);
	ft_printf("showing %s\n", f->patterns[f->pattern_index].name);
	fct_draw_fractal(f);
	
}

/*Callback for mlx_key_hook, for handling key events.
	- closes the window when ESC key is pressed
	- zooms in or out when + or - keys are pressed
	- changes the color palette when SPACE key is pressed
*/
void	fct_key_event(mlx_key_data_t data, void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	if (data.key == MLX_KEY_ESCAPE && data.action == MLX_PRESS)
		mlx_close_window(f->mlx);
	else if (data.key == MLX_KEY_KP_ADD && data.action == MLX_PRESS)
		fct_zoom(f, 1.1);
	else if (data.key == MLX_KEY_KP_SUBTRACT && data.action == MLX_PRESS)
		fct_zoom(f, 0.9);
	else if (data.key == MLX_KEY_SPACE && data.action == MLX_PRESS)
		fct_change_color(f);
	else if (data.key == MLX_KEY_ENTER && data.action == MLX_PRESS)
	{
		if (ft_strcmp(f->name, "julia") == 0)
		{
			if (ft_strcmp( f->patterns[0].name, "pattern_f"))
				fct_change_julia(f);
		}
	}
}

/*Callback for mlx_scroll_hook, for handling mouse scroll.
	- zooms in when scrolling up (ydelta > 0)
	- zooms out when scrolling down (ydelta < 0)
*/
void	fct_mouse_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	if (ydelta > 0)
		fct_zoom(f, 1.1);
	else if (ydelta < 0)
		fct_zoom(f, 0.9);
	if (xdelta > 0)
		ft_printf("dcha\n");
	else if (xdelta < 0)
		ft_printf("izq\n");
	ft_printf("cx = %d\ncy = %d\n", f->cx, f->cy);
}

/*Callback for mlx_mouse_hook*/
void	fct_mouse_click(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_fractol	*f;
	int32_t	mouse_x;
	int32_t	mouse_y;
	
	f = (t_fractol *)param;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		if (mods & MLX_CONTROL)
		{
			mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
			f->cx = (mouse_x / (double)WIDTH) * (f->max_x - f->min_x) + f->min_x;
			f->cy = (mouse_y / (double)HEIGHT) * (f->max_y - f->min_y) + f->min_y;
			fct_draw_fractal(f);
		}
		/*mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
		f->cx = (mouse_x / (double)WIDTH) * (f->max_x - f->min_x) + f->min_x;
		f->cy = (mouse_y / (double)HEIGHT) * (f->max_y - f->min_y) + f->min_y;
		if (mods & MLX_CONTROL)
			fct_draw_fractal(f);*/
	}
}
