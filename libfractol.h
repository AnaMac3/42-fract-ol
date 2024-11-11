/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:17:58 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/11 19:19:27 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFRACTOL_H
# define LIBFRACTOL_H
# include "my_libft/libft.h"
# include <MLX42.h>
# include <stdio.h>
# include <string.h>
# include <math.h> 

# include <stdlib.h>
# include <stdbool.h>

# define WIDTH 1000
# define HEIGHT 1000
# define BASE_ITER 80
# define ITER_INCREMENT 10
# define MAX_ZOOM 10000
# define MIN_ZOOM 1

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_palette
{
	t_color	colors[4];
}	t_palette;

typedef struct s_pattern
{
	char	*name;
	double	cx;
	double	cy;
}	t_pattern;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		*name;
	double		offset_x;
	double		offset_y;
	double		x;
	double		y;
	double		zx;
	double		zy;
	double		cx;
	double		cy;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	t_palette	palettes[3];
	int			palette_index;
	int			color_index;
	int			final_color;
	int			total_colors;
	t_pattern	patterns[7];
	int			pattern_index;
}	t_fractol;

//main.c
void	fct_help_msg(void);
void	fct_clean_fractol(t_fractol *f);
void	fct_init_fractol(t_fractol *f, char	**argv);
int		fct_check_args(int argc, char **argv);
int		main(int argc, char **argv);

//draw.c
int		fct_draw_fractal(t_fractol *f);

//color.c
int32_t	fct_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
int		fct_max_iterations(t_fractol *f);
int		fct_color_from_palette(t_fractol *f, int n, int max_iterations);

//mandelbrot.c
void	fct_init_mandelbrot(t_fractol *f);
void	fct_mandelbrot(t_fractol *f);

//julia.c
void	fct_pred_julia_patterns(t_fractol *f);
void	fct_set_julia_pattern(t_fractol *f, char *pattern);
void	fct_init_julia(t_fractol *f, char *pattern);
void	fct_julia(t_fractol *f);

//burning_ship.c
void	fct_init_burning_ship(t_fractol *f);
void	fct_burning_ship(t_fractol *f);

//events.c
void	fct_key_event(mlx_key_data_t data, void *param);
void	fct_mouse_scroll(double xdelta, double ydelta, void *param);
void	fct_click(mouse_key_t but, action_t act, modifier_key_t mds, void *p);

//events_2.c
void	fct_zoom(t_fractol *f, double zoom_factor);
void	fct_change_color(t_fractol *f);
void	fct_change_julia(t_fractol *f);

#endif