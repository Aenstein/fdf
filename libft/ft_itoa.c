/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 23:12:44 by aenstein          #+#    #+#             */
/*   Updated: 2019/09/29 12:47:31 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(unsigned int number)
{
	int				size;

	size = 0;
	while (number > 9)
	{
		number = number / 10;
		size++;
	}
	size++;
	return ((unsigned int)size);
}

char		*ft_itoa(int n)
{
	unsigned char	*str;
	unsigned int	len;
	unsigned int	negative;
	unsigned int	number;

	negative = 0;
	if (n < 0)
		number = (unsigned int)(n * -1);
	else
		number = (unsigned int)n;
	if (n < 0)
		negative = 1;
	len = (unsigned int)(ft_size(number));
	if (!(str = (unsigned char *)malloc(len + negative + 1)))
		return (NULL);
	str[len + negative] = '\0';
	while (number > 9)
	{
		str[negative + (len--) - 1] = (char)(number % 10 + 48);
		number = number / 10;
	}
	str[negative] = (char)(number % 10 + 48);
	if (negative == 1)
		str[0] = '-';
	return ((char *)str);
}
