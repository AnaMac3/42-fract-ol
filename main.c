/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:11:33 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/12 11:09:56 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/*Clean fractol structure*/
void	fct_clean_fractol(t_fractol *f)
{
	if (!f)
		return ;
	if (f->img)
	{
		mlx_delete_image(f->mlx, f->img);
		f->img = NULL;
	}
	if (f->mlx)
	{
		mlx_terminate(f->mlx);
		f->mlx = NULL;
	}
}

/*Display help message*/
void	fct_help_msg(void)
{
	ft_putstr_fd("Usage: ./fractol fractal_type julia_pattern\n\n", 1);
	ft_putstr_fd("fractal_type:\n - 'mandelbrot'\n - 'julia'\n", 1);
	ft_putstr_fd(" - 'burning_ship'\n\n", 1);
	ft_putstr_fd("julia_pattern (only if fractal_type == 'julia'):\n", 1);
	ft_putstr_fd(" - 'pattern_f' for c = mouse position when click\n", 1);
	ft_putstr_fd(" - 'pattern_1' for c = 0.279\n", 1);
	ft_putstr_fd(" - 'pattern_2' for c = 0.8, 0.156i\n", 1);
	ft_putstr_fd(" - 'pattern_3' for c = -0.70176, 0.6506i\n", 1);
	ft_putstr_fd(" - 'pattern_4' for c = 0.285, 0.01i\n", 1);
	ft_putstr_fd(" - 'pattern_5' for c =  0.279, 0.0i\n", 1);
	ft_putstr_fd(" - 'pattern_6' for c = -0.4, 0.6i\n", 1);
	ft_putstr_fd(" - 'pattern_7' for c = 0.355, 0.355i\n", 1);
}

/*Initialize the fractol structure*/
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
		fct_init_mandelbrot(f);
	else if (ft_strcmp(argv[1], "julia") == 0)
		fct_init_julia(f, argv[2]);
	else if (ft_strcmp(argv[1], "burning_ship") == 0)
		fct_init_burning_ship(f);
}

/*Checks the program arguments*/
int	fct_check_args(int argc, char **argv)
{
	int	error;

	error = 0;
	if (argc < 2 || argc > 3)
		error = 1;
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc != 3 || ft_strlen(argv[2]) != 9)
			error = 1;
		else if (ft_strncmp(argv[2], "pattern_", 8) != 0)
			error = 1;
		else if ((argv[2][8] < '1' || argv[2][8] > '7') && argv[2][8] != 'f')
			error = 1;
	}
	else if (ft_strcmp(argv[1], "mandelbrot") != 0 || argc != 2)
	{
		if (ft_strcmp(argv[1], "burning_ship") != 0)
			error = 1;
	}
	if (error == 1)
	{
		fct_help_msg();
		return (-1);
	}
	return (0);
}

/*Main function:
	- Checks arguments
	- Initializes the fractol structure
	- Sets up the key hook to handle keyboard events
	- Sets up the scrool hook to handle mouse scroll events
	- Draws the fractal
	- Enters the main loop to keep the window open and responsive
	to events
	- Cleans the fractol structure
	- Exits the program successully*/
int	main(int argc, char **argv)
{
	t_fractol	f;

	if (fct_check_args(argc, argv) < 0)
		exit(EXIT_FAILURE);
	fct_init_fractol(&f, argv);
	mlx_key_hook(f.mlx, fct_key_event, (void *)&f);
	mlx_scroll_hook(f.mlx, fct_mouse_scroll, (void *)&f);
	fct_draw_fractal(&f);
	mlx_loop(f.mlx);
	fct_clean_fractol(&f);
	exit (EXIT_SUCCESS);
}
