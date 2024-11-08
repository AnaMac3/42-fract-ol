/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:48:18 by amacarul          #+#    #+#             */
/*   Updated: 2024/11/08 18:33:27 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

//Encodes four individual bytes into a int
int32_t fct_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	fct_put_img(t_fractol *f)
{
	uint32_t	square_size;
	uint32_t	square_x;
	uint32_t	square_y;
	uint32_t	x;
	uint32_t	y;
	
	
	square_size = (int) (WIDTH * f->zoom_level);
	square_x = f->offset_x + (WIDTH - square_size) / 2;
	square_y = f->offset_y - (HEIGHT - square_size) / 2;
	x = 0;
	while (x < f->img->width)
	{
		y = 0;
		while(y < f->img->height)
		{
			mlx_put_pixel(f->img, x, y, fct_pixel(0, 0, 0, 225));
			y ++;
		}
		x ++;
	}
	x = 0;
	while (x < square_size)
	{
		y = 0;
		while (y < square_size)
		{
			if ((square_x + x) >= 0 && (square_x + x) < f->img->width && (square_y + y) < f->img->height)
				mlx_put_pixel(f->img,  square_x + x, square_y + y, fct_pixel(255, 0, 0, 255));
			y ++;
		}
		x ++;
	}
	mlx_image_to_window(f->mlx, f->img, 0, 0);
}

