/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:13:31 by aenstein          #+#    #+#             */
/*   Updated: 2019/09/26 19:44:34 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		search(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	char	*str;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (search(s[i]))
		i++;
	if (i == len)
		return (ft_strnew(0));
	while (search(s[len - 1]))
		len--;
	str = ft_strnew(len - i);
	if (NULL == str)
		return (NULL);
	j = 0;
	while (i < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
