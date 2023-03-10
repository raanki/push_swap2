/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:40:52 by ranki             #+#    #+#             */
/*   Updated: 2023/03/10 09:08:03 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content, t_list *lst)
{
	t_list	*l;

	l = malloc(sizeof(t_list));
	if (l == NULL)
	{
		ft_lstclear(lst);
		exit(EXIT_FAILURE);
	}
	l->content = content;
	l->next = NULL;
	return (l);
}

t_listopt	*ft_lstnewstr(char *s)
{
	t_listopt	*l;

	l = malloc(sizeof(t_listopt));
	if (l == NULL)
	{
		ft_lstclearchar(&l);
		exit(EXIT_FAILURE);
	}
	l->content = s;
	l->next = NULL;
	return (l);
}
