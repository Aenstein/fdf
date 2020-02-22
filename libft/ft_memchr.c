/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 07:20:47 by aenstein          #+#    #+#             */
/*   Updated: 2019/09/28 07:22:24 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int ch, size_t num)
{
	const unsigned char	*tmpstr;
	unsigned char		c;

	tmpstr = (const unsigned char *)str;
	c = (unsigned char)ch;
	while (num != 0)
	{
		if (*(tmpstr) == c)
			return ((void *)tmpstr);
		num--;
		tmpstr++;
	}
	return (NULL);
}
