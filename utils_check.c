/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:08:43 by ranki             #+#    #+#             */
/*   Updated: 2023/03/10 09:03:20 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlist(t_list *lst)
{
	if (lst == NULL)
		return ;
	ft_printf("%d ", lst->content);
	ft_printlist(lst->next);
}

void	ft_printlistchar(t_listopt *lst)
{
	if (lst == NULL)
		return ;
	ft_printf("%s\n", lst->content);
	ft_printlistchar(lst->next);
}

t_list	*ft_argtolist(int argc, char **argv)
{
	int		i;
	t_list	*lst;

	i = 1;
	lst = NULL;
	while (i < argc)
	{
		ft_lstadd_back(&lst, ft_lstnew(atoi(argv[i]), lst));
		i++;
	}
	return (lst);
}
