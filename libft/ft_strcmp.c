/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 07:40:14 by aenstein          #+#    #+#             */
/*   Updated: 2019/09/28 07:41:07 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return ((int)(*s1 - *s2));
		s1++;
		s2++;
	}
	if ((*s1 && !*s2) || (*s2 && !*s1))
		return ((int)(*s1 - *s2));
	return (0);
}
