/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel <michel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:48:58 by mm-furi           #+#    #+#             */
/*   Updated: 2024/12/12 19:19:29 by michel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_negative_numbers(t_stack *stack, int *offset)
{
	int	min_value;

	*offset = 0;
	min_value = find_min(stack);
	if (min_value < 0)
	{
		*offset = -min_value;
		shift_numbers(stack, *offset);
	}
}

void	sort_by_bits(t_stack *a, t_stack *b, int max_bits)
{
	int	i;
	int	j;
	int	num_elements;

	num_elements = a->size;
	
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < num_elements)
		{
			if (((a->top->value >> i) & 1) == 0)
				pb(b, a);
			else
				ra(a);
			j++;
		}
		move_back_to_a(a, b);
		i++;
	}
}

void	move_back_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
		pa(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	offset;

	if (a == NULL || a->top == NULL)
		return ;
	handle_negative_numbers(a, &offset);
	max_bits = calculate_max_bits(a);
	sort_by_bits(a, b, max_bits);
	if (offset > 0)
		unshift_numbers(a, offset);
}
