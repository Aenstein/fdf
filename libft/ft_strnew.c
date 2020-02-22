/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:57:51 by aenstein          #+#    #+#             */
/*   Updated: 2019/09/17 19:10:57 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned char *mem;

	mem = (unsigned char *)malloc(size + 1);
	if (!mem)
		return (NULL);
	mem[size] = '\0';
	while (size--)
		mem[size] = '\0';
	return ((char *)mem);
}
