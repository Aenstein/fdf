/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 07:35:43 by aenstein          #+#    #+#             */
/*   Updated: 2019/09/28 07:36:29 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *where, const char *what)
{
	unsigned int	j;

	if (!*what)
		return ((char *)where);
	while (*where)
	{
		j = 0;
		while (*(what + j) && (*(where + j) == *(what + j)))
			j++;
		if (*(what + j) == '\0')
			return ((char *)(where));
		where++;
	}
	return (NULL);
}
