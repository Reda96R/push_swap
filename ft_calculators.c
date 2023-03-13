/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:46:53 by rerayyad          #+#    #+#             */
/*   Updated: 2023/03/12 19:59:51 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rot_cal(t_stacks *stacks, int nbr)
{
	int	i;

	i = 0;
	if (ft_b_placer(stacks, nbr))
		i = ft_stack_size(stacks->b) - ft_b_placer(stacks->b, nbr);
}

