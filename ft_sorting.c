/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:28:58 by rerayyad          #+#    #+#             */
/*   Updated: 2023/03/22 18:45:19 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	ft_first_sort(t_stacks *stacks)
{
	int			counter;

	counter = 1;
	while (ft_stack_size(stacks->a) > 3 && counter++ < 3
		&& !ft_check_sorting(stacks->a))
		ft_push(&stacks->b, &stacks->a, 2);
	if (ft_stack_size(stacks->a) > 3 && !ft_check_sorting(stacks->a))
		ft_road_to_three(&stacks);
	if (!ft_check_sorting(stacks->a))
		ft_case_three(&stacks->a);
	return (*stacks);
}

void	ft_sort_stacks(t_stacks *stacks)
{
	t_stacks	tmp;

	tmp = *stacks;
	if (ft_stack_size(stacks->a) == 2)
		ft_swap(&stacks->a, 1);
	else
	{
		*stacks = ft_first_sort(&tmp);
		ft_second_sort(stacks);
	}
}
