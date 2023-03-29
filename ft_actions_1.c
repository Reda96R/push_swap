/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:53:50 by rerayyad          #+#    #+#             */
/*   Updated: 2023/03/22 18:35:53 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rot(t_stack **stack, int i)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	t_stack	*tmp3;

	if (!*stack || !(*stack)->next)
		return ;
	tmp1 = *stack;
	tmp2 = *stack;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp3 = tmp1->next;
	tmp1->next = NULL;
	tmp3->next = tmp2;
	*stack = tmp3;
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
