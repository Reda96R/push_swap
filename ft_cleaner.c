/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:21:08 by rerayyad          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/31 13:58:05 by rerayyad         ###   ########.fr       */
=======
/*   Updated: 2023/03/29 15:28:32 by rerayyad         ###   ########.fr       */
>>>>>>> 09d2d857c57fef8f386719bf717295ce7a80ab8b
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_cleaner(t_stack **stack, void (*del)(void *))
{
	t_stack	*tmp;

	if (!stack || !(*stack) || !del)
		return ;
	while (*stack)
	{
		tmp = (*stack);
		*stack = (*stack)->next;
		del(tmp->nbr);
		free(tmp);
	}
	*stack = NULL;
}

void	ft_cleaner(t_stacks *stacks, int n)
{
	ft_list_cleaner(&(stacks->a), free);
	ft_list_cleaner(&(stacks->b), free);
<<<<<<< HEAD
	if (n)
		exit(0);
=======
>>>>>>> 09d2d857c57fef8f386719bf717295ce7a80ab8b
}
