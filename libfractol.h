/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:17:58 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/10 14:26:23 by amacarul         ###   ########.fr       */
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
} t_palette;

typedef struct	s_pattern
{
	char	*name;
	double	cx;
	double	cy;
}	t_pattern;

typedef struct  s_fractol
{
	mlx_t   *mlx;
	mlx_image_t *img;
	char	*name;
	double	zoom_level; //controla nivel de zoom
	double	offset_x; //valores que se utilizan para desplazar la vista del fractal en el espacio gráfico
	double	offset_y;
	double	x;//valores del espacio de visualización, representan las coordenadas en pixeles de la imagen
	double	y;
	double	zx; //componente real de la secuencia de numeros complejos
	double	zy; //componente imaginaria de la secuencia de numeros complejos
	double	cx;//coordenadas complejas del punto en el cnjunto de mandelbrot correspondiente a x en la imagen
	double	cy;//coordenadas complejas del punto en el cnjunto de mandelbrot correspondiente a x en la imagen
	double	min_x; //limite minimo del eje real, representado en x
	double	max_x; //limite maximo del eje real
	double	min_y; //limite minimo del eje imaginario
	double	max_y; // limite maximo del eje imaginario
	t_palette	palettes[3];
	int		palette_index;
	int		color_index;
	int		final_color;
	int		total_colors;
	t_pattern	patterns[7];
	int		pattern_index; //para patrón de julia
} t_fractol;

//main.c
void	fct_help_msg(void);
void	fct_free_fractol(t_fractol *f);
void	fct_init_fractol(t_fractol *f, char	**argv);
int		fct_check_args(int argc, char **argv);
int		main(int argc, char **argv);

//draw.c
int	fct_draw_fractal(t_fractol *f);

//color.c
int32_t fct_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
int	fct_max_iterations(t_fractol *f);
int	fct_color_from_palette(t_fractol *f, int n, int max_iterations);

//mandelbrot.c
void	fct_init_mandelbrot(t_fractol *f);
void	fct_mandelbrot(t_fractol *f);

//julia.c
void	fct_set_julia_pattern(t_fractol *f, char *pattern);
void	fct_init_julia(t_fractol *f, char *pattern);
void	fct_julia(t_fractol *f);

//events.c
void	fct_zoom(t_fractol *f, double zoom_factor);
void	fct_change_color(t_fractol *f);
void	fct_change_julia(t_fractol *f);
void	fct_key_event(mlx_key_data_t data, void *param);
void	fct_mouse_scroll(double xdelta, double ydelta, void *param);

#endif