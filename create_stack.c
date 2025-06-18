/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:26:00 by jtoumani          #+#    #+#             */
/*   Updated: 2025/06/17 18:08:19 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	add_node(t_stack *a, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (a->top == NULL)
	{
		a->top = new_node;
		a->bottom = new_node;
	}
	else
	{
		a->bottom->next = new_node;
		a->bottom = new_node;
	}
	a->size++;
}

t_stack	*init_stack(void)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
	return (a);
}
