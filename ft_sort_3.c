/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:19:02 by ranki             #+#    #+#             */
/*   Updated: 2023/03/10 09:52:07 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checkmalloc(t_all *all, t_list **a, t_list **b, t_listopt **result)
{
	if (all == NULL)
	{
		ft_lstclear(*a);
		ft_lstclear(*b);
		ft_lstclearchar(result);
		free(all);
		exit(EXIT_FAILURE);
	}
}

void	ft_sort_adup(t_list **a, t_list **b, int size, t_listopt **result)
{
	t_list	*second;
	t_list	*third;
	t_all	*all;

	all = malloc(sizeof(t_all));
	ft_checkmalloc(all, a, b, result);
	second = (*a)->next;
	third = second->next;
	all->second = second;
	all->third = third;
	if (size == 2)
	{
		second = (*a)->next;
		all->second = second;
		if ((*a)->content > all->second->content)
			ft_swap_a(a, result);
	}
	else if (size == 3)
	{
		ft_sort_ap1(a, b, result, all);
		ft_sort_ap2(a, b, result, all);
	}
	free(all);
}

void	ft_sort_3express_d(t_list **b, int size, t_listopt **result)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (b == NULL || *b == 0)
		return ;
	while (ft_checksorted_d(*b, size) != 1)
	{
		tmp = (*b)->next;
		tmp2 = tmp->next;
		if (ft_checksorted(*b, size))
			ft_rotate_b(b, result);
		else if ((*b)->content < tmp2->content)
			ft_rotate_b(b, result);
		else if ((*b)->content < tmp->content)
			ft_swap_b(b, result);
		else
			ft_rotate_b(b, result);
	}
}

void	ft_sort_3express(t_list **b, int size, t_listopt **result)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (b == NULL || *b == 0)
		return ;
	while (ft_checksorted(*b, size) != 1)
	{
		tmp = (*b)->next;
		tmp2 = tmp->next;
		if (ft_checksorted_d(*b, size))
			ft_rotate_a(b, result);
		else if ((*b)->content > tmp2->content)
			ft_rotate_a(b, result);
		else if ((*b)->content > tmp->content)
			ft_swap_a(b, result);
		else
			ft_rotate_a(b, result);
	}
}

void	ft_sort_bdup(t_list **a, t_list **b, int size, t_listopt **result)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	ft_checkmalloc(all, a, b, result);
	all->second = (*b)->next;
	all->third = all->second->next;
	if (size == 1)
		ft_push_a(a, b, result);
	else if (size == 2)
	{
		all->second = (*b)->next;
		if ((*b)->content < all->second->content)
			ft_swap_b(b, result);
		ft_push_a(a, b, result);
		ft_push_a(a, b, result);
	}
	else if (size == 3)
	{
		ft_sort_p1(a, b, result, all);
		ft_sort_p2(a, b, result, all);
		ft_sort_p3(a, b, result, all);
	}
	free(all);
}
