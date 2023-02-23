/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:52:01 by rerayyad          #+#    #+#             */
/*   Updated: 2023/02/23 16:54:32 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_stack
{
	int				*nbr;
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

/* :::lists:::*/
t_stack	*ft_new(void *n);
void	ft_add_to_stack(t_stack **stack, t_stack *new);
t_stack	*ft_last(t_stack *stack);

/* :::checkers::: */
int		ft_check_sorting(t_stack *a);
int		ft_duplication_check(t_stack **stack, int n);
int		ft_type_checker(long *n, char *str);
int		ft_space_check(char c);
int		ft_isdigit(int c);

/* :::helpers::: */
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_atoi(const char *str);

/* :::sorting::: */
void	ft_sort_stacks(t_stacks *stacks);

/* :::actions::: */
void	ft_push(t_stack **dest, t_stack **src, int i);
void	ft_swap(t_stack **stack, int i);
void	ft_ss(t_stack **a, t_stack **b, int i);
void	ft_rotate(t_stack **stack, int i);
void	ft_rr(t_stack **a, t_stack **b, int i);
void	ft_rev_rot(t_stack **stack, int i);
void	ft_rrr(t_stack **a, t_stack **b, int i);

//void	ft_sb(t_stack **b, int i);
void	ft_ss(t_stack **a, t_stack **b, int i);

#endif
