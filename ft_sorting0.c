/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:28:58 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/02 22:42:47 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	ft_first_sort(t_stacks *stacks)
{
	int	counter;

	counter = 1;
	while (ft_stack_size(stacks->a) > 3 && counter++ < 3
		&& !ft_sorting_check(stacks->a))
		ft_push(&stacks->b, &stacks->a, 2);
	if (ft_stack_size(stacks->a) > 3 && !ft_sorting_check(stacks->a))
		ft_road_to_three(&stacks);
	if (!ft_sorting_check(stacks->a))
		ft_case_three(&stacks->a);
	return (*stacks);
}

t_stacks	ft_second_sort(t_stacks *stacks)
{
	int			i;
	t_stack		*tmp;
	t_stacks	tmp2;

	tmp2 = *stacks;
	while (stacks->b)
	{
		tmp = stacks->b;
		i = ft_rot_comb_ba(stacks);
		while (i >= 0)
		{
			if (i == ft_ra_rb_a(stacks, *tmp->nbr))
				i = ft_app_ra_rb(&tmp2, *tmp->nbr, 0);
			else if (i == ft_rra_rrb_a(stacks, *tmp->nbr))
				i = ft_app_rra_rrb(&tmp2, *tmp->nbr, 0);
			else if (i == ft_ra_rrb_a(stacks, *tmp->nbr))
				i = ft_app_ra_rrb(&tmp2, *tmp->nbr, 0);
			else if (i == ft_rra_rb_a(stacks, *tmp->nbr))
				i = ft_app_rra_rb(&tmp2, *tmp->nbr, 0);
			else
				tmp = tmp->next;
		}
		*stacks = tmp2;
	}
	return (*stacks);
}

void	ft_sort_stacks(t_stacks *stacks)
{
	t_stacks	tmp;
	int			id;

	tmp = *stacks;
	if (ft_stack_size(stacks->a) == 2)
		ft_swap(&stacks->a, 1);
	else if (ft_stack_size(stacks->a) == 5)
		ft_case_five(&stacks);
	else
	{
		*stacks = ft_first_sort(&tmp);
		tmp = *stacks;
		*stacks = ft_second_sort(&tmp);
		id = ft_index_finder(stacks->a, ft_min_finder(stacks->a));
		ft_bring_to_top(&stacks->a, ft_min_finder(stacks->a), id);
	}
}
