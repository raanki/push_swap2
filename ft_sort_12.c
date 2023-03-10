/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_12.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:40:32 by ranki             #+#    #+#             */
/*   Updated: 2022/12/17 09:04:58 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void sort_12d(t_list **a, t_list **b, t_listopt **result)
{
	ft_swap_a(a, result);
	ft_rotate_a(a, result);
	ft_rotate_a(a, result);
	ft_sort_adup(a, b, 3, result);
}*/
void	ft_sort_5part2(t_list **a, t_list **b, t_listopt **result, int min[2])
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	while (i <= ft_lstsize(*a) && check != 2)
	{
		if ((*a)->content == min[0] || (*a)->content == min[1])
		{
			ft_push_b(a, b, result);
			check++;
		}
		else
			ft_rotate_a(a, result);
		i++;
	}
	ft_sort_3express(a, 3, result);
	if ((*b)->content < (*b)->next->content)
		ft_swap_b(b, result);
	ft_push_a(a, b, result);
	ft_push_a(a, b, result);
}

void	sort_5(t_list **a, t_list **b, t_listopt **result)
{
	int		min[2];
	t_list	*tmp;

	tmp = (*a);
	min[0] = (*a)->content;
	while ((tmp) != NULL)
	{
		if (min[0] > tmp->content)
			min[0] = tmp->content;
		tmp = tmp->next;
	}
	tmp = (*a);
	if (min[0] == (*a)->content)
		min[1] = (*a)->next->content;
	else
		min[1] = (*a)->content;
	while ((tmp) != NULL)
	{
		if (min[1] > tmp->content && tmp->content != min[0])
			min[1] = tmp->content;
		tmp = tmp->next;
	}
	tmp = (*a);
	ft_sort_5part2(a, b, result, min);
}

void	ft_sort_4part1(t_list **a, t_list **b, t_listopt **result, int min1)
{
	int	i;

	i = 0;
	while (i <= ft_lstsize(*a))
	{
		if ((*a)->content == min1)
		{
			ft_push_b(a, b, result);
			break ;
		}
		else
			ft_rotate_a(a, result);
		i++;
	}
	ft_sort_3express(a, 3, result);
	ft_push_a(a, b, result);
}

void	sort_4(t_list **a, t_list **b, t_listopt **result)
{
	int		min1;
	t_list	*tmp;

	tmp = (*a);
	min1 = (*a)->content;
	while ((tmp) != NULL)
	{
		if (min1 > tmp->content)
			min1 = tmp->content;
		tmp = tmp->next;
	}
	tmp = (*a);
	ft_sort_4part1(a, b, result, min1);
}
