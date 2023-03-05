/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:11:54 by rerayyad          #+#    #+#             */
/*   Updated: 2023/03/05 18:51:37 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **dest, t_stack **src, int i)
{
	t_stack	*n;

	if (!*src)
		return ;
	n = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = n;
	if (i == 1)
		write (1, "pa\n", 3);
	else if (i == 2)
		write (1, "pb\n", 3);
}

void	ft_swap(t_stack **stack, int i)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	if (i == 1)
		write(1, "sa\n", 3);
	if (i == 2)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b, int i)
{
	if (!*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	ft_swap(a, 0);
	ft_swap(b, 0);
	if (i)
		write (1, "ss\n", 3);
}

void	ft_rotate(t_stack **stack, int i)
{
	t_stack	*n;

	if (!*stack || !(*stack)->next)
		return ;
	n = *stack;
	*stack = ft_last(*stack);
	(*stack)->next = n;
	*stack = n->next;
	n->next = NULL;
	if (i == 1)
		write (1, "ra\n", 3);
	else if (i == 2)
		write (1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b, int i)
{
	if (!*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	ft_rotate(a, 0);
	ft_rotate(b, 0);
	if (i)
		write (1, "rr\n", 3);
}
