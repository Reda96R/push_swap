/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:31:42 by rerayyad          #+#    #+#             */
/*   Updated: 2023/02/21 19:41:35 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a, int i)
{
	t_stack	*n;

	if (!*a || !(*a)->next)
		return ;
	n = *a;
	*a = (*a)->next;
	n->next = (*a)->next;
	(*a)->next = n;
	if (!i)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **b, int i)
{
	t_stack	*n;

	if (!*b || !(*b)->next)
		return ;
	n = *b;
	*b = (*b)->next;
	n->next = (*b)->next;
	(*b)->next = n;
	if (!i)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b, int i)
{
	t_stack	n;

	if (!*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	ft_sa(a, 1);
	ft_sb(b, 1);
	if (!i)
		write(1, "ss\n", 3);
}
