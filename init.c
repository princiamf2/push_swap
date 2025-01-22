/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:36:07 by mm-furi           #+#    #+#             */
/*   Updated: 2025/01/13 16:36:16 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(int argc, char **argv)
{
	t_stack *stack;
	int i;
	int value;

	stack = create_empty_stack();
	if (!stack)
		error_exit();
	i = argc - 1;

	while (i > 0)
	{
		if (!is_valid_number(argv[i]) || !is_int(argv[i]))
		{
			free_stack(stack);
			error_exit();
		}
		value = ft_atoi(argv[i]);
		if (!push_to_stack(stack, value))
		{
			free_stack(stack);
			error_exit();
		}
		i--;
	}
	if (!check_duplicates(stack))
	{
		free_stack(stack);
		error_exit();
	}
	return (stack);
}

t_stack *create_empty_stack(void)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

int push_to_stack(t_stack *stack, int value)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
	return (1);
}

void free_stack(t_stack *stack)
{
	t_node *current;
	t_node *next_node;

	if (stack == NULL)
		return;
	current = stack->top;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	free(stack);
}

int is_int(char *str)
{
	long value;

	value = ft_atol(str);
	if (value < INT_MIN || value > INT_MAX)
		return (0);
	return (1);
}

long ft_atol(char *str)
{
	int i;
	long result;
	int sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' ||
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int ft_atoi(char *str)
{
	return ((int)ft_atol(str));
}

int is_sorted(t_stack *stack)
{
	t_node *current;

	if (stack == NULL || stack->top == NULL)
		return (1);
	current = stack->top;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int check_duplicates(t_stack *stack)
{
	t_node *current;
	t_node *runner;

	current = stack->top;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->value == runner->value)
				return (0);
			runner = runner->next;
		}
		current = current->next;
	}
	return (1);
}

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void print_stack(t_stack *stack, char *name)
{
    t_node *current;

    printf("Stack %s: ", name);
    current = stack->top;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

t_node *nodelast(t_node *node)
{
	while (node)
	{
		if (!node->next)
			return (node);
		node = node->next;
	}
	return (node);
}
