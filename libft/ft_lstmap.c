/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <mcherel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:11:51 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/27 13:32:03 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*str;

	new = NULL;
	if (lst)
	{
		while (lst)
		{
			str = ft_lstnew((*f)(lst->content));
			if (!str)
			{
				ft_lstclear(&new, (*del));
				return (NULL);
			}
			ft_lstadd_back(&new, str);
			lst = lst->next;
		}
	}
	return (new);
}
/*iterates lst and applies (*f)function to each element content
 * creates a new liste resulting from (*f) application
 * the del function is there to delete one element if needed*/
