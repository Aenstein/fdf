/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:38:34 by aenstein          #+#    #+#             */
/*   Updated: 2019/09/24 21:34:58 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *mem;

	if (!(mem = (unsigned char *)malloc(size)))
		return (NULL);
	else
		while (size)
			mem[--size] = 0;
	return ((void *)mem);
}
