/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:26:24 by jtoumani          #+#    #+#             */
/*   Updated: 2025/06/05 17:40:42 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_stack *a, t_stack *b, int print)
{
	t_node	*temp;

	if (b->size == 0)
		return ;
	temp = b->top;
	b->top = temp->next;
	b->size--;
	if (b->size == 0)
		b->bottom = NULL;
	temp->next = a->top;
	a->top = temp;
	if (a->size == 0)
		a->bottom = temp;
	a->size++;
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, int print)
{
	t_node	*temp;

	if (a->size == 0)
		return ;
	temp = a->top;
	a->top = temp->next;
	a->size--;
	if (a->size == 0)
		a->bottom = NULL;
	temp->next = b->top;
	b->top = temp;
	if (b->size == 0)
		b->bottom = temp;
	b->size++;
	if (print)
		write(1, "pb\n", 3);
}
