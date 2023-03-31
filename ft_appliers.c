/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appliers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:46:10 by rerayyad          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/25 16:59:09 by rerayyad         ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2023/03/25 16:59:09 by rerayyad         ###   ########.fr       */
=======
/*   Updated: 2023/03/22 18:36:42 by rerayyad         ###   ########.fr       */
>>>>>>> a70e43dc9689dfd48803e95da8da18298151d614
>>>>>>> 09d2d857c57fef8f386719bf717295ce7a80ab8b
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_app_ra_rb(t_stacks *stacks, int nbr, int n)
{
	if (n)
	{
		while (*stacks->a->nbr != nbr
			&& ft_b_placer(stacks->b, nbr) > 0)
			ft_rr(&stacks->a, &stacks->b, 1);
		while (*stacks->a->nbr != nbr)
			ft_rotate(&stacks->a, 1);
		while (ft_b_placer(stacks->b, nbr) > 0)
			ft_rotate(&stacks->b, 2);
		ft_push(&stacks->b, &stacks->a, 2);
<<<<<<< HEAD
	}
	else
	{
		while (*stacks->b->nbr != nbr && ft_a_placer(stacks->a, nbr) > 0)
			ft_rr(&stacks->a, &stacks->b, 1);
		while (*stacks->b->nbr != nbr)
			ft_rotate(&stacks->b, 2);
		while (ft_a_placer(stacks->a, nbr) > 0)
			ft_rotate(&stacks->a, 1);
		ft_push(&stacks->a, &stacks->b, 1);
	}
	return (-1);
}

int	ft_app_rra_rrb(t_stacks *stacks, int nbr, int n)
{
	if (n)
	{
		while (*stacks->a->nbr != nbr
			&& ft_b_placer(stacks->b, nbr) > 0)
			ft_rrr(&stacks->a, &stacks->b, 1);
		while (*stacks->a->nbr != nbr)
			ft_rev_rot(&stacks->a, 1);
		while (ft_b_placer(stacks->b, nbr) > 0)
			ft_rev_rot(&stacks->b, 2);
		ft_push(&stacks->b, &stacks->a, 2);
	}
	else
	{
		while (*stacks->b->nbr != nbr && ft_a_placer(stacks->a, nbr) > 0)
			ft_rrr(&stacks->a, &stacks->b, 1);
		while (*stacks->b->nbr != nbr)
			ft_rev_rot(&stacks->b, 2);
		while (ft_a_placer(stacks->a, nbr) > 0)
			ft_rev_rot(&stacks->a, 1);
		ft_push(&stacks->a, &stacks->b, 1);
	}
	return (-1);
}

int	ft_app_ra_rrb(t_stacks *stacks, int nbr, int n)
{
	if (n)
	{
		while (*stacks->a->nbr != nbr)
			ft_rotate(&stacks->a, 1);
		while (ft_b_placer(stacks->b, nbr) > 0)
			ft_rev_rot(&stacks->b, 2);
		ft_push(&stacks->b, &stacks->a, 2);
	}
	else
	{
		while (ft_a_placer(stacks->a, nbr))
			ft_rotate(&stacks->a, 1);
		while (*stacks->b->nbr != nbr)
			ft_rev_rot(&stacks->b, 2);
		ft_push(&stacks->a, &stacks->b, 1);
	}
	return (-1);
}

int	ft_app_rra_rb(t_stacks *stacks, int nbr, int n)
{
	if (n)
	{
		while (*stacks->a->nbr != nbr)
			ft_rev_rot(&stacks->a, 1);
		while (ft_b_placer(stacks->b, nbr) > 0)
			ft_rotate(&stacks->b, 2);
		ft_push(&stacks->b, &stacks->a, 2);
	}
	else
	{
		while (ft_a_placer(stacks->a, nbr) > 0)
			ft_rev_rot(&stacks->a, 1);
		while (*stacks->b->nbr != nbr)
			ft_rotate(&stacks->b, 2);
		ft_push(&stacks->a, &stacks->b, 1);
	}
=======
	}
	else
	{
		while (*stacks->b->nbr != nbr && ft_a_placer(stacks->a, nbr) > 0)
			ft_rr(&stacks->a, &stacks->b, 1);
		while (*stacks->b->nbr != nbr)
			ft_rotate(&stacks->b, 2);
		while (ft_a_placer(stacks->a, nbr) > 0)
			ft_rotate(&stacks->a, 1);
		ft_push(&stacks->a, &stacks->b, 1);
	}
	return (-1);
}

int	ft_app_rra_rrb(t_stacks *stacks, int nbr, int n)
{
	if (n)
	{
		while (*stacks->a->nbr != nbr
			&& ft_b_placer(stacks->b, nbr) > 0)
			ft_rrr(&stacks->a, &stacks->b, 1);
		while (*stacks->a->nbr != nbr)
			ft_rev_rot(&stacks->a, 1);
		while (ft_b_placer(stacks->b, nbr) > 0)
			ft_rev_rot(&stacks->b, 2);
		ft_push(&stacks->b, &stacks->a, 2);
	}
	else
	{
		while (*stacks->b->nbr != nbr && ft_a_placer(stacks->a, nbr) > 0)
			ft_rrr(&stacks->a, &stacks->b, 1);
		while (*stacks->b->nbr != nbr)
			ft_rev_rot(&stacks->b, 2);
		while (ft_a_placer(stacks->a, nbr) > 0)
			ft_rev_rot(&stacks->a, 1);
		ft_push(&stacks->a, &stacks->b, 1);
	}
	return (-1);
}

int	ft_app_ra_rrb(t_stacks *stacks, int nbr, int n)
{
	if (n)
	{
		while (*stacks->a->nbr != nbr)
			ft_rotate(&stacks->a, 1);
		while (ft_b_placer(stacks->b, nbr) > 0)
			ft_rev_rot(&stacks->b, 2);
		ft_push(&stacks->b, &stacks->a, 2);
	}
	else
	{
		while (ft_a_placer(stacks->a, nbr))
			ft_rotate(&stacks->a, 1);
		while (*stacks->b->nbr != nbr)
			ft_rev_rot(&stacks->b, 2);
		ft_push(&stacks->a, &stacks->b, 1);
	}
	return (-1);
}

int	ft_app_rra_rb(t_stacks *stacks, int nbr, int n)
{
	if (n)
	{
		while (*stacks->a->nbr != nbr)
			ft_rev_rot(&stacks->a, 1);
		while (ft_b_placer(stacks->b, nbr) > 0)
			ft_rotate(&stacks->b, 2);
		ft_push(&stacks->b, &stacks->a, 2);
	}
<<<<<<< HEAD
	else
	{
		while (ft_a_placer(stacks->a, nbr) > 0)
			ft_rev_rot(&stacks->a, 1);
		while (*stacks->b->nbr != nbr)
			ft_rotate(&stacks->b, 2);
		ft_push(&stacks->a, &stacks->b, 1);
	}
=======
	//code else case
>>>>>>> a70e43dc9689dfd48803e95da8da18298151d614
>>>>>>> 09d2d857c57fef8f386719bf717295ce7a80ab8b
	return (-1);
}
