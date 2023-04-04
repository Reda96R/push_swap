/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:52:01 by rerayyad          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/02 20:44:45 by rerayyad         ###   ########.fr       */
=======
/*   Updated: 2023/04/01 17:41:02 by rerayyad         ###   ########.fr       */
>>>>>>> af5c9e92abfa76924b55b64cd5587c16988b52ac
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
# include "get_next_line.h"

typedef struct s_stack
{
	int				*nbr;
	struct s_stack	*next;
}t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}t_stacks;

void		print_stack(t_stack *stack);

/* :::main functions::: */
void		ft_init_stacks(t_stacks *stacks, int ac, char *av[], int n);
void		ft_cleaner(t_stacks *stacks, int n);
void		ft_errors_buster(t_stacks *stacks);

/* :::actions::: */
void		ft_push(t_stack **dest, t_stack **src, int i);
void		ft_swap(t_stack **stack, int i);
void		ft_ss(t_stack **a, t_stack **b, int i);
void		ft_rotate(t_stack **stack, int i);
void		ft_rr(t_stack **a, t_stack **b, int i);
void		ft_rev_rot(t_stack **stack, int i);
void		ft_rrr(t_stack **a, t_stack **b, int i);

/* :::sorting::: */
void		ft_sort_stacks(t_stacks *stacks);
t_stacks	ft_first_sort(t_stacks *stacks);
t_stacks	ft_second_sort(t_stacks *stacks);
void		ft_case_three(t_stack **a);
void		ft_case_five(t_stacks **stacks);
void		ft_road_to_three(t_stacks **stacks);

/* :::checkers::: */
int			ft_sorting_check(t_stack *a);
int			ft_duplication_check(t_stack **stack, int n);
int			ft_type_checker(long *n, char *str);
int			ft_space_check(char c);
int			ft_isdigit(int c);

/* :::calculators_b::: */
int			ft_rot_comb_ab(t_stacks	**stacks);
int			ft_ra_rb(t_stacks *stacks, int nbr);
int			ft_rra_rrb(t_stacks *stacks, int nbr);
int			ft_rra_rb(t_stacks *stacks, int nbr);
int			ft_ra_rrb(t_stacks *stacks, int nbr);

/* :::calculators_a::: */
int			ft_rot_comb_ba(t_stacks	*stacks);
int			ft_ra_rb_a(t_stacks *stacks, int nbr);
int			ft_rra_rrb_a(t_stacks *stacks, int nbr);
int			ft_rra_rb_a(t_stacks *stacks, int nbr);
int			ft_ra_rrb_a(t_stacks *stacks, int nbr);

/* :::appliers:::*/
int			ft_app_ra_rb(t_stacks *stacks, int nbr, int n);
int			ft_app_rra_rrb(t_stacks *stacks, int nbr, int n);
int			ft_app_ra_rrb(t_stacks *stacks, int nbr, int n);
int			ft_app_rra_rb(t_stacks *stacks, int nbr, int n);

/* :::placers::: */
int			ft_b_placer(t_stack *stack, int nbr);
int			ft_a_placer(t_stack *stack, int nbr);

/* :::finders::: */
int			ft_min_finder(t_stack *stack);
int			ft_max_finder(t_stack *stack);
int			ft_index_finder(t_stack *stack, int nbr);

/* :::lists:::*/
t_stack		*ft_new(void *n);
void		ft_add_to_stack(t_stack **stack, t_stack *new);
t_stack		*ft_last(t_stack *stack);
int			ft_stack_size(t_stack *stack);

/* :::helpers::: */
<<<<<<< HEAD
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
long		ft_atoi(const char *str);
void		ft_bring_to_top(t_stack **stack, int nbr, int id);
=======
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
long	ft_atoi(const char *str);
>>>>>>> af5c9e92abfa76924b55b64cd5587c16988b52ac

#endif
