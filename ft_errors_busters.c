/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_busters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:26:40 by rerayyad          #+#    #+#             */
/*   Updated: 2023/03/31 13:59:01 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_errors_buster(t_stacks *stacks)
{
	write(2, "Error\n", 6);
	ft_cleaner(stacks, 0);
	exit(1);
}
