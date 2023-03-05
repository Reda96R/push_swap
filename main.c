/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:52:57 by rerayyad          #+#    #+#             */
/*   Updated: 2023/03/05 19:12:50 by rerayyad         ###   ########.fr       */
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
	ft_init_stacks(&stacks, ac, av);
	printf("::: stack a before ::: \n");
	print_stack(stacks.a);
	if (!ft_check_sorting(stacks.a))
		ft_sort_stacks(&stacks);
	printf("::: stack a after ::: \n");
	print_stack(stacks.a);
	ft_cleaner(&stacks);
	return (0);
}
