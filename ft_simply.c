/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:38:25 by ranki             #+#    #+#             */
/*   Updated: 2023/03/10 09:42:15 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsizechar(t_listopt *lst)
{
	if (lst == NULL)
		return (0);
	return (1 + ft_lstsizechar(lst->next));
}

void	check_opti(t_listopt **lst, t_listopt **c, t_listopt **t, t_listopt **p)
{
	if ((!(ft_strcmp((*c)->content, "rb") && ft_strcmp((*t)->content, "rrb")))
		|| (ft_strcmp(((*c)->content), "ra") == 0
			&& ft_strcmp(((*t)->content), "rra") == 0)
		|| (ft_strcmp(((*c)->content), "rrb") == 0
			&& ft_strcmp(((*t)->content), "rb") == 0)
		|| (ft_strcmp(((*c)->content), "rra") == 0
			&& ft_strcmp(((*t)->content), "ra") == 0)
		|| (ft_strcmp(((*c)->content), "pa") == 0
			&& (ft_strcmp(((*t)->content), "pb") == 0))
		|| (ft_strcmp(((*c)->content), "pb") == 0
			&& ft_strcmp(((*t)->content), "pa") == 0))
	{
		(*p)->next = (*t)->next;
		free(*c);
		free((*t));
		(*p) = *lst;
		*c = (*lst)->next;
		(*t) = (*c)->next;
	}
	else
	{
		(*p) = (*p)->next;
		*c = (*c)->next;
		(*t) = (*t)->next;
	}
}

void	simply(t_listopt **lst)
{
	int			size;
	t_listopt	*tmp;
	t_listopt	*cure;
	t_listopt	*prec;

	size = ft_lstsizechar(*lst);
	if (size <= 3)
		return ;
	prec = (*lst);
	cure = (prec)->next;
	tmp = cure->next;
	while (prec && prec->next && prec->next->next && prec->next->next->next)
	{
		check_opti(lst, &cure, &tmp, &prec);
	}
}
