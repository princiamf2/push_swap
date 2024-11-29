/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:57:04 by mm-furi           #+#    #+#             */
/*   Updated: 2024/11/29 15:27:44 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	int		max;
	t_node	*cur;

	max = stack->top->value;
	cur = stack->top->next;
	while (cur != NULL)
	{
		if (cur->value > max)
			max = cur->value;
		cur = cur->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		return (0);
	min = stack->top->value;
	current = stack->top->next;
	while (current != NULL)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

void	shift_numbers(t_stack *stack, int offset)
{
	t_node	*cur;

	if (stack == NULL)
		return ;
	cur = stack->top;
	while (cur != NULL)
	{
		cur->value += offset;
		cur = cur->next;
	}
}

void	unshift_numbers(t_stack *stack, int offset)
{
	t_node	*cur;

	if (stack == NULL)
		return ;
	cur = stack->top;
	while (cur != NULL)
	{
		cur->value -= offset;
		cur = cur->next;
	}
}

int	calculate_max_bits(t_stack *stack)
{
	int	max;
	int	max_bits;

	max = find_max(stack);
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
