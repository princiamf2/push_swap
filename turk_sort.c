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

t_move	compute_costs(int pos_a, int pos_b, int size_a, int size_b)
{
	t_move move;
	int	rev_a;
	int rev_b;

	rev_a = size_a - pos_a;
	rev_b = size_b - pos_b;
	if (pos_a > pos_b)
		move.rr = pos_a;
	else
		move.rr = pos_b;
	if (rev_a > rev_b)
		move.rrr = rev_a;
	else
		move.rrr = rev_b;
	move.rarrb = pos_a + rev_b;
	move.rrbra = rev_a + pos_b;
	move.best = move.rr;
	move.method = 1;
	if (move.rrr < move.best)
	{
		move.best = move.rrr;
		move.method = 2;
	}
	if (move.rarrb < move.best)
	{
		move.best =move.rarrb;
		move.method = 3;
	}
	if (move.rrbra < move.best)
	{
		move.best = move.rrbra;
		move.method = 4;
	}
	return (move);
}

void apply_move(t_stack *a, t_stack *b, t_move move, int pos_a, int pos_b)
{
	int rev_a;
	int rev_b;
	int both;
	int diff;

	rev_a = a->size - pos_a;
	rev_b = b->size - pos_b;
	if (move.method == 1)
	{
		if (pos_a < pos_b)
			both = pos_a;
		else
			both = pos_b;
		while (both > 0)
		{
			rr(a, b);
			both--;
		}
		diff = pos_a - (pos_a < pos_b ? pos_a : pos_b);
		if (diff < 0)
			diff = 0;
		while (diff > 0)
		{
			ra(a);
			diff--;
		}
		diff = pos_b - (pos_a < pos_b ? pos_a : pos_b);
		if (diff < 0)
			diff = 0;
		while (diff > 0)
		{
			rb(b);
			diff--;
		}
	}
	else if (move.method == 2)
	{
		if (rev_a < rev_b)
			both = rev_a;
		else
			both = rev_b;
		while (both > 0)
		{
			rrr(a, b);
			both--;
		}
		diff = rev_a - (rev_a < rev_b ? rev_a : rev_b);
		if (diff < 0)
			diff = 0;
		while (diff > 0)
		{
			rra(a);
			diff--;
		}
		diff = rev_b - (rev_a < rev_b ? rev_a : rev_b);
		if (diff < 0)
			diff = 0;
		while (diff > 0)
		{
			rrb(b);
			diff--;
		}
	}
	else if (move.method == 3)
	{
		while (pos_a > 0)
		{
			ra(a);
			pos_a--;
		}
		while (rev_b > 0)
		{
			rrb(b);
			rev_b--;
		}
	}
	else if (move.method == 4)
	{
		while (rev_a > 0)
		{
			rra(a);
			rev_a--;
		}
		while (pos_b > 0)
		{
			rb(b);
			pos_b--;
		}
	}
}

int find_val_min_moove(t_stack *a, t_stack *b)
{
	 t_node *cur;
    int best_val;
    int best_cost;
    int pos_a;
    int pos_b;
    t_move tmp_move;

    best_val = 0;
    best_cost = INT_MAX;
    cur = a->top;
    while (cur)
    {
        pos_a = find_pos_to_stack(a, cur->value);
        pos_b = find_pos_insert(b, cur->value);
        tmp_move = compute_costs(pos_a, pos_b, a->size, b->size);

        if (tmp_move.best < best_cost)
        {
            best_cost = tmp_move.best;
            best_val = cur->value;
        }
        cur = cur->next;
    }
    return (best_val);
}

void push_to_b(t_stack *a, t_stack *b)
{
	int val;
	int pos;
	int pos_insert;
	t_move move;

	while (b->size < 2)
		pb(b, a);
	if (b->top->value < b->top->next->value)
		sb(b);
	while (a->size > 3)
	{
		val = find_val_min_moove(a, b);
		pos = find_pos_to_stack(a, val);
		pos_insert = find_pos_insert(b, val);
		move = compute_costs(pos, pos_insert, a->size, b->size);
		apply_move(a, b, move, pos, pos_insert);
		pb(b, a);
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
	int val;
	int pos;
	int first_val_push;

	push_to_b(a, b);
	val = find_max(b);
	first_val_push = val;
	while (b->top->value != val)
	{
		pos = find_pos_to_stack(b, val);
		if (pos > b->size / 2)
			rrb(b);
		else
			rb(b);
	}
	pa(a, b);
	while (b->size > 0)
	{
		val = find_max(b);
		while (b->top->value != val)
		{
			pos = find_pos_to_stack(b, val);
			if (pos > b->size / 2)
				rrb(b);
			else
				rb(b);
		}
		while (last_val(a) > val && last_val(a) != first_val_push)
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
