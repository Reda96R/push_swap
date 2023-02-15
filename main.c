/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:52:57 by rerayyad          #+#    #+#             */
/*   Updated: 2023/02/15 16:21:35 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stacks	stacks;

	ft_bzero(&stacks, sizeof(t_stacks));
	ft_init_stacks(&stacks, ac, av);
	ft_sort_stacks(&stacks);
	ft_cleaner(&stacks);
	exit(0);
	return (0);
}
