/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:36:42 by rerayyad          #+#    #+#             */
/*   Updated: 2023/03/12 19:59:45 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rot_com(t_stacks	*stacks)
{
	int		i;
	t_stack	*tmp;

	tmp = stacks->a;
	i = ft_rot_cal(stacks, stacks->a->nbr);
	while (tmp)
	{
	}
	return (i);
}

void	ft_case_three(t_stack **a)
{
	t_stack	*last;

	last = ft_last(*a);
	if (*(*a)->nbr == ft_min_finder(*a))
	{
		ft_rev_rot(a, 1);
		ft_swap(a, 1);
	}
	else if (*(*a)->nbr == ft_max_finder(*a))
	{
		ft_rotate(a, 1);
		if (!ft_check_sorting(*a))
			ft_swap(a, 1);
	}
	else
	{
		if (*last->nbr == ft_max_finder(*a))
			ft_swap(a, 1);
		else
			ft_rev_rot(a, 1);
	}
}

void	ft_road_to_three(t_stacks *stacks)
{
	int		i;
	t_stack	*tmp;

	i = ft_rot_comb(stacks);
	while (i >= 0)
	{
	}
	// ft_b_placer(stacks->b, *stacks->a->nbr);
}
