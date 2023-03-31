/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_busters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:26:40 by rerayyad          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/31 13:59:01 by rerayyad         ###   ########.fr       */
=======
/*   Updated: 2023/03/29 15:28:07 by rerayyad         ###   ########.fr       */
>>>>>>> 09d2d857c57fef8f386719bf717295ce7a80ab8b
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_errors_buster(t_stacks *stacks)
{
	write(2, "Error\n", 6);
	ft_cleaner(stacks, 0);
	exit(1);
}
