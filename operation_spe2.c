/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_spe2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:24:21 by mm-furi           #+#    #+#             */
/*   Updated: 2025/01/17 14:47:18 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *b)
{
	rotate(b);
    ft_putstr_fd("rb\n", 1);
}

void	rra(t_stack *a)
{
	rrotate(a);
    ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b)
{
	rrotate(b);
    ft_putstr_fd("rrb\n", 1);
}

void rr(t_stack *a, t_stack *b)
{
    rotate(a);
    rotate(b);
    ft_putstr_fd("rr\n", 1);
}

void rrr(t_stack *a, t_stack *b)
{
    rrotate(a);
    rrotate(b);
    ft_putstr_fd("rrr\n", 1);
}
