/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:39:06 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/11 17:48:24 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

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
			if (ft_strcmp(f->patterns[0].name, "pattern_f"))
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
}

/*Callback for mlx_mouse_hook*/
void	fct_click(mouse_key_t but, action_t act, modifier_key_t mds, void *p)
{
	t_fractol	*f;
	int32_t		xpos;
	int32_t		ypos;

	f = (t_fractol *)p;
	if (but == MLX_MOUSE_BUTTON_LEFT && act == MLX_PRESS)
	{
		if (mds & MLX_CONTROL)
		{
			mlx_get_mouse_pos(f->mlx, &xpos, &ypos);
			f->cx = (xpos / (double)WIDTH) * (f->max_x - f->min_x) + f->min_x;
			f->cy = (ypos / (double)HEIGHT) * (f->max_y - f->min_y) + f->min_y;
			fct_draw_fractal(f);
		}
	}
}
