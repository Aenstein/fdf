/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 07:49:25 by aenstein          #+#    #+#             */
/*   Updated: 2019/09/28 07:49:46 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char			*tmpdest;
	const unsigned char		*tmpsrc;

	tmpdest = (unsigned char*)dest;
	tmpsrc = (const unsigned char*)src;
	if (dest == src)
		return (dest);
	if (tmpdest < tmpsrc)
	{
		while (num > 0)
		{
			*(tmpdest++) = *(tmpsrc++);
			num--;
		}
	}
	else
	{
		while (num > 0)
		{
			*(tmpdest + num - 1) = *(tmpsrc + num - 1);
			num--;
		}
	}
	return (dest);
}
