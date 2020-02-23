/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaland <bshaland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:33:49 by aenstein          #+#    #+#             */
/*   Updated: 2020/02/23 20:38:59 by bshaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_default_color(int z, t_fdf *data)
{
	float	percentage;

	percentage = percent(data->min_z, data->max_z, z);
	if (percentage < 0.2)
		return (ORANGERED);
	else if (percentage < 0.4)
		return (DARKORANGE);
	else if (percentage < 0.6)
		return (ORANGE);
	else if (percentage < 0.8)
		return (GOLD);
	else
		return (YELLOW);
}

int	get_light(int start, int end, float percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_point cur, t_point start, t_point end, t_step step)
{
	int		red;
	int		green;
	int		blue;
	float	percentage;

	if (cur.color == end.color)
		return (cur.color);
	if (step.x_step > step.y_step)
		percentage = percent(start.x, end.x, cur.x);
	else
		percentage = percent(start.y, end.y, cur.y);
	red = get_light((start.color >> 16) & 0xFF,
					(end.color >> 16) & 0xFF,
					percentage);
	green = get_light((start.color >> 8) & 0xFF,
					(end.color >> 8) & 0xFF,
					percentage);
	blue = get_light(start.color & 0xFF,
					end.color & 0xFF,
					percentage);
	return ((red << 16) | (green << 8) | blue);
}
