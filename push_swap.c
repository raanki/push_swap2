/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:30:36 by ranki             #+#    #+#             */
/*   Updated: 2023/03/10 09:25:31 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	add_move(t_listopt **result, char *s)
{
	ft_lstadd_backchar(result, ft_lstnewstr(s));
}

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc <= 1)
	{
		return (0);
	}
	i = 1;
	if (ft_strcmp(argv[1], "c") == 0)
		i++;
	while (i < argc)
	{
		j = 0;
		while ('\0' != argv[i][j])
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9')
						|| argv[i][j] == '-'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_all(int argc, char **argv, t_list **lst)
{
	if (argc == 1)
		return (0);
	if (check_arg(argc, argv) == 0)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	*lst = ft_argtolist(argc, argv);
	if (ft_checksorted(*lst, ft_lstsize(*lst)))
	{
		ft_lstclear(*lst);
		return (0);
	}
	if (check_double(*lst) == 1)
	{
		ft_lstclear(*lst);
		write (2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char **(argv))
{
	t_list		*lst;
	t_list		*b;
	t_listopt	*result;

	b = NULL;
	result = NULL;
	if (check_all(argc, argv, &lst) == 0)
		return (0);
	if (ft_lstsize(lst) == 5)
		sort_5(&lst, &b, &result);
	if (ft_lstsize(lst) == 4)
		sort_4(&lst, &b, &result);
	else if (ft_lstsize(lst) <= 3)
		ft_sort_3express(&lst, ft_lstsize(lst), &result);
	else
		ft_quick_sort(&lst, &b, ft_lstsize(lst), &result);
	simply(&result);
	ft_printlistcolor(result);
	ft_lstclear(lst);
	ft_lstclear(b);
	ft_lstclearchar(&result);
	return (0);
}
