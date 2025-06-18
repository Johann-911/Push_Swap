/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:27:00 by jtoumani          #+#    #+#             */
/*   Updated: 2025/06/17 12:34:21 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_stack *a, int print)
{
	t_node	*temp;

	if (a->size < 2)
		return ;
	temp = a->top;
	a->top = temp->next;
	temp->next = NULL;
	a->bottom->next = temp;
	a->bottom = temp;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b, int print)
{
	t_node	*temp;

	if (b->size < 2)
		return ;
	temp = b->top;
	b->top = temp->next;
	temp->next = NULL;
	b->bottom->next = temp;
	b->bottom = temp;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		write(1, "rr\n", 3);
}
