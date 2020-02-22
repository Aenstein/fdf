/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:42:58 by aenstein          #+#    #+#             */
/*   Updated: 2020/02/17 22:54:15 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_fdf *data, int x, int y, int color)
{
	int i;

	if (x >= MENU_WIDTH && x < WIDTH && y >=0 && y < HEIGHT)
	{
		i = (x * data->bits_per_pixel / 8) + (y * data->size_line); 
		data->data_addr[i] = color;
		data->data_addr[++i] = color >> 8;
		data->data_addr[++i] = color >> 16;
	}
}

void	draw_background(t_fdf *data)
{
	int	*image;
	int	i;

	ft_bzero(data->data_addr, WIDTH * HEIGHT * (data->bits_per_pixel / 8));
	image = (int *)(data->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		image[i] = (i % WIDTH < MENU_WIDTH) ? MENU_BACK : BACK;
		i++;
	}
}

void	iso(float *x, float *y, float z, t_fdf *data)
{
	int		p_x;
	int		p_y;

	p_x = *x;
	p_y = *y;
	*x = (p_x - p_y) * cos(0.523599);
	*y = (p_x + p_y) * sin(0.523599) - z / mod(data->z_projection);
}

void	parallel(float *x, float *y, float z, t_fdf *data)
{
	int		p_x;
	int		p_y;

	p_x = *x;
	p_y = *y;
	*x = p_x - z / mod(data->z_projection);
	*y = p_y - z / mod(data->z_projection);
}

void	connect(t_point start, t_point end, t_fdf *data)
{
	t_step	step;

	data->color = color(data, start.z, end.z);
	if (data->projection == 1)
		iso(&start.x, &start.y, start.z, data);
	else
		parallel(&start.x, &start.y, start.z, data);
	if (data->projection == 1)
		iso(&end.x, &end.y, end.z, data);
	else
		parallel(&end.x, &end.y, end.z, data);
	zoomstart(&start.x, &start.y, data);
	zoomstart(&end.x, &end.y, data);
	shiftstart(&start.x, &end.x, data->shift_x);
	shiftstart(&start.y, &end.y, data->shift_y);
	steps(&step.x_step, &step.y_step, start, end);
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		pixel_put(data, (int)start.x, (int)start.y, data->color);
		start.x += step.x_step;
		start.y += step.y_step;
	}
}

void	draw_map(t_fdf *data)
{
	int		x;
	int		y;

	draw_background(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				connect(create_point(x, y, data), create_point(x + 1, y, data),
					data);
			if (y < data->height - 1)
				connect(create_point(x, y, data), create_point(x, y + 1, data),
					data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	print_menu(data);
}
