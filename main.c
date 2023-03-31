/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:52:57 by rerayyad          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/31 13:58:37 by rerayyad         ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2023/03/29 17:58:47 by rerayyad         ###   ########.fr       */
=======
/*   Updated: 2023/03/22 18:27:39 by rerayyad         ###   ########.fr       */
>>>>>>> a70e43dc9689dfd48803e95da8da18298151d614
>>>>>>> 09d2d857c57fef8f386719bf717295ce7a80ab8b
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
<<<<<<< HEAD
	ft_init_stacks(&stacks, ac, av, 1);
	if (!stacks.a)
		ft_errors_buster(&stacks);
	if (!ft_sorting_check(stacks.a))
		ft_sort_stacks(&stacks);
	ft_cleaner(&stacks, 0);
=======
	ft_init_stacks(&stacks, ac, av);
<<<<<<< HEAD
	if (!stacks.a)
		ft_errors_buster(&stacks);
	if (!ft_sorting_check(stacks.a))
		ft_sort_stacks(&stacks);
=======
	// printf("::: stack a before ::: \n");
	// print_stack(stacks.a);
	if (!ft_check_sorting(stacks.a))
		ft_sort_stacks(&stacks);
	// printf("\n::: stack a after ::: \n");
	// print_stack(stacks.a);
	// printf("\n<-::: stack b :::->\n");
	// print_stack(stacks.b);
	// while (1);
>>>>>>> a70e43dc9689dfd48803e95da8da18298151d614
	ft_cleaner(&stacks);
>>>>>>> 09d2d857c57fef8f386719bf717295ce7a80ab8b
	return (0);
}
