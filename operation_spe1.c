/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_spe1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:23:30 by mm-furi           #+#    #+#             */
/*   Updated: 2024/11/25 15:24:15 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	swap(a, "sa\n");
}

void	sb(t_stack *b)
{
	swap(b, "sb\n");
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b, "pa\n");
}

void	pb(t_stack *b, t_stack *a)
{
	push(b, a, "pb\n");
}

void	ra(t_stack *a)
{
	rotate(a, "ra\n");
}
