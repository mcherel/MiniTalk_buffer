/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:30:40 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/26 09:38:01 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!alst || !new)
		return ;
	last = *alst;
	if (*alst != NULL)
	{
		last = ft_lstlast(last);
		last->next = new;
	}
	else
		*alst = new;
	return ;
}
/*adds a new element at the back of the list*/
