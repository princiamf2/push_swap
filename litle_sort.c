/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   litle_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:53:57 by michel            #+#    #+#             */
/*   Updated: 2025/01/13 14:23:45 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack *a)
{
    int first = a->top->value;
    int second = a->top->next->value;
    int third = a->top->next->next->value;

    if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first > third)
        ra(a);
    else if (first < second && second > third && first < third)
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && first > third)
        rra(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	if (a->size != 5)
		return ;
	up_min_five(a);
	pb(b, a);
	up_min_four(a);
	pb(b, a);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
