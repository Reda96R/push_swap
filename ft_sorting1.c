/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:36:42 by rerayyad          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/29 17:58:47 by rerayyad         ###   ########.fr       */
=======
/*   Updated: 2023/03/22 18:19:01 by rerayyad         ###   ########.fr       */
>>>>>>> a70e43dc9689dfd48803e95da8da18298151d614
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
int	ft_rot_comb_ba(t_stacks *stacks)
=======
int	ft_rot_comb_ab(t_stacks	**stacks)
>>>>>>> a70e43dc9689dfd48803e95da8da18298151d614
{
	int		i;
	t_stack	*tmp;

<<<<<<< HEAD
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
=======
	i = ft_rra_rrb(*stacks, *(*stacks)->a->nbr);
	tmp = (*stacks)->a;
	while (tmp)
	{
>>>>>>> a70e43dc9689dfd48803e95da8da18298151d614
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

void	ft_road_to_three(t_stacks **stacks)
{
	int			i;
	t_stack		*tmp;
	t_stacks	tmp2;

	tmp2 = **stacks;
<<<<<<< HEAD
	while (ft_stack_size((*stacks)->a) > 3 && !ft_sorting_check((*stacks)->a))
=======
	while (ft_stack_size((*stacks)->a) > 3 && !ft_check_sorting((*stacks)->a))
>>>>>>> a70e43dc9689dfd48803e95da8da18298151d614
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
	// ft_b_placer(stacks->b, *stacks->a->nbr);
