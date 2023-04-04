/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:36:42 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/02 22:35:39 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rot_comb_ba(t_stacks *stacks)
{
	int		i;
	t_stack	*tmp;

	i = ft_rra_rrb_a(stacks, *stacks->b->nbr);
	tmp = stacks->b;
	while (tmp)
	{
		if (i > ft_ra_rb_a(stacks, *tmp->nbr))
			i = ft_ra_rb_a(stacks, *tmp->nbr);
		if (i > ft_rra_rrb_a(stacks, *tmp->nbr))
			i = ft_rra_rrb_a(stacks, *tmp->nbr);
		if (i > ft_ra_rrb_a(stacks, *tmp->nbr))
			i = ft_ra_rrb_a(stacks, *tmp->nbr);
		if (i > ft_rra_rb_a(stacks, *tmp->nbr))
			i = ft_rra_rb_a(stacks, *tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

int	ft_rot_comb_ab(t_stacks	**stacks)
{
	int		i;
	t_stack	*tmp;

	i = ft_rra_rrb(*stacks, *(*stacks)->a->nbr);
	tmp = (*stacks)->a;
	while (tmp)
	{
		if (i > ft_ra_rb(*stacks, *tmp->nbr))
			i = ft_ra_rb(*stacks, *tmp->nbr);
		if (i > ft_rra_rrb(*stacks, *tmp->nbr))
			i = ft_rra_rrb(*stacks, *tmp->nbr);
		if (i > ft_ra_rrb(*stacks, *tmp->nbr))
			i = ft_ra_rrb(*stacks, *tmp->nbr);
		if (i > ft_rra_rb(*stacks, *tmp->nbr))
			i = ft_rra_rb(*stacks, *tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

void	ft_case_three(t_stack **a)
{
	t_stack	*last;

	last = ft_last(*a);
	if (*(*a)->nbr == ft_min_finder(*a))
	{
		ft_rev_rot(a, 1);
		ft_swap(a, 1);
	}
	else if (*(*a)->nbr == ft_max_finder(*a))
	{
		ft_rotate(a, 1);
		if (!ft_sorting_check(*a))
			ft_swap(a, 1);
	}
	else
	{
		if (*last->nbr == ft_max_finder(*a))
			ft_swap(a, 1);
		else
			ft_rev_rot(a, 1);
	}
}

void	ft_case_five(t_stacks **stacks)
{
	t_stacks	tmp;
	int			nbr;
	int			id;

	tmp = **stacks;
	while (ft_stack_size(tmp.a) > 3)
	{
		nbr = ft_min_finder(tmp.a);
		id = ft_index_finder(tmp.a, ft_min_finder(tmp.a));
		ft_bring_to_top(&tmp.a, nbr, id);
		ft_push(&tmp.b, &tmp.a, 2);
	}
	if (ft_sorting_check(tmp.b))
		ft_swap(&tmp.b, 2);
	if (!ft_sorting_check(tmp.a))
		ft_case_three(&tmp.a);
	ft_push(&tmp.a, &tmp.b, 1);
	ft_push(&tmp.a, &tmp.b, 1);
	**stacks = tmp;
}

void	ft_road_to_three(t_stacks **stacks)
{
	int			i;
	t_stack		*tmp;
	t_stacks	tmp2;

	tmp2 = **stacks;
	while (ft_stack_size((*stacks)->a) > 3 && !ft_sorting_check((*stacks)->a))
	{
		tmp = (*stacks)->a;
		i = ft_rot_comb_ab(stacks);
		while (i >= 0)
		{
			if (i == ft_ra_rb(*stacks, *tmp->nbr))
				i = ft_app_ra_rb(&tmp2, *tmp->nbr, 1);
			else if (i == ft_rra_rrb(*stacks, *tmp->nbr))
				i = ft_app_rra_rrb(&tmp2, *tmp->nbr, 1);
			else if (i == ft_ra_rrb(*stacks, *tmp->nbr))
				i = ft_app_ra_rrb(&tmp2, *tmp->nbr, 1);
			else if (i == ft_rra_rb(*stacks, *tmp->nbr))
				i = ft_app_rra_rb(&tmp2, *tmp->nbr, 1);
			else
				tmp = tmp->next;
		}
	**stacks = tmp2;
	}
}
