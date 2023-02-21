/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:30:24 by rerayyad          #+#    #+#             */
/*   Updated: 2023/02/21 19:34:59 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **a, t_stack **b, int i)
{
	t_stack	*n;

	if (!*b)
		return ;
	n = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = n;
	if (!i)
		write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b, int i)
{
	t_stack	*n;

	if (*a)
		return ;
	n = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = n;
	if (!i)
		write(1, "pb\n", 3);
}

void	ft_ra(t_stack **a, int i)
{
	t_stack	*n;

	if (!*a || !(*a)->next)
		return ;
	n = *a;
	*a = ft_last(*a);
	(*a)->next = n;
	*a = n->next;
	n->next = NULL;
	if (!i)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b, int i)
{
	t_stack	*n;

	if (!*b || !(*b)->next)
		return ;
	n = *b;
	*b = ft_last(*b);
	(*b)->next = n;
	*b = n->next;
	n->next = NULL;
	if (!i)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b, int i)
{
	t_stack	*n;

	if (!*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	ft_rb(b, 1);
	ft_ra(a, 1);
	// n = *a;
	// *a = ft_last(*a);
	// (*a)->next = n;
	// *a = n->next;
	// n->next = NULL;
	// n = *b;
	// *b = ft_last(*b);
	// (*b)->next = n;
	// *b = n->next;
	// n->next = NULL;
	if (!i)
		write(1, "rr\n", 2);
}

