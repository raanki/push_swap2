/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:47:41 by ranki             #+#    #+#             */
/*   Updated: 2023/03/08 19:47:44 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_p1(t_list **a, t_list **b, t_listopt **result, t_all *all)
{
	if ((*b)->content >= all->second->content
		&& all->second->content >= all->third->content)
	{
		ft_push_a(a, b, result);
		ft_push_a(a, b, result);
		ft_push_a(a, b, result);
	}
	else if ((*b)->content >= all->second->content
		&& (*b)->content >= all->third->content
		&& all->second->content <= all->third->content)
	{
		ft_push_a(a, b, result);
		ft_swap_b(b, result);
		ft_push_a(a, b, result);
		ft_push_a(a, b, result);
	}
}

void	ft_sort_p2(t_list **a, t_list **b, t_listopt **result, t_all *all)
{
	if ((*b)->content <= all->second->content
		&& (*b)->content >= all->third->content
		&& all->second->content >= all->third->content)
	{
		ft_swap_b(b, result);
		ft_push_a(a, b, result);
		ft_push_a(a, b, result);
		ft_push_a(a, b, result);
	}
	else if ((*b)->content >= all->second->content
		&& all->second->content <= all->third->content
		&& (*b)->content <= all->third->content)
	{
		ft_push_a(a, b, result);
		ft_swap_b(b, result);
		ft_push_a(a, b, result);
		ft_swap_a(a, result);
		ft_push_a(a, b, result);
	}
}

void	ft_sort_p3(t_list **a, t_list **b, t_listopt **result, t_all *all)
{
	if ((*b)->content <= all->second->content
		&& all->second->content >= all->third->content
		&& (*b)->content <= all->third->content)
	{
		ft_swap_b(b, result);
		ft_push_a(a, b, result);
		ft_swap_b(b, result);
		ft_push_a(a, b, result);
		ft_push_a(a, b, result);
	}
	else if ((*b)->content <= all->second->content
		&& all->second->content <= all->third->content)
	{
		ft_rotate_b(b, result);
		ft_swap_b(b, result);
		ft_push_a(a, b, result);
		ft_push_a(a, b, result);
		ft_rrotate_b(b, result);
		ft_push_a(a, b, result);
	}
}

void	ft_sort_ap1(t_list **a, t_list **b, t_listopt **result, t_all *all)
{
	if ((*a)->content >= all->second->content
		&& all->second->content >= all->third->content)
	{
		ft_swap_a(a, result);
		ft_push_b(a, b, result);
		ft_swap_a(a, result);
		ft_push_a(a, b, result);
		ft_swap_a(a, result);
	}
	if ((*a)->content >= all->second->content
		&& (*a)->content >= all->third->content
		&& all->second->content <= all->third->content)
	{
		ft_swap_a(a, result);
		ft_push_b(a, b, result);
		ft_swap_a(a, result);
		ft_push_a(a, b, result);
	}
}

void	ft_sort_ap2(t_list **a, t_list **b, t_listopt **result, t_all *all)
{
	if ((*a)->content <= all->second->content
		&& (*a)->content >= all->third->content
		&& all->second->content >= all->third->content)
	{
		ft_push_b(a, b, result);
		ft_swap_a(a, result);
		ft_push_a(a, b, result);
		ft_swap_a(a, result);
	}
	if ((*a)->content >= all->second->content
		&& all->second->content <= all->third->content
		&& (*a)->content <= all->third->content)
		ft_swap_a(a, result);
	if ((*a)->content <= all->second->content
		&& all->second->content >= all->third->content
		&& (*a)->content <= all->third->content)
	{
		ft_push_b(a, b, result);
		ft_swap_a(a, result);
		ft_push_a(a, b, result);
	}
}
