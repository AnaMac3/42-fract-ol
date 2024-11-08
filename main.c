/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:11:33 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/08 19:20:44 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

//imprime mensaje error en stderr usando mlx_streror(mlx_errno),
//que convierte un codigo error en una cadena de caracteres legibles.
//deberia usar perror o strerror, porque fprintf no puedo usar.
void	ft_error(void)
{
	ft_putstr_fd(strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}

void	fct_help_msg(void)
{
	ft_putstr_fd("Please, select a fractal type:\n", 1);
	ft_putstr_fd("For Julia, write 'julia'\n", 1);
	ft_putstr_fd("For Mandelbrot, write 'mandelbrot'\n", 1);
	exit(EXIT_FAILURE);
}

void	init_mandelbrot(t_fractol *f)
{
	f->name = "mandelbrot";
	f->zoom_level = 300;
	f->min_x = -2.0;
	f->max_x = 1.0;
	f->min_y = -1.5;
	f->max_y = 1.5;
	f->offset_x = -0.5;
	f->offset_y = 0;
	f->palettes[0].colors[0] = (t_color){255, 20, 147};
	f->palettes[0].colors[1] = (t_color){50, 205, 50};
	f->palettes[0].colors[2] = (t_color){0, 191, 255};
	f->palettes[0].colors[3] = (t_color){255, 255, 0};
	f->palettes[1].colors[0] = (t_color){255, 102, 0};
	f->palettes[1].colors[1] = (t_color){138, 43, 226};
	f->palettes[1].colors[2] = (t_color){0, 255, 255};
	f->palettes[1].colors[3] = (t_color){255, 0, 102};
	f->palettes[2].colors[0] = (t_color){20, 244, 215};
	f->palettes[2].colors[1] = (t_color){30, 21, 226}; 
	f->palettes[2].colors[2] = (t_color){244, 21, 57};
	f->palettes[2].colors[3] = (t_color){187, 101, 222};
	f->current_palette = 0;
	f->color_index = 0;
}

void	init_julia(t_fractol *f)
{
	f->name = "julia";
	//AQUI A VER QUÉ HAY QUE PONER
	//
	//
	f->zoom_level = 300;
	f->min_x = -2.0;
	f->max_x = 1.0;
	f->min_y = -1.5;
	f->max_y = 1.5;
	f->offset_x = -0.5;
	f->offset_y = 0;
	f->palettes[0].colors[0] = (t_color){255, 20, 147};
	f->palettes[0].colors[1] = (t_color){50, 205, 50};
	f->palettes[0].colors[2] = (t_color){0, 191, 255};
	f->palettes[0].colors[3] = (t_color){255, 255, 0};
	f->palettes[1].colors[0] = (t_color){255, 102, 0};
	f->palettes[1].colors[1] = (t_color){138, 43, 226};
	f->palettes[1].colors[2] = (t_color){0, 255, 255};
	f->palettes[1].colors[3] = (t_color){255, 0, 102};
	f->palettes[2].colors[0] = (t_color){20, 244, 215};
	f->palettes[2].colors[1] = (t_color){30, 21, 226}; 
	f->palettes[2].colors[2] = (t_color){244, 21, 57};
	f->palettes[2].colors[3] = (t_color){187, 101, 222};
	f->current_palette = 0;
	f->color_index = 0;
}

//Inicializar la estructura fractol
void	fct_init_fractol(t_fractol *f, char	**argv)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	if (!f->mlx)
		exit(EXIT_FAILURE);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
	{
		mlx_terminate(f->mlx);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		init_mandelbrot(f);
	else if (ft_strcmp(argv[1], "julia") == 0)
		init_julia(f);
}

//main de prueba
int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc < 2)
		fct_help_msg();
	if (ft_strcmp(argv[1], "julia") != 0)
	{
		if (ft_strcmp(argv[1], "mandelbrot") != 0)
			fct_help_msg();
	}
	fct_init_fractol(&f, argv);
	//renderizadp
	//fct_put_img(&f);
	//mlx_hook
	mlx_key_hook(f.mlx, fct_key_event, (void *)&f);
	mlx_scroll_hook(f.mlx, fct_mouse_scroll, (void *)&f);
	//mlx_resize_hook(f.mlx, fct_resize_callback, (void *)&f);
	fct_draw_fractal(&f);
	//Si f es una variable de tipo t_fractol en lugar de un puntero,
	//hay que acceder a sus miembros mediante . en vez de con ->
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (EXIT_SUCCESS);	
}
