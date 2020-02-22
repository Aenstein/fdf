/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:40:08 by aenstein          #+#    #+#             */
/*   Updated: 2019/09/21 21:09:17 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *firstlist;
	t_list *secondlist;

	firstlist = *alst;
	while (firstlist)
	{
		secondlist = firstlist->next;
		del(firstlist->content, firstlist->content_size);
		free(firstlist);
		firstlist = secondlist;
	}
	*alst = NULL;
}
