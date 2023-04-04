/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:17:12 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/03 00:39:10 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_executer_extension(t_stacks **stacks, char *input, int n)
{
	if (n == 1)
	{
		if (input[2] == 'a')
			ft_rev_rot(&(*stacks)->a, 0);
		else if (input[2] == 'b')
			ft_rev_rot(&(*stacks)->b, 0);
		else if (input[2] == 'r')
			ft_rrr(&(*stacks)->a, &(*stacks)->b, 0);
	}
	else
	{
		if (input[1] == 'a')
			ft_push(&(*stacks)->a, &(*stacks)->b, 0);
		else if (input[1] == 'b')
			ft_push(&(*stacks)->b, &(*stacks)->a, 0);
	}
}

char	*ft_executer(t_stacks *stacks, char *input)
{
	if (input[0] == 's' && input[2] == '\n')
	{
		if (input[1] == 'a')
			ft_swap(&stacks->a, 0);
		else if (input[1] == 'b')
			ft_swap(&stacks->b, 0);
		else if (input[1] == 's')
			ft_ss(&stacks->a, &stacks->b, 0);
	}
	else if (input[0] == 'r' && input[2] == '\n')
	{
		if (input[1] == 'a')
			ft_rotate(&stacks->a, 0);
		else if (input[1] == 'b')
			ft_rotate(&stacks->b, 0);
		else if (input[1] == 'r')
			ft_rr(&stacks->a, &stacks->b, 0);
	}
	else if (input[0] == 'p' && input[2] == '\n')
		ft_executer_extension(&stacks, input, 0);
	else if (input[0] == 'r' && input[1] == 'r' && input[3] == '\n')
		ft_executer_extension(&stacks, input, 1);
	else
		ft_errors_buster(stacks);
	return (get_next_line(0));
}

void	ft_inspector(t_stacks *stacks, char *input)
{
	char	*str;

	while (input)
	{
		if (*input == '\n')
			ft_errors_buster(stacks);
		str = input;
		if (!str)
			ft_errors_buster(stacks);
		input = ft_executer(stacks, input);
		free(str);
	}
	if (stacks->b)
		write (1, "KO\n", 3);
	else if (!ft_sorting_check(stacks->a))
		write (1, "KO\n", 3);
	else
		write (1, "OK\n", 3);
	free(input);
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;
	char		*input;

	ft_bzero(&stacks, sizeof(t_stacks));
	ft_init_stacks(&stacks, ac, av, 0);
	if (!stacks.a)
		ft_errors_buster(&stacks);
	input = get_next_line(0);
	if (!input && !ft_sorting_check(stacks.a))
		write (1, "KO\n", 3);
	else if (!input && ft_sorting_check(stacks.a))
		write (1, "OK\n", 3);
	else
		ft_inspector(&stacks, input);
	ft_cleaner(&stacks, 0);
	return (0);
}
