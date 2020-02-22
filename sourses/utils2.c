/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:35:03 by aenstein          #+#    #+#             */
/*   Updated: 2020/02/17 23:05:40 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	create_point(float x, float y)
{
	t_point point;

	point.x = x;
	point.y = y;
	return (point);
}

void	zoomstart(float *x, float *y, t_fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
}

void	shiftstart(float *x, float *y, float shift)
{
	*x += shift;
	*y += shift;
}

int		color(t_fdf *data, float z, float z1)
{
	if (data->color_num == 1)
		return ((z || z1) ? 0xe80c0c : 0xffffff);
	else if (data->color_num == 2)
		return ((z || z1) ? 0xFFFF00 : 0xFF8C00);
	else
		return ((z || z1) ? 0x712F26 : 0x008000);
}

void	error_write(char *s)
{
	ft_putendl(s);
	exit(1);
}
