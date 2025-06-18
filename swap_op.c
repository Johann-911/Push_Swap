/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:27:04 by jtoumani          #+#    #+#             */
/*   Updated: 2025/06/17 12:34:45 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_stack *a, int print)
{
	t_node	*temp;

	if (a->size < 2)
		return ;
	temp = a->top;
	a->top = temp->next;
	temp->next = a->top->next;
	a->top->next = temp;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int print)
{
	t_node	*temp;

	if (b->size < 2)
		return ;
	temp = b->top;
	b->top = temp->next;
	temp->next = b->top->next;
	b->top->next = temp;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		write(1, "ss\n", 3);
}
