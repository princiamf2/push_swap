/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:45:35 by mm-furi           #+#    #+#             */
/*   Updated: 2025/01/22 16:23:43 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		return (0);
	a = init_stack(argc, argv);
	if (a->size == 3 && !is_sorted(a))
	{
		sort_three(a);
		print_stack(a, "a");
	}

	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	b = create_empty_stack();
	if (!b)
	{
		free_stack(a);
		error_exit();
	}
	moove_to_a(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
