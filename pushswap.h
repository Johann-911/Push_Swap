/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:26:52 by jtoumani          #+#    #+#             */
/*   Updated: 2025/06/20 15:43:10 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "Libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

// push operators
void				pa(t_stack *a, t_stack *b, int print);
void				pb(t_stack *a, t_stack *b, int print);

// swap operators
void				sa(t_stack *a, int print);
void				sb(t_stack *b, int print);
void				ss(t_stack *a, t_stack *b, int print);

// rotate operators
void				ra(t_stack *a, int print);
void				rb(t_stack *b, int print);
void				rr(t_stack *a, t_stack *b, int print);

// reverse rotate operators
void				rra(t_stack *a, int print);
void				rrb(t_stack *b, int print);
void				rrr(t_stack *a, t_stack *b, int print);

// utils
char				**ft_split(char const *s, char c);
char				**create_matrix(char **matrix, char const *s, char c,
						int index);
void				free_matrix(char **matrix, int index);
int					count_words(char *s, char c);

// error handling
void				free_arguments(char **arguments);
void				free_stack(t_stack *a);
void				exit_error(t_stack *a, t_stack *b, char **arguments);

// create stack
void				add_node(t_stack *a, int value);
t_stack				*init_stack(void);

// parsing check
bool				is_valid_nbr(char *str);
long				ft_atol(const char *str);
bool				is_duplicate(int value, t_stack *a);
void				parse_args(int argc, char **argv, t_stack *a, t_stack *b);

// sorting
int					smallest_index(t_stack *a);
void				push_small_top(t_stack *a);
void				assign_index(t_stack *a);
int					get_max_bits(t_stack *a);
void				raddix_sort(t_stack *a, t_stack *b);
void				sort_three(t_stack *a);
void				sort_four(t_stack *a, t_stack *b);
void				sort_five(t_stack *a, t_stack *b);
int					is_sorted(t_stack *a);

#endif