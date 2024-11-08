/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:39:06 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/08 19:23:24 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static void	zoom(t_fractol *f, double zoom_factor)
{
	int32_t	mouse_x;
	int32_t	mouse_y;
	double	mouse_r;
	double	mouse_i;

	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	mouse_r = f->min_x + (f->max_x - f->min_x) * (mouse_x / (double)WIDTH);
	mouse_i = f->min_y + (f->max_y - f->min_y) * (mouse_y / (double)HEIGHT);
	f->min_x = mouse_r - (mouse_r - f->min_x) / zoom_factor;
	f->max_x = mouse_r + (f->max_x - mouse_r) / zoom_factor;
	f->min_y = mouse_i - (mouse_i - f->min_y) / zoom_factor;
	f->max_y = mouse_i + (f->max_y - mouse_i) / zoom_factor;
	fct_draw_fractal(f);
}

static void	change_color(t_fractol *f)
{
	f->current_palette = (f->current_palette + 1) % 3;
	fct_draw_fractal(f);
}

void	fct_key_event(mlx_key_data_t data, void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	if (data.key == MLX_KEY_ESCAPE)
		mlx_close_window(f->mlx);//ver que habrá que cerrar más cosas o limpiarlas
	else if (data.key == MLX_KEY_KP_ADD)
		zoom(f, 2);
	else if (data.key == MLX_KEY_KP_SUBTRACT)
		zoom(f, 0.5);
	/*else if (data.key == MLX_KEY_UP ||data.key == MLX_KEY_W)
		ft_printf("Aquí habría que moverse arriba\n");
	else if (data.key == MLX_KEY_DOWN || data.key ==  MLX_KEY_S)
		ft_printf("Aquí habría que moverse abajo\n");
	else if (data.key == MLX_KEY_LEFT || data.key == MLX_KEY_A)
		ft_printf("Aquí habría que moverse a la izq\n");
	else if (data.key == MLX_KEY_RIGHT || data.key == MLX_KEY_D)
		ft_printf("Aquí habría que moverse a la dcha\n");*/
	else if (data.key == MLX_KEY_SPACE)
		change_color(f);
}

void	fct_mouse_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	if (ydelta > 0)
		zoom(f, 1.1);
	else if (ydelta < 0)
		zoom(f, 0.9);
	if (xdelta > 0)
		ft_printf("Scroll para la derecha\n");
	else if (xdelta < 0)
		ft_printf("Scroll para la izquierda\n");
}
