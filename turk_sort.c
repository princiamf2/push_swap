#include "push_swap.h"

int find_pos_insert(t_stack *stack, int nb)
{
	int i;
	t_node *cur;

	if (!stack || !stack->top)
		return (0);
	if (nb > stack->top->value)
		return (0);
	i = 0;
	cur = stack->top;
	while (cur && cur->next)
	{
		if (nb < cur->value && nb > cur->next->value)
			return (i + 1);
		i++;
		cur = cur->next;
	}
	return (i + 1);
}

int find_val_min_moove(t_stack *a, t_stack *b)
{
	int i;
	int j;
	int min;
	t_node *cur;

	j = INT_MAX;
	min = 0;
	cur = a->top;
	while (cur)
	{
		i = find_pos_insert(b, cur->value);
		if (i < j)
		{
			j = i;
			min = cur->value;
		}
		cur = cur->next;
	}
	return (min);
}

int is_same_rot(int n, int nb, int size)
{
	if (n > size / 2 && nb > size / 2)
        return (1);
    else if (n < size / 2&& nb < size / 2)
        return (2);
    return (0);
}

int find_pos_to_stack(t_stack *stack, int nb)
{
	int i;
	t_node *cur;

	if (!stack || !stack->top)
		return (-1);
	i = 0;
	cur = stack->top;
	while (cur != NULL)
	{
		if (cur->value == nb)
			return (i);
		i++;
		cur = cur->next;
	}
	return (-1);
}

void reverse_rot_a(t_stack *a, int nb)
{
	nb = a->size - nb;
	while (nb)
	{
		rra(a);
		nb--;
	}
}

void rot_a(t_stack *a, int nb)
{
	while (nb)
	{
		ra(a);
		nb--;
	}
}

void reverse_rot_b(t_stack *b, int nb)
{
	nb = b->size - nb;
	while (nb)
	{
		rrb(b);
		nb--;
	}
}

void rot_b(t_stack *b, int nb)
{
	while (nb)
	{
		rb(b);
		nb--;
	}
}

void best_rot(int pos, int pos_insert, t_stack *a, t_stack *b)
{
	int val;

	val = find_val_min_moove(a, b);
	if (pos == 0 && pos_insert == 0)
		return ;
	if (pos == a->size - 1)
	{
		rra(a);
		pos = 0;
	}
	while (pos > 0 && pos_insert > 0)
	{
		if (pos > a->size / 2 && pos_insert > b->size / 2)
			rrr(a, b);
		else if (pos < a->size / 2 && pos_insert < b->size / 2)
			rr(a, b);
		else
			break ;
		pos--;
		pos_insert--;
	}
	while (pos)
	{
		if (pos > a->size / 2)
		{
			reverse_rot_a(a, pos);
			pos = find_pos_to_stack(a, val);
		}
		else
		{
			rot_a(a, pos);
			pos = find_pos_to_stack(a, val);
		}
	}
	while (pos_insert)
	{
		if (pos_insert > b->size / 2)
			reverse_rot_b(b, pos_insert);
		else
			rot_b(b, pos_insert);
		pos_insert = find_pos_insert(b, val);
	}
}

void push_to_b(t_stack *a, t_stack *b)
{
	int val;
	int pos;
	int pos_insert;
	int back;

	while (b->size < 2)
		pb(b, a);
	if (b->top->value < b->top->next->value)
		sb(b);
	while (a->size > 3)
	{
		val = find_val_min_moove(a, b);
		pos = find_pos_to_stack(a, val);
		pos_insert = find_pos_insert(b, val);
		back = pos_insert;
		if (pos_insert == b->size && pos == 0 && val < find_min(b))
		{
			pb(b, a);
			rb(b);
			back = 0;
		}
		else if (pos_insert == b->size - 1 && pos == 0)
		{
			rrb(b);
			pb(b, a);
			rb(b);
			rb(b);
			back = 0;
		}
		else
		{
			best_rot(pos, pos_insert, a, b);
			pb(b, a);
		}
		while (back > 0)
		{
			if (back == b->size)
				break;
			else if (back == b->size - 3)
			{
				rb(b);
				rb(b);
				rb(b);
				break;
			}
			else if (back == b->size - 2)
			{
				rb(b);
				rb(b);
				break ;
			}
			else
			{
				back = b->size - back;
				if (back < b->size / 2)
					rot_b(b, back);
				else
					reverse_rot_b(b, back);
			}
			back = 0;
		}
	}
	sort_three(a);
}

int last_val(t_stack *stack)
{
	t_node *cur;
	int val;

	val = 0;
	cur = stack->top;
	while (cur)
	{
		if (cur->next == NULL)
			val = cur->value;
		cur = cur->next;
	}
	return val;
}

void moove_to_a(t_stack *a, t_stack *b)
{
	push_to_b(a, b);
	pa(a, b);
	while (b->size > 0)
	{
		while (last_val(a) > b->top->value)
		{
			rra(a);
			if (b->size == 1 && is_sorted(a))
				break;
		}
		pa(a, b);
	}
	while (!is_sorted(a))
		rra(a);
}
