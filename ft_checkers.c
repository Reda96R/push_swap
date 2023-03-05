/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:16:30 by rerayyad          #+#    #+#             */
/*   Updated: 2023/02/23 17:28:39 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sorting(t_stack *a)
{
	int	i;

	if (!a || !a->next)
		exit(1);
	i = *a->nbr;
	while (a)
	{
		if (i > *a->nbr)
			return (0);
		i = *a->nbr;
		a = a->next;
	}
	return (1);
}

int	ft_duplication_check(t_stack **stack, int n)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (*((int *)(tmp->nbr)) == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_digit_check(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_type_checker(long *n, char *str)
{
	int		i;
	long	x;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_digit_check(str[i]))
		return (0);
	while (str[i] && !ft_space_check(str[i]))
		if (!ft_digit_check(str[i++]))
			return (0);
	x = ft_atoi(str);
	if (x > INT_MAX || x < INT_MIN)
		return (0);
	*n = x;
	return (1);
}

int	ft_space_check(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == 32)
		return (1);
	return (0);
}
