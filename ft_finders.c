/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finders.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:45:26 by rerayyad          #+#    #+#             */
/*   Updated: 2023/03/12 17:23:11 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_finder(t_stack *stack)
{
	int	n;

	n = *stack->nbr;
	while (stack)
	{
		if (n > *stack->nbr)
			n = *stack->nbr;
		stack = stack->next;
	}
	return (n);
}

int	ft_max_finder(t_stack *stack)
{
	int	n;

	n = *stack->nbr;
	while (stack)
	{
		if (n < *stack->nbr)
			n = *stack->nbr;
		stack = stack->next;
	}
	return (n);
}

int	ft_index_finder(t_stack *stack, int nbr)
{
	int	i;

	i = 0;
	while (*stack->nbr != nbr)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
