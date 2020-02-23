/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaland <bshaland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:49:58 by aenstein          #+#    #+#             */
/*   Updated: 2020/02/23 20:29:20 by bshaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	steps(float *x_step, float *y_step, t_point start, t_point end)
{
	int		max;
	float	tmpx;
	float	tmpy;

	*x_step = end.x - start.x;
	*y_step = end.y - start.y;
	tmpx = *x_step;
	tmpy = *y_step;
	max = maxf(mod(tmpx), mod(tmpy));
	*x_step /= max;
	*y_step /= max;
}

void	z_heigt(t_fdf *data)
{
	int		x;
	int		y;

	y = 0;
	data->max_z = data->z_coord[0][0];
	data->min_z = data->z_coord[0][0];
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->max_z < data->z_coord[y][x])
				data->max_z = data->z_coord[y][x];
			if (data->min_z > data->z_coord[y][x])
				data->min_z = data->z_coord[y][x];
			x++;
		}
		y++;
	}
}

void	check_file(char *file_name, t_fdf *data)
{
	int		fd;
	int		width_line;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		if ((width_line = ft_wdcounter(line, ' ') < data->width))
		{
			close(fd);
			error_write(ERR_MAP);
		}
		free(line);
	}
}

void	print_menu(t_fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 30, y += 20, TEXT, "How to use:");
	mlx_string_put(mlx, win, 30, y += 35, TEXT, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 30, y += 30, TEXT, MOVE);
	mlx_string_put(mlx, win, 30, y += 30, TEXT, "Colors: 1, 2, 3");
	mlx_string_put(mlx, win, 30, y += 30, TEXT, BELOW);
	mlx_string_put(mlx, win, 30, y += 30, TEXT, HEIGHTER);
	mlx_string_put(mlx, win, 30, y += 30, TEXT, "ISO: 9");
	mlx_string_put(mlx, win, 30, y += 30, TEXT, "Parallel: 0");
}

float	percent(int start, int end, int current)
{
	float	placement;
	float	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}
