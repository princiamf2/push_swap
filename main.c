/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:45:35 by mm-furi           #+#    #+#             */
/*   Updated: 2024/11/29 17:07:31 by mm-furi          ###   ########.fr       */
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
	radix_sort(a, b);
	// print_stack(a, "a");
	// print_stack(b, "b");
	free_stack(a);
	free_stack(b);
	return (0);
}
