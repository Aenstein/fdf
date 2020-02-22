/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:05:48 by aenstein          #+#    #+#             */
/*   Updated: 2020/02/17 23:03:34 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	maxf(float a, float b)
{
	return (a > b ? a : b);
}

float	mod(float a)
{
	return ((a < 0) ? -a : a);
}

float	min(float a, float b)
{
	return (a < b ? a : b);
}

void	init(t_fdf *data, t_mouse *mouse)
{
	data->width = 0;
	data->height = 0;
	data->zoom = 0;
	data->color = 0;
	data->z_coord = NULL;
	data->shift_x = 0;
	data->shift_y = 0;
	data->projection = 0;
	data->z_projection = 0;
	data->color_num = 0;
	data->data_addr = NULL;
	mouse->is_pressed = false;
	mouse->x = 0;
	mouse->y = 0;
	mouse->previous_x = 0;
	mouse->previous_y = 0;
	data->mouse = mouse;
}

void	fdf_init(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->data_addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
		&(data->size_line), &(data->endian));
	data->shift_x = WIDTH / 2.5;
	data->shift_y = HEIGHT / 2.5;
	data->projection = 1;
	data->color_num = 1;
	data->z_projection = 1;
	data->zoom = min((((WIDTH - MENU_WIDTH) / data->width) / 2.5),
			((HEIGHT / data->height)) / 2.5);
	if (data->zoom == 0)
		data->zoom = 1;
}
