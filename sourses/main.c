/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:08:33 by aenstein          #+#    #+#             */
/*   Updated: 2020/02/24 19:30:57 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, t_fdf *data)
{
	if (key == 0 || key == 2 || key == 13 || key == 1)
		shif(key, data);
	if (key == 69 || key == 78)
		zoom(key, data);
	if (key == 25 || key == 29 || key == 86 || key == 83 || key == 84 || key \
	== 85 || key == 88 || key == 89 || key == 91 || key == 92)
		rotate(key, data);
	if (key == 18)
		data->color_num = 1;
	if (key == 19)
		data->color_num = 2;
	if (key == 20)
		data->color_num = 3;
	if (key == 12)
		data->rotation->z_projection += 1;
	if (key == 14 && (data->rotation->z_projection - 1) != 0)
		data->rotation->z_projection -= 1;
	if (key == 53)
		exit(0);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_map(data);
	return (0);
}

int		mouse_press(int but, int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	if (but == 4 || but == 5)
		zoom(but, data);
	if (but == 1)
		data->mouse->is_pressed = true;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_map(data);
	return (0);
}

int		mouse_release(int but, int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	(void)but;
	data->mouse->is_pressed = false;
	return (0);
}

int		mouse_move(int x, int y, t_fdf *data)
{
	data->mouse->previous_x = data->mouse->x;
	data->mouse->previous_y = data->mouse->y;
	data->mouse->x = x;
	data->mouse->y = y;
	if (data->mouse->is_pressed == 1)
	{
		if (data->mouse->x > data->mouse->previous_x)
			data->shift_x += 7;
		if (data->mouse->x < data->mouse->previous_x)
			data->shift_x -= 7;
		if (data->mouse->y > data->mouse->previous_y)
			data->shift_y += 6;
		if (data->mouse->y < data->mouse->previous_y)
			data->shift_y -= 6;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_map(data);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_fdf	data[1];
	t_mouse	mouse[1];
	t_rot	rotate[1];

	if (ac == 2)
	{
		init(data, mouse, rotate);
		read_file(av[1], data);
		fdf_init(data);
		mlx_hook(data->win_ptr, 2, 0, key_press, data);
		mlx_hook(data->win_ptr, 4, 0, mouse_press, data);
		mlx_hook(data->win_ptr, 5, 0, mouse_release, data);
		mlx_hook(data->win_ptr, 6, 0, mouse_move, data);
		draw_map(data);
		mlx_loop(data->mlx_ptr);
	}
	else
		error_write(ERR_USAAGE);
	return (0);
}
