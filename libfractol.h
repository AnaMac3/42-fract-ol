/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:17:58 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/08 19:09:57 by amacarul         ###   ########.fr       */
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
# define BASE_ITER 90
# define ITER_INCREMENT 10
# define MAX_ZOOM 10000
# define MIN_ZOOM 1

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct	s_palette
{
	t_color	colors[4]; //paletas de 5 colores
} t_palette;

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
	//int		colors[3];
	//t_color color[3];
	int		current_palette;
	int		color_index;
} t_fractol;

//main.c
void	ft_error(void);
int		main(int argc, char **argv);

//pcreate_img.c
int32_t fct_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	fct_fill_image_with_color(mlx_image_t *img, int32_t r, int32_t g, int32_t b);
void	fct_put_img(t_fractol *f);
void	fct_resize_callback(int32_t width, int32_t height, void *param);

//fct_julia.c
void	calculate_mandelbrot(t_fractol *f);
int		fct_draw_fractal(t_fractol *f);

//hook_prueba.c
void	ft_keyhook(void* param, mlx_image_t *image);
void	ft_scrollhook(double ydelta,  mlx_image_t *image, mlx_t	*mlx);

//events.c
void	fct_key_event(mlx_key_data_t data, void *param);
void	fct_mouse_scroll(double xdelta, double ydelta, void* param);

#endif