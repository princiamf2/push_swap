#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

t_stack				*init_stack(int argc, char **argv);
t_stack				*create_empty_stack(void);
int					push_to_stack(t_stack *stack, int value);
void				free_stack(t_stack *stack);
int					is_valid_number(char *str);
int					is_int(char *str);
int					ft_isdigit(int c);
int					ft_isspace(int c);
int					is_sorted(t_stack *stack);
int					check_duplicates(t_stack *stack);
long				ft_atol(char *str);
int					ft_atoi(char *str);
void				ft_putstr_fd(char *str, int fd);
size_t				ft_strlen(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
void				swap(t_stack *stack);
void				push(t_stack *dest, t_stack *src);
void				rotate(t_stack *stack);
void				rrotate(t_stack *stack);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *b, t_stack *a);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
int					find_max(t_stack *stack);
int					find_min(t_stack *stack);
void				shift_numbers(t_stack *stack, int offset);
void				unshift_numbers(t_stack *stack, int offset);
int					calculate_max_bits(t_stack *stack);
void				handle_negative_numbers(t_stack *stack, int *offset);
void				sort_by_bits(t_stack *a, t_stack *b, int max_bits);
void				move_back_to_a(t_stack *a, t_stack *b);
void				radix_sort(t_stack *a, t_stack *b);
int					main(int argc, char **argv);
void				error_exit(void);
void				print_stack(t_stack *stack, char *name);
void 				sort_three(t_stack *a);
void				sort_five(t_stack *a, t_stack *b);
void 				up_min_four(t_stack *a);
void 				up_min_five(t_stack *a);
void				push_to_b(t_stack *a, t_stack *b);
void 				moove_to_a(t_stack *a, t_stack *b);
#endif
