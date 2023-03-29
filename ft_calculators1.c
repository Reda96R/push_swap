/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculators1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:09:01 by rerayyad          #+#    #+#             */
/*   Updated: 2023/03/25 17:53:55 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra_rb_a(t_stacks *stacks, int nbr)
{
	int	i;

	i = ft_a_placer(stacks->a, nbr);
	if (i < ft_index_finder(stacks->b, nbr))
		i = ft_index_finder(stacks->b, nbr);
	return (i);
}

int	ft_rra_rrb_a(t_stacks *stacks, int nbr)
{
	int	i;

	i = 0;
	if (ft_a_placer(stacks->a, nbr))
		i = ft_stack_size(stacks->a) - ft_a_placer(stacks->a, nbr);
	if (ft_index_finder(stacks->b, nbr)
		&& (i < (ft_stack_size(stacks->b) - ft_index_finder(stacks->b, nbr))))
		i = ft_stack_size(stacks->b) - ft_index_finder(stacks->b, nbr);
	return (i);
}

int	ft_ra_rrb_a(t_stacks *stacks, int nbr)
{
	int	i;

	i = 0;
	if (ft_index_finder(stacks->b, nbr))
		i = ft_stack_size(stacks->b) - ft_index_finder(stacks->b, nbr);
	i = ft_a_placer(stacks->a, nbr) + i;
	return (i);
}

int	ft_rra_rb_a(t_stacks *stacks, int nbr)
{
	int	i;

	i = 0;
	if (ft_a_placer(stacks->a, nbr))
		i = ft_stack_size(stacks->a) - ft_a_placer(stacks->a, nbr);
	i = ft_index_finder(stacks->b, nbr) + i;
	return (i);
}
