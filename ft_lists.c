/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:32:09 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/01 15:11:58 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new(void *n)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = n;
	new->next = NULL;
	return (new);
}

void	ft_add_to_stack(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if (!stack || !new)
		return ;
	else if (!(*stack))
	{
		*stack = new;
		return ;
	}
	current = (*stack);
	while (current->next)
		current = current->next;
	current->next = new;
}

t_stack	*ft_last(t_stack *stack)
{
	while (stack)
	{
		if (!stack->next)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

int	ft_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
