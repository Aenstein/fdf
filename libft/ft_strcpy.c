/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 07:26:34 by aenstein          #+#    #+#             */
/*   Updated: 2019/09/28 07:27:09 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;
	size_t	q;

	i = ft_strlen(src);
	q = 0;
	while (q <= i)
	{
		dest[q] = src[q];
		q++;
	}
	return (dest);
}
