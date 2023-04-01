/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:52:57 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/01 16:20:19 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int		i;
	t_stack	*tmp;	

	tmp = stack;
	i = 0;
	while (tmp)
	{
		printf("nbr id%d :%d\n", i, *tmp->nbr);
		tmp = tmp->next;
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;

	ft_bzero(&stacks, sizeof(t_stacks));
	ft_init_stacks(&stacks, ac, av, 1);
	if (!stacks.a)
		ft_errors_buster(&stacks);
	if (ft_stack_size(stacks.a) == 1)
		ft_cleaner(&stacks, 1);
	if (!ft_sorting_check(stacks.a))
		ft_sort_stacks(&stacks);
	ft_cleaner(&stacks, 0);
	return (0);
}
