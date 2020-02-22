/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:02:12 by aenstein          #+#    #+#             */
/*   Updated: 2020/02/17 23:01:02 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shif(int key, t_fdf *data)
{
	if (key == 0)
		data->shift_x -= 10;
	if (key == 2)
		data->shift_x += 10;
	if (key == 13)
		data->shift_y -= 10;
	if (key == 1)
		data->shift_y += 10;
}

void	zoom(int key, t_fdf *data)
{
	if (key == 69 || key == 5)
		data->zoom += 1;
	if ((key == 78 || key == 4) && data->zoom - 1 != 0)
		data->zoom -= 1;
}
