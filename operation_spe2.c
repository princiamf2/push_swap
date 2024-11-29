/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_spe2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:24:21 by mm-furi           #+#    #+#             */
/*   Updated: 2024/11/25 15:24:52 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *b)
{
	rotate(b, "rb\n");
}

void	rra(t_stack *a)
{
	rrotate(a, "rra\n");
}

void	rrb(t_stack *b)
{
	rrotate(b, "rrb\n");
}
