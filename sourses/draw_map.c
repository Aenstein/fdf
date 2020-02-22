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
	t_z		z_coords;

	take_z(&z_coords, start, end, data);
	data->color = color(data, z_coords.z, z_coords.z1);
	if (data->projection == 1)
		iso(&start.x, &start.y, z_coords.z, data);
	else
		parallel(&start.x, &start.y, z_coords.z, data);
	if (data->projection == 1)
		iso(&end.x, &end.y, z_coords.z1, data);
	else
		parallel(&end.x, &end.y, z_coords.z1, data);
	zoomstart(&start.x, &start.y, data);
	zoomstart(&end.x, &end.y, data);
	shiftstart(&start.x, &end.x, data->shift_x);
	shiftstart(&start.y, &end.y, data->shift_y);
	steps(&step.x_step, &step.y_step, start, end);
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, (int)start.x,
				(int)start.y, data->color);
		start.x += step.x_step;
		start.y += step.y_step;
	}
}

void	draw_map(t_fdf *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				connect(create_point(x, y), create_point(x + 1, y), data);
			if (y < data->height - 1)
				connect(create_point(x, y), create_point(x, y + 1), data);
			x++;
		}
		y++;
	}
	print_menu(data);
}
