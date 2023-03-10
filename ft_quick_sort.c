/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:33:14 by ranki             #+#    #+#             */
/*   Updated: 2023/03/10 09:59:39 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_median(t_list *lst, int size)
{
	int		min;
	int		max;
	t_list	*tmp;
	int		i;

	i = 0;
	if (lst == NULL)
		return (0);
	tmp = lst;
	min = tmp->content;
	max = tmp->content;
	while (tmp != NULL && i < size)
	{
		if (min > tmp->content)
			min = tmp->content;
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
		i++;
	}
	min = min / 2;
	max = max / 2;
	return (min + max);
}

void	ft_quick_sort_a3(t_list **a, t_list **b, t_listopt **result)
{
	if (b != NULL && *b != NULL
		&& a != NULL && *a != NULL
		&& (*a)->next != NULL && (*a)->content > (*a)->next->content
		&& (*b)->content < (*a)->next->content)
		ft_swap_a(a, result);
}

void	ft_quick_sort_a4(t_list **a, int size_a, t_listopt **result)
{
	int	i;

	i = 0;
	while (i++ < size_a)
		ft_rrotate_a(a, result);
}

int	ft_quick_sort_a2(t_list **a, t_list **b, int size, t_listopt **result)
{
	int	iabp[4];

	iabp[0] = 0;
	iabp[1] = 0;
	iabp[2] = 0;
	iabp[3] = ft_median(*a, size);
	while (iabp[0]++ < size)
	{
		ft_quick_sort_a3(a, b, result);
		if ((*a)->content <= iabp[3])
		{
			ft_push_b(a, b, result);
			iabp[2]++;
		}
		else
		{
			ft_rotate_a(a, result);
			iabp[1]++;
		}
	}
	ft_quick_sort_a4(a, iabp[1], result);
	return (ft_quick_sort(a, b, iabp[1], result)
		&& ft_quick_sort_b(a, b, iabp[2], result));
}

int	ft_quick_sort(t_list **a, t_list **b, int size, t_listopt **result)
{
	if (ft_checksorted(*a, size))
		return (1);
	if (size <= 3)
	{
		ft_sort_adup(a, b, size, result);
		return (1);
	}
	return (ft_quick_sort_a2(a, b, size, result));
}
