/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_spe1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:23:30 by mm-furi           #+#    #+#             */
/*   Updated: 2025/01/17 14:44:26 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *b, t_stack *a)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}
