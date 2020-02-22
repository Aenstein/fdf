/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 07:15:48 by aenstein          #+#    #+#             */
/*   Updated: 2019/09/28 07:16:32 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char		*tmpdest;
	const unsigned char	*tmpsrc;

	tmpdest = (unsigned char*)dest;
	tmpsrc = (const unsigned char*)src;
	if (tmpdest == tmpsrc)
		return (dest);
	while (num-- > 0)
		*(tmpdest++) = *(tmpsrc++);
	return (dest);
}
