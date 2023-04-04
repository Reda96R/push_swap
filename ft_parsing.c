/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:31:13 by rerayyad          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/03 17:11:12 by rerayyad         ###   ########.fr       */
=======
/*   Updated: 2023/04/01 16:51:47 by rerayyad         ###   ########.fr       */
>>>>>>> af5c9e92abfa76924b55b64cd5587c16988b52ac
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_fill_stack(t_stack **stack, long nbr)
{
	t_stack	*new;
	int		*content;

	if (ft_duplication_check(stack, nbr))
		return (0);
	content = malloc(sizeof (int));
	if (!content)
		return (0);
	*content = nbr;
	new = ft_new(content);
	if (!new)
	{
		free(content);
		return (0);
	}
	ft_add_to_stack(stack, new);
	return (1);
}

int	ft_parser(t_stack **stack, char *str)
{
	long	n;

	if (ft_type_checker(&n, str) && ft_fill_stack(stack, n))
		return (1);
	return (0);
}

void	ft_init_stacks(t_stacks *stacks, int ac, char *av[], int n)
{
	int		i;
	size_t	j;

	if (ac < 2 && n)
		ft_cleaner(stacks, 1);
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
			while (av[i][j] && !ft_space_check(av[i][j]))
				j++;
		}
		i++;
	}
}
