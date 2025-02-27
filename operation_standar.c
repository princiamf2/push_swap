/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_standar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:23:44 by mm-furi           #+#    #+#             */
/*   Updated: 2025/01/17 14:39:51 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack == NULL || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	push(t_stack *dest, t_stack *src)
{
	t_node	*temp;

	if (src == NULL || src->top == NULL)
		return ;
	temp = src->top;
	src->top = src->top->next;
	temp->next = dest->top;
	dest->top = temp;
	src->size--;
	dest->size++;
}

void	rotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*current;

	if (stack == NULL || stack->size < 2)
		return ;
	temp = stack->top;
	stack->top = stack->top->next;
	temp->next = NULL;
	current = stack->top;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
}

void	rrotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*current;

	prev = NULL;
	if (stack == NULL || stack->size < 2)
		return ;
	current = stack->top;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = stack->top;
	stack->top = current;
}
