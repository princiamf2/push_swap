/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   litle_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel <michel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:53:57 by michel            #+#    #+#             */
/*   Updated: 2024/12/16 00:39:25 by michel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack *a)
{
    int first = a->top->value;
    int second = a->top->next->value;
    int third = a->top->next->next->value;

    if (first > second && second < third && first < third)
        sa(a); // Cas 1
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    } // Cas 2
    else if (first > second && second < third && first > third)
        ra(a); // Cas 3
    else if (first < second && second > third && first < third)
    {
        sa(a);
        ra(a);
    } // Cas 4
    else if (first < second && second > third && first > third)
        rra(a); // Cas 5
    // Si aucun cas n'est satisfait, la pile est déjà triée
}

t_stack **create_chunks(t_stack *stack)
{
    t_stack **chunks;
    int i;
    int j;
    int chunks_count;
    t_node *cur;
    t_node *new;

    if (stack->size < 5 || stack->size % 5 != 0)
    {
        ft_putstr_fd("la taile de la stack est pas un multiple de 5\n", 2);
        return (NULL);
    }
    j = 0;
    cur = stack->top;
    chunks_count = stack->size / 5;
    chunks = (t_stack **)malloc(sizeof(t_stack *) * chunks_count);
    if (!chunks)
    {
        ft_putstr_fd("allocation chunks echouer\n", 2);
        return (NULL);
    }
    while (j < chunks_count)
    {
        chunks[j] = (t_stack *)malloc(sizeof(t_stack));
        if (!chunks[j])
        {
            ft_putstr_fd("Allocation d'un chunk echouée\n", 2);
            while (j > 0)
            {
                free(chunks[j]);
                j--;
            }
            free(chunks);
            return (NULL);
        }
        chunks[j]->top = NULL;
        chunks[j]->size = 0;
        i = 0; 
        while (i < 5)
        {
            new = (t_node *)malloc(sizeof(t_node));
            if (!new)
            {
                while (j > 0)
                {
                    free(chunks[j]);
                    j--;
                }
                free(chunks);
                ft_putstr_fd("Allocation d'un nœud échouée\n", 2);
                return (NULL);
            }
            new->value = cur->value;
            new->next = chunks[j]->top;
            chunks[j]->top = new;
            chunks[j]->size++;
            cur = cur->next;
            i++;
        }
        j++;

    }
    return chunks;
}

t_stack    **sort_stack_of_stack(t_stack *a, t_stack *b)
{
    t_stack **tmp;
    int i;
    int chunks_count;
    
    if (a->size < 5 || a->size % 5 != 0)
        return (NULL);
    chunks_count = a->size / 5;
    tmp = create_chunks(a);
    i = 0;
    while (i < chunks_count)
    {
        sort_five(tmp[i], b);
        i++;
    }
    return tmp;
}

int find_chunks_have_min(t_stack **stack, int chunks_count)
{
    int		min;
    int     i;
    int     flg;
	t_node	*current;

	if (stack == NULL || chunks_count == 0)
		return (-1);
    i = 0;
    flg = 0;
	min = stack[0]->top->value;
    while (i <  chunks_count)
    {
        current = stack[i]->top;
        while (current != NULL)
	    {
		    if (current->value < min)
            {
                min = current->value;
                flg = i;
            }
		    current = current->next;
	    }
        i++;
    }
	return (flg);
}

void    sort_stack(t_stack *a, t_stack *b)
{
    int j;
    int i;
    int end;
    t_stack **tmp;
    int     chunks_count;
    
    if (a->size <= 5 || a->size % 5 != 0)
        return ;
    tmp = sort_stack_of_stack(a, b);
    chunks_count = a->size / 5;
    i = 0;
    end = a->size;
    while (i < end)
    {
        j = find_chunks_have_min(tmp, chunks_count);
        pb(b, tmp[j]);
        i++;
    }
    // free(a);
    // i = 0;
    // while (i < chunks_count)
    // {
    //     free(tmp[i]);
    //     i++;
    // }
    // free(tmp);
    // a = create_empty_stack();
    // while (b->size > 0)
    // {
    //     pa(a, b);    
    // }
}