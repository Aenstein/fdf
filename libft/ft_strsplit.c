/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:00:19 by aenstein          #+#    #+#             */
/*   Updated: 2019/09/29 12:39:10 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_w(char const *s, char c, int k)
{
	int len;

	len = 0;
	while (s[k] != c && s[k] != '\0')
	{
		len++;
		k++;
	}
	if (s[k] == '\0' && len == 0)
		len++;
	return (len);
}

static int	ft_c(char const *s, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_strdel((void *)str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**str;
	int				i;
	int				j;
	int				k;

	i = -1;
	k = 0;
	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_c(s, c) + 1))))
		return (NULL);
	while (s[k] != '\0')
	{
		j = -1;
		while (s[k] == c && s[k] != '\0')
			k++;
		if (!(str[++i] = (char *)malloc(sizeof(char) * (ft_w(s, c, k) + 1))))
			return (ft_free(str));
		while (s[k] != c && s[k] != '\0')
			str[i][++j] = s[k++];
		str[i][++j] = '\0';
	}
	str[ft_c(s, c)] = NULL;
	return (str);
}
