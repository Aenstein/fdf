/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 07:32:27 by aenstein          #+#    #+#             */
/*   Updated: 2019/09/28 07:33:17 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t len;

	len = 0;
	while (s1[len] != '\0' && len < n)
		len++;
	if (len == n)
		return (len + ft_strlen(s2));
	i = len;
	while (i < n - 1 && s2[i - len] != '\0')
	{
		s1[i] = s2[i - len];
		i++;
	}
	s1[i] = '\0';
	return (len + ft_strlen(s2));
}
