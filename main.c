/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:52:57 by rerayyad          #+#    #+#             */
/*   Updated: 2023/03/31 13:58:37 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;	

	tmp = stack;
	while (tmp)
	{
		printf("nbr: %d\n", *tmp->nbr);
		tmp = tmp->next;
	}
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;

	ft_bzero(&stacks, sizeof(t_stacks));
	ft_init_stacks(&stacks, ac, av, 1);
	if (!stacks.a)
		ft_errors_buster(&stacks);
	if (!ft_sorting_check(stacks.a))
		ft_sort_stacks(&stacks);
	ft_cleaner(&stacks, 0);
	return (0);
}
