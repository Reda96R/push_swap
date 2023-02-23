/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:53:50 by rerayyad          #+#    #+#             */
/*   Updated: 2023/02/23 12:31:05 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rot(t_stack **stack, int i)
{
	t_stack	*n;
	int		j;

	if (!*stack || !(*stack)->next)
		return ;
	n = *stack;
	j = 0;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		j++;
	}
	(*stack)->next = n;
	while (j-- > 1)
	{
		n = n->next;
		j--;
	}
	n->next = NULL;
	if (i == 1)
		write (1, "rra\n", 4);
	else if (i == 2)
		write (1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b, int i)
{
	if (!*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	ft_rev_rot(a, 0);
	ft_rev_rot(b, 0);
	if (i)
		write (1, "rrr\n", 4);
}
