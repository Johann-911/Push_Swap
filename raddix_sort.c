/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raddix_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:25:49 by jtoumani          #+#    #+#             */
/*   Updated: 2025/06/18 12:41:24 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	assign_index(t_stack *a)
{
	t_node	*current;
	t_node	*comp;
	int		index;

	current = a->top;
	while (current)
	{
		index = 0;
		comp = a->top;
		while (comp)
		{
			if (comp->value < current->value)
				index++;
			comp = comp->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	get_max_bits(t_stack *a)
{
	t_node	*current;
	int		bits;
	int		max;

	max = 0;
	bits = 0;
	current = a->top;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	while (max >> bits)
		bits++;
	return (bits);
}

void	raddix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	assign_index(a);
	max_bits = get_max_bits(a);
	size = a->size;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->top->index >> i) & 1) == 1)
				ra(a, 1);
			else
				pb(a, b, 1);
			j++;
		}
		while (b->size > 0)
			pa(a, b, 1);
		i++;
	}
}
