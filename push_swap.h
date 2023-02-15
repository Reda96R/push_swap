/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:52:01 by rerayyad          #+#    #+#             */
/*   Updated: 2023/02/15 12:45:29 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}t_stacks;

void	ft_init_stacks(t_stacks *stacks, int ac, char *av[]);
void	ft_cleaner(t_stacks *stacks);
void	ft_errors_buster(t_stacks *stacks);

/* :::helpers.c::: */
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);

#endif
