/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 07:14:30 by aenstein          #+#    #+#             */
/*   Updated: 2019/09/28 07:15:15 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)ptr;
	while (num != 0)
	{
		num--;
		tmp[num] = (unsigned char)value;
	}
	return (ptr);
}
