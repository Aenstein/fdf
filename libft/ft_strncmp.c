/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 07:41:20 by aenstein          #+#    #+#             */
/*   Updated: 2019/09/28 07:42:08 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	while (*s1 && *s2 && n != 0)
	{
		if (*s1 != *s2)
			return ((int)(*s1 - *s2));
		s1++;
		s2++;
		n--;
	}
	if (((*s1 && !*s2) || (*s2 && !*s1)) && n != 0)
		return ((int)(*s1 - *s2));
	return (0);
}
