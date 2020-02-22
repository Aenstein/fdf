/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 04:12:15 by aenstein          #+#    #+#             */
/*   Updated: 2019/09/28 04:12:40 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	char	buf;

	if (!str)
		return (NULL);
	i = 0;
	while (i < (ft_strlen(str) + 1) / 2)
	{
		buf = str[i];
		str[i] = str[ft_strlen(str) - i];
		str[ft_strlen(str) - i] = buf;
		i++;
	}
	return (str);
}
