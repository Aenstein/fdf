/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaland <bshaland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:42:58 by aenstein          #+#    #+#             */
/*   Updated: 2020/02/23 17:07:57 by bshaland         ###   ########.fr       */
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

void	connect(t_point start, t_point end, t_fdf *data)
{
	t_step	step;
	t_point cur;

	data->color = color(data, start.z, end.z);
	zoomstart(&start.x, &start.y, data);
	zoomstart(&end.x, &end.y, data);
	shiftstart(&start.x, &end.x, data->shift_x);
	shiftstart(&start.y, &end.y, data->shift_y);
	printf("%f\n", start.x);
	steps(&step.x_step, &step.y_step, start, end);
	cur = start;
	while ((int)(cur.x - end.x) || (int)(cur.y - end.y))
	{
		pixel_put(data, (int)cur.x, (int)cur.y, get_color(cur, start, end, step));
		cur.x += step.x_step;
		cur.y += step.y_step;
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
