/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:00:49 by mm-furi           #+#    #+#             */
/*   Updated: 2025/01/13 14:23:33 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[i] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void up_min_five(t_stack *a)
{
	int min;
	int	i;
	int	min_pos;
	t_node *cur;

	if (a->size != 5)
		return ;
	cur = a->top;
	i = 0;
	min = find_min(a);
	min_pos = 0;
	while (cur != NULL)
	{
		if (cur->value == min)
			min_pos = i;
		i++;
		cur = cur->next;
	}
	if (min_pos == 0)
		return ;
	else if (min_pos == 1)
		sa(a);
	else if (min_pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_pos == 3)
	{
		rra(a);
		rra(a);
	}
	else if (min_pos == 4)
		rra(a);
}

void up_min_four(t_stack *a)
{
	int min;
	int	i;
	int	min_pos;
	t_node *cur;

	if (a->size != 4)
		return ;
	cur = a->top;
	i = 0;
	min = find_min(a);
	min_pos = 0;
	while (cur != NULL)
	{
		if (cur->value == min)
			min_pos = i;
		i++;
		cur = cur->next;
	}
	if (min_pos == 0)
		return ;
	else if (min_pos == 1)
		sa(a);
	else if (min_pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_pos == 3)
		rra(a);
}
