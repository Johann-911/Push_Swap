/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:26:56 by jtoumani          #+#    #+#             */
/*   Updated: 2025/06/17 12:29:10 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_stack *a, int print)
{
	t_node	*temp;

	if (a->size < 2)
		return ;
	temp = a->top;
	while (temp->next->next != NULL)
		temp = temp->next;
	a->bottom->next = a->top;
	a->top = a->bottom;
	a->bottom = temp;
	a->bottom->next = NULL;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int print)
{
	t_node	*temp;

	if (b->size < 2)
		return ;
	temp = b->top;
	while (temp->next->next != NULL)
		temp = temp->next;
	b->bottom->next = b->top;
	b->top = b->bottom;
	b->bottom = temp;
	b->bottom->next = NULL;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		write(1, "rrr\n", 4);
}
