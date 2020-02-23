/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:24:13 by bshaland          #+#    #+#             */
/*   Updated: 2020/02/23 21:41:55 by aenstein         ###   ########.fr       */
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
	*y = (p_x + p_y) * sin(0.523599) - z / mod(data->rotation->z_projection);
}

void	rotate_x(float *y, float *z, double x_rot)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(x_rot) + *z * sin(x_rot);
	*z = -previous_y * sin(x_rot) + *z * cos(x_rot);
}

void	rotate_y(float *x, float *z, double y_rot)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(y_rot) + *z * sin(y_rot);
	*z = -previous_x * sin(y_rot) + *z * cos(y_rot);
}

void	rotate_z(float *x, float *y, double z_rot)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(z_rot) - previous_y * sin(z_rot);
	*y = previous_x * sin(z_rot) + previous_y * cos(z_rot);
}

t_point	project(t_point p, t_fdf *fdf)
{
	p.x *= fdf->zoom;
	p.y *= fdf->zoom;
	p.z *= fdf->zoom / fdf->rotation->z_projection;
	p.x -= (fdf->width * fdf->zoom) / 2;
	p.y -= (fdf->height * fdf->zoom) / 2;
	rotate_x(&p.y, &p.z, fdf->rotation->x_rot);
	rotate_y(&p.x, &p.z, fdf->rotation->y_rot);
	rotate_z(&p.x, &p.y, fdf->rotation->z_rot);
	if (fdf->rotation->projection == 1)
		iso(&p.x, &p.y, p.z, fdf);
	else if (fdf->rotation->projection == 2)
		parallel(&p.x, &p.y, p.z, fdf);
	return (p);
}
