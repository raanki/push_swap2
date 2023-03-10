/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlistcolor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:59:03 by ranki             #+#    #+#             */
/*   Updated: 2023/03/10 09:12:55 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlistcolor(t_listopt *lst)
{
	if (lst == NULL)
		return ;
	if (ft_strcmp(lst->content, "pa") == 0)
		ft_printf(_RED);
	else if (ft_strcmp(lst->content, "pb") == 0)
		ft_printf(_CYAN);
	else if (ft_strcmp(lst->content, "ra") == 0)
		ft_printf(_GREEN);
	else if (ft_strcmp(lst->content, "rb") == 0)
		ft_printf(_YELLOW);
	else if (ft_strcmp(lst->content, "rra") == 0)
		ft_printf(_BLUE);
	else if (ft_strcmp(lst->content, "rrb") == 0)
		ft_printf(_PURPLE);
	else if (ft_strcmp(lst->content, "sa") == 0)
		ft_printf(_WHITE);
	else if (ft_strcmp(lst->content, "sb") == 0)
		ft_printf(_CYAN);
	ft_printf("%s\n", lst->content);
	ft_printf(_END);
	ft_printlistcolor(lst->next);
}
