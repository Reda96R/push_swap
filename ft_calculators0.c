/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculators0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:46:53 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/01 22:35:38 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra_rb(t_stacks *stacks, int nbr)
{
	int	i;

	i = ft_b_placer(stacks->b, nbr);
	if (i < ft_index_finder(stacks->a, nbr))
		i = ft_index_finder(stacks->a, nbr);
	return (i);
}

int	ft_rra_rrb(t_stacks *stacks, int nbr)
{
	int	i;

	i = 0;
	if (ft_b_placer(stacks->b, nbr))
		i = ft_stack_size(stacks->b) - ft_b_placer(stacks->b, nbr);
	if (ft_index_finder(stacks->a, nbr)
		&& (i < (ft_stack_size(stacks->a) - ft_index_finder(stacks->a, nbr))))
		i = ft_stack_size(stacks->a) - ft_index_finder(stacks->a, nbr);
	return (i);
}

int	ft_rra_rb(t_stacks *stacks, int nbr)
{
	int	i;

	i = 0;
	if (ft_index_finder(stacks->a, nbr))
		i = ft_stack_size(stacks->a) - ft_index_finder(stacks->a, nbr);
	i = ft_b_placer(stacks->b, nbr) + i;
	return (i);
}

int	ft_ra_rrb(t_stacks *stacks, int nbr)
{
	int	i;

	i = 0;
	if (ft_b_placer(stacks->b, nbr))
		i = ft_stack_size(stacks->b) - ft_b_placer(stacks->b, nbr);
	i = ft_index_finder(stacks->a, nbr) + i;
	return (i);
}
