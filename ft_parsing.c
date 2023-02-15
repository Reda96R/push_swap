/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:31:13 by rerayyad          #+#    #+#             */
/*   Updated: 2023/02/15 16:21:30 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parser(t_stack **stack, char *str)
{
	long	n;

	if (ft_type_check(&n, str) && ft_put(stack, n))
		return (1);
	return (0);
}

void	ft_init_stacks(t_stacks *stacks, int ac, char *av[])
{
	int		i;
	size_t	j;

	if (ac == 1)
		exit(0);
	i = 1;
	while (ac > i)
	{
		j = 0;
		if (!av[i][0])
			ft_errors_buster(stacks);
		while (av[i][j])
		{
			while (av[i][j] && ft_space_check(av[i][j]))
				j++;
			if (!av[i][j])
				break ;
			if (!ft_parser(&(stacks->a), &(av[i][j])))
				ft_errors_buster(stacks);
			while (av[i][j] && !ft_space(av[i][j]))
				j++;
		}
		i++;
	}
}
