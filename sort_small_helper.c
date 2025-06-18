/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:30:06 by jtoumani          #+#    #+#             */
/*   Updated: 2025/06/17 12:35:12 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	smallest_index(t_stack *a)
{
	t_node	*current;
	int		smallest;
	int		current_pos;
	int		smallest_pos;

	current = a->top;
	current_pos = 0;
	smallest_pos = 0;
	smallest = a->top->value;
	while (current)
	{
		if (current->value < smallest)
		{
			smallest = current->value;
			smallest_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (smallest_pos);
}

void	push_small_top(t_stack *a)
{
	int	small;

	small = smallest_index(a);
	if (a->size < 2)
		return ;
	if (small <= a->size / 2)
	{
		while (small-- > 0)
			ra(a, 1);
	}
	else
	{
		small = a->size - small;
		while (small-- > 0)
			rra(a, 1);
	}
}
