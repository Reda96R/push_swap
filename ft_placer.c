/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:05:35 by rerayyad          #+#    #+#             */
/*   Updated: 2023/03/12 19:04:38 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_b_placer(t_stack *stack, int nbr)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr > *stack->nbr && nbr < *ft_last(stack)->nbr)
		i = 0;
	else if (nbr > ft_max_finder(stack) || nbr < ft_min_finder(stack))
	{
		i = ft_index_finder(stack, ft_max_finder(stack));
		printf("testing\n");
	}
	else
	{
		tmp = stack->next;
		printf("here\n");
		while (*stack->nbr < nbr || *tmp->nbr > nbr)
		{
			stack = stack->next;
			tmp = stack->next;
			i++;
		}
	}
	printf("number i ::: %d\n", i);
	return (i);
}
