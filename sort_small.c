/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:31:07 by jtoumani          #+#    #+#             */
/*   Updated: 2025/06/23 12:19:54 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three(t_stack *a)
{
	int	one;
	int	two;
	int	three;

	one = a->top->value;
	two = a->top->next->value;
	three = a->bottom->value;
	if (one > two && two < three && three > one)
		sa(a, 1);
	else if (one > two && two > three)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (one > two && two < three && three < one)
		ra(a, 1);
	else if (one < two && two > three && three > one)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (one < two && two > three && three < one)
		rra(a, 1);
}

void	sort_four(t_stack *a, t_stack *b)
{
	push_small_top(a);
	pb(a, b, 1);
	sort_three(a);
	pa(a, b, 1);
}

void	sort_five(t_stack *a, t_stack *b)
{
	push_small_top(a);
	pb(a, b, 1);
	push_small_top(a);
	pb(a, b, 1);
	sort_three(a);
	pa(a, b, 1);
	pa(a, b, 1);
}

int	is_sorted(t_stack *a)
{
	t_node	*nbr;

	nbr = a->top;
	if (!a)
		return (1);
	while (nbr->next)
	{
		if (nbr->value > nbr->next->value)
			return (0);
		nbr = nbr->next;
	}
	return (1);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a, 1);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
		raddix_sort(a, b);
}
