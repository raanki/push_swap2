/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:23:46 by ranki             #+#    #+#             */
/*   Updated: 2023/03/10 09:41:03 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort_b3(int size_b, t_list **b, t_listopt **result)
{
	int	i;

	i = 0;
	while (i++ < size_b)
		ft_rrotate_b(b, result);
}

int	ft_quick_sort_b2(t_list **a, t_list **b, int size, t_listopt **result)
{
	int	i;
	int	size_b;
	int	size_a;
	int	pivot;

	i = 0;
	size_b = 0;
	size_a = 0;
	pivot = ft_median(*b, size);
	while (i++ < size)
	{
		if ((*b)->content >= pivot)
		{
			ft_push_a(a, b, result);
			size_a++;
		}
		else
		{
			ft_rotate_b(b, result);
			size_b++;
		}
	}
	ft_quick_sort_b3(size_b, b, result);
	return (ft_quick_sort(a, b, size_a, result)
		&& ft_quick_sort_b(a, b, size_b, result));
}

int	ft_quick_sort_b(t_list **a, t_list **b, int size, t_listopt **result)
{
	if (ft_checksorted_d(*b, size))
	{
		while (size--)
			ft_push_a(a, b, result);
		return (1);
	}
	if (size <= 3)
	{
		ft_sort_bdup(a, b, size, result);
		return (1);
	}
	return (ft_quick_sort_b2(a, b, size, result));
}
